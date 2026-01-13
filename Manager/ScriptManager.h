/*****************************************************************************
FileName:   ScriptManager.h
Author:     Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE_SCRIPTMANAGER_H
#define BALLENGINE_SCRIPTMANAGER_H

#include "../Header/Define.h"
#include "../Header/SingletonClassDefine.h"
#include "../Core/Manager.h"

#include <random>
#include <stack>
#include <vector>
#include <cstring>
#include <map>

BE_BEGIN
    class ScriptManager : public Manager {
    public:
        constexpr static unsigned char operatorPriority[21] = {
            11, 11, 11, 11, 10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 6, 6, 5,
            4, 3, 2, 1
        };

        ScriptManager();

        ~ScriptManager() override;

        std::string pretreatment(const char *code);

        double execute(const std::string &expression);

        BEvent analysis(std::string code);

        void memoryWrite(const std::string &key, int value);

        int memoryRead(const std::string &key);

        void processEvent(BEvent event) override;

    protected:
        static unsigned char getOperatorIndex(const std::string &operatorString);

        std::map<std::string, int> memoryMap;
    };

BE_END

#endif //BALLENGINE_SCRIPTMANAGER_H
