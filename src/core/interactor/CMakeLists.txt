# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core Gui REQUIRED)
find_package(QCoro6 REQUIRED COMPONENTS Core)
find_package(qleany CONFIG REQUIRED) 

set(LIBRARY_NAME qleany-editor-interactor)

option(BUILD_SHARED_LIBS "Build libraries as shared libraries" ON)

if(BUILD_SHARED_LIBS)
    set(LIB_TYPE SHARED)
else()
    set(LIB_TYPE STATIC)
endif()


include(interactors.cmake)

set(SRCS
    qleany_editor_interactor_export.h
    event_dispatcher.h
    event_dispatcher.cpp
    interactor_registration.h
    error_signals.h
    progress_signals.h
    interactor_registration.cpp
)

qt_add_library(${LIBRARY_NAME} ${LIB_TYPE} ${SRCS} ${INTERACTOR_LIST})

include(GenerateExportHeader)
generate_export_header(${LIBRARY_NAME}
    BASE_NAME qleany_editor_interactor)

target_include_directories(${LIBRARY_NAME} PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_BINARY_DIR}

)

target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-root)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-recent-project)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-project)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-global-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-entity-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-entity)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-entity-field)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-entity-parent)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-repository-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-repository)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-interactor-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-application-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-application-feature)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-c-r-u-d)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-custom-command)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-custom-d-t-o)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-custom-d-t-o-field)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-custom-query)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-d-t-o-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-c-q-r-s-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-contracts-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-presenter-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-presenter-single)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-presenter-list-model)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-application-feature-front-end-component)
target_link_libraries(${LIBRARY_NAME} PRIVATE
    Qt6::Core Qt6::Gui)
target_link_libraries(${LIBRARY_NAME} PRIVATE QCoro::Core)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany)

if(IOS)
    install(TARGETS ${LIBRARY_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif(IOS)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    install(TARGETS ${LIBRARY_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif(CMAKE_SYSTEM_NAME STREQUAL "Linux")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    install(TARGETS ${LIBRARY_NAME}
        RUNTIME DESTINATION ${BINDIR}
        LIBRARY DESTINATION ${LIBDIR})
endif(CMAKE_SYSTEM_NAME STREQUAL "Windows")