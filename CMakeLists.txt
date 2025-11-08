cmake_minimum_required(VERSION 3.16)

project(QLion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Qt6_DIR "C:/Qt/6.9.2/msvc2022_64/lib/cmake/Qt6")
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)
message(STATUS "Qt6 Core Found: ${Qt6Core_FOUND}")
message(STATUS "Qt6 Core Include Dir: ${Qt6Core_INCLUDE_DIRS}")



set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


include(GNUInstallDirs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

file(GLOB RES_FILES "res/*")

file(GLOB_RECURSE RES_RAW_FILES
    ${CMAKE_SOURCE_DIR}/res/images/*
    ${CMAKE_SOURCE_DIR}/res/qss/*
    ${CMAKE_SOURCE_DIR}/res/configs/*
)

set(QRC_FILE ${CMAKE_BINARY_DIR}/auto_global_resources.qrc)
file(WRITE ${QRC_FILE} "<RCC>\n    <qresource prefix=\"/\">\n")
foreach(FILE ${RES_RAW_FILES})
    file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR}/res ${FILE})
    file(APPEND ${QRC_FILE} "        <file>${REL_PATH}</file>\n")
endforeach()
file(APPEND ${QRC_FILE} "    </qresource>\n</RCC>")


add_library(GlobalResources STATIC ${QRC_FILE})

target_link_libraries(GlobalResources PRIVATE Qt6::Core Qt6::Gui)

target_include_directories(GlobalResources PUBLIC ${CMAKE_SOURCE_DIR}/res)


add_library(GlobalDependencies INTERFACE)



target_link_libraries(GlobalDependencies INTERFACE
    GlobalResources
    Qt6::Core
    Qt6::Gui
)

target_include_directories(GlobalDependencies INTERFACE
    ${CMAKE_SOURCE_DIR}/src
)



include_directories(${CMAKE_SOURCE_DIR}/3rdparty/include)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/lib)


add_subdirectory(src)
