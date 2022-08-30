/*****************************************************************************
FileName:   PasterManager.h
Author:     Xeler
Desc:       Define class Paster and PasterManager.
******************************************************************************/

#ifndef BALLENGINE4CPP_PASTERMANAGER_H
#define BALLENGINE4CPP_PASTERMANAGER_H

#include "../Core/define.h"
#include "../Core/Manager.h"
#include "../ComplexType/BPaster.h"
#include <map>

BE_BEGIN

    class PasterManager : public Manager {
    public:
        explicit PasterManager(BImage *basePic = nullptr);

        ~PasterManager();

        void processEvent(BEvent event) override;

        PtrNum addPaster(const BPaster &paster);

        bool removePaster(PtrNum point);

        BPaster &getPaster(PtrNum point);

        bool setPaster(PtrNum point, const BPaster &paster);

        bool checkPasterValid(PtrNum point);

        BPaster &operator[](PtrNum point);

        void clear();

        BImage drawScreen(unsigned short framesSpace = 1);

    private:
        BPaster baseScreen;
        std::map<PtrNum, BPaster> pasterMap;
    };

BE_END

#endif //BALLENGINE4CPP_PASTERMANAGER_H
