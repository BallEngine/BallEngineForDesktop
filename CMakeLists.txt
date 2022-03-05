cmake_minimum_required(VERSION 3.21)
project(BallEngine4CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.2.2/mingw_64")

add_library(BallEngine4CPP main.cpp Core/define.h
        BaseType/BString.cpp BaseType/BString.h
        BaseType/BImage.cpp BaseType/BImage.h
        Core/Manager.cpp Core/Manager.h
        Core/BallEngine.cpp Core/BallEngine.h
        Core/SystemInterface.cpp Core/SystemInterface.h
        Manager/ScriptManager.cpp Manager/ScriptManager.h
        Manager/AudioManager.cpp Manager/AudioManager.h
        Manager/PasterManager.cpp Manager/PasterManager.h
        Helper/NetHelper.cpp Helper/NetHelper.h
        Helper/INFHelper.cpp Helper/INFHelper.h
        PlatformInterface/GLInterface.cpp PlatformInterface/GLInterface.h
        PlatformInterface/QtInterface.cpp PlatformInterface/QtInterface.h BaseType/BThread.cpp BaseType/BThread.h Helper/LogHelper.cpp Helper/LogHelper.h Helper/HTTPHelper.cpp Helper/HTTPHelper.h BaseType/BPaster.cpp BaseType/BPaster.h)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(BallEngine4CPP
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
