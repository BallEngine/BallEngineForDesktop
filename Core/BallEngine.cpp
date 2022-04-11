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
}

void BallEngine::emitBEvent(const BEvent &event) {
    BallEngine &instance = BallEngine::instantiation();
    switch (event.to) {
        case Interface:
            instance.systemInterface->processEvent(event);
            break;
        case PasterSys:
            instance.pasterManager->processEvent(event);
            break;
        case ScriptSys:
        case Other:
            instance.scriptManager->processEvent(event);
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


