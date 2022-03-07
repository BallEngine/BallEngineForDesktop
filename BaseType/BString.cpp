/*****************************************************************************
FileName:   BString.cpp
Creater:    Xeler
Desc:       Desc
Version:    1.0
******************************************************************************/

#include "BString.h"

namespace be {

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
}

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
    while (!m_listCharPtrStack.empty()) {
        delete[] m_listCharPtrStack.top();
        m_listCharPtrStack.pop();
    }
    delete[] m_pString;
}

BString &BString::operator+(const BString &bString) {
    checkStringSpace(m_iStringLength + bString.m_iStringLength);
    strCopy(m_pString + m_iStringLength, bString.m_pString);
    m_iStringLength += bString.m_iStringLength;
    return (*this);
}

BString &BString::operator+(const char *str) {
    unsigned int strLength = strCount(str);
    checkStringSpace(m_iStringLength + strLength);
    strCopy(m_pString + m_iStringLength, str);
    m_iStringLength += strLength;
    return (*this);
}

BString &BString::operator+(char c) {
    checkStringSpace(m_iStringLength + 1);
    m_pString[m_iStringLength] = c;
    m_iStringLength++;
    m_pString[m_iStringLength] = '\0';
    return (*this);
}

BString &BString::operator=(const BString &bString) {
    if (m_pString == bString.m_pString) {
        return *this;
    }
    m_iStringLength = bString.m_iStringLength;
    checkStringSpace(m_iStringLength);
    strCopy(m_pString, bString.m_pString);
    return *this;
}

BString &BString::operator=(const char *str) {
    m_iStringLength = strCount(str);
    checkStringSpace(m_iStringLength);
    strCopy(m_pString, str);
    return *this;
}

BString &BString::operator=(char c) {
    m_iStringLength = 1;
    checkStringSpace(m_iStringLength);
    m_pString[0] = c;
    m_pString[1] = '\0';
    return *this;
}

bool BString::operator==(const BString &bString) {
    unsigned int i;
    if (m_iStringLength != bString.m_iStringLength) {
        return false;
    } else {
        return (*this) == bString.m_pString;
    }
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
    m_iStringLength = m_iStringLength + strCount(str);
    checkStringSpace(m_iStringLength);
    strCopy(m_pString + strCount(m_pString), str);
    return *this;
}

BString BString::operator+=(char c) {
    checkStringSpace(m_iStringLength + 1);
    m_pString[m_iStringLength] = c;
    m_iStringLength++;
    m_pString[m_iStringLength] = '\0';
    return *this;
}

char BString::operator[](unsigned long point) {
    return m_pString[point];
}

char *BString::toCStyleStr() {
    char *retStr = new char[m_iStringLength + 1];
    strCopy(retStr, m_pString);
    m_listCharPtrStack.push(retStr);
    return retStr;
}

BString BString::strSub(unsigned int startIndex, unsigned int endIndex) {
    if (endIndex < startIndex || (endIndex - startIndex) >= m_iStringLength) {
        return BString();
    } else {
        BString bString = BString(m_pString + endIndex - startIndex);
        return bString;
    }
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

unsigned long BString::getLength() {
    return m_iStringLength;
}

void BString::checkStringSpace(unsigned int length) {
    if (length >= m_iStringLength) {
        char *tempStr = new char[m_iStringLength + 1];
        be::strCopy(tempStr, m_pString);
        m_iMemoryLength = length;
    }
}

void BString::memoryGC(unsigned int threshold) {
    if (threshold > (m_iMemoryLength - m_iStringLength)) {
        char *tempStr = new char[m_iStringLength + 1];
        unsigned int offset = 0;
        while (offset <= m_iStringLength) {
            tempStr[offset] = m_pString[offset];
            offset++;
        }
        delete[] m_pString;
        m_pString = tempStr;
    }
}
