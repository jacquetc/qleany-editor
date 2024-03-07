# SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)

project(qleany-editor VERSION 0.1)

include(FeatureSummary)

set(QT6_MIN_VERSION 6.5.0)
set(KF6_MIN_VERSION 6.0.0)

find_package(ECM ${KF6_MIN_VERSION} REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH})

include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMSetupVersion)
include(ECMFindQmlModule)

if(NOT ANDROID)
    include(KDEGitCommitHooks)
    include(KDEClangFormat)
endif()

remove_definitions(
    -DQT_NO_CAST_FROM_ASCII
    -DQT_NO_CAST_TO_ASCII
    -DQT_NO_CAST_FROM_BYTEARRAY
    -DQT_NO_KEYWORDS
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add -fexceptions
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

ecm_setup_version(${PROJECT_VERSION}
    VARIABLE_PREFIX QLEANY_EDITOR
    VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/src/ui/kirigami/version-qleany-editor.h"
)

set(QT_EXTRA_COMPONENTS)

if(NOT ANDROID)
    list(APPEND QT_EXTRA_COMPONENTS Widgets)
endif()

find_package(Qt6 ${QT6_MIN_VERSION} REQUIRED COMPONENTS Core Gui Qml QuickControls2 Svg Concurrent Sql ${QT_EXTRA_COMPONENTS})
find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS Kirigami2 CoreAddons Config I18n)
find_package(QCoro6 REQUIRED COMPONENTS Core Qml)

qt_policy(SET QTP0001 NEW)

ecm_find_qmlmodule(org.kde.kirigamiaddons.formcard 1.0)

if(ANDROID)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/android/version.gradle.in ${CMAKE_BINARY_DIR}/version.gradle)
endif()

# handles the entities
add_subdirectory(src/core/entities/)

# stores the interfaces
add_subdirectory(src/core/contracts)

# handles the data access from inside the system
add_subdirectory(src/core/persistence/)

# handles the data access from outside the system
add_subdirectory(src/core/contracts.dto)

# handles the CQRS commands, queries and validators
add_subdirectory(src/core/contracts.cqrs)

# handles the use cases
add_subdirectory(src/core/application)

# handles the interaction between the system's inner layers (use cases, DTOs)
# and the external world
add_subdirectory(src/core/interactor/)

# handles the Qt models
add_subdirectory(src/ui/presenter)

add_subdirectory(src/ui/kirigami)

install(FILES org.kde.qleany-editor.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES org.kde.qleany-editor.metainfo.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
ki18n_install(po)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

if(NOT ANDROID)
    file(GLOB_RECURSE ALL_CLANG_FORMAT_SOURCE_FILES src/*.cpp src/*.h)
    kde_clang_format(${ALL_CLANG_FORMAT_SOURCE_FILES})
    kde_configure_git_pre_commit_hook(CHECKS CLANG_FORMAT)
endif()
