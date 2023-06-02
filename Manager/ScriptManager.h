/*****************************************************************************
FileName:   ScriptManager.h
Author:     Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE_SCRIPTMANAGER_H
#define BALLENGINE_SCRIPTMANAGER_H

#include <stack>
#include <vector>
#include <string>
#include "../define.h"
#include "../Core/Manager.h"

BE_BEGIN


    class ScriptManager : public Manager {
    public:

        constexpr static unsigned char operatorPriority[21] = {11, 11, 11, 11, 10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 6, 6, 5,
                                                               4, 3, 2, 1};

        ScriptManager();

        ~ScriptManager();

        //预处理函数
        std::string pretreatment(char *code);

        //执行函数
        double execute(std::string expression);

        //解析函数
        BEvent analysis(std::string code);

        void *memoryWrite(std::string key, void *value);

        void *memoryRead(std::string key);

        void processEvent(BEvent event) override;

    protected:
        static unsigned char getOperatorIndex(std::string operatorString);


    private:
        std::vector<std::string> key[26];
        std::vector<int> value[26];
    };
BE_END

#endif //BALLENGINE_SCRIPTMANAGER_H
