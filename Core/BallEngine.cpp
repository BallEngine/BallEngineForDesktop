/*****************************************************************************
FileName:   BallEngine.cpp
Creater:    Xeler
Desc:       Engine Code.
******************************************************************************/

#include "BallEngine.h"
#include "../Manager/PasterManager.h"
#include "../Manager/ScriptManager.h"

BE_USE

BallEngine::BallEngine() {
    audioManager = new AudioManager();
    pasterManager = new PasterManager();
    scriptManager = new ScriptManager();

    systemInterface = nullptr;
}

void BallEngine::initialization(SystemInterface &interface) {
    systemInterface = &interface;
}


void BallEngine::emitBEvent(const BEvent &event) {
    switch (event.to) {
        case Interface:
            systemInterface->processEvent(event);
            break;
        case PasterSys:
            pasterManager->processEvent(event);
            break;
        case ScriptSys:
        case Other:
            scriptManager->processEvent(event);
            break;
        default:
            break;
    }
}

AudioManager &BallEngine::getAudioManager() {
    return *audioManager;
}

PasterManager &BallEngine::getPasterManager() {
    return *pasterManager;
}

ScriptManager &BallEngine::getScriptManager() {
    return *scriptManager;
}

SystemInterface &BallEngine::getSystemInterface() {
    return *systemInterface;
}
