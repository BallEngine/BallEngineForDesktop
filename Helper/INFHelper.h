/*****************************************************************************
FileName:   INFHelper.h
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_JSONHELPER_H
#define BALLENGINE4CPP_JSONHELPER_H

#include "../Other/BString.h"
#include <map>
#include <fstream>

namespace be {

    class INFHelper {
    public:
        explicit INFHelper(BString fileName);
        ~INFHelper();
        BString getValue(BString &dataName);
    protected:
        void analysis(BString code);
    private:
        std::map<BString, BString> m_mapData;
    };

}

#endif //BALLENGINE4CPP_JSONHELPER_H
