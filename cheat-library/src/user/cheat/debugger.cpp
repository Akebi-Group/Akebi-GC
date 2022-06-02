#include <pch-il2cpp.h>

void DebuggerBypassPre()
{
#ifdef _DEBUG
	LOG_INFO("You have no implementation for anti-debugger bypass.\n\tSo if you try to attach VS debugger to process - game will crash.");
#endif

	// Sry, implementation is private for now
}

void DebuggerBypassPost()
{
	// Sry, implementation is privite for now
}