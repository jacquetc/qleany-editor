// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "repository_component_interactor.h"

#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include "repository_component/commands/create_repository_component_command.h"
#include "repository_component/commands/create_repository_component_command_handler.h"
#include "repository_component/commands/remove_repository_component_command.h"
#include "repository_component/commands/remove_repository_component_command_handler.h"
#include "repository_component/commands/update_repository_component_command.h"
#include "repository_component/commands/update_repository_component_command_handler.h"
#include "repository_component/queries/get_repository_component_query_handler.h"
#include "repository_component/queries/get_repository_component_with_details_query_handler.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::RepositoryComponent;
using namespace QleanyEditor::Application::Features::RepositoryComponent::Commands;
using namespace QleanyEditor::Application::Features::RepositoryComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<RepositoryComponentInteractor> RepositoryComponentInteractor::s_instance = nullptr;

RepositoryComponentInteractor::RepositoryComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

RepositoryComponentInteractor *RepositoryComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<RepositoryComponentDTO> RepositoryComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetRepositoryComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceRepositoryComponentRepository *>(m_repositoryProvider->repository("RepositoryComponent"));
        GetRepositoryComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->repositoryComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "repositoryComponent"_L1);

    // async wait for result signal
    const std::optional<RepositoryComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->repositoryComponent(), &RepositoryComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return RepositoryComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<RepositoryComponentWithDetailsDTO> RepositoryComponentInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetRepositoryComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceRepositoryComponentRepository *>(m_repositoryProvider->repository("RepositoryComponent"));
        GetRepositoryComponentWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->repositoryComponent()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "repositoryComponent"_L1);

    // async wait for result signal
    const std::optional<RepositoryComponentWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->repositoryComponent(), &RepositoryComponentSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return RepositoryComponentWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<RepositoryComponentDTO> RepositoryComponentInteractor::create(const CreateRepositoryComponentDTO &dto)
{
    CreateRepositoryComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceRepositoryComponentRepository *>(m_repositoryProvider->repository("RepositoryComponent"));

    auto *handler = new CreateRepositoryComponentCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreateRepositoryComponentCommandHandler::repositoryComponentCreated,
                     m_eventDispatcher->repositoryComponent(),
                     &RepositoryComponentSignals::created);

    QObject::connect(handler, &CreateRepositoryComponentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::RepositoryComponent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->project()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateRepositoryComponentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::RepositoryComponent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->project()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateRepositoryComponentCommandHandler::repositoryComponentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->repositoryComponent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateRepositoryComponentCommandHandler, CreateRepositoryComponentCommand>(
        RepositoryComponentInteractor::tr("Create repositoryComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "repositoryComponent"_L1);

    // async wait for result signal
    const std::optional<RepositoryComponentDTO> optional_result =
        co_await qCoro(handler, &CreateRepositoryComponentCommandHandler::repositoryComponentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return RepositoryComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<RepositoryComponentDTO> RepositoryComponentInteractor::update(const UpdateRepositoryComponentDTO &dto)
{
    UpdateRepositoryComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceRepositoryComponentRepository *>(m_repositoryProvider->repository("RepositoryComponent"));

    auto *handler = new UpdateRepositoryComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateRepositoryComponentCommandHandler::repositoryComponentUpdated, this, [this](RepositoryComponentDTO dto) {
        Q_EMIT m_eventDispatcher->repositoryComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateRepositoryComponentCommandHandler::repositoryComponentDetailsUpdated,
                     m_eventDispatcher->repositoryComponent(),
                     &RepositoryComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateRepositoryComponentCommandHandler, UpdateRepositoryComponentCommand>(
        RepositoryComponentInteractor::tr("Update repositoryComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "repositoryComponent"_L1);

    // async wait for result signal
    const std::optional<RepositoryComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateRepositoryComponentCommandHandler::repositoryComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return RepositoryComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> RepositoryComponentInteractor::remove(int id)
{
    RemoveRepositoryComponentCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceRepositoryComponentRepository *>(m_repositoryProvider->repository("RepositoryComponent"));

    auto *handler = new RemoveRepositoryComponentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveRepositoryComponentCommandHandler, RemoveRepositoryComponentCommand>(
        RepositoryComponentInteractor::tr("Remove repositoryComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "repositoryComponent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateRepositoryComponentDTO RepositoryComponentInteractor::getCreateDTO()
{
    return CreateRepositoryComponentDTO();
}

UpdateRepositoryComponentDTO RepositoryComponentInteractor::getUpdateDTO()
{
    return UpdateRepositoryComponentDTO();
}
