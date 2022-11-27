#pragma once

struct GlobalVars;

#ifdef DumpCode
#include "const.h"
#endif

struct UserSettings
{
#ifndef DumpCode
	static void setWideGuideLine(GlobalVars* globalVars, unsigned char enable);
#else
	SEGMENT(".text$setWideGuideLine")     static void setWideGuideLine(GlobalVars* globalVars, unsigned char enable);
	SEGMENT(".text$setWideGuideLineStub") static void setWideGuideLineStub();
#endif
};

