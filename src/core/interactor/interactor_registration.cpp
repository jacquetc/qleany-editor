// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "interactor_registration.h"
#include "application_component/application_component_interactor.h"
#include "application_feature/application_feature_interactor.h"
#include "c_q_r_s_component/c_q_r_s_component_interactor.h"
#include "c_r_u_d/c_r_u_d_interactor.h"
#include "contracts_component/contracts_component_interactor.h"
#include "custom_command/custom_command_interactor.h"
#include "custom_d_t_o/custom_d_t_o_interactor.h"
#include "custom_d_t_o_field/custom_d_t_o_field_interactor.h"
#include "custom_query/custom_query_interactor.h"
#include "d_t_o_component/d_t_o_component_interactor.h"
#include "entity/entity_interactor.h"
#include "entity_component/entity_component_interactor.h"
#include "entity_field/entity_field_interactor.h"
#include "entity_parent/entity_parent_interactor.h"
#include "event_dispatcher.h"
#include "front_end_component/front_end_component_interactor.h"
#include "global_component/global_component_interactor.h"
#include "interactor_component/interactor_component_interactor.h"
#include "presenter_component/presenter_component_interactor.h"
#include "presenter_list_model/presenter_list_model_interactor.h"
#include "presenter_single/presenter_single_interactor.h"
#include "project/project_interactor.h"
#include "recent_project/recent_project_interactor.h"
#include "repository/repository_interactor.h"
#include "repository_component/repository_component_interactor.h"
#include "root/root_interactor.h"
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>
#include <qleany/tools/undo_redo/undo_redo_scopes.h>

using namespace QleanyEditor::Interactor;

InteractorRegistration::InteractorRegistration(QObject *parent, InterfaceRepositoryProvider *repositoryProvider)
    : QObject{parent}
{
    auto dispatcher = QSharedPointer<EventDispatcher>(new EventDispatcher());

    // Undo Redo System
    Scopes scopes(QStringList() << "root"_L1
                                << "recentProject"_L1
                                << "project"_L1
                                << "globalComponent"_L1
                                << "entityComponent"_L1
                                << "entity"_L1
                                << "entityField"_L1
                                << "entityParent"_L1
                                << "repositoryComponent"_L1
                                << "repository"_L1
                                << "interactorComponent"_L1
                                << "applicationComponent"_L1
                                << "applicationFeature"_L1
                                << "cRUD"_L1
                                << "customCommand"_L1
                                << "customDTO"_L1
                                << "customDTOField"_L1
                                << "customQuery"_L1
                                << "dTOComponent"_L1
                                << "cQRSComponent"_L1
                                << "contractsComponent"_L1
                                << "presenterComponent"_L1
                                << "presenterSingle"_L1
                                << "presenterListModel"_L1
                                << "frontEndComponent"_L1);
    auto *undoRedoSystem = new Qleany::Tools::UndoRedo::ThreadedUndoRedoSystem(this, scopes);

    // error handling
    connect(undoRedoSystem, &Qleany::Tools::UndoRedo::ThreadedUndoRedoSystem::errorSent, this, [dispatcher](Qleany::Error error) {
        qDebug() << "Error in undo redo system: " << error.status() << error.code() << error.message() << error.data() << error.stackTrace();
        Q_EMIT dispatcher->error()->errorSent(error);
    });
    connect(undoRedoSystem, &Qleany::Tools::UndoRedo::ThreadedUndoRedoSystem::warningSent, this, [dispatcher](Qleany::Error error) {
        qDebug() << "Warning in undo redo system: " << error.status() << error.code() << error.message() << error.data() << error.stackTrace();
        Q_EMIT dispatcher->error()->warningSent(error);
    });

    // RootInteractor

    new Root::RootInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *rootSignalHolder = repositoryProvider->repository("Root")->signalHolder();

    // removal
    connect(rootSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->root(), &RootSignals::removed);

    // active status
    connect(repositoryProvider->repository("root")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->root(),
            &RootSignals::activeStatusChanged);

    // RecentProjectInteractor

    new RecentProject::RecentProjectInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *recentProjectSignalHolder = repositoryProvider->repository("RecentProject")->signalHolder();

    // removal
    connect(recentProjectSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->recentProject(), &RecentProjectSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(recentProjectSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        RootRelationDTO dto(-1, RootRelationDTO::RelationField::RecentProjects, removedIds, -1);
        Q_EMIT dispatcher->root()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("recentProject")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->recentProject(),
            &RecentProjectSignals::activeStatusChanged);

    // ProjectInteractor

    new Project::ProjectInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *projectSignalHolder = repositoryProvider->repository("Project")->signalHolder();

    // removal
    connect(projectSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->project(), &ProjectSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(projectSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        RootRelationDTO dto(-1, RootRelationDTO::RelationField::Project, removedIds, -1);
        Q_EMIT dispatcher->root()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("project")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->project(),
            &ProjectSignals::activeStatusChanged);

    // GlobalComponentInteractor

    new GlobalComponent::GlobalComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *globalComponentSignalHolder = repositoryProvider->repository("GlobalComponent")->signalHolder();

    // removal
    connect(globalComponentSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->globalComponent(),
            &GlobalComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(globalComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::GlobalComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("globalComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->globalComponent(),
            &GlobalComponentSignals::activeStatusChanged);

    // EntityComponentInteractor

    new EntityComponent::EntityComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *entityComponentSignalHolder = repositoryProvider->repository("EntityComponent")->signalHolder();

    // removal
    connect(entityComponentSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->entityComponent(),
            &EntityComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(entityComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::EntityComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("entityComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->entityComponent(),
            &EntityComponentSignals::activeStatusChanged);

    // EntityInteractor

    new Entity::EntityInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *entitySignalHolder = repositoryProvider->repository("Entity")->signalHolder();

    // removal
    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->entity(), &EntitySignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        EntityComponentRelationDTO dto(-1, EntityComponentRelationDTO::RelationField::Entities, removedIds, -1);
        Q_EMIT dispatcher->entityComponent()->relationRemoved(dto);
    });

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        RepositoryRelationDTO dto(-1, RepositoryRelationDTO::RelationField::Entity, removedIds, -1);
        Q_EMIT dispatcher->repository()->relationRemoved(dto);
    });

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ApplicationFeatureRelationDTO dto(-1, ApplicationFeatureRelationDTO::RelationField::DtoIdenticalToEntity, removedIds, -1);
        Q_EMIT dispatcher->applicationFeature()->relationRemoved(dto);
    });

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        CRUDRelationDTO dto(-1, CRUDRelationDTO::RelationField::EntityMappableWith, removedIds, -1);
        Q_EMIT dispatcher->cRUD()->relationRemoved(dto);
    });

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        CustomCommandRelationDTO dto(-1, CustomCommandRelationDTO::RelationField::Entities, removedIds, -1);
        Q_EMIT dispatcher->customCommand()->relationRemoved(dto);
    });

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        CustomQueryRelationDTO dto(-1, CustomQueryRelationDTO::RelationField::Entities, removedIds, -1);
        Q_EMIT dispatcher->customQuery()->relationRemoved(dto);
    });

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        PresenterSingleRelationDTO dto(-1, PresenterSingleRelationDTO::RelationField::Entity, removedIds, -1);
        Q_EMIT dispatcher->presenterSingle()->relationRemoved(dto);
    });

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        PresenterListModelRelationDTO dto(-1, PresenterListModelRelationDTO::RelationField::Entity, removedIds, -1);
        Q_EMIT dispatcher->presenterListModel()->relationRemoved(dto);
    });

    connect(entitySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        PresenterListModelRelationDTO dto(-1, PresenterListModelRelationDTO::RelationField::InRelationOf, removedIds, -1);
        Q_EMIT dispatcher->presenterListModel()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("entity")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->entity(),
            &EntitySignals::activeStatusChanged);

    // EntityFieldInteractor

    new EntityField::EntityFieldInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *entityFieldSignalHolder = repositoryProvider->repository("EntityField")->signalHolder();

    // removal
    connect(entityFieldSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->entityField(), &EntityFieldSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(entityFieldSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        EntityRelationDTO dto(-1, EntityRelationDTO::RelationField::Fields, removedIds, -1);
        Q_EMIT dispatcher->entity()->relationRemoved(dto);
    });

    connect(entityFieldSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        PresenterListModelRelationDTO dto(-1, PresenterListModelRelationDTO::RelationField::DisplayedField, removedIds, -1);
        Q_EMIT dispatcher->presenterListModel()->relationRemoved(dto);
    });

    connect(entityFieldSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        PresenterListModelRelationDTO dto(-1, PresenterListModelRelationDTO::RelationField::RelationFieldName, removedIds, -1);
        Q_EMIT dispatcher->presenterListModel()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("entityField")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->entityField(),
            &EntityFieldSignals::activeStatusChanged);

    // EntityParentInteractor

    new EntityParent::EntityParentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *entityParentSignalHolder = repositoryProvider->repository("EntityParent")->signalHolder();

    // removal
    connect(entityParentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->entityParent(), &EntityParentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(entityParentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        EntityRelationDTO dto(-1, EntityRelationDTO::RelationField::Parent, removedIds, -1);
        Q_EMIT dispatcher->entity()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("entityParent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->entityParent(),
            &EntityParentSignals::activeStatusChanged);

    // RepositoryComponentInteractor

    new RepositoryComponent::RepositoryComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *repositoryComponentSignalHolder = repositoryProvider->repository("RepositoryComponent")->signalHolder();

    // removal
    connect(repositoryComponentSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->repositoryComponent(),
            &RepositoryComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(repositoryComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::RepositoryComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("repositoryComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->repositoryComponent(),
            &RepositoryComponentSignals::activeStatusChanged);

    // RepositoryInteractor

    new Repository::RepositoryInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *repositorySignalHolder = repositoryProvider->repository("Repository")->signalHolder();

    // removal
    connect(repositorySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->repository(), &RepositorySignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(repositorySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        RepositoryComponentRelationDTO dto(-1, RepositoryComponentRelationDTO::RelationField::Repositories, removedIds, -1);
        Q_EMIT dispatcher->repositoryComponent()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("repository")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->repository(),
            &RepositorySignals::activeStatusChanged);

    // InteractorComponentInteractor

    new InteractorComponent::InteractorComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *interactorComponentSignalHolder = repositoryProvider->repository("InteractorComponent")->signalHolder();

    // removal
    connect(interactorComponentSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->interactorComponent(),
            &InteractorComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(interactorComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::InteractorComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("interactorComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->interactorComponent(),
            &InteractorComponentSignals::activeStatusChanged);

    // ApplicationComponentInteractor

    new ApplicationComponent::ApplicationComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *applicationComponentSignalHolder = repositoryProvider->repository("ApplicationComponent")->signalHolder();

    // removal
    connect(applicationComponentSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->applicationComponent(),
            &ApplicationComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(applicationComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::ApplicationComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("applicationComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->applicationComponent(),
            &ApplicationComponentSignals::activeStatusChanged);

    // ApplicationFeatureInteractor

    new ApplicationFeature::ApplicationFeatureInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *applicationFeatureSignalHolder = repositoryProvider->repository("ApplicationFeature")->signalHolder();

    // removal
    connect(applicationFeatureSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->applicationFeature(),
            &ApplicationFeatureSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(applicationFeatureSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ApplicationComponentRelationDTO dto(-1, ApplicationComponentRelationDTO::RelationField::Features, removedIds, -1);
        Q_EMIT dispatcher->applicationComponent()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("applicationFeature")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->applicationFeature(),
            &ApplicationFeatureSignals::activeStatusChanged);

    // CRUDInteractor

    new CRUD::CRUDInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *cRUDSignalHolder = repositoryProvider->repository("CRUD")->signalHolder();

    // removal
    connect(cRUDSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->cRUD(), &CRUDSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(cRUDSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ApplicationFeatureRelationDTO dto(-1, ApplicationFeatureRelationDTO::RelationField::Crud, removedIds, -1);
        Q_EMIT dispatcher->applicationFeature()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("cRUD")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->cRUD(),
            &CRUDSignals::activeStatusChanged);

    // CustomCommandInteractor

    new CustomCommand::CustomCommandInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *customCommandSignalHolder = repositoryProvider->repository("CustomCommand")->signalHolder();

    // removal
    connect(customCommandSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->customCommand(), &CustomCommandSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(customCommandSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ApplicationFeatureRelationDTO dto(-1, ApplicationFeatureRelationDTO::RelationField::CustomCommands, removedIds, -1);
        Q_EMIT dispatcher->applicationFeature()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("customCommand")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->customCommand(),
            &CustomCommandSignals::activeStatusChanged);

    // CustomDTOInteractor

    new CustomDTO::CustomDTOInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *customDTOSignalHolder = repositoryProvider->repository("CustomDTO")->signalHolder();

    // removal
    connect(customDTOSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->customDTO(), &CustomDTOSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(customDTOSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        CustomCommandRelationDTO dto(-1, CustomCommandRelationDTO::RelationField::DtoIn, removedIds, -1);
        Q_EMIT dispatcher->customCommand()->relationRemoved(dto);
    });

    connect(customDTOSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        CustomCommandRelationDTO dto(-1, CustomCommandRelationDTO::RelationField::DtoOut, removedIds, -1);
        Q_EMIT dispatcher->customCommand()->relationRemoved(dto);
    });

    connect(customDTOSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        CustomQueryRelationDTO dto(-1, CustomQueryRelationDTO::RelationField::DtoIn, removedIds, -1);
        Q_EMIT dispatcher->customQuery()->relationRemoved(dto);
    });

    connect(customDTOSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        CustomQueryRelationDTO dto(-1, CustomQueryRelationDTO::RelationField::DtoOut, removedIds, -1);
        Q_EMIT dispatcher->customQuery()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("customDTO")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->customDTO(),
            &CustomDTOSignals::activeStatusChanged);

    // CustomDTOFieldInteractor

    new CustomDTOField::CustomDTOFieldInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *customDTOFieldSignalHolder = repositoryProvider->repository("CustomDTOField")->signalHolder();

    // removal
    connect(customDTOFieldSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->customDTOField(), &CustomDTOFieldSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(customDTOFieldSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        CustomDTORelationDTO dto(-1, CustomDTORelationDTO::RelationField::Fields, removedIds, -1);
        Q_EMIT dispatcher->customDTO()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("customDTOField")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->customDTOField(),
            &CustomDTOFieldSignals::activeStatusChanged);

    // CustomQueryInteractor

    new CustomQuery::CustomQueryInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *customQuerySignalHolder = repositoryProvider->repository("CustomQuery")->signalHolder();

    // removal
    connect(customQuerySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->customQuery(), &CustomQuerySignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(customQuerySignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ApplicationFeatureRelationDTO dto(-1, ApplicationFeatureRelationDTO::RelationField::CustomQueries, removedIds, -1);
        Q_EMIT dispatcher->applicationFeature()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("customQuery")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->customQuery(),
            &CustomQuerySignals::activeStatusChanged);

    // DTOComponentInteractor

    new DTOComponent::DTOComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *dTOComponentSignalHolder = repositoryProvider->repository("DTOComponent")->signalHolder();

    // removal
    connect(dTOComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->dTOComponent(), &DTOComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(dTOComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::DtoComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("dTOComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->dTOComponent(),
            &DTOComponentSignals::activeStatusChanged);

    // CQRSComponentInteractor

    new CQRSComponent::CQRSComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *cQRSComponentSignalHolder = repositoryProvider->repository("CQRSComponent")->signalHolder();

    // removal
    connect(cQRSComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, dispatcher->cQRSComponent(), &CQRSComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(cQRSComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::CqrsComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("cQRSComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->cQRSComponent(),
            &CQRSComponentSignals::activeStatusChanged);

    // ContractsComponentInteractor

    new ContractsComponent::ContractsComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *contractsComponentSignalHolder = repositoryProvider->repository("ContractsComponent")->signalHolder();

    // removal
    connect(contractsComponentSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->contractsComponent(),
            &ContractsComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(contractsComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::ContractsComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("contractsComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->contractsComponent(),
            &ContractsComponentSignals::activeStatusChanged);

    // PresenterComponentInteractor

    new PresenterComponent::PresenterComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *presenterComponentSignalHolder = repositoryProvider->repository("PresenterComponent")->signalHolder();

    // removal
    connect(presenterComponentSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->presenterComponent(),
            &PresenterComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(presenterComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::PresenterComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("presenterComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->presenterComponent(),
            &PresenterComponentSignals::activeStatusChanged);

    // PresenterSingleInteractor

    new PresenterSingle::PresenterSingleInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *presenterSingleSignalHolder = repositoryProvider->repository("PresenterSingle")->signalHolder();

    // removal
    connect(presenterSingleSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->presenterSingle(),
            &PresenterSingleSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(presenterSingleSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        PresenterComponentRelationDTO dto(-1, PresenterComponentRelationDTO::RelationField::Singles, removedIds, -1);
        Q_EMIT dispatcher->presenterComponent()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("presenterSingle")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->presenterSingle(),
            &PresenterSingleSignals::activeStatusChanged);

    // PresenterListModelInteractor

    new PresenterListModel::PresenterListModelInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *presenterListModelSignalHolder = repositoryProvider->repository("PresenterListModel")->signalHolder();

    // removal
    connect(presenterListModelSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->presenterListModel(),
            &PresenterListModelSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(presenterListModelSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        PresenterComponentRelationDTO dto(-1, PresenterComponentRelationDTO::RelationField::ListModels, removedIds, -1);
        Q_EMIT dispatcher->presenterComponent()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("presenterListModel")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->presenterListModel(),
            &PresenterListModelSignals::activeStatusChanged);

    // FrontEndComponentInteractor

    new FrontEndComponent::FrontEndComponentInteractor(repositoryProvider, undoRedoSystem, dispatcher);

    SignalHolder *frontEndComponentSignalHolder = repositoryProvider->repository("FrontEndComponent")->signalHolder();

    // removal
    connect(frontEndComponentSignalHolder,
            &Qleany::Contracts::Repository::SignalHolder::removed,
            dispatcher->frontEndComponent(),
            &FrontEndComponentSignals::removed);

    // spread removal signal to all other entity signal holders so as to remove the relations

    connect(frontEndComponentSignalHolder, &Qleany::Contracts::Repository::SignalHolder::removed, this, [dispatcher](QList<int> removedIds) {
        ProjectRelationDTO dto(-1, ProjectRelationDTO::RelationField::FrontEndComponent, removedIds, -1);
        Q_EMIT dispatcher->project()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("frontEndComponent")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->frontEndComponent(),
            &FrontEndComponentSignals::activeStatusChanged);
}

InteractorRegistration::~InteractorRegistration()
{
}