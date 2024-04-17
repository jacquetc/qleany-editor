# This file was generated automatically by Qleany's generator, edit at your own risk! 
# If you do, be careful to not overwrite it when you run the generator again.
find_package(Qt6 COMPONENTS Core Quick Qml REQUIRED)
find_package(QCoro6 REQUIRED COMPONENTS Core Qml)

set(PLUGIN_NAME qleany-editor-qml-interactors)

qt_add_library(${PLUGIN_NAME} STATIC)

qt6_add_qml_module(${PLUGIN_NAME}
    URI "Interactors"
    VERSION 1.0
    SOURCES
    
    foreign_root_interactor.h
    foreign_recent_project_interactor.h
    foreign_project_interactor.h
    foreign_global_component_interactor.h
    foreign_entity_component_interactor.h
    foreign_entity_interactor.h
    foreign_entity_field_interactor.h
    foreign_entity_parent_interactor.h
    foreign_repository_component_interactor.h
    foreign_repository_interactor.h
    foreign_interactor_component_interactor.h
    foreign_application_component_interactor.h
    foreign_application_feature_interactor.h
    foreign_c_r_u_d_interactor.h
    foreign_custom_command_interactor.h
    foreign_custom_d_t_o_interactor.h
    foreign_custom_d_t_o_field_interactor.h
    foreign_custom_query_interactor.h
    foreign_d_t_o_component_interactor.h
    foreign_c_q_r_s_component_interactor.h
    foreign_contracts_component_interactor.h
    foreign_presenter_component_interactor.h
    foreign_presenter_single_interactor.h
    foreign_presenter_list_model_interactor.h
    foreign_front_end_component_interactor.h
    foreign_event_dispatcher.h

)

target_link_libraries(${PLUGIN_NAME} PRIVATE qleany-editor-interactor)
target_link_libraries(${PLUGIN_NAME} PRIVATE QCoro::Core QCoro::Qml)

target_link_libraries(${PLUGIN_NAME}
    PRIVATE Qt6::Quick Qt6::Core Qt6::Qml
)