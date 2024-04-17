// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "custom_d_t_o_field_interactor.h"

#include "custom_d_t_o_field/commands/create_custom_d_t_o_field_command.h"
#include "custom_d_t_o_field/commands/create_custom_d_t_o_field_command_handler.h"
#include "custom_d_t_o_field/commands/remove_custom_d_t_o_field_command.h"
#include "custom_d_t_o_field/commands/remove_custom_d_t_o_field_command_handler.h"
#include "custom_d_t_o_field/commands/update_custom_d_t_o_field_command.h"
#include "custom_d_t_o_field/commands/update_custom_d_t_o_field_command_handler.h"
#include "custom_d_t_o_field/queries/get_custom_d_t_o_field_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::CustomDTOField;
using namespace QleanyEditor::Application::Features::CustomDTOField::Commands;
using namespace QleanyEditor::Application::Features::CustomDTOField::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<CustomDTOFieldInteractor> CustomDTOFieldInteractor::s_instance = nullptr;

CustomDTOFieldInteractor::CustomDTOFieldInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

CustomDTOFieldInteractor *CustomDTOFieldInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<CustomDTOFieldDTO> CustomDTOFieldInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCustomDTOFieldQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCustomDTOFieldRepository *>(m_repositoryProvider->repository("CustomDTOField"));
        GetCustomDTOFieldQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->customDTOField()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "customDTOField"_L1);

    // async wait for result signal
    const std::optional<CustomDTOFieldDTO> optional_result =
        co_await qCoro(m_eventDispatcher->customDTOField(), &CustomDTOFieldSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CustomDTOFieldDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomDTOFieldDTO> CustomDTOFieldInteractor::create(const CreateCustomDTOFieldDTO &dto)
{
    CreateCustomDTOFieldCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCustomDTOFieldRepository *>(m_repositoryProvider->repository("CustomDTOField"));

    auto *handler = new CreateCustomDTOFieldCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateCustomDTOFieldCommandHandler::customDTOFieldCreated, m_eventDispatcher->customDTOField(), &CustomDTOFieldSignals::created);

    QObject::connect(handler, &CreateCustomDTOFieldCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = CustomDTORelationDTO(ownerId, CustomDTORelationDTO::RelationField::Fields, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->customDTO()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateCustomDTOFieldCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = CustomDTORelationDTO(ownerId, CustomDTORelationDTO::RelationField::Fields, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->customDTO()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateCustomDTOFieldCommandHandler::customDTOFieldRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->customDTOField()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateCustomDTOFieldCommandHandler, CreateCustomDTOFieldCommand>(CustomDTOFieldInteractor::tr("Create customDTOField"),
                                                                                                     handler,
                                                                                                     query);

    // push command
    m_undo_redo_system->push(command, "customDTOField"_L1);

    // async wait for result signal
    const std::optional<CustomDTOFieldDTO> optional_result =
        co_await qCoro(handler, &CreateCustomDTOFieldCommandHandler::customDTOFieldCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CustomDTOFieldDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomDTOFieldDTO> CustomDTOFieldInteractor::update(const UpdateCustomDTOFieldDTO &dto)
{
    UpdateCustomDTOFieldCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCustomDTOFieldRepository *>(m_repositoryProvider->repository("CustomDTOField"));

    auto *handler = new UpdateCustomDTOFieldCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateCustomDTOFieldCommandHandler::customDTOFieldUpdated, this, [this](CustomDTOFieldDTO dto) {
        Q_EMIT m_eventDispatcher->customDTOField()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateCustomDTOFieldCommandHandler::customDTOFieldDetailsUpdated,
                     m_eventDispatcher->customDTOField(),
                     &CustomDTOFieldSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateCustomDTOFieldCommandHandler, UpdateCustomDTOFieldCommand>(CustomDTOFieldInteractor::tr("Update customDTOField"),
                                                                                                     handler,
                                                                                                     query);

    // push command
    m_undo_redo_system->push(command, "customDTOField"_L1);

    // async wait for result signal
    const std::optional<CustomDTOFieldDTO> optional_result =
        co_await qCoro(handler, &UpdateCustomDTOFieldCommandHandler::customDTOFieldUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CustomDTOFieldDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> CustomDTOFieldInteractor::remove(int id)
{
    RemoveCustomDTOFieldCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceCustomDTOFieldRepository *>(m_repositoryProvider->repository("CustomDTOField"));

    auto *handler = new RemoveCustomDTOFieldCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveCustomDTOFieldCommandHandler, RemoveCustomDTOFieldCommand>(CustomDTOFieldInteractor::tr("Remove customDTOField"),
                                                                                                     handler,
                                                                                                     query);

    // push command
    m_undo_redo_system->push(command, "customDTOField"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateCustomDTOFieldDTO CustomDTOFieldInteractor::getCreateDTO()
{
    return CreateCustomDTOFieldDTO();
}

UpdateCustomDTOFieldDTO CustomDTOFieldInteractor::getUpdateDTO()
{
    return UpdateCustomDTOFieldDTO();
}
