cmake_minimum_required(VERSION 3.21)
project(BallEngine4CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

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
        Helper/HTTPHelper.h Helper/HTTPHelper.cpp
        PlatformInterface/GLInterface.h PlatformInterface/GLInterface.cpp
        PlatformInterface/QtInterface.h PlatformInterface/QtInterface.cpp)

target_link_libraries(BallEngine4CPP
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)
    set(CMAKE_LIBRARY_PATH "C:\\Windows\\System32\\")
    target_link_libraries(BallEngine4CPP ws2_32)
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
