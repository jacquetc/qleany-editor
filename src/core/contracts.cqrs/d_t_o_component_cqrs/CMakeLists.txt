# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-cqrs-d-t-o-component)

set(SRC

    
    d_t_o_component/queries/get_d_t_o_component_query.h
    d_t_o_component/commands/create_d_t_o_component_command.h
    d_t_o_component/commands/update_d_t_o_component_command.h
    d_t_o_component/commands/remove_d_t_o_component_command.h
    d_t_o_component/validators/create_d_t_o_component_command_validator.h
    d_t_o_component/validators/update_d_t_o_component_command_validator.h
    d_t_o_component/validators/remove_d_t_o_component_command_validator.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )

set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
        
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-d-t-o-component)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)