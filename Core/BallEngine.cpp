/*****************************************************************************
FileName:   BallEngine.cpp
Author:     Xeler
Desc:       SDL window package class.
******************************************************************************/

#include "BallEngine.h"

BE_USE

BallEngine::BallEngine() : width(0), height(0) {
    audioManager = new AudioManager();
    scriptManager = new ScriptManager();
    pasterManager = new PasterManager(width, height);
}

void BallEngine::init(const std::string &setupFile) {
    SDL_Init(SDL_INIT_EVERYTHING);

    BConfig setup(setupFile);

    std::string title = setup.getValue("window.title");
    int width = std::stoi(setup.getValue("window.width"));
    int height = std::stoi(setup.getValue("window.height"));

    m_window = SDL_CreateWindow(title.c_str(),
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               width, height,
                               SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}



void BallEngine::emitBEvent(const BEvent &event) const {
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

AudioManager &BallEngine::getAudioManager() const {
    return *audioManager;
}

PasterManager &BallEngine::getPasterManager() const {
    return *pasterManager;
}

ScriptManager &BallEngine::getScriptManager() const {
    return *scriptManager;
}
