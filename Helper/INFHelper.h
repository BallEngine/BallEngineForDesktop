/*****************************************************************************
FileName:   INFHelper.h
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_JSONHELPER_H
#define BALLENGINE4CPP_JSONHELPER_H

#include "../Other/BString.h"
#include <vector>
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
        std::vector<BString> key;
        std::vector<BString> value;
    };

}

#endif //BALLENGINE4CPP_JSONHELPER_H
