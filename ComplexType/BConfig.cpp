/*****************************************************************************
FileName:   BConfig.cpp
Author:     Xeler
Desc:       Desc.
******************************************************************************/
#include "BConfig.h"

#include <cstring>

BE_USE

BConfig::BConfig(const std::string &fileName) : m_configFile(fileName) {
    reload();
}

BConfig::~BConfig() {
    if (m_configFile.is_open()) {
        m_configFile.flush();

        m_configFile.close();
    }
}

void BConfig::setValue(const std::string &key, const std::string &value) {
    std::pair<std::string, std::string> kvPair;

    kvPair.first = key;
    kvPair.second = value;

    m_config.insert(kvPair);
}

std::string BConfig::getValue(const std::string &key) {
    return m_config.at(key);
}

void BConfig::reload() {
    if (m_configFile.is_open()) {
        char buffer[65535 + 1];
        unsigned short offset = 0;
        while (!m_configFile.eof()) {
            m_configFile.getline(buffer, 65535);
            offset = buffer - std::strchr(buffer, '=');
            std::pair<std::string, std::string> kvPair = std::make_pair(std::string(buffer, offset),
                                                                        std::string(buffer + offset));
            m_config.insert(kvPair);
        }
        m_configFile.seekg(0);
    }
}

void BConfig::save() {
    if (m_configFile.is_open()) {
        char buffer[65535 + 1];
        auto iter = m_config.begin();
        while (!m_configFile) {
            unsigned short offset = strlen(iter->first.c_str());
            strncpy(buffer, iter->first.c_str(), offset);
            buffer[offset] = '=';
            offset = strlen(iter->second.c_str());
            buffer[strlen(buffer)] = '\n';
            strncpy(buffer + offset, iter->second.c_str(), offset);

            m_configFile.write(buffer, 65535);
            ++iter;
        }
        m_configFile.seekg(0);
    }
}
