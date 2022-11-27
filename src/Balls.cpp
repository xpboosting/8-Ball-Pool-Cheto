#include "Balls.h"
#include "Memory.h"
#include "Offsets.h"
#include "globalVars.h"
#include "GameManager.h"
#include "CodeManager.h"

#ifndef DumpCode

bool Balls::initBallList(GlobalVars* globalVars, UINT32& ballList, int& ballCount)
{
    return ExecuteFunction(initBallList, globalVars, ballList, ballCount);
}

UINT32 Balls::getBall(GlobalVars* globalVars, UINT32 index, const UINT32& ballList)
{
    return ExecuteFunction(getBall, globalVars, index, ballList);
}

#else

bool Balls::initBallList(GlobalVars* globalVars, UINT32& ballList, int& ballCount)
{
    UINT32 table, balls;

    table     = GameManager::getTable(globalVars);
    balls     = globalVars->memory->read<UINT32>(table + Offsets::Balls);
    ballList  = globalVars->memory->read<UINT32>(balls + Offsets::Entry);
    ballCount = globalVars->memory->read<int>(balls + Offsets::Count);

    return true;
}

void Balls::initBallListStub() {}

UINT32 Balls::getBall(GlobalVars* globalVars, UINT32 index, const UINT32& ballList)
{
    return globalVars->memory->read<UINT32>(ballList + index * 4UL);
}

void Balls::getBallStub() {}

#endif