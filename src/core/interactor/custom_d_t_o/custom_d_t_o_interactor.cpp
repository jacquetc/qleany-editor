// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "custom_d_t_o_interactor.h"

#include "custom_d_t_o/commands/create_custom_d_t_o_command.h"
#include "custom_d_t_o/commands/create_custom_d_t_o_command_handler.h"
#include "custom_d_t_o/commands/remove_custom_d_t_o_command.h"
#include "custom_d_t_o/commands/remove_custom_d_t_o_command_handler.h"
#include "custom_d_t_o/commands/update_custom_d_t_o_command.h"
#include "custom_d_t_o/commands/update_custom_d_t_o_command_handler.h"
#include "custom_d_t_o/queries/get_custom_d_t_o_query_handler.h"
#include "custom_d_t_o/queries/get_custom_d_t_o_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::CustomDTO;
using namespace QleanyEditor::Application::Features::CustomDTO::Commands;
using namespace QleanyEditor::Application::Features::CustomDTO::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<CustomDTOInteractor> CustomDTOInteractor::s_instance = nullptr;

CustomDTOInteractor::CustomDTOInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

CustomDTOInteractor *CustomDTOInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<CustomDTODTO> CustomDTOInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCustomDTOQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCustomDTORepository *>(m_repositoryProvider->repository("CustomDTO"));
        GetCustomDTOQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->customDTO()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "customDTO"_L1);

    // async wait for result signal
    const std::optional<CustomDTODTO> optional_result =
        co_await qCoro(m_eventDispatcher->customDTO(), &CustomDTOSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CustomDTODTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomDTOWithDetailsDTO> CustomDTOInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCustomDTOQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCustomDTORepository *>(m_repositoryProvider->repository("CustomDTO"));
        GetCustomDTOWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->customDTO()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "customDTO"_L1);

    // async wait for result signal
    const std::optional<CustomDTOWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->customDTO(), &CustomDTOSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CustomDTOWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomDTODTO> CustomDTOInteractor::create(const CreateCustomDTODTO &dto)
{
    CreateCustomDTOCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCustomDTORepository *>(m_repositoryProvider->repository("CustomDTO"));

    auto *handler = new CreateCustomDTOCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateCustomDTOCommandHandler::customDTOCreated, m_eventDispatcher->customDTO(), &CustomDTOSignals::created);

    QObject::connect(handler, &CreateCustomDTOCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = CustomCommandRelationDTO(ownerId, CustomCommandRelationDTO::RelationField::DtoIn, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->customCommand()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateCustomDTOCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = CustomCommandRelationDTO(ownerId, CustomCommandRelationDTO::RelationField::DtoIn, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->customCommand()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateCustomDTOCommandHandler::customDTORemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->customDTO()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateCustomDTOCommandHandler, CreateCustomDTOCommand>(CustomDTOInteractor::tr("Create customDTO"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customDTO"_L1);

    // async wait for result signal
    const std::optional<CustomDTODTO> optional_result =
        co_await qCoro(handler, &CreateCustomDTOCommandHandler::customDTOCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CustomDTODTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomDTODTO> CustomDTOInteractor::update(const UpdateCustomDTODTO &dto)
{
    UpdateCustomDTOCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCustomDTORepository *>(m_repositoryProvider->repository("CustomDTO"));

    auto *handler = new UpdateCustomDTOCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateCustomDTOCommandHandler::customDTOUpdated, this, [this](CustomDTODTO dto) {
        Q_EMIT m_eventDispatcher->customDTO()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateCustomDTOCommandHandler::customDTODetailsUpdated,
                     m_eventDispatcher->customDTO(),
                     &CustomDTOSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateCustomDTOCommandHandler, UpdateCustomDTOCommand>(CustomDTOInteractor::tr("Update customDTO"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customDTO"_L1);

    // async wait for result signal
    const std::optional<CustomDTODTO> optional_result =
        co_await qCoro(handler, &UpdateCustomDTOCommandHandler::customDTOUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CustomDTODTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> CustomDTOInteractor::remove(int id)
{
    RemoveCustomDTOCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceCustomDTORepository *>(m_repositoryProvider->repository("CustomDTO"));

    auto *handler = new RemoveCustomDTOCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveCustomDTOCommandHandler, RemoveCustomDTOCommand>(CustomDTOInteractor::tr("Remove customDTO"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customDTO"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateCustomDTODTO CustomDTOInteractor::getCreateDTO()
{
    return CreateCustomDTODTO();
}

UpdateCustomDTODTO CustomDTOInteractor::getUpdateDTO()
{
    return UpdateCustomDTODTO();
}
