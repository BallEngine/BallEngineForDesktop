/*****************************************************************************
FileName:   ScriptManager.h
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_SCRIPTMANAGER_H
#define BALLENGINE4CPP_SCRIPTMANAGER_H

#include <vector>
#include "../define.h"
#include "../Template/Manager.h"

BE_BEGIN

    class ScriptManager : public Manager {
    public:
        ScriptManager();
        ~ScriptManager();
        //执行函数
        int execute(BString code);
        //解析函数
        Event analysis(BString code);
        //预处理函数
        BString pretreatment(char* code);
        void* memoryWrite(BString key,void* value);
        void* memoryRead(BString key);
    protected:
        std::vector<BString> key[26];
        std::vector<int> value[26];
    };
BE_END

#endif //BALLENGINE4CPP_SCRIPTMANAGER_H
