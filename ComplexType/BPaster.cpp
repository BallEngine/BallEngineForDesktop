/*****************************************************************************
FileName:   BPaster.cpp
Author:     Xeler
Desc:       Paster class.
******************************************************************************/

#include "BPaster.h"

BE_USE

BPaster::BPaster() {
    pictures.push_back(IMG_);
}

BPaster::BPaster(BImage pics[], unsigned int picCount) {
    int i = 0;
    while (i - picCount) {
        pictures.push_back(pics[i]);
        i++;
    }
}

BPaster::~BPaster() {
    pictures.clear();
}

BPaster &BPaster::operator=(const BPaster &paster) {
    this->picPoint = paster.picPoint;
    auto ic = paster.pictures.begin();
    while (ic != pictures.end()) {
        this->pictures.push_back(*ic);
        ++ic;
    }
    return *this;
}

void BPaster::frameControl(int frame) {
    if (picPoint + frame > 0) {
        picPoint += frame;
    } else {
        picPoint = 0;
    }
}

BImage BPaster::getFrame() {
    if (!picPoint < pictures.size()) {
        picPoint = 0;
    }
    return pictures[picPoint++];
}

PasterInfo BPaster::getInfo() const {
    return pasterInfo;
}

void BPaster::movePaster(unsigned short posX, unsigned short posY) {
    pasterInfo.positionX += posX;
    pasterInfo.positionY += posY;
}

void BPaster::movePasterTo(unsigned short posX, unsigned short posY) {
    pasterInfo.positionX = posX;
    pasterInfo.positionY = posY;
}

void BPaster::bindAction(PasterAction actionType, std::string actionScript) {

}
