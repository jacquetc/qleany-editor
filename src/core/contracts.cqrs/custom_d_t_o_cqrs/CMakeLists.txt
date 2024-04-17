# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-cqrs-custom-d-t-o)

set(SRC

    
    custom_d_t_o/queries/get_custom_d_t_o_query.h
    custom_d_t_o/commands/create_custom_d_t_o_command.h
    custom_d_t_o/commands/update_custom_d_t_o_command.h
    custom_d_t_o/commands/remove_custom_d_t_o_command.h
    custom_d_t_o/validators/create_custom_d_t_o_command_validator.h
    custom_d_t_o/validators/update_custom_d_t_o_command_validator.h
    custom_d_t_o/validators/remove_custom_d_t_o_command_validator.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )

set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
        
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-custom-d-t-o)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)