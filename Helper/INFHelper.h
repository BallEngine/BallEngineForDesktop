/*****************************************************************************
FileName:   INFHelper.h
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_JSONHELPER_H
#define BALLENGINE4CPP_JSONHELPER_H

#include "../BaseType/BString.h"
#include <map>
#include <string>
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
        std::map<std::string , BString> m_mapData;
    };

}

#endif //BALLENGINE4CPP_JSONHELPER_H
