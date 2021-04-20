/*****************************************************************************
FileName:   BImage.h
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_BIMAGE_H
#define BALLENGINE4CPP_BIMAGE_H

#include "BString.h"
#include <fstream>

typedef unsigned char byte;
typedef unsigned int uint;

namespace be {

    enum ImageType {
        NONE = 0,
        BMP_NONE,
        BMP_AVE,
        BMP_,
        BMP_8BYTE,
        PNG,
        JPG
    };
    
    enum GrayType{
        NOTYPE = 0,
        AVERAGE,
        Standard,
        BYTE8
    };

    struct Paint {
        uint red, green, blue, alpha, size;
    };
    Paint createPaint(uint red, uint green, uint blue, uint alpha, uint size);

    class BImage {
    public:
        BImage();
        BImage(BString imagePath);
        BImage(BImage bImage, uint startX, uint startY, uint endX, uint endY);
        BImage(const BImage &bImage);
        BImage &operator=(const BImage &bImage);
        ~BImage();
        void drawLine(uint startX, uint startY, uint endX, uint endY, Paint paint);
        void drawArc(uint circleX, uint circleY, uint radius, uint startAngle, uint endAngle, Paint paint);
        void drawArc(uint pointAX, uint pointAY, uint pointBX, uint pointBY, uint pointCX, uint pointCY, Paint paint);
        void drawPic(BImage pic, uint startX, uint startY, Paint paint);
        byte* getImageData();
        ImageType getType();
    private:
        ImageType type;
        uint width, height;
        unsigned long imageLength;
        unsigned short pixelLength,picHeadLength;
        byte *picData;
    };

}

#endif //BALLENGINE4CPP_BIMAGE_H
