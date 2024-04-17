// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "custom_command_interactor.h"

#include "custom_command/commands/create_custom_command_command.h"
#include "custom_command/commands/create_custom_command_command_handler.h"
#include "custom_command/commands/remove_custom_command_command.h"
#include "custom_command/commands/remove_custom_command_command_handler.h"
#include "custom_command/commands/update_custom_command_command.h"
#include "custom_command/commands/update_custom_command_command_handler.h"
#include "custom_command/queries/get_custom_command_query_handler.h"
#include "custom_command/queries/get_custom_command_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::CustomCommand;
using namespace QleanyEditor::Application::Features::CustomCommand::Commands;
using namespace QleanyEditor::Application::Features::CustomCommand::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<CustomCommandInteractor> CustomCommandInteractor::s_instance = nullptr;

CustomCommandInteractor::CustomCommandInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

CustomCommandInteractor *CustomCommandInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<CustomCommandDTO> CustomCommandInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCustomCommandQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCustomCommandRepository *>(m_repositoryProvider->repository("CustomCommand"));
        GetCustomCommandQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->customCommand()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "customCommand"_L1);

    // async wait for result signal
    const std::optional<CustomCommandDTO> optional_result =
        co_await qCoro(m_eventDispatcher->customCommand(), &CustomCommandSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CustomCommandDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomCommandWithDetailsDTO> CustomCommandInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCustomCommandQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCustomCommandRepository *>(m_repositoryProvider->repository("CustomCommand"));
        GetCustomCommandWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->customCommand()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "customCommand"_L1);

    // async wait for result signal
    const std::optional<CustomCommandWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->customCommand(), &CustomCommandSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CustomCommandWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomCommandDTO> CustomCommandInteractor::create(const CreateCustomCommandDTO &dto)
{
    CreateCustomCommandCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCustomCommandRepository *>(m_repositoryProvider->repository("CustomCommand"));

    auto *handler = new CreateCustomCommandCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateCustomCommandCommandHandler::customCommandCreated, m_eventDispatcher->customCommand(), &CustomCommandSignals::created);

    QObject::connect(handler, &CreateCustomCommandCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ApplicationFeatureRelationDTO(ownerId, ApplicationFeatureRelationDTO::RelationField::CustomCommands, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->applicationFeature()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateCustomCommandCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ApplicationFeatureRelationDTO(ownerId, ApplicationFeatureRelationDTO::RelationField::CustomCommands, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->applicationFeature()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateCustomCommandCommandHandler::customCommandRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->customCommand()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreateCustomCommandCommandHandler, CreateCustomCommandCommand>(CustomCommandInteractor::tr("Create customCommand"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customCommand"_L1);

    // async wait for result signal
    const std::optional<CustomCommandDTO> optional_result =
        co_await qCoro(handler, &CreateCustomCommandCommandHandler::customCommandCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CustomCommandDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomCommandDTO> CustomCommandInteractor::update(const UpdateCustomCommandDTO &dto)
{
    UpdateCustomCommandCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCustomCommandRepository *>(m_repositoryProvider->repository("CustomCommand"));

    auto *handler = new UpdateCustomCommandCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateCustomCommandCommandHandler::customCommandUpdated, this, [this](CustomCommandDTO dto) {
        Q_EMIT m_eventDispatcher->customCommand()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateCustomCommandCommandHandler::customCommandDetailsUpdated,
                     m_eventDispatcher->customCommand(),
                     &CustomCommandSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdateCustomCommandCommandHandler, UpdateCustomCommandCommand>(CustomCommandInteractor::tr("Update customCommand"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customCommand"_L1);

    // async wait for result signal
    const std::optional<CustomCommandDTO> optional_result =
        co_await qCoro(handler, &UpdateCustomCommandCommandHandler::customCommandUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CustomCommandDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> CustomCommandInteractor::remove(int id)
{
    RemoveCustomCommandCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceCustomCommandRepository *>(m_repositoryProvider->repository("CustomCommand"));

    auto *handler = new RemoveCustomCommandCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemoveCustomCommandCommandHandler, RemoveCustomCommandCommand>(CustomCommandInteractor::tr("Remove customCommand"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customCommand"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateCustomCommandDTO CustomCommandInteractor::getCreateDTO()
{
    return CreateCustomCommandDTO();
}

UpdateCustomCommandDTO CustomCommandInteractor::getUpdateDTO()
{
    return UpdateCustomCommandDTO();
}
