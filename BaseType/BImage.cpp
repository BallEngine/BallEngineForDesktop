/*****************************************************************************
FileName:   BImage.cpp
Creater:    Xeler
Desc:       Desc
******************************************************************************/

#include "BImage.h"

using namespace be;

struct BPaint defaultPaint{0, 0, 0, 0, 0};

BImage::BImage() {
    imageType = None;
    imageInfo.width = 0;
    imageInfo.height = 0;
    imageInfo.picLength = 0;
    picInfo = nullptr;
    picData = nullptr;
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
    imageType = bImage.imageType;
    imageInfo.width = bImage.imageInfo.width;
    imageInfo.height = bImage.imageInfo.height;
    imageInfo.picLength = bImage.imageInfo.picLength;
    picData = new byte[bImage.imageInfo.picLength];
    memcpy(picData, bImage.picData, bImage.imageInfo.picLength);
    switch (imageType) {
        case ImageType::Bmp:
            picInfo = new BmpInfo;
            break;
        case ImageType::Jpg:
            picInfo = new JpgInfo;
            break;
        case ImageType::Png:
            picInfo = new PngInfo;
            break;
        case ImageType::None:
            picInfo = nullptr;
            break;
    }
}

BImage &BImage::operator=(const BImage &bImage) {
    imageType = bImage.imageType;
    imageInfo.width = bImage.imageInfo.width;
    imageInfo.height = bImage.imageInfo.height;
    imageInfo.picLength = bImage.imageInfo.picLength;
    picData = new byte[bImage.imageInfo.picLength];
    memcpy(picData, bImage.picData, bImage.imageInfo.picLength);
    switch (imageType) {
        case ImageType::Bmp:
            picInfo = new BmpInfo;
            break;
        case ImageType::Jpg:
            picInfo = new JpgInfo;
            break;
        case ImageType::Png:
            picInfo = new PngInfo;
            break;
        case ImageType::None:
            picInfo = nullptr;
            break;
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
    return imageInfo.picLength;
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
    return imageType;
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

    imageType = Bmp;
    imageInfo.width = sourceBmpImageInfo.width;
    imageInfo.height = sourceBmpImageInfo.height;
    imageInfo.picLength = sourceBmpImageInfo.sizeImage;
    ((BmpInfo *) picInfo)->reserved[0] = sourceBmpInfo.reserved1;
    ((BmpInfo *) picInfo)->reserved[1] = sourceBmpInfo.reserved2;
    ((BmpInfo *) picInfo)->compression = sourceBmpImageInfo.compression;

    if (sourceBmpImageInfo.bitCount >= 24) {
        if (sourceBmpImageInfo.clrUsed <= 0) {
            sourceBmpImageInfo.clrUsed = pow(2, sourceBmpImageInfo.bitCount);
        }
        dword offset = 0;
        while (sourceBmpImageInfo.clrUsed > offset) {
            picStream.read((char *) (&(((BmpInfo *) picInfo)->colors[offset])), sizeof(BmpRGBSQUAD));
            offset++;
        }
    }

    picData = new byte[imageInfo.picLength];
    picStream.read((char *) (picData), imageInfo.picLength);
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
