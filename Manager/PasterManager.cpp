/*****************************************************************************
FileName:   PasterManager.cpp
Creater:    Xeler
Desc:       PasterManager & Paster class code.
Version:    0.1
******************************************************************************/

#include "PasterManager.h"
#include "../Core/BallEngine.h"

BE_USE

PasterManager::PasterManager(BImage *basePic) {
    baseScreen = BPaster(basePic);
}

PasterManager::~PasterManager() {
    clear();
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
        pasters.erase(point);
    }
    return valid;
}

void PasterManager::clear() {
    pasters.clear();
}

BPaster &PasterManager::operator[](PtrNum point) {
    return getPaster(point);
}

BPaster &PasterManager::getPaster(PtrNum point) {
    bool valid = checkPasterValid(point);
    if (valid) {
        return pasters[point];
    }
    return baseScreen;
}

bool PasterManager::setPaster(PtrNum point, const BPaster &paster) {
    std::pair<PtrNum, BPaster> valuePair(point, paster);
    pasters.insert(valuePair);
    return valuePair.first;
}

bool PasterManager::checkPasterValid(PtrNum point) {
    return pasters.find(point) != pasters.end();
}

BImage PasterManager::drawScreen(unsigned short framesSpace) {
    BImage newScreen = baseScreen.getFrame();
    auto ic = pasters.begin();
    while (ic != pasters.end()) {
        newScreen.drawPic(ic->second.getFrame(), 0, 0);
        ic++;
    }
    return newScreen;
}
