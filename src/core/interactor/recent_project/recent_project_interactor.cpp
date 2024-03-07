// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "recent_project_interactor.h"

#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include "recent_project/commands/remove_recent_project_command.h"
#include "recent_project/commands/remove_recent_project_command_handler.h"
#include "recent_project/queries/get_all_recent_project_query_handler.h"
#include "recent_project/queries/get_recent_project_query_handler.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::RecentProject;
using namespace QleanyEditor::Application::Features::RecentProject::Commands;
using namespace QleanyEditor::Application::Features::RecentProject::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<RecentProjectInteractor> RecentProjectInteractor::s_instance = nullptr;

RecentProjectInteractor::RecentProjectInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

RecentProjectInteractor *RecentProjectInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<RecentProjectDTO> RecentProjectInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get");

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetRecentProjectQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceRecentProjectRepository *>(m_repositoryProvider->repository("RecentProject"));
        GetRecentProjectQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            emit m_eventDispatcher->recentProject()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "recentProject");

    // async wait for result signal
    const std::optional<RecentProjectDTO> optional_result =
        co_await qCoro(m_eventDispatcher->recentProject(), &RecentProjectSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return RecentProjectDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<QList<RecentProjectDTO>> RecentProjectInteractor::getAll() const
{
    auto queryCommand = new QueryCommand("getAll");

    queryCommand->setQueryFunction([&](QPromise<Result<void>> &progressPromise) {
        auto interface = static_cast<InterfaceRecentProjectRepository *>(m_repositoryProvider->repository("RecentProject"));
        GetAllRecentProjectQueryHandler handler(interface);
        auto result = handler.handle(progressPromise);

        if (result.isSuccess()) {
            emit m_eventDispatcher->recentProject()->getAllReplied(result.value());
        }
        return Result<void>(result.error());
    });
    m_undo_redo_system->push(queryCommand, "recentProject");

    // async wait for result signal
    const std::optional<QList<RecentProjectDTO>> optional_result =
        co_await qCoro(m_eventDispatcher->recentProject(), &RecentProjectSignals::getAllReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return QList<RecentProjectDTO>() << RecentProjectDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> RecentProjectInteractor::remove(int id)
{
    RemoveRecentProjectCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceRecentProjectRepository *>(m_repositoryProvider->repository("RecentProject"));

    auto *handler = new RemoveRecentProjectCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemoveRecentProjectCommandHandler, RemoveRecentProjectCommand>(RecentProjectInteractor::tr("Remove recentProject"), handler, query);

    // push command
    m_undo_redo_system->push(command, "recentProject");

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}
