#pragma once

struct Ball;
struct GlobalVars;

#include <basetsd.h>

#ifdef DumpCode
#include "const.h"
#endif

struct Balls
{
#ifndef DumpCode
	static bool   initBallList(GlobalVars* globalVars, UINT32& ballList, int& ballCount);
	static UINT32 getBall(GlobalVars* globalVars, UINT32 index, const UINT32& ballList);

#else
	SEGMENT(".text$initBallList")     static bool   initBallList(GlobalVars* globalVars, UINT32& ballList, int& ballCount);
	SEGMENT(".text$initBallListStub") static void   initBallListStub();
	SEGMENT(".text$getBall")          static UINT32 getBall(GlobalVars* globalVars, UINT32 index, const UINT32& ballList);
	SEGMENT(".text$getBallStub")      static void   getBallStub();
#endif

	inline UINT32 getCueBall(GlobalVars* globalVars, const UINT32& ballList) { return getBall(globalVars, 0UL, ballList); }

private:
	struct Offsets
	{
		static constexpr UINT32 Count = 0x4UL;
		static constexpr UINT32 Entry = 0xCUL;
		static constexpr UINT32 Balls = 0x2F0UL;
	};
};
