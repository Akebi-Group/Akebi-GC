#include "pch-il2cpp.h"
#include "PacketSniffer.h"

#ifdef _PACKET_SNIFFER
#include "SnifferWindow.h"
#endif

#include <fstream>
#include <helpers.h>

namespace cheat::feature 
{
	PacketSniffer::PacketSniffer() : Feature(),
		NF(f_CaptureEnabled, "Capturing", "PacketSniffer", false),
		NF(f_ManipulationEnabled, "Manipulation", "PacketSniffer", false),
		NF(f_PipeName, "Pipe name", "PacketSniffer", "genshin_packet_pipe")

	{
		sniffer::MessageManager::Connect(f_PipeName.value());

		HookManager::install(app::Kcp_KcpNative_kcp_client_send_packet, KcpNative_kcp_client_send_packet_Hook);
		HookManager::install(app::MoleMole_KcpClient_TryDequeueEvent, KcpClient_TryDequeueEvent_Hook);
	}

	const FeatureGUIInfo& PacketSniffer::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Packet Sniffer", "Settings", true };
		return info;
	}

	void PacketSniffer::DrawMain()
	{
		ImGui::Text("Dev: for working needs server for named pipe with specified name.\nCheck 'packet-handler' project like example.");
		ConfigWidget(f_PipeName, "Pipe name for connecting. Changes will apply after next game launch.");
		ConfigWidget(f_CaptureEnabled, "Enable capturing of packet info and sending to pipe, if it exists.");
		ConfigWidget(f_ManipulationEnabled, "Enable blocking and modifying packets by sniffer, can cause network lags.");
	}
	
	PacketSniffer& PacketSniffer::GetInstance()
	{
		static PacketSniffer instance;
		return instance;
	}

	bool ProcessModifiedData(app::KcpPacket_1* packet)
	{
		auto modifyData = sniffer::MessageManager::WaitFor<ModifyData>();
		if (!modifyData)
			return false;

		switch (modifyData->modifyType)
		{
		case PacketModifyType::Blocked:
			return true;
		case PacketModifyType::Modified:
		{
			auto dataSize = modifyData->modifiedData.size();
			packet->data = new byte[dataSize]();
			memcpy_s(packet->data, dataSize, modifyData->modifiedData.data(), dataSize);
			packet->dataLen = static_cast<uint32_t>(dataSize);
		}
		break;
		case PacketModifyType::Unchanged:
		default:
			break;
		}
		return false;
	}

	bool PacketSniffer::OnPacketIO(app::KcpPacket_1* packet, PacketIOType type)
	{
		if (!sniffer::MessageManager::IsConnected())
			return true;

		if (!f_CaptureEnabled)
			return true;

		PacketData packetData = ParseRawPacketData((char*)packet->data, packet->dataLen);
		if (!packetData.valid)
			return true;

		packetData.ioType = type;
		packetData.blockModeEnabled = f_ManipulationEnabled;
		sniffer::MessageManager::Send(packetData);

		bool canceled = f_ManipulationEnabled && ProcessModifiedData(packet);

		return !canceled;
	}

	char* PacketSniffer::EncryptXor(void* content, uint32_t length)
	{
		app::Byte__Array* byteArray = (app::Byte__Array*)new char[length + 0x20];
		byteArray->max_length = length;
		memcpy_s(byteArray->vector, length, content, length);

		app::MoleMole_Packet_XorEncrypt(&byteArray, length, nullptr);

		auto result = new char[length];
		memcpy_s(result, length, byteArray->vector, length);
		delete[] byteArray;

		return (char*)result;
	}

	PacketData PacketSniffer::ParseRawPacketData(char* encryptedData, uint32_t length)
	{
		PacketData packetData = sniffer::MessageManager::CreateMessage<PacketData>();
		// Decrypting packetData
		auto data = EncryptXor(encryptedData, length);

		uint16_t magicHead = util::ReadMapped<uint16_t>(data, 0);

		if (magicHead != 0x4567)
		{
			LOG_ERROR("Head magic value for packet is not valid.");
			return packetData;
		}

		uint16_t magicEnd = util::ReadMapped<uint16_t>(data, length - 2);
		if (magicEnd != 0x89AB)
		{
			LOG_ERROR("End magic value for packet is not valid.");
			return packetData;
		}

		uint16_t messageId = util::ReadMapped<uint16_t>(data, 2);
		uint16_t headSize = util::ReadMapped<uint16_t>(data, 4);
		uint32_t contenSize = util::ReadMapped<uint32_t>(data, 6);

		if (length < headSize + contenSize + 12)
		{
			LOG_ERROR("Packet size is not valid.");
			return packetData;
		}

		packetData.valid = true;
		packetData.messageID = messageId;

		packetData.headRawData = std::vector<byte>((size_t)headSize, 0);
		memcpy_s(packetData.headRawData.data(), headSize, data + 10, headSize);

		packetData.messageRawData = std::vector<byte>((size_t)contenSize, 0);
		memcpy_s(packetData.messageRawData.data(), contenSize, data + 10 + headSize, contenSize);

		delete[] data;

		return packetData;
	}

	bool PacketSniffer::KcpClient_TryDequeueEvent_Hook(void* __this, app::ClientKcpEvent* evt, MethodInfo* method)
	{
		auto result = CALL_ORIGIN(KcpClient_TryDequeueEvent_Hook, __this, evt, method);

		if (!result || evt->_evt.type != app::KcpEventType__Enum::EventRecvMsg ||
			evt->_evt.packet == nullptr || evt->_evt.packet->data == nullptr)
			return result;

		auto& sniffer = GetInstance();
		return sniffer.OnPacketIO(evt->_evt.packet, PacketIOType::Receive);
	}

	int32_t PacketSniffer::KcpNative_kcp_client_send_packet_Hook(void* kcp_client, app::KcpPacket_1* packet, MethodInfo* method)
	{
		auto& sniffer = GetInstance();
		if (!sniffer.OnPacketIO(packet, PacketIOType::Send))
			return 0;

		return CALL_ORIGIN(KcpNative_kcp_client_send_packet_Hook, kcp_client, packet, method);
	}
}

