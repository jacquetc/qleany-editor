// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "entity_field_interactor.h"

#include "entity_field/commands/create_entity_field_command.h"
#include "entity_field/commands/create_entity_field_command_handler.h"
#include "entity_field/commands/remove_entity_field_command.h"
#include "entity_field/commands/remove_entity_field_command_handler.h"
#include "entity_field/commands/update_entity_field_command.h"
#include "entity_field/commands/update_entity_field_command_handler.h"
#include "entity_field/queries/get_entity_field_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::EntityField;
using namespace QleanyEditor::Application::Features::EntityField::Commands;
using namespace QleanyEditor::Application::Features::EntityField::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<EntityFieldInteractor> EntityFieldInteractor::s_instance = nullptr;

EntityFieldInteractor::EntityFieldInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

EntityFieldInteractor *EntityFieldInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<EntityFieldDTO> EntityFieldInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetEntityFieldQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceEntityFieldRepository *>(m_repositoryProvider->repository("EntityField"));
        GetEntityFieldQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->entityField()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "entityField"_L1);

    // async wait for result signal
    const std::optional<EntityFieldDTO> optional_result =
        co_await qCoro(m_eventDispatcher->entityField(), &EntityFieldSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return EntityFieldDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<EntityFieldDTO> EntityFieldInteractor::create(const CreateEntityFieldDTO &dto)
{
    CreateEntityFieldCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceEntityFieldRepository *>(m_repositoryProvider->repository("EntityField"));

    auto *handler = new CreateEntityFieldCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateEntityFieldCommandHandler::entityFieldCreated, m_eventDispatcher->entityField(), &EntityFieldSignals::created);

    QObject::connect(handler, &CreateEntityFieldCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = EntityRelationDTO(ownerId, EntityRelationDTO::RelationField::Fields, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->entity()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateEntityFieldCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = EntityRelationDTO(ownerId, EntityRelationDTO::RelationField::Fields, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->entity()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateEntityFieldCommandHandler::entityFieldRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->entityField()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateEntityFieldCommandHandler, CreateEntityFieldCommand>(EntityFieldInteractor::tr("Create entityField"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entityField"_L1);

    // async wait for result signal
    const std::optional<EntityFieldDTO> optional_result =
        co_await qCoro(handler, &CreateEntityFieldCommandHandler::entityFieldCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return EntityFieldDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<EntityFieldDTO> EntityFieldInteractor::update(const UpdateEntityFieldDTO &dto)
{
    UpdateEntityFieldCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceEntityFieldRepository *>(m_repositoryProvider->repository("EntityField"));

    auto *handler = new UpdateEntityFieldCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateEntityFieldCommandHandler::entityFieldUpdated, this, [this](EntityFieldDTO dto) {
        Q_EMIT m_eventDispatcher->entityField()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateEntityFieldCommandHandler::entityFieldDetailsUpdated,
                     m_eventDispatcher->entityField(),
                     &EntityFieldSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateEntityFieldCommandHandler, UpdateEntityFieldCommand>(EntityFieldInteractor::tr("Update entityField"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entityField"_L1);

    // async wait for result signal
    const std::optional<EntityFieldDTO> optional_result =
        co_await qCoro(handler, &UpdateEntityFieldCommandHandler::entityFieldUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return EntityFieldDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> EntityFieldInteractor::remove(int id)
{
    RemoveEntityFieldCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceEntityFieldRepository *>(m_repositoryProvider->repository("EntityField"));

    auto *handler = new RemoveEntityFieldCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveEntityFieldCommandHandler, RemoveEntityFieldCommand>(EntityFieldInteractor::tr("Remove entityField"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entityField"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateEntityFieldDTO EntityFieldInteractor::getCreateDTO()
{
    return CreateEntityFieldDTO();
}

UpdateEntityFieldDTO EntityFieldInteractor::getUpdateDTO()
{
    return UpdateEntityFieldDTO();
}
