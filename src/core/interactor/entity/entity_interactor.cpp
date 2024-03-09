// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "entity_interactor.h"

#include "entity/commands/create_entity_command.h"
#include "entity/commands/create_entity_command_handler.h"
#include "entity/commands/remove_entity_command.h"
#include "entity/commands/remove_entity_command_handler.h"
#include "entity/commands/update_entity_command.h"
#include "entity/commands/update_entity_command_handler.h"
#include "entity/queries/get_entity_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::Entity;
using namespace QleanyEditor::Application::Features::Entity::Commands;
using namespace QleanyEditor::Application::Features::Entity::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<EntityInteractor> EntityInteractor::s_instance = nullptr;

EntityInteractor::EntityInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

EntityInteractor *EntityInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<EntityDTO> EntityInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetEntityQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceEntityRepository *>(m_repositoryProvider->repository("Entity"));
        GetEntityQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->entity()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "entity"_L1);

    // async wait for result signal
    const std::optional<EntityDTO> optional_result = co_await qCoro(m_eventDispatcher->entity(), &EntitySignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return EntityDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<EntityDTO> EntityInteractor::create(const CreateEntityDTO &dto)
{
    CreateEntityCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceEntityRepository *>(m_repositoryProvider->repository("Entity"));

    auto *handler = new CreateEntityCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateEntityCommandHandler::entityCreated, m_eventDispatcher->entity(), &EntitySignals::created);

    QObject::connect(handler, &CreateEntityCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = EntityComponentRelationDTO(ownerId, EntityComponentRelationDTO::RelationField::Entities, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->entityComponent()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateEntityCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = EntityComponentRelationDTO(ownerId, EntityComponentRelationDTO::RelationField::Entities, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->entityComponent()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateEntityCommandHandler::entityRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->entity()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateEntityCommandHandler, CreateEntityCommand>(EntityInteractor::tr("Create entity"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entity"_L1);

    // async wait for result signal
    const std::optional<EntityDTO> optional_result = co_await qCoro(handler, &CreateEntityCommandHandler::entityCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return EntityDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<EntityDTO> EntityInteractor::update(const UpdateEntityDTO &dto)
{
    UpdateEntityCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceEntityRepository *>(m_repositoryProvider->repository("Entity"));

    auto *handler = new UpdateEntityCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateEntityCommandHandler::entityUpdated, this, [this](EntityDTO dto) {
        Q_EMIT m_eventDispatcher->entity()->updated(dto);
    });
    QObject::connect(handler, &UpdateEntityCommandHandler::entityDetailsUpdated, m_eventDispatcher->entity(), &EntitySignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateEntityCommandHandler, UpdateEntityCommand>(EntityInteractor::tr("Update entity"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entity"_L1);

    // async wait for result signal
    const std::optional<EntityDTO> optional_result = co_await qCoro(handler, &UpdateEntityCommandHandler::entityUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return EntityDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> EntityInteractor::remove(int id)
{
    RemoveEntityCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceEntityRepository *>(m_repositoryProvider->repository("Entity"));

    auto *handler = new RemoveEntityCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveEntityCommandHandler, RemoveEntityCommand>(EntityInteractor::tr("Remove entity"), handler, query);

    // push command
    m_undo_redo_system->push(command, "entity"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateEntityDTO EntityInteractor::getCreateDTO()
{
    return CreateEntityDTO();
}

UpdateEntityDTO EntityInteractor::getUpdateDTO()
{
    return UpdateEntityDTO();
}
