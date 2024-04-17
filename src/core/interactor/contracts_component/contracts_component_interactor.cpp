// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "contracts_component_interactor.h"

#include "contracts_component/commands/create_contracts_component_command.h"
#include "contracts_component/commands/create_contracts_component_command_handler.h"
#include "contracts_component/commands/remove_contracts_component_command.h"
#include "contracts_component/commands/remove_contracts_component_command_handler.h"
#include "contracts_component/commands/update_contracts_component_command.h"
#include "contracts_component/commands/update_contracts_component_command_handler.h"
#include "contracts_component/queries/get_contracts_component_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::ContractsComponent;
using namespace QleanyEditor::Application::Features::ContractsComponent::Commands;
using namespace QleanyEditor::Application::Features::ContractsComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<ContractsComponentInteractor> ContractsComponentInteractor::s_instance = nullptr;

ContractsComponentInteractor::ContractsComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

ContractsComponentInteractor *ContractsComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<ContractsComponentDTO> ContractsComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetContractsComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceContractsComponentRepository *>(m_repositoryProvider->repository("ContractsComponent"));
        GetContractsComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->contractsComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "contractsComponent"_L1);

    // async wait for result signal
    const std::optional<ContractsComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->contractsComponent(), &ContractsComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return ContractsComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<ContractsComponentDTO> ContractsComponentInteractor::create(const CreateContractsComponentDTO &dto)
{
    CreateContractsComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceContractsComponentRepository *>(m_repositoryProvider->repository("ContractsComponent"));

    auto *handler = new CreateContractsComponentCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreateContractsComponentCommandHandler::contractsComponentCreated,
                     m_eventDispatcher->contractsComponent(),
                     &ContractsComponentSignals::created);

    QObject::connect(handler, &CreateContractsComponentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::ContractsComponent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->project()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateContractsComponentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::ContractsComponent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->project()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateContractsComponentCommandHandler::contractsComponentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->contractsComponent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreateContractsComponentCommandHandler, CreateContractsComponentCommand>(ContractsComponentInteractor::tr("Create contractsComponent"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "contractsComponent"_L1);

    // async wait for result signal
    const std::optional<ContractsComponentDTO> optional_result =
        co_await qCoro(handler, &CreateContractsComponentCommandHandler::contractsComponentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return ContractsComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<ContractsComponentDTO> ContractsComponentInteractor::update(const UpdateContractsComponentDTO &dto)
{
    UpdateContractsComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceContractsComponentRepository *>(m_repositoryProvider->repository("ContractsComponent"));

    auto *handler = new UpdateContractsComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateContractsComponentCommandHandler::contractsComponentUpdated, this, [this](ContractsComponentDTO dto) {
        Q_EMIT m_eventDispatcher->contractsComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateContractsComponentCommandHandler::contractsComponentDetailsUpdated,
                     m_eventDispatcher->contractsComponent(),
                     &ContractsComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdateContractsComponentCommandHandler, UpdateContractsComponentCommand>(ContractsComponentInteractor::tr("Update contractsComponent"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "contractsComponent"_L1);

    // async wait for result signal
    const std::optional<ContractsComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateContractsComponentCommandHandler::contractsComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return ContractsComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> ContractsComponentInteractor::remove(int id)
{
    RemoveContractsComponentCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceContractsComponentRepository *>(m_repositoryProvider->repository("ContractsComponent"));

    auto *handler = new RemoveContractsComponentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemoveContractsComponentCommandHandler, RemoveContractsComponentCommand>(ContractsComponentInteractor::tr("Remove contractsComponent"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "contractsComponent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateContractsComponentDTO ContractsComponentInteractor::getCreateDTO()
{
    return CreateContractsComponentDTO();
}

UpdateContractsComponentDTO ContractsComponentInteractor::getUpdateDTO()
{
    return UpdateContractsComponentDTO();
}
