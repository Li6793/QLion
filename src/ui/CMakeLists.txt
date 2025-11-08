file(GLOB_RECURSE UI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow/*.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/*.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/widgets/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/widgets/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/widgets/*.ui
)



find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_library(UIModule STATIC ${UI_SOURCES})

set_target_properties(UIModule PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

target_link_libraries(UIModule
    PRIVATE
        Qt6::Widgets
        Qt6::Core
        Qt6::Gui
        CoreModule
        GlobalDependencies
)
target_link_libraries(UIModule PRIVATE Qt6::Core Qt6::Widgets)
target_link_libraries(UIModule PRIVATE Qt6::Core Qt6::Widgets)
target_link_libraries(UIModule PRIVATE Qt6::Core Qt6::Widgets)

target_include_directories(UIModule
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
