/*****************************************************************************
FileName:   ScriptManager.h
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_SCRIPTMANAGER_H
#define BALLENGINE4CPP_SCRIPTMANAGER_H

#include <vector>
#include <stack>
#include "../define.h"
#include "../Template/Manager.h"

BE_BEGIN


    class ScriptManager : public Manager {
    public:

        constexpr static unsigned char operatorPriority[21] = {11, 11, 11, 11, 10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 6, 6, 5,
                                                               4, 3, 2, 1};

        ScriptManager();

        ~ScriptManager();

        //预处理函数
        BString pretreatment(char *code);

        //执行函数
        double execute(BString expression);

        //解析函数
        Event analysis(BString code);

        void *memoryWrite(BString key, void *value);

        void *memoryRead(BString key);

    protected:
        static unsigned char getOperatorIndex(BString operatorString);


    private:
        std::vector<BString> key[26];
        std::vector<int> value[26];
    };
BE_END

#endif //BALLENGINE4CPP_SCRIPTMANAGER_H
