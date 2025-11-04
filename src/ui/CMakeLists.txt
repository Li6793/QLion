# 1. 收集UI模块源文件（包含.cpp/.h/.ui）
file(GLOB_RECURSE UI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.ui  # 新增：UI界面文件
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



# 2. 编译静态库（库名UIModule）
add_library(UIModule STATIC ${UI_SOURCES})

set_target_properties(UIModule PROPERTIES
    AUTOMOC ON  # 处理 Q_OBJECT 宏，生成 moc_*.cpp
    AUTOUIC ON  # 处理 .ui 文件，生成 ui_*.h（比如 MainWindow.ui 生成 ui_MainWindow.h）
    AUTORCC ON  # 处理资源文件（如果后续用到 res/resources.qrc，需添加到 UI_SOURCES）
)

# 3. 链接UI依赖（必须链接Qt Widgets库）
target_link_libraries(UIModule
    PRIVATE
        Qt6::Widgets  # UI模块核心依赖
        Qt6::Core
        Qt6::Gui
        CoreModule    # UI如需调用core模块，添加此依赖
)

# 4. 暴露UI模块头文件路径
target_include_directories(UIModule
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
