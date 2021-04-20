/*****************************************************************************
FileName:   PasterManager.h
Creater:    Xeler
Date:       2021/04/20
Desc:       Define class Paster and PasterManager.
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_PASTERMANAGER_H
#define BALLENGINE4CPP_PASTERMANAGER_H

#include "../define.h"
#include "../Template/Manager.h"
#include <vector>

_BE_BEGIN

    class Paster {
    public:
        Paster(BImage pics[], unsigned int picCount = 1);
        ~Paster();
        Paster &operator=(const Paster &paster);
        void frameControl(int frameNumber = 1);
        BImage getFrame();
    private:
        std::vector<BImage> pictures;
        int picPoint = 0, picNumber = 0;
    };

    class PasterManager : public Manager {
    public:
        PasterManager();
        ~PasterManager();
        void processEvent(Event event);
        int addPaster(Paster paster);
        bool removePaster(unsigned int point);
        bool changePaster(unsigned int point, Paster paster);
        Paster *getPaster(unsigned int point);
        Paster operator[](unsigned int point);
        void clear();
    private:
        std::vector<Paster> pasters;
        std::vector<int> pastersID;
    };

_BE_END

#endif //BALLENGINE4CPP_PASTERMANAGER_H
