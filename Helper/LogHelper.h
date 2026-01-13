/*****************************************************************************
FileName:   LogHelper.h
Author:     Xeler
Desc:       Log 4 BallEngine
******************************************************************************/

#ifndef BALLENGINE_LOGHELPER_H
#define BALLENGINE_LOGHELPER_H

#include "../Header/Define.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

#include "../Header/SingletonClassDefine.h"

#ifdef WIN32
#include <windows.h>
#endif

enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERR
};

class LogHelper {
CLASS_OPTION:
    SINGLETON_CLASS(LogHelper)
private:
    std::ofstream logFile;
    bool outputToFile = false;
    bool outputToDebug = true;
    std::string logFilePath;

    ~LogHelper();

    std::string levelToString(LogLevel level);

    void writeToFile(const std::string &formattedMessage);

    void writeToDebug(const std::string &formattedMessage);

CLASS_INTERFACE:
    void initialize(const std::string &filePath = "", bool fileOutput = false, bool debugOutput = true);

    void setOutputToFile(bool enable);

    void setOutputToDebug(bool enable);

    void setLogFilePath(const std::string &path);

    void log(LogLevel level, const std::string &message);

    void debug(const std::string &message);

    void info(const std::string &message);

    void warning(const std::string &message);

    void error(const std::string &message);

    void close();
};

#endif //BALLENGINE_LOGHELPER_H
