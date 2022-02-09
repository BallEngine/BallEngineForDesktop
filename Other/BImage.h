/*****************************************************************************
FileName:   BImage.h
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_BIMAGE_H
#define BALLENGINE4CPP_BIMAGE_H

#include "BString.h"
#include <fstream>

typedef unsigned short word;
typedef unsigned long dword;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long ulong;

namespace be {

    //DelayTODO : support png&jpg
    enum ImageType {
        NONE = 0,
        BMP,
        PNG,
        JPG
    };

    struct BmpRGBSQUAD{
        byte rgbBlue;
        byte rgbGreen;
        byte rgbRed;
        byte rgbReserved;
    };

    struct SourceBmpInfo{
        word type;
        dword size;
        word reserved1;
        word reserved2;
        dword offBits;
    };

    struct SourceBmpImageInfo{
        dword size;
        long width;
        long height;
        word planes;
        word bitCount;
        dword compression;
        dword sizeImage;
        long xPelsPerMeter;
        long yPelsPerMeter;
        dword clrUsed;
        dword clrImportant;
    };

    struct BmpInfo{
        word reserved[2];
        word compression;
    };

    struct PngInfo{
    };

    struct JpgInfo{
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
        void drawPic(BImage pic, uint startX, uint startY);
        byte* getImageData();
        ImageType getType();
    private:
        ImageType type;
        BmpInfo bmpInfo;
        PngInfo pngInfo;
        JpgInfo jpgInfo;
        ulong width, height;
        ulong picLength;
        byte *picData;
    };

}

#endif //BALLENGINE4CPP_BIMAGE_H
