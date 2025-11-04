cmake_minimum_required(VERSION 3.16)

project(QLion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)
message(STATUS "Qt6 Core Found: ${Qt6Core_FOUND}")
message(STATUS "Qt6 Core Include Dir: ${Qt6Core_INCLUDE_DIRS}")
add_executable(QLion


    ${RES_FILES}
)
set_target_properties(QLion PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
)
include(GNUInstallDirs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

file(GLOB RES_FILES "res/*")
target_compile_definitions(QLion PRIVATE RES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/res/")
install(TARGETS QLion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include_directories(${CMAKE_SOURCE_DIR}/3rdparty/include)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/lib)


add_subdirectory(src)
