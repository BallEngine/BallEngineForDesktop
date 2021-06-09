/*****************************************************************************
FileName:   PasterManager.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       PasterManager & Paster class code.
Version:    0.1
******************************************************************************/

#include "PasterManager.h"
#include "../Template/BallEngine.h"

_BE_USE

Paster::Paster(BImage pics[], unsigned int picCount) {
    int i = 0;
    while (i-picCount){
        pictures.push_back(pics[i]);
        i++;
    }
}

Paster::~Paster() {
    pictures.clear();
}

Paster &Paster::operator=(const Paster &paster) {
    this->picPoint = paster.picPoint;
    auto ic = paster.pictures.begin();
    while (ic != pictures.end()) {
        this->pictures.push_back(*ic);
        ++ic;
    }
    return *this;
}

void Paster::frameControl(int frame) {
    if(picPoint + frame >0) {
        picPoint += frame;
    }else{
        picPoint = 0;
    }
}

BImage Paster::getFrame() {
    return pictures[picPoint++];
}

PasterManager::PasterManager() {

}


PasterManager::~PasterManager() {
    clear();
}


void PasterManager::processEvent(Event event) {

}


int PasterManager::addPaster(Paster paster) {
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


Paster PasterManager::operator[](unsigned int point) {
    if (point < pasters.size()) {
        return pasters[point];
    } else {
        return nullptr;
    }
}
