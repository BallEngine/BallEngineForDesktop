/*****************************************************************************
FileName:   BString.h
Creater:    Xeler
Date:       2021/04/20
Desc:       Kit Class.
Version:    1.0
******************************************************************************/

#ifndef BALLENGINE4CPP_BSTRING_H
#define BALLENGINE4CPP_BSTRING_H

namespace be {

    //返回字符数，不含'/0'
    unsigned int strCount(const char *str);
    //拷贝时自动附加'/0'
    void strCopy(char *to, const char *from);

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
        BString strSub(unsigned int startIndex);
        BString strSub(unsigned int startIndex, unsigned int endIndex);
        //查找某个字符第一次出现的位置（自0开始计数，没找到返回-1）
        int strFind(char c);
    private:
        //工具函数，检查并为临时变量申请指定长度空间
        void checkNewTempChars(unsigned int length);
    protected:
        //字符串指针
        char *m_pString;
        //不含'/0'的字符总数
        unsigned int m_iStringLength;
        //临时操作用指针
        char *m_pTempChars;
    };

}

#endif //BALLENGINE4CPP_BSTRING_H
