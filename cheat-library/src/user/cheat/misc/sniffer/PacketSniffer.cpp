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
		NF(m_CapturingEnabled, "Capturing", "PacketSniffer", false),
		NF(m_ManipulationEnabled, "Manipulation", "PacketSniffer", false),
		NF(m_PipeEnabled, "Pipe", "PacketSniffer", false)

#ifdef _PACKET_SNIFFER
		, NF(m_ProtoDirPath, "Proto Dir Path", "PacketSniffer", ""),
		NF(m_ProtoIDFilePath, "Proto ID File Path", "PacketSniffer", ""),
		m_PacketParser(m_ProtoDirPath, m_ProtoIDFilePath)
#endif

	{
		sniffer::MessageManager::Connect("genshin_packet_pipe");

		HookManager::install(app::KcpNative_kcp_client_send_packet, KcpNative_kcp_client_send_packet_Hook);
		HookManager::install(app::KcpClient_TryDequeueEvent, KcpClient_TryDequeueEvent_Hook);
	}

	const FeatureGUIInfo& PacketSniffer::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Packet Sniffer", "Settings", true };
		return info;
	}

	bool PacketSniffer::OnCapturingChanged()
	{
#ifdef _PACKET_SNIFFER
		if (!m_CapturingEnabled)
			return true;

		if (!m_ProtoDirPath.value().empty() && !m_ProtoIDFilePath.value().empty())
		{
			m_PacketParser.SetProtoIDPath(m_ProtoIDFilePath);
			m_PacketParser.SetProtoDir(m_ProtoDirPath);
			return true;
		}

		return false;
#endif

		return true;
	}

	void PacketSniffer::DrawMain()
	{

		//ImGui::Text("Dev: for working needs server for named pipe 'genshin_packet_pipe'.\nCheck 'packet-handler' project like example.");
		if (ConfigWidget(m_CapturingEnabled, "Enabling capturing of packet info and sending to pipe, if it exists."))
		{ 
			bool result = OnCapturingChanged();
			if (!result)
			{
				m_CapturingEnabled = false;
				ImGui::OpenPopup("Error");
			}
		}
		
		if (ImGui::BeginPopup("Error"))
		{
			ImGui::Text("Please fill 'Proto Dir Path' and 'Proto ID File Path' before enabling capture.");
			ImGui::EndPopup();
		}

#ifdef _PACKET_SNIFFER
		auto& window = sniffer::SnifferWindow::GetInstance();
		ConfigWidget(window.m_Show, "Show capturing window.");

		ConfigWidget(m_PipeEnabled, "Enable sending of packet data to pipe with name 'genshin_packet_pipe'.\n"\
			"This feature can be used with external monitoring tools.");
		//ConfigWidget(m_ManipulationEnabled, "Enabling manipulation packet feature, that allows to replace, block incoming/outcoming packets." \
		//	"\nThis feature often needs, to read-write pipe operation, so can decrease network bandwidth.");

		if (m_CapturingEnabled)
		{
			ImGui::Text("These parameters can only be changed when 'Capturing' is disabled.");
			ImGui::BeginDisabled();
		}

		ConfigWidget(m_ProtoDirPath, "Path to directory containing Genshin .proto files.");
		ConfigWidget(m_ProtoIDFilePath, "Path to JSON file containing packet id->packet name info.");

		if (m_CapturingEnabled)
			ImGui::EndDisabled();
#else
		ImGui::Text("When capture is enabled, raw packet data will be send to named pipe: 'genshin_packet_pipe'.");
		ImGui::Text("'Raw' means that you should to parse protobuf structure by yourself.");
#endif
	}
	
	void PacketSniffer::DrawExternal()
	{
#ifdef _PACKET_SNIFFER
		auto& window = sniffer::SnifferWindow::GetInstance();
		if (window.m_Show)
			window.Draw();
#endif
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
		if (!m_CapturingEnabled)
			return true;

		PacketData packetData = ParseRawPacketData((char*)packet->data, packet->dataLen);
		if (!packetData.valid)
			return true;

		packetData.ioType = type;
		packetData.blockModeEnabled = m_ManipulationEnabled;

#ifdef _PACKET_SNIFFER
		bool parsed = m_PacketParser.Parse(packetData);
		if (!parsed)
			return true;

		sniffer::SnifferWindow::GetInstance().OnPacketIO({packetData});
#endif

		sniffer::MessageManager::Send(packetData);

		bool canceled = m_ManipulationEnabled && ProcessModifiedData(packet);

#ifdef _PACKET_SNIFFER
		if (m_PacketParser.IsUnionPacket(packetData))
		{
			for (auto& nestedPacketData : m_PacketParser.ParseUnionPacket(packetData))
			{
				sniffer::SnifferWindow::GetInstance().OnPacketIO({ nestedPacketData });
				sniffer::MessageManager::Send(nestedPacketData);
			}
		}
#endif

		return !canceled;
	}

	char* PacketSniffer::EncryptXor(void* content, uint32_t length)
	{
		app::Byte__Array* byteArray = (app::Byte__Array*)new char[length + 0x20];
		byteArray->max_length = length;
		memcpy_s(byteArray->vector, length, content, length);

		app::Packet_XorEncrypt(nullptr, &byteArray, length, nullptr);

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

	int32_t PacketSniffer::KcpNative_kcp_client_send_packet_Hook(void* __this, void* kcp_client, app::KcpPacket_1* packet, MethodInfo* method)
	{
		auto& sniffer = GetInstance();
		if (!sniffer.OnPacketIO(packet, PacketIOType::Send))
			return 0;

		return CALL_ORIGIN(KcpNative_kcp_client_send_packet_Hook, __this, kcp_client, packet, method);
	}
}

