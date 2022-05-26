#include "pch-il2cpp.h"
#include "MessageManager.h"

namespace sniffer
{

	void MessageManager::Send(MessageBase& data)
	{
		if (!IsConnected())
			return;

		s_Pipe->WriteObject(data.header());
		s_Pipe->WriteObject(data);
	}

	MessageBase* MessageManager::ReceiveMessage()
	{
		if (!IsConnected())
			return nullptr;

		MessageHeader header;
		s_Pipe->ReadObject(header);

		MessageIDs messageID = static_cast<MessageIDs>(header.messageID());

#define MESSAGE_CASE(mid, type)\
					case mid:                                       \
					{										        \
						auto data = new type(header);	            \
						s_Pipe->ReadObject(*data);			        \
						CallHandlers(*data);					    \
						return reinterpret_cast<MessageBase*>(data);\
					}										  

		switch (messageID)
		{
			MESSAGE_CASE(MessageIDs::PACKET_DATA, PacketData);
			MESSAGE_CASE(MessageIDs::MODIFY_DATA, ModifyData);
		default:
			break;
		}

		return nullptr;
	}

	void MessageManager::ProcessMessage()
	{
		delete ReceiveMessage();
	}

	bool MessageManager::IsConnected()
	{
		if (s_Pipe == nullptr)
			return false;

		return s_Pipe->IsPipeOpened() || TryConnectToPipe();
	}

	void MessageManager::SetConnectionDelay(uint32_t delay)
	{
		s_ConnectionDelay = delay;
	}

	uint32_t MessageManager::GetConnectionDelay()
	{
		return s_ConnectionDelay;
	}

	void MessageManager::Connect(const std::string& pipeName)
	{
		if (s_Pipe != nullptr)
			delete s_Pipe;

		s_Pipe = new PipeTransfer(pipeName);
		TryConnectToPipe();
	}

	void MessageManager::Disconnect()
	{
		if (s_Pipe == nullptr)
			return;

		delete s_Pipe;
	}
}