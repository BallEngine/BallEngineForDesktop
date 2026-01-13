/*****************************************************************************
FileName:   PasterManager.cpp
Author:     Xeler
Desc:       PasterManager & Paster class code.
******************************************************************************/

#include "PasterManager.h"
#include "../Core/BallEngine.h"

BE_USE

PasterManager::PasterManager() : m_baseScreen() {
}

PasterManager::~PasterManager() {
    this->clear();
}

void PasterManager::init(const char* title, int width, int height) {
    m_baseScreen = *SDL_CreateRGBSurface(0, width, height, 8, 0, 0, 0, 0);
    m_window = SDL_CreateWindow(title,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                width, height,
                                SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void PasterManager::processEvent(BEvent event) {
}

PtrNum PasterManager::addPaster(const BPaster &paster) {
    static PtrNum nextId = 1;

    PtrNum point = nextId;
    while (m_pasterMap.find(point) != m_pasterMap.end()) {
        point++;
    }

    nextId = point + 1;

    setPaster(point, paster);
    return point;
}


void PasterManager::removePaster(PtrNum point) {
    m_pasterMap.erase(point);
}

void PasterManager::clear() {
    m_pasterMap.clear();
}

BPaster *PasterManager::operator[](PtrNum point) {
    return getPaster(point);
}

BPaster *PasterManager::getPaster(PtrNum point) {
    const auto it = m_pasterMap.find(point);
    if (it != m_pasterMap.end()) {
        return &it->second;
    }

    return nullptr;
}

bool PasterManager::setPaster(PtrNum point, const BPaster &paster) {
    std::pair<PtrNum, BPaster> valuePair(point, paster);
    m_pasterMap.insert(valuePair);
    return valuePair.first;
}

SDL_Texture *PasterManager::drawScreen(unsigned short framesSpace) {
    SDL_Texture *targetTexture = SDL_CreateTexture(
        m_renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        m_baseScreen.w,
        m_baseScreen.h
    );

    SDL_SetRenderTarget(m_renderer, targetTexture);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    for (auto &pair: m_pasterMap) {
        SDL_Texture *frameTexture = pair.second.getFrame();
        PosPair pos = pair.second.getPos();

        SDL_Rect destRect = {pos.x, pos.y, 0, 0};

        SDL_RenderCopy(m_renderer, frameTexture, nullptr, &destRect);
    }

    SDL_SetRenderTarget(m_renderer, nullptr);

    return targetTexture;
}
