#include <Windows.h>
#include <stdio.h>
//#include <direct.h>
//#include <io.h>

#include "MemoryMgr.h"
#include "update.h"
 
 
void init(HINSTANCE hInst)
{
 	updatemod();
}
 
BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		//init_dsound(hInst);
		// //debug
		//DisableThreadLibraryCalls(hInst);
		//if (AllocConsole()) {
		//    freopen("CONOUT$", "w", stdout);
		//    SetConsoleTitle("debug spy");
		//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		//}
		init(hInst);

	}

	if (reason == DLL_PROCESS_DETACH)
	{
		//FreeLibrary(dsound.dll);
 
	}

	return TRUE;
}
