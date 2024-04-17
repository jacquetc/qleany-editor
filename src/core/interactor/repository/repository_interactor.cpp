// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "repository_interactor.h"

#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include "repository/commands/create_repository_command.h"
#include "repository/commands/create_repository_command_handler.h"
#include "repository/commands/remove_repository_command.h"
#include "repository/commands/remove_repository_command_handler.h"
#include "repository/commands/update_repository_command.h"
#include "repository/commands/update_repository_command_handler.h"
#include "repository/queries/get_all_repository_query_handler.h"
#include "repository/queries/get_repository_query_handler.h"
#include "repository/queries/get_repository_with_details_query_handler.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::Repository;
using namespace QleanyEditor::Application::Features::Repository::Commands;
using namespace QleanyEditor::Application::Features::Repository::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<RepositoryInteractor> RepositoryInteractor::s_instance = nullptr;

RepositoryInteractor::RepositoryInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

RepositoryInteractor *RepositoryInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<RepositoryDTO> RepositoryInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetRepositoryQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceRepositoryRepository *>(m_repositoryProvider->repository("Repository"));
        GetRepositoryQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->repository()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "repository"_L1);

    // async wait for result signal
    const std::optional<RepositoryDTO> optional_result =
        co_await qCoro(m_eventDispatcher->repository(), &RepositorySignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return RepositoryDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<RepositoryWithDetailsDTO> RepositoryInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetRepositoryQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceRepositoryRepository *>(m_repositoryProvider->repository("Repository"));
        GetRepositoryWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->repository()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "repository"_L1);

    // async wait for result signal
    const std::optional<RepositoryWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->repository(), &RepositorySignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return RepositoryWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<QList<RepositoryDTO>> RepositoryInteractor::getAll() const
{
    auto queryCommand = new QueryCommand("getAll"_L1);

    queryCommand->setQueryFunction([&](QPromise<Result<void>> &progressPromise) {
        auto interface = static_cast<InterfaceRepositoryRepository *>(m_repositoryProvider->repository("Repository"));
        GetAllRepositoryQueryHandler handler(interface);
        auto result = handler.handle(progressPromise);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->repository()->getAllReplied(result.value());
        }
        return Result<void>(result.error());
    });
    m_undo_redo_system->push(queryCommand, "repository"_L1);

    // async wait for result signal
    const std::optional<QList<RepositoryDTO>> optional_result =
        co_await qCoro(m_eventDispatcher->repository(), &RepositorySignals::getAllReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return QList<RepositoryDTO>() << RepositoryDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<RepositoryDTO> RepositoryInteractor::create(const CreateRepositoryDTO &dto)
{
    CreateRepositoryCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceRepositoryRepository *>(m_repositoryProvider->repository("Repository"));

    auto *handler = new CreateRepositoryCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateRepositoryCommandHandler::repositoryCreated, m_eventDispatcher->repository(), &RepositorySignals::created);

    QObject::connect(handler, &CreateRepositoryCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = RepositoryComponentRelationDTO(ownerId, RepositoryComponentRelationDTO::RelationField::Repositories, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->repositoryComponent()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateRepositoryCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = RepositoryComponentRelationDTO(ownerId, RepositoryComponentRelationDTO::RelationField::Repositories, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->repositoryComponent()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateRepositoryCommandHandler::repositoryRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->repository()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateRepositoryCommandHandler, CreateRepositoryCommand>(RepositoryInteractor::tr("Create repository"), handler, query);

    // push command
    m_undo_redo_system->push(command, "repository"_L1);

    // async wait for result signal
    const std::optional<RepositoryDTO> optional_result =
        co_await qCoro(handler, &CreateRepositoryCommandHandler::repositoryCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return RepositoryDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<RepositoryDTO> RepositoryInteractor::update(const UpdateRepositoryDTO &dto)
{
    UpdateRepositoryCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceRepositoryRepository *>(m_repositoryProvider->repository("Repository"));

    auto *handler = new UpdateRepositoryCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateRepositoryCommandHandler::repositoryUpdated, this, [this](RepositoryDTO dto) {
        Q_EMIT m_eventDispatcher->repository()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateRepositoryCommandHandler::repositoryDetailsUpdated,
                     m_eventDispatcher->repository(),
                     &RepositorySignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateRepositoryCommandHandler, UpdateRepositoryCommand>(RepositoryInteractor::tr("Update repository"), handler, query);

    // push command
    m_undo_redo_system->push(command, "repository"_L1);

    // async wait for result signal
    const std::optional<RepositoryDTO> optional_result =
        co_await qCoro(handler, &UpdateRepositoryCommandHandler::repositoryUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return RepositoryDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> RepositoryInteractor::remove(int id)
{
    RemoveRepositoryCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceRepositoryRepository *>(m_repositoryProvider->repository("Repository"));

    auto *handler = new RemoveRepositoryCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveRepositoryCommandHandler, RemoveRepositoryCommand>(RepositoryInteractor::tr("Remove repository"), handler, query);

    // push command
    m_undo_redo_system->push(command, "repository"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateRepositoryDTO RepositoryInteractor::getCreateDTO()
{
    return CreateRepositoryDTO();
}

UpdateRepositoryDTO RepositoryInteractor::getUpdateDTO()
{
    return UpdateRepositoryDTO();
}
