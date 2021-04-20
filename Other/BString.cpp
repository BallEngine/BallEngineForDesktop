/*****************************************************************************
FileName:   BString.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    1.0
******************************************************************************/

#include "BString.h"

using namespace be;

BString::BString() {
    stringLength = 0;
    string = new char;
    string[0] = '\0';
}

BString::BString(const char *str) {
    stringLength = stringCount(str);
    string = new char[stringLength + 1];
    stringCpy(string, str);
}

BString::BString(const BString &bString) {
    stringLength = bString.stringLength;
    string = new char[stringLength + 1];
    stringCpy(string, bString.string);
}

BString::~BString() {
    delete[] string;
}

BString &BString::operator+(const BString &bString) {
    tmp.stringLength = this->stringLength + bString.stringLength;
    tmp.string = new char[tmp.stringLength + 1];
    tmp.string = this->string + *bString.string;
    tmp.string[tmp.stringLength] = '\0';
    return tmp;
}

BString &BString::operator+(const char *str) {
    tmp.stringLength = this->stringLength + stringCount(str);
    tmp.string = new char[tmp.stringLength + 1];
    tmp.string = this->string + *str;
    tmp.string[tmp.stringLength] = '\0';
    return tmp;
}

BString &BString::operator+(char c) {
    tmp.stringLength = this->stringLength + 1;
    tmp.string = new char[tmp.stringLength + 1];
    tmp.string = this->string + c;
    tmp.string[tmp.stringLength] = '\0';
    return tmp;
}

BString &BString::operator=(const BString &bString) {
    if (this == &bString) {
        return *this;
    }
    if (string != nullptr) {
        delete string;
        string = nullptr;
    }
    stringLength = bString.stringLength;
    string = new char[stringLength + 1];
    stringCpy(string, bString.string);
    return *this;
}

BString &BString::operator=(const char *str) {
    if (string != nullptr) {
        delete string;
        string = nullptr;
    }
    stringLength = stringCount(str);
    string = new char[stringLength + 1];
    stringCpy(string, str);
    return *this;
}

BString &BString::operator=(char c) {
    if (string != nullptr) {
        delete string;
        string = nullptr;
    }
    stringLength = 1;
    string = new char[stringLength + 1];
    string[0] = c;
    string[1] = '\0';
    return *this;
}

bool BString::operator==(const BString &bString) {
    unsigned int i;
    if (stringLength != bString.stringLength) {
        return false;
    }
    for (i = 0; i < stringLength; i++) {
        if (string[i] != bString.string[i])
            return false;
    }
    return true;
}

bool BString::operator==(const char *str) {
    unsigned int i = 0;
    while (string[i] == str[i]) {
        if (!(string[i] + str[i]))break;
    }
    return string[i] == str[i];
}

bool BString::operator!=(const BString &bString) {
    return !(*this == bString);
}

BString BString::operator+=(const BString &bString) {
    *this = *this + bString.string;
    return *this;
}

BString BString::operator+=(const char *str) {
    char *temp = string;
    stringLength = stringLength + stringCount(str);
    string = new char[stringLength + 1];
    stringCpy(string, temp);
    stringCpy(string + stringCount(string), str);
    string[stringLength] = '\0';
    delete temp;
    return *this;
}

BString BString::operator+=(char c) {
    char *temp = string;
    stringLength++;
    string = new char[stringLength + 1];
    stringCpy(string, temp);
    string[stringLength - 1] = c;
    string[stringLength] = '\0';
    return *this;
}

char BString::operator[](unsigned long point) {
    return string[point];
}

char *BString::toChar() {
    tempChars = new char[stringLength];
    stringCpy(tempChars, string);
    return tempChars;
}

void BString::stringCpy(char *s1, const char *s2) {
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

unsigned int BString::stringCount(const char *str) {
    unsigned int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
