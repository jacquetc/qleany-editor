# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-cqrs-application-feature)

set(SRC

    
    application_feature/queries/get_application_feature_query.h
    application_feature/commands/create_application_feature_command.h
    application_feature/commands/update_application_feature_command.h
    application_feature/commands/remove_application_feature_command.h
    application_feature/validators/create_application_feature_command_validator.h
    application_feature/validators/update_application_feature_command_validator.h
    application_feature/validators/remove_application_feature_command_validator.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )

set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
        
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-contracts)
target_link_libraries(${LIBRARY_NAME} PRIVATE qleany-editor-entities)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-application-feature)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)