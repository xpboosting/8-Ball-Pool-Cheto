#include "Ball.h"
#include "Memory.h"
#include "Offsets.h"
#include "GlobalVars.h"
#include "CodeManager.h"

#ifndef DumpCode

Vector2D Ball::getPosition(GlobalVars* globalVars, UINT32 object)
{
    return ExecuteFunction(getPosition, globalVars, object);
}

int Ball::classification(GlobalVars* globalVars, UINT32 object)
{
    return ExecuteFunction(classification, globalVars, object);
}

int Ball::getState(GlobalVars* globalVars, UINT32 object)
{
    return ExecuteFunction(getState, globalVars, object);
}


#else

Vector2D Ball::getPosition(GlobalVars* globalVars, UINT32 object)
{
    return globalVars->memory->read<Vector2D>(object + Offsets::Position);
}

void Ball::getPositionStub() {}

int Ball::classification(GlobalVars* globalVars, UINT32 object)
{
    return globalVars->memory->read<int>(object + Offsets::classification);
}

void Ball::classificationStub() {}

int Ball::getState(GlobalVars* globalVars, UINT32 object)
{
    return globalVars->memory->read<int>(object + Offsets::State);
}

void Ball::getStateStub() {}

#endif

bool Ball::isOnTable(GlobalVars* globalVars, UINT32 object)
{
    int state = getState(globalVars, object);

    return ((state == 1) || (state == 2));
}