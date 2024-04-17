# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-dto-presenter-list-model)

set(SRC

    
    presenter_list_model/presenter_list_model_dto.h
    presenter_list_model/presenter_list_model_with_details_dto.h
    presenter_list_model/create_presenter_list_model_dto.h
    presenter_list_model/update_presenter_list_model_dto.h
    presenter_list_model/presenter_list_model_relation_dto.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )
                    
set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-entity)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-entity-field)

target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-entity)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-entity-field)


target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)