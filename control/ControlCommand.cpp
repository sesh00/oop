#include "ControlCommand.h"
#include <windows.h>

HANDLE hStdin;
DWORD fdwSaveOldMode;

ControlCommand::ControlCommand() { actionIndex = 0;}

int ControlCommand::getAction(){
    return this->actionIndex;
}

bool ControlCommand::setAction() {
    int counter = 0;
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;

    if (hStdin == INVALID_HANDLE_VALUE){
        InitMessage(ERRORMESSAGE, "Get std handle error");
        return false;
    }

    if (!GetConsoleMode(hStdin, &fdwSaveOldMode)){
        InitMessage(ERRORMESSAGE, "Get console mode error");
        return false;
    }

    if (!SetConsoleMode(hStdin, fdwMode)){
        InitMessage(ERRORMESSAGE, "Set console mode error");
        return false;
    }

    while (counter++ <= 10000000)
    {
        if (!ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead)){
            InitMessage(ERRORMESSAGE, "Read console input error");
            return false;
        }
        for (i = 0; i < cNumRead; i++)
        {
            if (irInBuf[i].EventType == KEY_EVENT)
            {
                if (irInBuf[i].Event.KeyEvent.bKeyDown){
                    this->actionIndex = irInBuf[i].Event.KeyEvent.wVirtualKeyCode;
                    return true;
                }
            }
        }
    }
    SetConsoleMode(hStdin, fdwSaveOldMode);
    InitMessage(GAMEMESSAGE, "Game was exited");
    return false;
}