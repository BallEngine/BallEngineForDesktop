/*****************************************************************************
FileName:   PasterManager.h
Creater:    Xeler
Desc:       Define class Paster and PasterManager.
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_PASTERMANAGER_H
#define BALLENGINE4CPP_PASTERMANAGER_H

#include "../Core/define.h"
#include "../Core/Manager.h"
#include "../ComplexType/BPaster.h"
#include <vector>

BE_BEGIN

    class PasterManager : public Manager {
    public:
        PasterManager();
        ~PasterManager();
        void processEvent(BEvent event);
        int addPaster(BPaster paster);
        bool removePaster(unsigned int point);
        bool changePaster(unsigned int point, BPaster paster);
        BPaster *getPaster(unsigned int point);
        BPaster operator[](unsigned int point);
        void clear();
    private:
        std::vector<BPaster> pasters;
        std::vector<int> pastersID;
    };

BE_END

#endif //BALLENGINE4CPP_PASTERMANAGER_H
