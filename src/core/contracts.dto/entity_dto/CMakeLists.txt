# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-dto-entity)

set(SRC

    
    entity/entity_dto.h
    entity/entity_with_details_dto.h
    entity/create_entity_dto.h
    entity/update_entity_dto.h
    entity/entity_relation_dto.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )
                    
set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-entity-field)
add_dependencies(${LIBRARY_NAME} qleany-editor-contracts-dto-entity-parent)

target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-entity-field)
target_link_libraries(${LIBRARY_NAME} PUBLIC qleany-editor-contracts-dto-entity-parent)


target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)