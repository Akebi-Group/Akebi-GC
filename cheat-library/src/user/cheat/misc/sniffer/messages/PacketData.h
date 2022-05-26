#pragma once
#include <cheat-base/PipeTransfer.h>
#include "MessageBase.h"

enum class PacketIOType 
{
	Receive,
	Send
};

enum class PacketDataType
{
	Raw,
	Parsed
};

class PacketData : public MessageBase
{
public:
	using MessageBase::MessageBase;
	
	bool blockModeEnabled;

	PacketIOType ioType;
	PacketDataType dataType;

	bool valid;
	
	uint64_t parentPacketID;

	int16_t messageID;
	std::vector<byte> headRawData;
	std::vector<byte> messageRawData;

	std::string name;
	std::string headJson;
	std::string messageJson;
	
	// Inherited via PipeSerializedObject
	virtual void Write(PipeTransfer* transfer) override;
	virtual void Read(PipeTransfer* transfer) override;
};