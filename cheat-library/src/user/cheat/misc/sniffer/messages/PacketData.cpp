#include <pch-il2cpp.h>
#include "PacketData.h"

void PacketData::Write(PipeTransfer* transfer)
{
	transfer->Write(blockModeEnabled);
	transfer->Write(ioType);
	transfer->Write(dataType);
	transfer->Write(valid);
	transfer->Write(parentPacketID);
	transfer->Write(messageID);
	transfer->Write(headRawData);
	transfer->Write(messageRawData);

	if (dataType == PacketDataType::Parsed)
	{
		transfer->Write(name);
		transfer->Write(headJson);
		transfer->Write(messageJson);
	}
}

void PacketData::Read(PipeTransfer* transfer)
{
	transfer->Read(blockModeEnabled);
	transfer->Read(ioType);
	transfer->Read(dataType);
	transfer->Read(valid);
	transfer->Read(parentPacketID);
	transfer->Read(messageID);
	transfer->Read(headRawData);
	transfer->Read(messageRawData);

	if (dataType == PacketDataType::Parsed)
	{
		transfer->Read(name);
		transfer->Read(headJson);
		transfer->Read(messageJson);
	}
}
