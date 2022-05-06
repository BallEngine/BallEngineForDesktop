#ifndef BALLENGINE4CPP_BPASTER_H
#define BALLENGINE4CPP_BPASTER_H

#include <vector>

#include "../Core/define.h"
#include "../BaseType/BImage.h"

BE_BEGIN
    struct PasterInfo {
        unsigned short positionX, positionY;
        unsigned short sizeX, sizeY;
        float scale;
    };

    class BPaster {
    public:
        BPaster();

        explicit BPaster(BImage pics[], unsigned int picCount = 1);

        ~BPaster();

        BPaster &operator=(const BPaster &paster);

        void frameControl(int frameNumber = 1);

        BImage getFrame();

        PasterInfo getInfo();

        void movePaster(unsigned short posX, unsigned short posY);

        void movePasterTo(unsigned short posX, unsigned short posY);

        void

        //TODO:Zoom

    private:
        PasterInfo pasterInfo;
        std::vector<BImage> pictures;
        int picPoint = 0, picNumber = 0;
    };

BE_END

#endif //BALLENGINE4CPP_BPASTER_H
