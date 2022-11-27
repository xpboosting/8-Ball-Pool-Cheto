#include "UserSettings.h"
#include "GlobalVars.h"
#include "Offsets.h"
#include "Memory.h"

#include "CodeManager.h"

#ifndef DumpCode

void UserSettings::setWideGuideLine(GlobalVars* globalVars, unsigned char enable)
{
	ExecuteFunction(setWideGuideLine, globalVars, enable);
}

#else

void UserSettings::setWideGuideLine(GlobalVars* globalVars, unsigned char enable)
{
	globalVars->memory->write(globalVars->sharedUserSettings + 0xE, enable);
}

void UserSettings::setWideGuideLineStub() {}

#endif