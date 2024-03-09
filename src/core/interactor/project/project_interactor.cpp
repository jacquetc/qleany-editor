// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "project_interactor.h"

#include "project/commands/close_project_command.h"
#include "project/commands/close_project_command_handler.h"
#include "project/commands/create_project_command.h"
#include "project/commands/create_project_command_handler.h"
#include "project/commands/load_project_command.h"
#include "project/commands/load_project_command_handler.h"
#include "project/commands/save_project_command.h"
#include "project/commands/save_project_command_handler.h"
#include "project/queries/get_project_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::Project;
using namespace QleanyEditor::Application::Features::Project::Commands;
using namespace QleanyEditor::Application::Features::Project::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<ProjectInteractor> ProjectInteractor::s_instance = nullptr;

ProjectInteractor::ProjectInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                     ThreadedUndoRedoSystem *undo_redo_system,
                                     QSharedPointer<EventDispatcher> eventDispatcher)
    : QObject{nullptr}
{
    m_repositoryProvider = repositoryProvider;

    // connections for undo commands:
    m_undo_redo_system = undo_redo_system;
    m_eventDispatcher = eventDispatcher;

    s_instance = this;
}

ProjectInteractor *ProjectInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<ProjectDTO> ProjectInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetProjectQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceProjectRepository *>(m_repositoryProvider->repository("Project"));
        GetProjectQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->project()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "project"_L1);

    // async wait for result signal
    const std::optional<ProjectDTO> optional_result =
        co_await qCoro(m_eventDispatcher->project(), &ProjectSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return ProjectDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<> ProjectInteractor::loadProject(LoadProjectDTO dto)
{
    LoadProjectCommand query;

    query.req = dto;

    auto projectRepository = static_cast<InterfaceProjectRepository *>(m_repositoryProvider->repository("Project"));

    auto globalComponentRepository = static_cast<InterfaceGlobalComponentRepository *>(m_repositoryProvider->repository("GlobalComponent"));

    auto recentProjectRepository = static_cast<InterfaceRecentProjectRepository *>(m_repositoryProvider->repository("RecentProject"));

    auto *handler = new LoadProjectCommandHandler(projectRepository, globalComponentRepository, recentProjectRepository);

    Q_UNIMPLEMENTED();

    // connect

    QObject::connect(handler, &LoadProjectCommandHandler::loadProjectChanged, m_eventDispatcher->project(), &ProjectSignals::loadProjectChanged);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<LoadProjectCommandHandler, LoadProjectCommand>(ProjectInteractor::tr("Doing LoadProject"), handler, query);

    // set progress minimum duration
    command->setProgressMinimumDuration(1000);
    m_eventDispatcher->progress()->bindToProgressSignals(command);

    // push command
    m_undo_redo_system->push(command, "project"_L1);

    co_return;
}

QCoro::Task<> ProjectInteractor::saveProject(SaveProjectDTO dto)
{
    SaveProjectCommand query;

    query.req = dto;

    auto projectRepository = static_cast<InterfaceProjectRepository *>(m_repositoryProvider->repository("Project"));

    auto globalComponentRepository = static_cast<InterfaceGlobalComponentRepository *>(m_repositoryProvider->repository("GlobalComponent"));

    auto *handler = new SaveProjectCommandHandler(projectRepository, globalComponentRepository);

    Q_UNIMPLEMENTED();

    // connect

    QObject::connect(handler, &SaveProjectCommandHandler::saveProjectChanged, m_eventDispatcher->project(), &ProjectSignals::saveProjectChanged);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<SaveProjectCommandHandler, SaveProjectCommand>(ProjectInteractor::tr("Doing SaveProject"), handler, query);

    // set progress minimum duration
    command->setProgressMinimumDuration(1000);
    m_eventDispatcher->progress()->bindToProgressSignals(command);

    // push command
    m_undo_redo_system->push(command, "project"_L1);

    co_return;
}

QCoro::Task<> ProjectInteractor::createProject(CreateProjectDTO dto)
{
    CreateProjectCommand query;

    query.req = dto;

    auto projectRepository = static_cast<InterfaceProjectRepository *>(m_repositoryProvider->repository("Project"));

    auto globalComponentRepository = static_cast<InterfaceGlobalComponentRepository *>(m_repositoryProvider->repository("GlobalComponent"));

    auto *handler = new CreateProjectCommandHandler(projectRepository, globalComponentRepository);

    Q_UNIMPLEMENTED();

    // connect

    QObject::connect(handler, &CreateProjectCommandHandler::createProjectChanged, m_eventDispatcher->project(), &ProjectSignals::createProjectChanged);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateProjectCommandHandler, CreateProjectCommand>(ProjectInteractor::tr("Doing CreateProject"), handler, query);

    // set progress minimum duration
    command->setProgressMinimumDuration(1000);
    m_eventDispatcher->progress()->bindToProgressSignals(command);

    // push command
    m_undo_redo_system->push(command, "project"_L1);

    co_return;
}

QCoro::Task<> ProjectInteractor::closeProject()
{
    CloseProjectCommand query;

    auto projectRepository = static_cast<InterfaceProjectRepository *>(m_repositoryProvider->repository("Project"));

    auto *handler = new CloseProjectCommandHandler(projectRepository);

    Q_UNIMPLEMENTED();

    // connect

    QObject::connect(handler, &CloseProjectCommandHandler::closeProjectChanged, m_eventDispatcher->project(), &ProjectSignals::closeProjectChanged);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CloseProjectCommandHandler, CloseProjectCommand>(ProjectInteractor::tr("Doing CloseProject"), handler, query);

    // set progress minimum duration
    command->setProgressMinimumDuration(1000);
    m_eventDispatcher->progress()->bindToProgressSignals(command);

    // push command
    m_undo_redo_system->push(command, "project"_L1);

    co_return;
}
