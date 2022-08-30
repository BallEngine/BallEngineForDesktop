cmake_minimum_required(VERSION 3.21)
project(BallEngine4CPP)

set(CMAKE_CXX_STANDARD 14)
set(INC_DIR ./Library/include/)
set(LINK_DIR ./Library/library/)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})

add_executable(BallEngine4CPP main.cpp Core/define.h
        BaseType/BImage.h BaseType/BImage.cpp
        BaseType/BThread.h BaseType/BThread.cpp
        ComplexType/BPaster.h ComplexType/BPaster.cpp
        Core/Manager.h Core/Manager.cpp
        Core/BallEngine.h Core/BallEngine.cpp
        Core/SystemInterface.h Core/SystemInterface.cpp
        Manager/ScriptManager.h Manager/ScriptManager.cpp
        Manager/AudioManager.h Manager/AudioManager.cpp
        Manager/PasterManager.h Manager/PasterManager.cpp
        Manager/GameManager.h Manager/GameManager.cpp
        Helper/NetHelper.h Helper/NetHelper.cpp
        Helper/LogHelper.h Helper/LogHelper.cpp
        Helper/HTTPHelper.h Helper/HTTPHelper.cpp)

if (WIN32)
    set(CMAKE_LIBRARY_PATH "C:\\Windows\\System32\\")
    target_link_libraries(BallEngine4CPP ws2_32 sdl2)
endif ()
