/*****************************************************************************
FileName:   INFHelper.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "INFHelper.h"

using namespace be;

INFHelper::INFHelper(BString fileName) {
    std::ifstream jsonFile = std::ifstream(fileName.toChar(), std::ios::in | std::ios::binary);
    jsonFile.seekg(std::ios::end);
    unsigned long fileLength = jsonFile.tellg(), count = 0;
    char *temp = new char[fileLength + 1], *cache = new char[fileLength + 1];
    jsonFile.seekg(std::ios::beg);
    temp[fileLength] = '\0';
    jsonFile.read(temp, fileLength);
    fileLength = 0;
    while (temp[count] != '\0') {
        if (cache[fileLength] != ' ' && cache[fileLength] != '\n') {
            cache[fileLength] = temp[count];
            fileLength++;
        }
        count++;
    }
    cache[fileLength + 1] = '\0';
    analysis(BString(cache));
    delete[] temp;
    delete[] cache;
    jsonFile.close();
}

INFHelper::~INFHelper() {
    auto ic = key.begin();
    while (key.begin() != key.end()) {
        key.erase(ic);
    }
    auto ic2 = value.begin();
    while (value.begin() != value.end()) {
        value.erase(ic2);
    }
}

BString INFHelper::getValue(BString &dataName) {
    unsigned int point = 0;
    while (point < key.size()) {
        if (key[point] == dataName) {
            return value[point];
        }
        point++;
    }
    return BString();
}

void INFHelper::analysis(BString code) {
    unsigned long count = 0;
    BString cache = BString();
    while (code[count] != '\0') {
        while (code[count] != '=') {
            cache += code[count];
            count++;
        }
        key.push_back(cache);
        cache = BString();
        count++;
        while (code[count] != '\n') {
            cache += code[count];
            count++;
        }
        value.push_back(cache);
        cache = BString();
        count++;
    }
}
