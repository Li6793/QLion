add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(model)
add_subdirectory(config)


find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

set(GLOBAL_RESOURCES
    ${PROJECT_ROOT}/src/res/resources.qrc
)
add_executable(QLion
    main.cpp
    ${GLOBAL_RESOURCES}
)


target_link_libraries(QLion
    PRIVATE
        Qt6::Widgets
        Qt6::Core
        Qt6::Gui
        Qt6::Network
        CoreModule
        UIModule
        ModelModule
        ConfigModule
)

target_link_libraries(QLion PRIVATE Qt6::Core Qt6::Widgets)

target_include_directories(QLion
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/core
        ${CMAKE_CURRENT_SOURCE_DIR}/ui
        ${CMAKE_CURRENT_SOURCE_DIR}/model
        ${CMAKE_CURRENT_SOURCE_DIR}/config
)

function(qt_deploy_target target)
    if(WIN32)
        find_program(WINDEPLOYQT_EXE windeployqt
            HINTS
                "C:/Qt/6.9.2/msvc2022_64/bin"
                "${QT_BIN_DIR}"
                "$ENV{QTDIR}/bin"
        )
        if(WINDEPLOYQT_EXE)

            if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR
               (DEFINED CMAKE_CONFIGURATION_TYPES AND "Debug" IN_LIST CMAKE_CONFIGURATION_TYPES))
                set(DEPLOY_MODE --debug)
            else()
                set(DEPLOY_MODE --release)
            endif()

            add_custom_command(TARGET ${target} POST_BUILD
                COMMAND ${WINDEPLOYQT_EXE}
                    --verbose 1
                    ${DEPLOY_MODE}
                    --no-compiler-runtime
                    --dir $<TARGET_FILE_DIR:${target}>
                    $<TARGET_FILE:${target}>
                VERBATIM
                COMMENT "64位Qt依赖部署完成：$<TARGET_FILE_DIR:${target}>"
            )
        else()
            message(FATAL_ERROR "未找到64位windeployqt，请检查Qt 64位版本是否安装")
        endif()
    endif()
endfunction()


qt_deploy_target(${PROJECT_NAME})
