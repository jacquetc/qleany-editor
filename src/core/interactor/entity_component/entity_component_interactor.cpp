// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "entity_component_interactor.h"

#include "entity_component/commands/update_entity_component_command.h"
#include "entity_component/commands/update_entity_component_command_handler.h"
#include "entity_component/queries/get_entity_component_query_handler.h"
#include "entity_component/queries/get_entity_component_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::EntityComponent;
using namespace QleanyEditor::Application::Features::EntityComponent::Commands;
using namespace QleanyEditor::Application::Features::EntityComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<EntityComponentInteractor> EntityComponentInteractor::s_instance = nullptr;

EntityComponentInteractor::EntityComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

EntityComponentInteractor *EntityComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<EntityComponentDTO> EntityComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetEntityComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceEntityComponentRepository *>(m_repositoryProvider->repository("EntityComponent"));
        GetEntityComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->entityComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "entityComponent"_L1);

    // async wait for result signal
    const std::optional<EntityComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->entityComponent(), &EntityComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return EntityComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<EntityComponentWithDetailsDTO> EntityComponentInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetEntityComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceEntityComponentRepository *>(m_repositoryProvider->repository("EntityComponent"));
        GetEntityComponentWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->entityComponent()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "entityComponent"_L1);

    // async wait for result signal
    const std::optional<EntityComponentWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->entityComponent(), &EntityComponentSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return EntityComponentWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<EntityComponentDTO> EntityComponentInteractor::update(const UpdateEntityComponentDTO &dto)
{
    UpdateEntityComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceEntityComponentRepository *>(m_repositoryProvider->repository("EntityComponent"));

    auto *handler = new UpdateEntityComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateEntityComponentCommandHandler::entityComponentUpdated, this, [this](EntityComponentDTO dto) {
        Q_EMIT m_eventDispatcher->entityComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateEntityComponentCommandHandler::entityComponentDetailsUpdated,
                     m_eventDispatcher->entityComponent(),
                     &EntityComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateEntityComponentCommandHandler, UpdateEntityComponentCommand>(EntityComponentInteractor::tr("Update entityComponent"),
                                                                                                       handler,
                                                                                                       query);

    // push command
    m_undo_redo_system->push(command, "entityComponent"_L1);

    // async wait for result signal
    const std::optional<EntityComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateEntityComponentCommandHandler::entityComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return EntityComponentDTO();
    }

    co_return optional_result.value();
}

UpdateEntityComponentDTO EntityComponentInteractor::getUpdateDTO()
{
    return UpdateEntityComponentDTO();
}
