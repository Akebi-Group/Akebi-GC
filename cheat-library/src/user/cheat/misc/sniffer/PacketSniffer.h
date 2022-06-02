// ReSharper disable All
#pragma once

#include <filesystem>

#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <cheat-base/PipeTransfer.h>
#include "messages/PacketData.h"
#include "messages/ModifyData.h"

#include "MessageManager.h"

#ifdef _PACKET_SNIFFER
#include "PacketParser.h"
#include "PacketInfo.h"
#endif

namespace cheat::feature 
{
	
	class PacketSniffer : public Feature
    {
	public:
		config::Field<bool> m_CapturingEnabled;
		config::Field<bool> m_ManipulationEnabled;
		config::Field<bool> m_PipeEnabled;

#ifdef _PACKET_SNIFFER
		config::Field<std::string> m_ProtoDirPath;
		config::Field<std::string> m_ProtoIDFilePath;
#endif

		static PacketSniffer& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		void DrawExternal() final;

	private:
#ifdef _PACKET_SNIFFER
		sniffer::PacketParser m_PacketParser;
#endif
		PacketSniffer();
		PacketData ParseRawPacketData(char* encryptedData, uint32_t length);
		bool OnCapturingChanged();

		static char* EncryptXor(void* content, uint32_t length);
		static bool KcpClient_TryDequeueEvent_Hook(void* __this, app::ClientKcpEvent* evt, MethodInfo* method);
		static int32_t KcpNative_kcp_client_send_packet_Hook(void* kcp_client, app::KcpPacket_1* packet, MethodInfo* method);
		
		bool OnPacketIO(app::KcpPacket_1* packet, PacketIOType type);
	};
}

