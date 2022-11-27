#pragma once

#include <basetsd.h>

#ifdef DumpCode
#include "const.h"
#endif

struct GlobalVars;

struct UserInfo
{
#ifndef DumpCode
	static int getWinStreak(GlobalVars* globalVars);
#else
	SEGMENT(".text$getWinStreak")     static int  getWinStreak(GlobalVars* globalVars);
	SEGMENT(".text$getWinStreakStub") static void getWinStreakStub();
#endif
private:
	struct Offsets
	{
		static constexpr UINT32 winStreak = 0x158UL;
	};
};