cmake_minimum_required(VERSION 3.21)
project(BallEngine)

set(CMAKE_CXX_STANDARD 14)
set(INC_DIR ./Library/include/)
set(LINK_DIR ./Library/library/)

include_directories(${INC_DIR})
link_directories(${LINK_DIR} )

add_executable(BallEngine main.cpp Core/define.h
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
    set(CMAKE_LIBRARY_PATH "C:\\Windows\\System32\\")
    target_link_libraries(BallEngine ws2_32 SDL2)
endif ()
