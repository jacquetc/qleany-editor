# SPDX-License-Identifier: BSD-2-Clause
# SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

# Target: static library
qt_add_qml_module(qleany-editor_static
    STATIC
    URI org.kde.qleany-editor
    VERSION 1.0
    QML_FILES
    contents/ui/Main.qml
    contents/ui/About.qml
)

target_sources(qleany-editor_static PUBLIC
    app.cpp
)
qcoro_enable_coroutines()

target_link_libraries(qleany-editor_static PUBLIC qleany-editor-entities)
target_link_libraries(qleany-editor_static PUBLIC qleany-editor-persistence)
target_link_libraries(qleany-editor_static PUBLIC qleany-editor-interactor)
target_link_libraries(qleany-editor_static PUBLIC qleany-editor-presenter)
target_link_libraries(qleany-editor_static PRIVATE QCoro::Core QCoro::Qml)
target_link_libraries(qleany-editor_static PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Svg
    Qt6::Concurrent
    KF6::I18n
    KF6::CoreAddons
    KF6::ConfigCore
    KF6::ConfigGui
)
target_include_directories(qleany-editor_static PUBLIC ${CMAKE_BINARY_DIR})

include(${CMAKE_CURRENT_SOURCE_DIR}/realqmlmodules.cmake)

if(ANDROID)
    kirigami_package_breeze_icons(ICONS
        list-add
        help-about
        application-exit
        applications-graphics
    )
else()
    target_link_libraries(qleany-editor_static PUBLIC Qt::Widgets)
endif()

kconfig_add_kcfg_files(qleany-editor_static GENERATE_MOC qleany-editorconfig.kcfgc)

# Target: main executable
add_executable(qleany-editor main.cpp)
target_link_libraries(qleany-editor PUBLIC qleany-editor_static qleany-editor_staticplugin)
install(TARGETS qleany-editor ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
