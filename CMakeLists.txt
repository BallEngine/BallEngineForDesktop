cmake_minimum_required(VERSION 3.13)
project(BallEngine4CPP)

set(CMAKE_CXX_STANDARD 11)

add_library(BallEngine4CPP define.h
        Other/BString.cpp Other/BString.h
        Other/BImage.cpp Other/BImage.h
        Template/Manager.cpp Template/Manager.h
        Template/BallEngine.cpp Template/BallEngine.h
        Template/SystemInterface.cpp Template/SystemInterface.h
        Manager/ScriptManager.cpp Manager/ScriptManager.h
        Manager/AudioManager.cpp Manager/AudioManager.h
        Manager/PasterManager.cpp Manager/PasterManager.h
        Helper/NetHelper.cpp Helper/NetHelper.h
        Helper/INFHelper.cpp Helper/INFHelper.h
        PlatformInterface/GLInterface.cpp PlatformInterface/GLInterface.h
        PlatformInterface/QtInterface.cpp PlatformInterface/QtInterface.h Other/BThread.cpp Other/BThread.h)
