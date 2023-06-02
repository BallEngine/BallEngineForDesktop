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

void BallEngine::initialization(std::string setupFile) {

    // Init
    SDL_Init(SDL_INIT_EVERYTHING);

    // Load Settings
    Help

    SDL_CreateWindow("",);
}


void BallEngine::emitBEvent(const BEvent &event) {
    switch (event.to) {
        case AudioSys:
            audioManager->processEvent(event);
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
