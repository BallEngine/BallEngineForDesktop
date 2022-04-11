#ifndef BALLENGINE4CPP_BPASTER_H
#define BALLENGINE4CPP_BPASTER_H

#include <vector>

#include "../Core/define.h"
#include "../BaseType/BImage.h"

BE_BEGIN

    class BPaster {
    public:
        BPaster();

        BPaster(BImage pics[], unsigned int picCount = 1);

        ~BPaster();

        BPaster &operator=(const BPaster &paster);

        void frameControl(int frameNumber = 1);

        BImage getFrame();

    private:
        std::vector<BImage> pictures;
        int picPoint = 0, picNumber = 0;
    };

BE_END

#endif //BALLENGINE4CPP_BPASTER_H
