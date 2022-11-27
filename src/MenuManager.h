#pragma once

#include <basetsd.h>

#ifdef DumpCode
#include "const.h"
#endif

struct GlobalVars;

struct MenuManager
{
#ifndef DumpCode
	static INT32 menuState(GlobalVars* globalVars);
#else
	SEGMENT(".text$menuState")     static INT32 menuState(GlobalVars* globalVars);
	SEGMENT(".text$menuStateStub") static void  menuStateStub();
#endif

	static bool isInGame(GlobalVars* globalVars);

private:
	struct Offsets
	{
		static constexpr UINT32 StateManager = 0x284UL;
	};
};
