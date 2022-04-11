#include "BPaster.h"

BE_USE

BPaster::BPaster() {
    pictures.push_back(*BImage::getBlankImage(ImageType::None));
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
    return pictures[picPoint++];
}
