/*****************************************************************************
FileName:   BImage.cpp
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "BImage.h"

using namespace be;

BImage::BImage() {
    type = None;
    width = 0;
    height = 0;
    picData = nullptr;
}

BImage::BImage(BString imagePath) {
    std::ifstream imageFile = std::ifstream(imagePath.toChar(), std::ios::in | std::ios::binary);

    int flag = -1;

    BString filePostfix = imagePath.strSub(imagePath.getLength() - 4, imagePath.getLength());

    if (filePostfix == ".bmp") {
        convertFromBMP(imageFile);
    } else if (filePostfix == ".jpg" || filePostfix == "jpeg") {
        convertFromJPG(imageFile);
    } else if (filePostfix == ".png") {
        convertFromPNG(imageFile);
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

void BImage::convertFromBMP(std::ifstream picStream) {
    SourceBmpInfo sourceBmpInfo{};
    SourceBmpImageInfo sourceBmpImageInfo{};

    picStream.read((char *) (&sourceBmpInfo), sizeof(sourceBmpInfo));
    picStream.read((char *) (&sourceBmpImageInfo), sizeof(sourceBmpImageInfo));

    type = Bmp;
    width = sourceBmpImageInfo.width;
    height = sourceBmpImageInfo.height;
    bmpInfo.reserved[0] = sourceBmpInfo.reserved1;
    bmpInfo.reserved[1] = sourceBmpInfo.reserved2;
    bmpInfo.compression = sourceBmpImageInfo.compression;
    picLength = sourceBmpImageInfo.sizeImage;

    if (sourceBmpImageInfo.bitCount >= 24) {
        if (sourceBmpImageInfo.clrUsed <= 0) {
            sourceBmpImageInfo.clrUsed = pow(2, sourceBmpImageInfo.bitCount);
        }
        dword offset = 0;
        while (sourceBmpImageInfo.clrUsed > offset) {
            picStream.read((char *) (&(bmpInfo.colors[offset])), sizeof(BmpRGBSQUAD));
            offset++;
        }
    }

    picData = new byte[(picLength)];
    picStream.read((char *) (picData), picLength);
}

void BImage::convertFromJPG(std::ifstream picStream) {

}

void BImage::convertFromPNG(std::ifstream picStream) {

}
