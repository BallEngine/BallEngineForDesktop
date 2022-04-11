/*****************************************************************************
FileName:   BImage.cpp
Creater:    Xeler
Desc:       Desc
******************************************************************************/

#include "BImage.h"

using namespace be;

struct BPaint defaultPaint{0, 0, 0, 0, 0};

BImage::BImage() {
    type = None;
    width = 0;
    height = 0;
    picLength = 0;
    picData = nullptr;
    bmpInfo = {};
    jpgInfo = {};
    pngInfo = {};
}

BImage::BImage(std::string imagePath) {
    std::ifstream imageFile = std::ifstream(imagePath.c_str(), std::ios::in | std::ios::binary);

    int flag = -1;

    std::string filePostfix = imagePath.substr(imagePath.length() - 4, imagePath.length());

    if (filePostfix == ".bmp") {
        convertFromBMP(imageFile);
    } else if (filePostfix == ".jpg") {
        convertFromJPG(imageFile);
    } else if (filePostfix == ".png") {
        convertFromPNG(imageFile);
    } else {
        //默认是JPEG
        convertFromJPG(imageFile);
    }

    imageFile.close();
}

BImage::BImage(const BImage &bImage) {
    type = bImage.type;
    bmpInfo = bImage.bmpInfo;
    jpgInfo = bImage.jpgInfo;
    pngInfo = bImage.pngInfo;
    width = bImage.width;
    height = bImage.height;
    picLength = bImage.picLength;
    picData = bImage.picData;
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

void BImage::drawLine(uint startX, uint startY, uint endX, uint endY, BPaint paint) {

}

void BImage::drawArc(uint circleX, uint circleY, uint radius, uint startAngle, uint endAngle, BPaint paint) {

}

void BImage::drawArc(uint pointAX, uint pointAY, uint pointBX, uint pointBY, uint pointCX, uint pointCY, BPaint paint) {

}

void BImage::drawPic(const BImage &pic, uint startX, uint startY) {

}

void BImage::clip(uint pointAX, uint pointAY, uint pointBX, uint pointBY) {

}

byte *BImage::getImageData() {
    return picData;
}

unsigned long BImage::getImageDataSize() {
    return picLength;
}

byte *BImage::getImageSourceData() {
    //TODO
    return (byte *) 0;
}

unsigned long BImage::getImageSourceDataSize() {
    //TODO
    return 0;
}

ImageType BImage::getType() {
    return type;
}

BImage *BImage::getBlankImage(ImageType type) {
    static BImage blankImage[] = {BImage(), BImage(), BImage(), BImage()};

    return new BImage(blankImage[type]);
}

void BImage::convertFromBMP(std::ifstream &picStream) {
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

void BImage::convertFromJPG(std::ifstream &picStream) {

}

void BImage::convertFromPNG(std::ifstream &picStream) {

}

byte *BImage::convertToBMPSource() {
    return nullptr;
}

byte *BImage::convertToJPGSource() {
    return nullptr;
}

byte *BImage::convertToPNGSource() {
    return nullptr;
}
