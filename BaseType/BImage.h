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

    struct ImageInfo {
        ulong width, height;
        ulong picLength;
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
        word reserved[2];
        word compression;
        BmpRGBSQUAD *colors;
    };

    struct PngInfo {

    };

    struct JpgInfo {
    };

    struct BPaint {
        uint red, green, blue, alpha, size;
    };

    class BImage {
    public:
        explicit BImage();

        BImage(std::string imagePath);

        BImage(const BImage &bImage);

        BImage &operator=(const BImage &bImage);

        ~BImage();

        void drawLine(uint startX, uint startY, uint endX, uint endY, BPaint paint);

        void drawArc(uint circleX, uint circleY, uint radius, uint startAngle, uint endAngle, BPaint paint);

        void drawArc(uint pointAX, uint pointAY, uint pointBX, uint pointBY, uint pointCX, uint pointCY, BPaint paint);

        void drawPic(const BImage &pic, uint startX, uint startY);

        void clip(uint pointAX, uint pointAY, uint pointBX, uint pointBY);

        byte *getImageData();

        unsigned long getImageDataSize();

        byte *getImageSourceData();

        unsigned long getImageSourceDataSize();

        ImageType getType();

        static BImage *getBlankImage(ImageType type);

    protected:
        void convertFromBMP(std::ifstream &picStream);

        void convertFromJPG(std::ifstream &picStream);

        void convertFromPNG(std::ifstream &picStream);

        byte *convertToBMPSource();

        byte *convertToJPGSource();

        byte *convertToPNGSource();

    private:
        ImageType imageType;
        ImageInfo imageInfo;
        void *picInfo;
        byte *picData;
    };

}

#endif //BALLENGINE4CPP_BIMAGE_H
