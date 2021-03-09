cmake_minimum_required(VERSION 3.7)

project(badCalc
  VERSION 0.0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

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

include(GNUInstallDirs)

if(NOT WIN32 AND CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(CMAKE_INSTALL_PREFIX "/opt/WaywardLlama/${PROJECT_NAME}")
endif()

install(TARGETS badCalc
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(WIN32)
  install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/dll/"
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    USE_SOURCE_PERMISSIONS
  )
endif()

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(CPACK_PACKAGE_NAME                    badCalc                      )
  set(CPACK_PACKAGE_VENDOR                  WaywardLlama                 )
  set(CPACK_PACKAGE_DESCRIPTION_SUMMARY     "A bad caculator"            )
  set(CPACK_PACKAGE_VERSION_MAJOR           ${PROJECT_VERSION_MAJOR}     )
  set(CPACK_PACKAGE_VERSION_MINOR           ${PROJECT_VERSION_MINOR}     )
  set(CPACK_PACKAGE_VERSION_PATCH           ${PROJECT_VERSION_PATCH}     )
  set(CPACK_PACKAGE_INSTALL_DIRECTORY       "badCalc"                    )
  set(CPACK_VERBATIM_VARIABLES              YES                          )
  set(CPACK_PACKAGE_DESCRIPTION
    "This calculator is very bad. Why have you installed it?"
  )
  set(CPACK_GENERATOR                       IFW                          )
  include(CPack)
endif()
