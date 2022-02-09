/*****************************************************************************
FileName:   BImage.cpp
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "BImage.h"

using namespace be;

BImage::BImage() {
    type = NONE;
    width = 0;
    height = 0;
    picData = nullptr;
}

BImage::BImage(BString imagePath) {
    std::ifstream imageFile = std::ifstream(imagePath.toChar(), std::ios::in | std::ios::binary);

    int flag = -1;

    BString filePostfix = imagePath.strSub(imagePath.getLength() - 4, imagePath.getLength());

    if (filePostfix == ".bmp" ) {

    } else if (filePostfix == ".jpg" || filePostfix == "jpeg") {

    } else if (filePostfix == ".png") {

    } else {

    }

    imageFile.close();
}

BImage::BImage(BImage bImage, uint startX, uint startY, uint endX, uint endY) {

}

BImage::BImage(const BImage &bImage) {
    (*this) = bImage;
}

BImage &BImage::operator=(const BImage &bImage) {
    type = bImage.type;
    width = bImage.width;
    height = bImage.height;
    picLength = bImage.picLength;
    ulong copyLength = picLength;
    picData = new byte[copyLength];
    while (copyLength--) {
        picData[copyLength] = bImage.picData[copyLength];
    }
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

void BImage::drawPic(BImage pic, uint startX, uint startY) {

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
