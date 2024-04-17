// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component.h"
#include "application_feature.h"
#include "c_q_r_s_component.h"
#include "c_r_u_d.h"
#include "common_parent.h"
#include "contracts_component.h"
#include "custom_command.h"
#include "custom_d_t_o.h"
#include "custom_d_t_o_field.h"
#include "custom_query.h"
#include "d_t_o_component.h"
#include "entity.h"
#include "entity_component.h"
#include "entity_field.h"
#include "entity_parent.h"
#include "front_end_component.h"
#include "global_component.h"
#include "interactor_component.h"
#include "presenter_component.h"
#include "presenter_list_model.h"
#include "presenter_single.h"
#include "project.h"
#include "recent_project.h"
#include "repository.h"
#include "repository_component.h"
#include "root.h"

#include <QObject>

namespace QleanyEditor::Entities
{

class EntitiesRegistration : public QObject
{
    Q_OBJECT
public:
    explicit EntitiesRegistration(QObject *parent)
        : QObject(parent)
    {
        qRegisterMetaType<QleanyEditor::Entities::CommonParent>("QleanyEditor::Entities::CommonParent");
        qRegisterMetaType<QleanyEditor::Entities::Root>("QleanyEditor::Entities::Root");
        qRegisterMetaType<QleanyEditor::Entities::RecentProject>("QleanyEditor::Entities::RecentProject");
        qRegisterMetaType<QleanyEditor::Entities::Project>("QleanyEditor::Entities::Project");
        qRegisterMetaType<QleanyEditor::Entities::GlobalComponent>("QleanyEditor::Entities::GlobalComponent");
        qRegisterMetaType<QleanyEditor::Entities::EntityComponent>("QleanyEditor::Entities::EntityComponent");
        qRegisterMetaType<QleanyEditor::Entities::Entity>("QleanyEditor::Entities::Entity");
        qRegisterMetaType<QleanyEditor::Entities::EntityParent>("QleanyEditor::Entities::EntityParent");
        qRegisterMetaType<QleanyEditor::Entities::EntityField>("QleanyEditor::Entities::EntityField");
        qRegisterMetaType<QleanyEditor::Entities::RepositoryComponent>("QleanyEditor::Entities::RepositoryComponent");
        qRegisterMetaType<QleanyEditor::Entities::Repository>("QleanyEditor::Entities::Repository");
        qRegisterMetaType<QleanyEditor::Entities::InteractorComponent>("QleanyEditor::Entities::InteractorComponent");
        qRegisterMetaType<QleanyEditor::Entities::ApplicationComponent>("QleanyEditor::Entities::ApplicationComponent");
        qRegisterMetaType<QleanyEditor::Entities::ApplicationFeature>("QleanyEditor::Entities::ApplicationFeature");
        qRegisterMetaType<QleanyEditor::Entities::CRUD>("QleanyEditor::Entities::CRUD");
        qRegisterMetaType<QleanyEditor::Entities::CustomCommand>("QleanyEditor::Entities::CustomCommand");
        qRegisterMetaType<QleanyEditor::Entities::CustomDTO>("QleanyEditor::Entities::CustomDTO");
        qRegisterMetaType<QleanyEditor::Entities::CustomDTOField>("QleanyEditor::Entities::CustomDTOField");
        qRegisterMetaType<QleanyEditor::Entities::CustomQuery>("QleanyEditor::Entities::CustomQuery");
        qRegisterMetaType<QleanyEditor::Entities::DTOComponent>("QleanyEditor::Entities::DTOComponent");
        qRegisterMetaType<QleanyEditor::Entities::CQRSComponent>("QleanyEditor::Entities::CQRSComponent");
        qRegisterMetaType<QleanyEditor::Entities::ContractsComponent>("QleanyEditor::Entities::ContractsComponent");
        qRegisterMetaType<QleanyEditor::Entities::PresenterComponent>("QleanyEditor::Entities::PresenterComponent");
        qRegisterMetaType<QleanyEditor::Entities::PresenterSingle>("QleanyEditor::Entities::PresenterSingle");
        qRegisterMetaType<QleanyEditor::Entities::PresenterListModel>("QleanyEditor::Entities::PresenterListModel");
        qRegisterMetaType<QleanyEditor::Entities::FrontEndComponent>("QleanyEditor::Entities::FrontEndComponent");
    }
};

} // namespace QleanyEditor::Entities