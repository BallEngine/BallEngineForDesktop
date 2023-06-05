/*****************************************************************************
FileName:   BConfig.h
Author:    Xeler
Desc:       Desc.
******************************************************************************/
#ifndef BALLENGINE_BCONFIG_H
#define BALLENGINE_BCONFIG_H

#include "../define.h"

#include <map>
#include <string>

BE_BEGIN

    class BConfig {
    public:
        BConfig(const std::string fileName);

        ~BConfig();

        void setValue(const std::string &key, const std::string &value);

        std::string getValue(const std::string &key);

        void reload();
        void save();

    private:

        std::map<> m_config;
    };

BE_END

#endif //BALLENGINE_BCONFIG_H
