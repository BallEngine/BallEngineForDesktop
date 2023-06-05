/*****************************************************************************
FileName:   PasterManager.cpp
Author:     Xeler
Desc:       PasterManager & Paster class code.
******************************************************************************/

#include "PasterManager.h"
#include "../Core/BallEngine.h"

BE_USE

PasterManager::PasterManager(unsigned int width, unsigned int height) {
    baseScreen = *(SDL_CreateRGBSurface(0, width, height, 8, 0, 0, 0, 0));
}

PasterManager::~PasterManager() {

    this->clear();
}

void PasterManager::processEvent(BEvent event) {

}

PtrNum PasterManager::addPaster(const BPaster &paster) {
    PtrNum point = (PtrNum) (&paster);
    bool valid = checkPasterValid(point);
    while (valid) {
        point++;
        valid = checkPasterValid(point);
    }
    setPaster(point, paster);
    return point;
}

bool PasterManager::removePaster(PtrNum point) {
    bool valid = checkPasterValid(point);
    if (valid) {
        pasterMap.erase(point);
    }
    return valid;
}

void PasterManager::clear() {
    pasterMap.clear();
}

BPaster &PasterManager::operator[](PtrNum point) {
    return getPaster(point);
}

BPaster &PasterManager::getPaster(PtrNum point) {
    bool valid = checkPasterValid(point);
    if (valid) {
        return pasterMap[point];
    }
    return baseScreen;
}

bool PasterManager::setPaster(PtrNum point, const BPaster &paster) {
    std::pair<PtrNum, BPaster> valuePair(point, paster);
    pasterMap.insert(valuePair);
    return valuePair.first;
}

bool PasterManager::checkPasterValid(PtrNum point) {
    return pasterMap.find(point) != pasterMap.end();
}

SDL_Surface PasterManager::drawScreen(unsigned short framesSpace) {
    SDL_Surface newScreen = baseScreen;
    auto ic = pasterMap.begin();
    while (ic != pasterMap.end()) {

        newScreen.draw(ic->second.getFrame(), ic->second.getPos(), 0);
        ic++;
    }
    return newScreen;
}
