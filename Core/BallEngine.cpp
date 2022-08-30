/*****************************************************************************
FileName:   BallEngine.cpp
Author:     Xeler
Desc:       SDL window package class.
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

void BallEngine::initialization() {
}


void BallEngine::emitBEvent(const BEvent &event) {
    switch (event.to) {
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
