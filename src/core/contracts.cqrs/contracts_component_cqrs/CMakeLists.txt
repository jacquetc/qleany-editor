# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-cqrs-contracts-component)

set(SRC

    
    contracts_component/queries/get_contracts_component_query.h
    contracts_component/commands/create_contracts_component_command.h
    contracts_component/commands/update_contracts_component_command.h
    contracts_component/commands/remove_contracts_component_command.h
    contracts_component/validators/create_contracts_component_command_validator.h
    contracts_component/validators/update_contracts_component_command_validator.h
    contracts_component/validators/remove_contracts_component_command_validator.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )

set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
        
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-contracts-component)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)