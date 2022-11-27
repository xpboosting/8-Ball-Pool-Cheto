#pragma once

#include "const.h"
#include <basetsd.h>

#ifdef DumpCode
#include "const.h"
#endif

struct GlobalVars;

struct VisualGuide
{
#ifndef DumpCode
	static vec_t getAimAngle(GlobalVars* globalVars, UINT32 visualGuide);
	static float getPlayerTimer(GlobalVars* globalVars, UINT32 visualGuide);
	static void  setAimAngle(GlobalVars* globalVars, UINT32 visualGuide, const vec_t& angle);
	static bool  initVisualGuide(GlobalVars* globalVars, UINT32* out);

#else
	SEGMENT(".text$getAimAngle")         static vec_t getAimAngle(GlobalVars* globalVars, UINT32 visualGuide);
	SEGMENT(".text$getAimAngleStub")     static void  getAimAngleStub();
	SEGMENT(".text$getPlayerTimer")      static float getPlayerTimer(GlobalVars* globalVars, UINT32 visualGuide);
	SEGMENT(".text$getPlayerTimerStub")  static void  getPlayerTimerStub();
	SEGMENT(".text$setAimAngle")         static void  setAimAngle(GlobalVars* globalVars, UINT32 visualGuide, const vec_t& angle);
	SEGMENT(".text$setAimAngleStub")     static void  setAimAngleStub();
	SEGMENT(".text$initVisualGuide")     static bool  initVisualGuide(GlobalVars* globalVars, UINT32* out);
	SEGMENT(".text$initVisualGuideStub") static void  initVisualGuideStub();
#endif

private:
	struct Offsets
	{
		static constexpr UINT32 AimAngle    = 0x18UL;
		static constexpr UINT32 Timer       = 0x28UL;
		static constexpr UINT32 VisualGuide = 0x27CUL;
		static constexpr UINT32 VisualCue   = 0x2D8UL;
	};
};

