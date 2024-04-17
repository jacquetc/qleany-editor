# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-cqrs-entity-parent)

set(SRC

    
    entity_parent/queries/get_entity_parent_query.h
    entity_parent/commands/create_entity_parent_command.h
    entity_parent/commands/update_entity_parent_command.h
    entity_parent/commands/remove_entity_parent_command.h
    entity_parent/validators/create_entity_parent_command_validator.h
    entity_parent/validators/update_entity_parent_command_validator.h
    entity_parent/validators/remove_entity_parent_command_validator.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )

set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
        
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-entity-parent)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)