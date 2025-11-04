# 1. 收集core模块的所有源文件（递归包含子目录的.cpp/.h）
file(GLOB_RECURSE CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dataprocess/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dataprocess/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/communication/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/communication/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/*.h
)

# 2. 编译静态库
add_library(ConfigModule STATIC ${CORE_SOURCES})

# 3. 链接core模块依赖（如依赖Qt或第三方库，需添加）
target_link_libraries(ConfigModule
    PRIVATE
        Qt6::Core  # core模块如需Qt核心功能，添加此依赖
        # 第三方库（如有，如：xxx）
)

# 4. 暴露core模块的头文件路径（供其他模块引用）
target_include_directories(ConfigModule
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}  # 允许外部包含 "core/xxx.h"
)
