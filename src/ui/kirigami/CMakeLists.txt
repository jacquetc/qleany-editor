# SPDX-License-Identifier: BSD-2-Clause SPDX-FileCopyrightText: %{CURRENT_YEAR}
# %{AUTHOR} <%{EMAIL}>

option(BUILD_WITH_MOCKS "Build with mocks" OFF)

# Target: static library
qt_add_qml_module(
  qleany-editor_static
  STATIC
  URI
  org.kde.qleanyeditor
  VERSION
  1.0
  QML_FILES
  contents/ui/Main.qml
  contents/ui/About.qml
  contents/ui/Index.qml
  contents/ui/WelcomePage.qml
  SOURCES
  app.cpp)

qcoro_enable_coroutines()

target_link_libraries(qleany-editor_static PUBLIC qleany-editor-entities)
target_link_libraries(qleany-editor_static PUBLIC qleany-editor-persistence)
target_link_libraries(qleany-editor_static PUBLIC qleany-editor-interactor)
target_link_libraries(qleany-editor_static PUBLIC qleany-editor-presenter)
target_link_libraries(qleany-editor_static PRIVATE QCoro::Core QCoro::Qml)
target_link_libraries(
  qleany-editor_static
  PUBLIC Qt6::Core
         Qt6::Gui
         Qt6::Qml
         Qt6::Quick
         Qt6::QuickControls2
         Qt6::Svg
         Qt6::Concurrent
         KF6::I18n
         KF6::CoreAddons
         KF6::ConfigCore
         KF6::ConfigGui)
target_include_directories(qleany-editor_static PUBLIC ${CMAKE_BINARY_DIR})

if(NOT BUILD_WITH_MOCKS)
  include(${CMAKE_CURRENT_SOURCE_DIR}/realqmlmodules.cmake)
endif()

if(ANDROID)
  kirigami_package_breeze_icons(ICONS list-add help-about application-exit
                                applications-graphics)
else()
  target_link_libraries(qleany-editor_static PUBLIC Qt::Widgets)
endif()

kconfig_add_kcfg_files(qleany-editor_static GENERATE_MOC
                       qleany-editorconfig.kcfgc)

# Target: main executable
add_executable(qleany-editor main.cpp)

if(BUILD_WITH_MOCKS)
  # copy mock_imports in binary folder
  file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/mock_imports
       DESTINATION ${CMAKE_BINARY_DIR}/bin)
  target_compile_definitions(qleany-editor PRIVATE BUILD_WITH_MOCKS)
endif()

target_link_libraries(qleany-editor PUBLIC qleany-editor_static
                                           qleany-editor_staticplugin)
install(TARGETS qleany-editor ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
