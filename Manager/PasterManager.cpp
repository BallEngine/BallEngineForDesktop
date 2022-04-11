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
    //TODO
}

int PasterManager::addPaster(BPaster paster) {
    pasters.push_back(paster);
    pastersID.push_back(pasters.size() + 1);
    return pastersID[pastersID.size() - 1];
}

bool PasterManager::removePaster(unsigned int point) {
    auto ic = pasters.begin();
    auto ic2 = pastersID.begin();
    while (--point && ic != pasters.end()) {
        ++ic;
        ++ic2;
    }
    if (ic != pasters.end()) {
        pasters.erase(ic);
        pastersID.erase(ic2);
        return true;
    } else {
        return false;
    }
}

void PasterManager::clear() {
    pasters.clear();
    pastersID.clear();
}

bool PasterManager::changePaster(unsigned int point, BPaster paster) {
    //TODO
    return false;
}

BPaster &PasterManager::operator[](unsigned int point) {
    if (point < pasters.size()) {
        return pasters[point];
    } else {
        return baseScreen;
    }
}
