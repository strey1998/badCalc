cmake_minimum_required(VERSION 3.7)

project(badCalc
  VERSION 0.0.2
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

set(REQUIRED_QT_DLLS Qt5Core Qt5Widgets Qt5Gui)

if(WIN32)
  add_custom_command(TARGET badCalc POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
      "${Qt5_DIR}/../../../plugins/platforms"
      "$<TARGET_FILE_DIR:badCalc>/platforms/"
  )

  foreach(DLL_NAME IN LISTS REQUIRED_QT_DLLS)
    add_custom_command(TARGET badCalc POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${Qt5_DIR}/../../../bin/${DLL_NAME}.dll"
        $<TARGET_FILE_DIR:badCalc>
    )
  endforeach()
endif()

# message("Message: $<1:Hello> $<0:World>")
# file(COPY "${Qt5_DIR}/../../../plugins/platforms/" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>)
# message(WARNING "BIN: ${CMAKE_CURRENT_BINARY_DIR}")

include(GNUInstallDirs)

if(NOT WIN32 AND CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(CMAKE_INSTALL_PREFIX "/opt/WaywardLlama/${PROJECT_NAME}")
endif()

install(TARGETS badCalc
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(WIN32)
  install(DIRECTORY "${Qt5_DIR}/../../../plugins/platforms"
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    USE_SOURCE_PERMISSIONS
  )
  foreach(DLL_NAME IN LISTS REQUIRED_QT_DLLS)
    install(PROGRAMS "${Qt5_DIR}/../../../bin/${DLL_NAME}.dll"
      DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
  endforeach()
endif()

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(CPACK_PACKAGE_NAME                    badCalc                                     )
  set(CPACK_PACKAGE_VENDOR                  WaywardLlama                                )
  set(CPACK_PACKAGE_DESCRIPTION_SUMMARY     "A bad caculator"                           )
  set(CPACK_PACKAGE_VERSION_MAJOR           ${PROJECT_VERSION_MAJOR}                    )
  set(CPACK_PACKAGE_VERSION_MINOR           ${PROJECT_VERSION_MINOR}                    )
  set(CPACK_PACKAGE_VERSION_PATCH           ${PROJECT_VERSION_PATCH}                    )
  set(CPACK_PACKAGE_INSTALL_DIRECTORY       "badCalc"                                   )
  set(CPACK_VERBATIM_VARIABLES              YES                                         )
  set(CPACK_RESOURCE_FILE_LICENSE           ${CMAKE_CURRENT_LIST_DIR}/LICENSE.txt       )
  set(CPACK_PACKAGE_DESCRIPTION
    "This calculator is very bad. Why have you installed it?"
  )
  if(WIN32)
    set(CPACK_GENERATOR                     WIX                                         )
  else()
    set(CPACK_GENERATOR                     IFW                                         )
  endif()
  include(CPack)
endif()
