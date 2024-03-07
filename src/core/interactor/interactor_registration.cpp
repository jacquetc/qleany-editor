// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "interactor_registration.h"
#include "entity/entity_interactor.h"
#include "entity_component/entity_component_interactor.h"
#include "event_dispatcher.h"
#include "global_component/global_component_interactor.h"
#include "project/project_interactor.h"
#include "recent_project/recent_project_interactor.h"
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
    Scopes scopes(QStringList() << "root"
                                << "recentProject"
                                << "project"
                                << "globalComponent"
                                << "entityComponent"
                                << "entity");
    auto *undoRedoSystem = new Qleany::Tools::UndoRedo::ThreadedUndoRedoSystem(this, scopes);

    // error handling
    connect(undoRedoSystem, &Qleany::Tools::UndoRedo::ThreadedUndoRedoSystem::errorSent, this, [dispatcher](Qleany::Error error) {
        qDebug() << "Error in undo redo system: " << error.status() << error.code() << error.message() << error.data() << error.stackTrace();
        emit dispatcher->error()->errorSent(error);
    });
    connect(undoRedoSystem, &Qleany::Tools::UndoRedo::ThreadedUndoRedoSystem::warningSent, this, [dispatcher](Qleany::Error error) {
        qDebug() << "Warning in undo redo system: " << error.status() << error.code() << error.message() << error.data() << error.stackTrace();
        emit dispatcher->error()->warningSent(error);
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
        emit dispatcher->root()->relationRemoved(dto);
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
        emit dispatcher->root()->relationRemoved(dto);
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
        emit dispatcher->project()->relationRemoved(dto);
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
        emit dispatcher->entityComponent()->relationRemoved(dto);
    });

    // active status
    connect(repositoryProvider->repository("entity")->signalHolder(),
            &Qleany::Contracts::Repository::SignalHolder::activeStatusChanged,
            dispatcher->entity(),
            &EntitySignals::activeStatusChanged);
}

InteractorRegistration::~InteractorRegistration()
{
}