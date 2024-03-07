// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "project/load_project_dto.h"
#include "project/project_dto.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include "project/save_project_dto.h"

#include "project/create_project_dto.h"

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::Project;

namespace QleanyEditor::Interactor::Project
{

class QLEANY_EDITOR_INTERACTOR_EXPORT ProjectInteractor : public QObject
{
    Q_OBJECT
public:
    explicit ProjectInteractor(InterfaceRepositoryProvider *repositoryProvider,
                               ThreadedUndoRedoSystem *undo_redo_system,
                               QSharedPointer<EventDispatcher> eventDispatcher);

    static ProjectInteractor *instance();

    Q_INVOKABLE QCoro::Task<ProjectDTO> get(int id) const;

public slots:

    QCoro::Task<> loadProject(LoadProjectDTO dto);

    QCoro::Task<> saveProject(SaveProjectDTO dto);

    QCoro::Task<> createProject(CreateProjectDTO dto);

    QCoro::Task<> closeProject();

private:
    static QPointer<ProjectInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    ProjectInteractor() = delete;
    ProjectInteractor(const ProjectInteractor &) = delete;
    ProjectInteractor &operator=(const ProjectInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::Project