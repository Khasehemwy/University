cmake_minimum_required(VERSION 3.5)

project(untitled LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES untitled_zh_CN.ts)

if(ANDROID)
  add_library(untitled SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    multiadd.cpp
    multiadd.h
    multiadd.ui
    Include.h
    Class.h
    Class.cpp
    singleadd.cpp
    singleadd.h
    singleadd.ui
    modifyname.cpp
    modifyname.h
    modifyname.ui
    ${TS_FILES}
  )
else()
  add_executable(untitled WIN32
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    multiadd.cpp
    multiadd.h
    multiadd.ui
    Include.h
    Class.h
    Class.cpp
    singleadd.cpp
    singleadd.h
    singleadd.ui
    modifyname.cpp
    modifyname.h
    modifyname.ui
    removecity.cpp
    removecity.h
    removecity.ui
    addpath.cpp
    addpath.h
    addpath.ui
    mincost.cpp
    mincost.h
    mincost.ui
    mincostans.cpp
    mincostans.h
    mincostans.ui
    mindist.cpp
    mindist.h
    mindist.ui
    mindistans.cpp
    mindistans.h
    mindistans.ui
    ${TS_FILES}
  )
endif()

target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
