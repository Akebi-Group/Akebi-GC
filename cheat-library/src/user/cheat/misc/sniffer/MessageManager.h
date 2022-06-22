#pragma once
#include "messages/MessageHeader.h"
#include "messages/ModifyData.h"
#include "messages/PacketData.h"

#include <vector>

namespace sniffer
{
	enum MessageIDs : uint32_t
	{
		NONE = 0,
		PACKET_DATA = 1,
		MODIFY_DATA = 2
	};

	class MessageManager
	{
	public:
		template<class T>
		using CallbackFunction = void(*)(const T& packetData);

		template<class T>
		inline static void AddHandler(CallbackFunction<T> callback)
		{
			s_Handlers.push_back(callback);
		}

		template<class TMessage>
		inline static TMessage CreateMessage(uint32_t reqID = 0)
		{
			static_assert(std::is_base_of<MessageBase, TMessage>::value, "Should be derived of MessageBase.");

			return TMessage(MessageHeader{ GetMessageIDByType<TMessage>(), reqID });
		}

		template<class TMessage>
		inline static std::optional<TMessage> WaitFor()
		{
			static_assert(std::is_base_of<MessageBase, TMessage>::value, "Should be derived of MessageBase.");

			if (!IsConnected())
				return {};

			while (true)
			{
				auto messagePtr = ReceiveMessage();
				if (messagePtr == nullptr)
					return {};

				if (GetMessageIDByType<TMessage>() != messagePtr->messageID())
				{
					delete messagePtr;
					continue;
				}

				// Copying message
				TMessage message = *reinterpret_cast<TMessage*>(messagePtr);
				delete messagePtr;

				return message;
			}
		}

		static void Send(MessageBase& data);

		static MessageBase* ReceiveMessage();

		static void ProcessMessage();

		static void SetConnectionDelay(uint32_t delay);

		static uint32_t GetConnectionDelay();

		static bool IsConnected();

		static void Connect(const std::string& pipeName);

		static void Disconnect();

	private:

		inline static PipeTransfer* s_Pipe = nullptr;

		inline static uint32_t s_ConnectionDelay = 5;
		inline static std::time_t s_NextTimeToConnect = 0;

		template<class T>
		static std::vector<CallbackFunction<T>> s_Handlers;

		static bool TryConnectToPipe()
		{
			if (s_Pipe == nullptr)
				return false;

			std::time_t currTime = std::time(0);
			if (s_NextTimeToConnect > currTime)
				return false;

			bool result = s_Pipe->Connect();
			if (result)
				LOG_INFO("Connected to pipe successfully.");
			else
				s_NextTimeToConnect = currTime + 5; // delay in 5 sec
			return result;
		}

		template<class TMessage> static uint32_t GetMessageIDByType();
		template<> static uint32_t GetMessageIDByType<PacketData>() { return MessageIDs::PACKET_DATA; }
		template<> static uint32_t GetMessageIDByType<ModifyData>() { return MessageIDs::MODIFY_DATA; }

		template<class T>
		static void CallHandlers(const T& message)
		{
			for (auto& handler : s_Handlers<T>)
				handler(message);
		}
	};
}