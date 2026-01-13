#include "LogHelper.h"
#include <chrono>
#include <iomanip>

void LogHelper::initialize(const std::string &filePath, bool fileOutput, bool debugOutput) {
    setOutputToFile(fileOutput);
    setOutputToDebug(debugOutput);
    if (!filePath.empty()) {
        setLogFilePath(filePath);
    }
}

void LogHelper::setOutputToFile(bool enable) {
    if (enable && !outputToFile) {
        if (logFilePath.empty()) {
            logFilePath = "ballengine.log";
        }
        logFile.open(logFilePath, std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "Failed to open log file: " << logFilePath << std::endl;
            outputToFile = false;
        } else {
            outputToFile = true;
        }
    } else if (!enable && outputToFile) {
        close();
        outputToFile = false;
    }
}

void LogHelper::setOutputToDebug(bool enable) {
    outputToDebug = enable;
}

void LogHelper::setLogFilePath(const std::string &path) {
    logFilePath = path;
    if (outputToFile) {
        if (logFile.is_open()) {
            logFile.close();
        }
        logFile.open(logFilePath, std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "Failed to open log file: " << logFilePath << std::endl;
            outputToFile = false;
        }
    }
}

void LogHelper::log(LogLevel level, const std::string &message) {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  now.time_since_epoch()) % 1000;

    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    ss << '.' << std::setfill('0') << std::setw(3) << ms.count();

    std::string timestamp = ss.str();
    std::string levelStr = levelToString(level);
    std::string formattedMessage = "[" + timestamp + "] [" + levelStr + "] " + message;

    if (outputToFile) {
        writeToFile(formattedMessage);
    }
    if (outputToDebug) {
        writeToDebug(formattedMessage);
    }
}

void LogHelper::debug(const std::string &message) {
    log(LogLevel::DEBUG, message);
}

void LogHelper::info(const std::string &message) {
    log(LogLevel::INFO, message);
}

void LogHelper::warning(const std::string &message) {
    log(LogLevel::WARN, message);
}

void LogHelper::error(const std::string &message) {
    log(LogLevel::ERR, message);
}

void LogHelper::writeToFile(const std::string &formattedMessage) {
    if (logFile.is_open()) {
        logFile << formattedMessage << std::endl;
        logFile.flush(); // 确保立即写入
    }
}

void LogHelper::writeToDebug(const std::string &formattedMessage) {
#ifdef _WIN32
    OutputDebugStringA((formattedMessage + "\n").c_str());
#else
    std::cout << formattedMessage << std::endl;
#endif
}

std::string LogHelper::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARN: return "WARNING";
        case LogLevel::ERR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void LogHelper::close() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

LogHelper::~LogHelper() {
    close();
}
