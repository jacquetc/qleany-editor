# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-dto-project)

set(SRC

    
    project/project_dto.h
    project/project_with_details_dto.h
    project/project_relation_dto.h
    project/load_project_dto.h
    project/save_project_dto.h
    project/create_project_dto.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )
                    
set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-interactor-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-entity-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-d-t-o-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-repository-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-global-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-presenter-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-application-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-c-q-r-s-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-front-end-component)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-contracts-component)

target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-interactor-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-entity-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-d-t-o-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-repository-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-global-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-presenter-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-application-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-c-q-r-s-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-front-end-component)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-contracts-component)


target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)