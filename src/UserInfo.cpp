#include "UserInfo.h"

#include "Memory.h"
#include "GlobalVars.h"
#include "CodeManager.h"

#ifndef DumpCode

int UserInfo::getWinStreak(GlobalVars* globalVars)
{
	return ExecuteFunction(getWinStreak, globalVars);
}

#else

int UserInfo::getWinStreak(GlobalVars* globalVars)
{
	return globalVars->memory->read<int>(globalVars->sharedUserInfo + Offsets::winStreak);
}

void UserInfo::getWinStreakStub() {}

#endif