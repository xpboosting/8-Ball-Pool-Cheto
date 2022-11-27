#include <iostream>
#include "GlobalVars.h"
#include "Memory.h"
#include "GUI.h"
#include "Menu.h"
#include "GameManager.h"
#include "Prediction.h"

#include <thread>
#include "Utils.h"
#include "MenuManager.h"
#include "UserInfo.h"

#include "discord.h"
#include "config.h"
#include "skCrypt.h"

bool gUnload;

void autoThread()
{
    int automaticAction;

    while (gUnload == false) {
        /*if (UserInfo::getWinStreak() >= gGlobalVars->features.maxWinStreak) {
            automaticAction = 2;
            goto Label;
        }
        else
        {
            automaticAction = gGlobalVars->features.automatic;
        }*/

        if (gGlobalVars->features.automatic) {
        Label:
            gPrediction->initAutoAim();
        }

        Sleep(10);
    }
}

#ifdef _WINDLL
DWORD WINAPI start(PVOID dll)
#else
int main()
#endif
{
    bool        initResult;
    INT         result = EXIT_SUCCESS;
    HINSTANCE   instance;
    HANDLE      gMutex, process;
    std::thread newThread;

    gMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, skCrypt("8BPH"));
    if (gMutex) {
        fatal(skCrypt("application is already running"), skCrypt("unknown"), 0);
        result = EXIT_FAILURE;
        goto exitLabel;
    }
    else
    {
        gMutex = CreateMutex(0, 0, skCrypt("8BPH"));
    }

    //launch8BPGame();
    instance = GetModuleHandle(NULL);
    srand(static_cast<UINT32>(time(nullptr)));
    notifyUser(skCrypt("Waiting 8 Ball Pool process..."));
Label:
    Sleep(500);
    process = Memory::getProcessHandle();
    if (process != nullptr) {
        initResult = gGlobalVars->init();
        if (initResult == false) {
            CloseHandle(process);
            goto Label;
        }

        Config::load();
        Discord::init();
        Discord::update();
        gPrediction->onInitialization();
        notifyUser(skCrypt("8 Ball Pool process found."));
        if (Menu::init(instance)) {
            gUnload = false;
            newThread = std::thread(autoThread); // init auto aim/play thread
            GUI::init();
            Menu::runLoop();
            Menu::end(instance);
            gUnload = true;
            newThread.join(); // wait for our thread to finish.
        }
        else
        {
            result = EXIT_FAILURE;
        }

        CloseHandle(process);
    }
    else
    {
        goto Label;
    }

    if (gMutex)
        ReleaseMutex(gMutex);

exitLabel:
#ifdef _WINDLL
    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(dll), result);
#endif

    return result;
}

#ifdef _WINDLL

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, start, hinstDLL, 0, nullptr);
        break;
    }

    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

#endif