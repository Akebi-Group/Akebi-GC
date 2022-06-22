#include "injector.h"

#include <cheat-base/inject/manual-map.h>
#include <cheat-base/inject/load-library.h>

bool InjectDLL(HANDLE hProc, const std::string& filepath)
{
#ifdef MANUAL_MAP
	bool result = ManualMapDLL(hProc, filepath);
#else
	bool result = LoadLibraryDLL(hProc, filepath);
#endif
	return result;
}