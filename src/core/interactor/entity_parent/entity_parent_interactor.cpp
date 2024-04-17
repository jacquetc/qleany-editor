// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "entity_parent_interactor.h"

#include "entity_parent/commands/create_entity_parent_command.h"
#include "entity_parent/commands/create_entity_parent_command_handler.h"
#include "entity_parent/commands/remove_entity_parent_command.h"
#include "entity_parent/commands/remove_entity_parent_command_handler.h"
#include "entity_parent/commands/update_entity_parent_command.h"
#include "entity_parent/commands/update_entity_parent_command_handler.h"
#include "entity_parent/queries/get_entity_parent_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::EntityParent;
using namespace QleanyEditor::Application::Features::EntityParent::Commands;
using namespace QleanyEditor::Application::Features::EntityParent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<EntityParentInteractor> EntityParentInteractor::s_instance = nullptr;

EntityParentInteractor::EntityParentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

EntityParentInteractor *EntityParentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<EntityParentDTO> EntityParentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetEntityParentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceEntityParentRepository *>(m_repositoryProvider->repository("EntityParent"));
        GetEntityParentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->entityParent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "entityParent"_L1);

    // async wait for result signal
    const std::optional<EntityParentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->entityParent(), &EntityParentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return EntityParentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<EntityParentDTO> EntityParentInteractor::create(const CreateEntityParentDTO &dto)
{
    CreateEntityParentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceEntityParentRepository *>(m_repositoryProvider->repository("EntityParent"));

    auto *handler = new CreateEntityParentCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateEntityParentCommandHandler::entityParentCreated, m_eventDispatcher->entityParent(), &EntityParentSignals::created);

    QObject::connect(handler, &CreateEntityParentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = EntityRelationDTO(ownerId, EntityRelationDTO::RelationField::Parent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->entity()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateEntityParentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = EntityRelationDTO(ownerId, EntityRelationDTO::RelationField::Parent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->entity()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateEntityParentCommandHandler::entityParentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->entityParent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreateEntityParentCommandHandler, CreateEntityParentCommand>(EntityParentInteractor::tr("Create entityParent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entityParent"_L1);

    // async wait for result signal
    const std::optional<EntityParentDTO> optional_result =
        co_await qCoro(handler, &CreateEntityParentCommandHandler::entityParentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return EntityParentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<EntityParentDTO> EntityParentInteractor::update(const UpdateEntityParentDTO &dto)
{
    UpdateEntityParentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceEntityParentRepository *>(m_repositoryProvider->repository("EntityParent"));

    auto *handler = new UpdateEntityParentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateEntityParentCommandHandler::entityParentUpdated, this, [this](EntityParentDTO dto) {
        Q_EMIT m_eventDispatcher->entityParent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateEntityParentCommandHandler::entityParentDetailsUpdated,
                     m_eventDispatcher->entityParent(),
                     &EntityParentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdateEntityParentCommandHandler, UpdateEntityParentCommand>(EntityParentInteractor::tr("Update entityParent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entityParent"_L1);

    // async wait for result signal
    const std::optional<EntityParentDTO> optional_result =
        co_await qCoro(handler, &UpdateEntityParentCommandHandler::entityParentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return EntityParentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> EntityParentInteractor::remove(int id)
{
    RemoveEntityParentCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceEntityParentRepository *>(m_repositoryProvider->repository("EntityParent"));

    auto *handler = new RemoveEntityParentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemoveEntityParentCommandHandler, RemoveEntityParentCommand>(EntityParentInteractor::tr("Remove entityParent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entityParent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateEntityParentDTO EntityParentInteractor::getCreateDTO()
{
    return CreateEntityParentDTO();
}

UpdateEntityParentDTO EntityParentInteractor::getUpdateDTO()
{
    return UpdateEntityParentDTO();
}
