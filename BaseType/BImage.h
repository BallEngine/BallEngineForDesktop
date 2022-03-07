/*****************************************************************************
FileName:   BImage.h
Creater:    Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE4CPP_BIMAGE_H
#define BALLENGINE4CPP_BIMAGE_H

#include <fstream>
#include <cmath>

typedef unsigned short word;
typedef unsigned long dword;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long ulong;

namespace be {

    //DelayTODO : support png&jpg
    enum ImageType {
        None = 0,
        Bmp,
        Png,
        Jpg
    };

    struct BmpRGBSQUAD {
        byte rgbBlue;
        byte rgbGreen;
        byte rgbRed;
        byte rgbReserved;
    };

    struct SourceBmpInfo {
        word type;
        dword size;
        word reserved1;
        word reserved2;
        dword offBits;
    };

    struct SourceBmpImageInfo {
        dword size;
        long width;
        long height;
        word planes;
        word bitCount;
        dword compression;
        dword sizeImage;
        long xPixelsPerMeter;
        long yPixelsPerMeter;
        dword clrUsed;
        dword clrImportant;
    };

    struct BmpInfo {
        word reserved[2] = {0, 0};
        word compression = 0;
        BmpRGBSQUAD *colors = nullptr;
    };

    struct PngInfo {

    };

    struct JpgInfo {
    };

    struct Paint {
        uint red, green, blue, alpha, size;
    } defaultPaint{0, 0, 0, 0, 0};

    class BImage {
    public:
        explicit BImage();

        BImage(std::string imagePath);

        BImage(const BImage &bImage);

        BImage &operator=(const BImage &bImage);

        ~BImage();

        void drawLine(uint startX, uint startY, uint endX, uint endY, Paint paint);

        void drawArc(uint circleX, uint circleY, uint radius, uint startAngle, uint endAngle, Paint paint);

        void drawArc(uint pointAX, uint pointAY, uint pointBX, uint pointBY, uint pointCX, uint pointCY, Paint paint);

        void drawPic(const BImage &pic, uint startX, uint startY);

        void clip(uint pointAX, uint pointAY, uint pointBX, uint pointBY);

        byte *getImageData();

        unsigned long getImageDataSize();

        ImageType getType();

    protected:
        void convertFromBMP(std::ifstream &picStream);

        void convertFromJPG(std::ifstream &picStream);

        void convertFromPNG(std::ifstream &picStream);

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
