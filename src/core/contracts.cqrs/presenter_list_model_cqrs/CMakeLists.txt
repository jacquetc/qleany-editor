# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-cqrs-presenter-list-model)

set(SRC

    
    presenter_list_model/queries/get_presenter_list_model_query.h
    presenter_list_model/commands/create_presenter_list_model_command.h
    presenter_list_model/commands/update_presenter_list_model_command.h
    presenter_list_model/commands/remove_presenter_list_model_command.h
    presenter_list_model/validators/create_presenter_list_model_command_validator.h
    presenter_list_model/validators/update_presenter_list_model_command_validator.h
    presenter_list_model/validators/remove_presenter_list_model_command_validator.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )

set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
        
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-presenter-list-model)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)