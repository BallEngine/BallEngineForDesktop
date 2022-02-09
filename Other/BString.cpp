/*****************************************************************************
FileName:   BString.cpp
Creater:    Xeler
Desc:       Desc
Version:    1.0
******************************************************************************/

#include "BString.h"

using namespace be;

BString::BString() {
    m_iStringLength = 0;
    m_pString = nullptr;
    m_pString[0] = '\0';
}

BString::BString(const char *str) {
    m_iStringLength = strCount(str);
    m_pString = new char[m_iStringLength + 1];
    strCopy(m_pString, str);
}

BString::BString(const BString &bString) {
    m_iStringLength = bString.m_iStringLength;
    m_pString = new char[m_iStringLength + 1];
    strCopy(m_pString, bString.m_pString);
}

BString::~BString() {
    delete[] m_pString;
    delete[] m_pTempChars;
}

BString &BString::operator+(const BString &bString) {
    char *tempChars = new char[m_iStringLength + bString.m_iStringLength + 1];
    strCopy(tempChars, m_pString);
    strCopy(tempChars + m_iStringLength, bString.m_pString);
    delete[] m_pString;
    m_pString = tempChars;
    m_iStringLength += bString.m_iStringLength;
    return (*this);
}

BString &BString::operator+(const char *str) {
    unsigned int strLength = strCount(str);
    char *tempChars = new char[m_iStringLength + strLength + 1];
    strCopy(tempChars, m_pString);
    strCopy(tempChars + m_iStringLength, str);
    delete[] m_pString;
    m_pString = tempChars;
    m_iStringLength += strLength;
    return (*this);
}

BString &BString::operator+(char c) {
    char *tempChars = new char[m_iStringLength + 2];
    strCopy(tempChars, m_pString);
    m_pString[m_iStringLength] = c;
    m_pString[m_iStringLength] = '\0';
    delete[] m_pString;
    m_pString = tempChars;
    m_iStringLength += 1;
    return (*this);
}

BString &BString::operator=(const BString &bString) {
    if (this == &bString) {
        return *this;
    }
    if (m_pString != nullptr) {
        delete m_pString;
        m_pString = nullptr;
    }
    m_iStringLength = bString.m_iStringLength;
    m_pString = new char[m_iStringLength + 1];
    strCopy(m_pString, bString.m_pString);
    return *this;
}

BString &BString::operator=(const char *str) {
    if (m_pString != nullptr) {
        delete m_pString;
        m_pString = nullptr;
    }
    m_iStringLength = strCount(str);
    m_pString = new char[m_iStringLength + 1];
    strCopy(m_pString, str);
    return *this;
}

BString &BString::operator=(char c) {
    if (m_pString != nullptr) {
        delete m_pString;
        m_pString = nullptr;
    }
    m_iStringLength = 1;
    m_pString = new char[m_iStringLength + 1];
    m_pString[0] = c;
    m_pString[1] = '\0';
    return *this;
}

bool BString::operator==(const BString &bString) {
    unsigned int i;
    if (m_iStringLength != bString.m_iStringLength) {
        return false;
    }
    for (i = 0; i < m_iStringLength; i++) {
        if (m_pString[i] != bString.m_pString[i])
            return false;
    }
    return true;
}

bool BString::operator==(const char *str) {
    unsigned int i = 0;
    while (m_pString[i] == str[i]) {
        if (i > m_iStringLength) {
            break;
        }
        i++;
    }
    return m_pString[i] == str[i];
}

bool BString::operator!=(const BString &bString) {
    return !(*this == bString);
}

BString BString::operator+=(const BString &bString) {
    *this = *this + bString.m_pString;
    return *this;
}

BString BString::operator+=(const char *str) {
    char *temp = new;
    m_iStringLength = m_iStringLength + strCount(str);
    m_pString = new char[m_iStringLength + 1];
    strCopy(m_pString, temp);
    strCopy(m_pString + strCount(m_pString), str);
    m_pString[m_iStringLength] = '\0';
    delete temp;
    return *this;
}

BString BString::operator+=(char c) {
    char *temp = m_pString;
    m_iStringLength++;
    m_pString = new char[m_iStringLength + 1];
    strCopy(m_pString, temp);
    m_pString[m_iStringLength - 1] = c;
    m_pString[m_iStringLength] = '\0';
    delete temp;
    return *this;
}

char BString::operator[](unsigned long point) {
    return m_pString[point];
}

char *BString::toChar() {
    checkNewTempChars(m_iStringLength);
    strCopy(m_pTempChars, m_pString);
    return m_pTempChars;
}

BString BString::strSub(unsigned int startIndex) {
    if (startIndex >= m_iStringLength) {
        return BString();
    } else {
        unsigned int offset = 0;

        checkNewTempChars(m_iStringLength - startIndex);
        while ((startIndex + offset) <= m_iStringLength) {
            m_pTempChars[offset] = m_pString[startIndex + offset];
            offset++;
        }
    }
    return BString(m_pTempChars);
}

BString BString::strSub(unsigned int startIndex, unsigned int endIndex) {
    if (endIndex < startIndex || (endIndex - startIndex) >= m_iStringLength) {
        return BString();
    } else {
        unsigned int offset = 0;
        checkNewTempChars(endIndex - startIndex);
        while ((startIndex + offset) <= endIndex) {
            m_pTempChars[offset] = m_pString[startIndex + offset];
            offset++;
        }
    }
    return BString(m_pTempChars);
}

int BString::strFind(char c) {
    int point = 0;
    while (point < m_iStringLength) {
        if (m_pString[point] == c) {
            return point + 1;
        }
        point++;
    }
    return -1;
}

void BString::checkNewTempChars(unsigned int length) {
    delete[] m_pTempChars;
    m_pTempChars = new char[length];
}

unsigned long BString::getLength() {
    return m_iStringLength;
}

void strCopy(char *to, const char *from) {
    int i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

unsigned int strCount(const char *str) {
    unsigned int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
