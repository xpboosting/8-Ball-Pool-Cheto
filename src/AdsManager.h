#pragma once

#include <basetsd.h>

#ifdef DumpCode
#include "const.h"
#endif

struct GlobalVars;

struct AdsManager
{
#ifndef DumpCode
	static void disableAdBreakScreen(GlobalVars* globalVars);
#else
	SEGMENT(".text$disableAdBreakScreen")     static void disableAdBreakScreen(GlobalVars* globalVars);
	SEGMENT(".text$disableAdBreakScreenStub") static void disableAdBreakScreenStub();
#endif
private:
	struct Offsets
	{
		static constexpr SIZE_T SharedAdsManager        = 0x35DB9D4UL;
		static constexpr SIZE_T InterstitialsController = 0x84UL;
	};
};