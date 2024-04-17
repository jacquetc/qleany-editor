# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-dto-application-feature)

set(SRC

    
    application_feature/application_feature_dto.h
    application_feature/application_feature_with_details_dto.h
    application_feature/create_application_feature_dto.h
    application_feature/update_application_feature_dto.h
    application_feature/application_feature_relation_dto.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )
                    
set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-custom-command)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-entity)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-c-r-u-d)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-custom-query)

target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-custom-command)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-entity)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-c-r-u-d)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-custom-query)


target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)