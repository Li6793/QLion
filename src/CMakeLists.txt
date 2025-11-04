# 1. 先添加所有模块子目录（每个模块编译成静态库）
add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(model)
add_subdirectory(config)

# 2. 编译主程序（main.cpp是入口）
find_package(Qt6 REQUIRED COMPONENTS Core)


find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)


add_executable(MainApp
    main.cpp
    core/dataprocess/logger.h core/dataprocess/logger.cpp
    #${CMAKE_SOURCE_DIR}/res/resources.qrc
)

# 3. 为主程序链接依赖（Qt库+自定义模块库）
target_link_libraries(MainApp
    PRIVATE
        Qt6::Widgets  # Qt界面库
        Qt6::Core     # Qt核心库
        Qt6::Gui      # Qt图形库
        CoreModule    # 自定义core模块（静态库）
        UIModule      # 自定义ui模块（静态库）
        ModelModule   # 自定义model模块（静态库）
        ConfigModule  # 自定义config模块（静态库）
        # 第三方库（如有，直接写库名，如：libxxx.a 写 xxx）
)
target_link_libraries(MainApp PRIVATE Qt6::Core)
target_link_libraries(MainApp PRIVATE Qt6::Core)
target_link_libraries(MainApp PRIVATE Qt6::Core)
target_link_libraries(MainApp PRIVATE Qt6::Core Qt6::Widgets)

# 4. 主程序头文件路径（包含各模块的头文件）
target_include_directories(MainApp
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/core
        ${CMAKE_CURRENT_SOURCE_DIR}/ui
        ${CMAKE_CURRENT_SOURCE_DIR}/model
        ${CMAKE_CURRENT_SOURCE_DIR}/config
)
