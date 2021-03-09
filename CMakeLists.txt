cmake_minimum_required(VERSION 3.7)

project(badCalc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_FIND_DEBUG_MODE TRUE)
# find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# add_subdirectory(vendor)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        include/mainwindow.h
        src/calculator.cpp
        include/calculator.h
        src/mainwindow.ui
)

add_executable(badCalc ${PROJECT_SOURCES})

target_include_directories(badCalc PRIVATE include)
target_link_libraries(badCalc PRIVATE Qt5::Widgets)
