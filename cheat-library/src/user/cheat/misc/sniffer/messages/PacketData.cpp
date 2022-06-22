#include <pch-il2cpp.h>
#include "PacketData.h"

void PacketData::Write(PipeTransfer* transfer)
{
	transfer->Write(blockModeEnabled);
	transfer->Write(ioType);
	transfer->Write(messageID);
	transfer->Write(headRawData);
	transfer->Write(messageRawData);
}

void PacketData::Read(PipeTransfer* transfer)
{
	transfer->Read(blockModeEnabled);
	transfer->Read(ioType);
	transfer->Read(messageID);
	transfer->Read(headRawData);
	transfer->Read(messageRawData);
}
