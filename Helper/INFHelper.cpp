/*****************************************************************************
FileName:   INFHelper.cpp
Creater:    Xeler
Desc:       inf file helper,use key/value.
Version:    0.1
******************************************************************************/

#include "INFHelper.h"

using namespace be;

INFHelper::INFHelper(BString &fileName) {
    std::ifstream fileStream = std::ifstream(fileName.toCStyleStr(), std::ios::in | std::ios::binary);
    fileStream.seekg(std::ios::end);
    unsigned long fileLength = fileStream.tellg(), count = 0;
    char *temp = new char[fileLength + 1], *cache = new char[fileLength + 1];
    fileStream.seekg(std::ios::beg);
    temp[fileLength] = '\0';
    fileStream.read(temp, fileLength);
    fileLength = 0;
    while (temp[count] != '\0') {
        if (cache[fileLength] != ' ' && cache[fileLength] != '\n') {
            cache[fileLength] = temp[count];
            fileLength++;
        } else {
            cache[fileLength + 1] = '\0';
            analysis(BString(cache));
            fileLength = 0;
        }
        count++;
    }
    delete[] temp;
    delete[] cache;
    fileStream.close();
}

INFHelper::~INFHelper() {
    m_mapData.clear();
}

BString INFHelper::getValue(BString &dataName) {
    return m_mapData.at(dataName.toCStyleStr());
}

void INFHelper::setValue(std::string &dataName, BString dataValue) {
    m_mapData.insert(dataName,dataValue);
}


void INFHelper::analysis(BString code) {
    unsigned long point = code.strFind('=');
    std::pair<std::string, BString> dataPair;
    dataPair.first = code.strSub(0, point).toCStyleStr();
    dataPair.second = code.strSub(point + 1, code.getLength());
    m_mapData.insert(dataPair);
}
