# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-cqrs-c-r-u-d)

set(SRC

    
    c_r_u_d/queries/get_c_r_u_d_query.h
    c_r_u_d/commands/create_c_r_u_d_command.h
    c_r_u_d/commands/update_c_r_u_d_command.h
    c_r_u_d/commands/remove_c_r_u_d_command.h
    c_r_u_d/validators/create_c_r_u_d_command_validator.h
    c_r_u_d/validators/update_c_r_u_d_command_validator.h
    c_r_u_d/validators/remove_c_r_u_d_command_validator.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )

set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
        
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-c-r-u-d)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)