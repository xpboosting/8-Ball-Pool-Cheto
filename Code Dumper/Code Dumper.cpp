#include <iostream>
#include <Windows.h>
#include <fstream>

#pragma optimize("", off)
#pragma runtime_checks("", off)
#pragma check_stack(off)

#include <CodeManager.h>
#include <GlobalVars.h>
#include <UserInfo.h>
#include <UserSettings.h>
#include <AdsManager.h>
#include <GenericData.h>
#include <MenuManager.h>
#include <Ball.h>
#include <Balls.h>
#include <const.h>

#define DumpFunction(_class, _func) \
[]() \
{ \
    int           i; \
    int           functionSize; \
    std::ofstream outputFile; \
    std::string   filename; \
    char          buffer[4096]; \
    PVOID         start = _class::_func; \
    PVOID         end = _class::_func##Stub; \
    \
    functionSize = reinterpret_cast<SIZE_T>(end) - reinterpret_cast<SIZE_T>(start); \
    memcpy(buffer, start, functionSize); \
    for (i = 0; i < functionSize; i++) { \
        buffer[i] ^= rawDataEncryptionKey[i % rawDataEncryptionKeySize]; \
    } \
 \
    filename = "rawData\\"; \
    filename += EVText(#_func); \
    outputFile = std::ofstream(filename, std::ios::binary); \
    outputFile.write(buffer, functionSize); \
    outputFile.close(); \
}();

int main()
{
    CreateDirectory("rawData", nullptr);

    // user info
    DumpFunction(UserInfo, getWinStreak);

    // user settings
    DumpFunction(UserSettings, setWideGuideLine);

    // Ads Manager
    DumpFunction(AdsManager, disableAdBreakScreen);

    // Ball
    DumpFunction(Ball, getPosition);
    DumpFunction(Ball, classification);
    DumpFunction(Ball, getState);

    // Balls
    DumpFunction(Balls, initBallList);
    DumpFunction(Balls, getBall);

    // Balls
    DumpFunction(Balls, initBallList);
    DumpFunction(Balls, getBall);

    // Visual Guide
    DumpFunction(VisualGuide, getAimAngle);
    DumpFunction(VisualGuide, getPlayerTimer);
    DumpFunction(VisualGuide, setAimAngle);
    DumpFunction(VisualGuide, initVisualGuide);

    // Menu Manager
    DumpFunction(MenuManager, menuState);

    printf("Done!\n");
    std::cin.get();

    return EXIT_SUCCESS;
}

#pragma runtime_checks("", restore)
