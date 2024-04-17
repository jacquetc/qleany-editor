# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-application-feature-c-r-u-d)

option(BUILD_SHARED_LIBS "Build libraries as shared libraries" ON)

if(BUILD_SHARED_LIBS)
    set(LIB_TYPE SHARED)
else()
    set(LIB_TYPE STATIC)
endif()

set(SRC

    
    c_r_u_d/commands/create_c_r_u_d_command_handler.cpp
    c_r_u_d/commands/create_c_r_u_d_command_handler.h
    c_r_u_d/commands/remove_c_r_u_d_command_handler.cpp
    c_r_u_d/commands/remove_c_r_u_d_command_handler.h
    c_r_u_d/commands/update_c_r_u_d_command_handler.cpp
    c_r_u_d/commands/update_c_r_u_d_command_handler.h
    c_r_u_d/queries/get_c_r_u_d_query_handler.cpp
    c_r_u_d/queries/get_c_r_u_d_query_handler.h
    c_r_u_d/queries/get_c_r_u_d_with_details_query_handler.cpp
    c_r_u_d/queries/get_c_r_u_d_with_details_query_handler.h
)
qt_add_library(${LIBRARY_NAME} ${LIB_TYPE} ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_BINARY_DIR}
)

include(GenerateExportHeader)
generate_export_header(${LIBRARY_NAME}
    BASE_NAME qleany_editor_application_c_r_u_d)

target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-persistence)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-cqrs-c-r-u-d)

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