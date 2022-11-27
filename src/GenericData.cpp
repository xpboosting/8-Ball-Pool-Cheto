#include "GenericData.h"
#include "GlobalVars.h"
#include "Memory.h"

#include "Offsets.h"

#ifndef DumpCode

vec_t VisualGuide::getAimAngle(GlobalVars* globalVars, UINT32 visualGuide)
{
    return globalVars->memory->read<vec_t>(visualGuide + Offsets::AimAngle);
}

float VisualGuide::getPlayerTimer(GlobalVars* globalVars, UINT32 visualGuide)
{
    return globalVars->memory->read<float>(visualGuide + Offsets::Timer);
}

void VisualGuide::setAimAngle(GlobalVars* globalVars, UINT32 visualGuide, const vec_t& angle)
{
    globalVars->memory->write(visualGuide + Offsets::AimAngle, angle);
}

bool VisualGuide::initVisualGuide(GlobalVars* globalVars, UINT32* out)
{
    UINT32 genericData = globalVars->memory->read<UINT32>(globalVars->sharedGameManager + Offsets::VisualCue);

    *out = globalVars->memory->read<UINT32>(genericData + Offsets::VisualGuide);
    if (*out == NULL)
        return false;

    return true;
}

#else

vec_t VisualGuide::getAimAngle(GlobalVars* globalVars, UINT32 visualGuide)
{
    return globalVars->memory->read<vec_t>(visualGuide + Offsets::AimAngle);
}

void VisualGuide::getAimAngleStub() {}

float VisualGuide::getPlayerTimer(GlobalVars* globalVars, UINT32 visualGuide)
{
    return globalVars->memory->read<float>(visualGuide + Offsets::Timer);
}

void VisualGuide::getPlayerTimerStub() {}

void VisualGuide::setAimAngle(GlobalVars* globalVars, UINT32 visualGuide, const vec_t& angle)
{
    globalVars->memory->write(visualGuide + Offsets::AimAngle, angle);
}

void VisualGuide::setAimAngleStub() {}

bool VisualGuide::initVisualGuide(GlobalVars* globalVars, UINT32* out)
{
    UINT32 genericData = globalVars->memory->read<UINT32>(globalVars->sharedGameManager + Offsets::VisualCue);

    *out = globalVars->memory->read<UINT32>(genericData + Offsets::VisualGuide);
    if (*out == NULL)
        return false;

    return true;
}

void VisualGuide::initVisualGuideStub() {}

#endif