CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
PROJECT(BallEngine)

SET(CMAKE_CXX_STANDARD 14)
SET(INC_DIR ./Library/include/)
SET(LINK_DIR ./Library/library/)

INCLUDE_DIRECTORIES(${INC_DIR})
LINK_DIRECTORIES(${LINK_DIR})

ADD_EXECUTABLE(BallEngine main.cpp Core/define.h
        BaseType/BThread.h BaseType/BThread.cpp
        ComplexType/BPaster.h ComplexType/BPaster.cpp
        Core/Manager.h Core/Manager.cpp
        Core/BallEngine.h Core/BallEngine.cpp
        Manager/ScriptManager.h Manager/ScriptManager.cpp
        Manager/AudioManager.h Manager/AudioManager.cpp
        Manager/PasterManager.h Manager/PasterManager.cpp
        Manager/GameManager.h Manager/GameManager.cpp
        Helper/NetHelper.h Helper/NetHelper.cpp
        Helper/LogHelper.h Helper/LogHelper.cpp
        ComplexType/BWindow.cpp ComplexType/BWindow.h)

if (WIN32)
    SET(CMAKE_LIBRARY_PATH "C:\\Windows\\System32\\")
    TARGET_LINK_LIBRARIES(BallEngine ws2_32 SDL2)
endif ()
