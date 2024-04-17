# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-application-feature-application-component)

option(BUILD_SHARED_LIBS "Build libraries as shared libraries" ON)

if(BUILD_SHARED_LIBS)
    set(LIB_TYPE SHARED)
else()
    set(LIB_TYPE STATIC)
endif()

set(SRC

    
    application_component/commands/create_application_component_command_handler.cpp
    application_component/commands/create_application_component_command_handler.h
    application_component/commands/remove_application_component_command_handler.cpp
    application_component/commands/remove_application_component_command_handler.h
    application_component/commands/update_application_component_command_handler.cpp
    application_component/commands/update_application_component_command_handler.h
    application_component/queries/get_application_component_query_handler.cpp
    application_component/queries/get_application_component_query_handler.h
    application_component/queries/get_application_component_with_details_query_handler.cpp
    application_component/queries/get_application_component_with_details_query_handler.h
)
qt_add_library(${LIBRARY_NAME} ${LIB_TYPE} ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_BINARY_DIR}
)

include(GenerateExportHeader)
generate_export_header(${LIBRARY_NAME}
    BASE_NAME qleany_editor_application_application_component)

target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-persistence)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-cqrs-application-component)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)

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