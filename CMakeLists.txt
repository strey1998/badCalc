cmake_minimum_required(VERSION 3.5)

project(badCalc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_FIND_DEBUG_MODE TRUE)
# find_package(QT NAMES Qt6 COMPONENTS Widgets REQUIRED)
# find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_subdirectory(vendor)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        include/mainwindow.h
        src/calculator.cpp
        include/calculator.h
        src/mainwindow.ui
)

add_executable(badCalc ${PROJECT_SOURCES})

target_link_libraries(badCalc PRIVATE Qt6::Widgets)
