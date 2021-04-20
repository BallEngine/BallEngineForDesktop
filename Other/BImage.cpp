/*****************************************************************************
FileName:   BImage.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "BImage.h"

using namespace be;

BImage::BImage() {
    type = NONE;
    imageLength = 0;
    width = 0;
    height = 0;
    picData = nullptr;
    picHeadLength=0;
    pixelLength = 0;
}

BImage::BImage(BString imagePath) {
    std::ifstream imageFile = std::ifstream(imagePath.toChar(), std::ios::in | std::ios::binary);
    imageFile.seekg(std::ios::end);
    imageLength = 1 + imageFile.tellg();
    picData = new byte[imageLength];
    imageFile.read((char *) picData, imageLength);
    imageFile.close();
}

BImage::BImage(BImage bImage, uint startX, uint startY, uint endX, uint endY) {

}

BImage::BImage(const BImage &bImage) {
    type = bImage.type;
    imageLength = bImage.imageLength;
    picHeadLength = bImage.picHeadLength;
    pixelLength = bImage.pixelLength;
    width = bImage.width;
    height = bImage.height;
    while (imageLength--) {
        picData[imageLength] = bImage.picData[imageLength];
    }
    imageLength = bImage.imageLength;
}

BImage &BImage::operator=(const BImage &bImage) {
    type = bImage.type;
    imageLength = bImage.imageLength;
    width = bImage.width;
    height = bImage.height;
    while (imageLength--) {
        picData[imageLength] = bImage.picData[imageLength];
    }
    imageLength = bImage.imageLength;
    return *this;
}

BImage::~BImage() {
    delete[] picData;
}

void BImage::drawLine(uint startX, uint startY, uint endX, uint endY, Paint paint) {

}

void BImage::drawArc(uint circleX, uint circleY, uint radius, uint startAngle, uint endAngle, Paint paint) {

}

void BImage::drawArc(uint pointAX, uint pointAY, uint pointBX, uint pointBY, uint pointCX, uint pointCY, Paint paint) {

}

void BImage::drawPic(BImage pic, uint startX, uint startY, Paint paint) {
    
}

byte *BImage::getImageData() {
    return picData;
}

ImageType BImage::getType() {
    return type;
}

Paint createPaint(uint red, uint green, uint blue, uint alpha, uint size) {
    struct Paint paint = {red, green, blue, alpha, size};
    return paint;
}
