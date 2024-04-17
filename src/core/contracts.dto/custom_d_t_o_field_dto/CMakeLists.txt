# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.

find_package(Qt6 COMPONENTS Core  REQUIRED)

set(LIBRARY_NAME qleany-editor-contracts-dto-custom-d-t-o-field)

set(SRC

    
    custom_d_t_o_field/custom_d_t_o_field_dto.h
    custom_d_t_o_field/create_custom_d_t_o_field_dto.h
    custom_d_t_o_field/update_custom_d_t_o_field_dto.h
)
qt_add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${LIBRARY_NAME} PROPERTIES
                    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                    )
                    
set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)




target_link_libraries(${LIBRARY_NAME}
    PRIVATE Qt6::Core
)