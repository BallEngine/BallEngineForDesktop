/*****************************************************************************
FileName:   BString.h
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    1.0
******************************************************************************/

#ifndef BALLENGINE4CPP_BSTRING_H
#define BALLENGINE4CPP_BSTRING_H

namespace be {

    class BString {
    public:
        BString();
        explicit BString(const char *str);
        BString(const BString &bString);
        ~BString();
        BString &operator+(const BString &bString);
        BString &operator+(const char *str);
        BString &operator+(char c);
        BString &operator=(const BString &bString);
        BString &operator=(const char *str);
        BString &operator=(char c);
        bool operator==(const BString &bString);
        bool operator==(const char *str);
        bool operator!=(const BString &bString);
        BString operator+=(const BString &bString);
        BString operator+=(const char *str);
        BString operator+=(char c);
        char operator[](unsigned long point);
        char *toChar();
        static void stringCpy(char *s1, const char *s2);
        static unsigned int stringCount(const char *str);
    private:
        char *string;
        unsigned int stringLength;
        static char *tempChars;
        static BString tmp;
    };

}

#endif //BALLENGINE4CPP_BSTRING_H
