// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "custom_query_interactor.h"

#include "custom_query/commands/create_custom_query_command.h"
#include "custom_query/commands/create_custom_query_command_handler.h"
#include "custom_query/commands/remove_custom_query_command.h"
#include "custom_query/commands/remove_custom_query_command_handler.h"
#include "custom_query/commands/update_custom_query_command.h"
#include "custom_query/commands/update_custom_query_command_handler.h"
#include "custom_query/queries/get_custom_query_query_handler.h"
#include "custom_query/queries/get_custom_query_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::CustomQuery;
using namespace QleanyEditor::Application::Features::CustomQuery::Commands;
using namespace QleanyEditor::Application::Features::CustomQuery::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<CustomQueryInteractor> CustomQueryInteractor::s_instance = nullptr;

CustomQueryInteractor::CustomQueryInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

CustomQueryInteractor *CustomQueryInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<CustomQueryDTO> CustomQueryInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCustomQueryQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCustomQueryRepository *>(m_repositoryProvider->repository("CustomQuery"));
        GetCustomQueryQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->customQuery()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "customQuery"_L1);

    // async wait for result signal
    const std::optional<CustomQueryDTO> optional_result =
        co_await qCoro(m_eventDispatcher->customQuery(), &CustomQuerySignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CustomQueryDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomQueryWithDetailsDTO> CustomQueryInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCustomQueryQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCustomQueryRepository *>(m_repositoryProvider->repository("CustomQuery"));
        GetCustomQueryWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->customQuery()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "customQuery"_L1);

    // async wait for result signal
    const std::optional<CustomQueryWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->customQuery(), &CustomQuerySignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CustomQueryWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomQueryDTO> CustomQueryInteractor::create(const CreateCustomQueryDTO &dto)
{
    CreateCustomQueryCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCustomQueryRepository *>(m_repositoryProvider->repository("CustomQuery"));

    auto *handler = new CreateCustomQueryCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateCustomQueryCommandHandler::customQueryCreated, m_eventDispatcher->customQuery(), &CustomQuerySignals::created);

    QObject::connect(handler, &CreateCustomQueryCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ApplicationFeatureRelationDTO(ownerId, ApplicationFeatureRelationDTO::RelationField::CustomQueries, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->applicationFeature()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateCustomQueryCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ApplicationFeatureRelationDTO(ownerId, ApplicationFeatureRelationDTO::RelationField::CustomQueries, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->applicationFeature()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateCustomQueryCommandHandler::customQueryRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->customQuery()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateCustomQueryCommandHandler, CreateCustomQueryCommand>(CustomQueryInteractor::tr("Create customQuery"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customQuery"_L1);

    // async wait for result signal
    const std::optional<CustomQueryDTO> optional_result =
        co_await qCoro(handler, &CreateCustomQueryCommandHandler::customQueryCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CustomQueryDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CustomQueryDTO> CustomQueryInteractor::update(const UpdateCustomQueryDTO &dto)
{
    UpdateCustomQueryCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCustomQueryRepository *>(m_repositoryProvider->repository("CustomQuery"));

    auto *handler = new UpdateCustomQueryCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateCustomQueryCommandHandler::customQueryUpdated, this, [this](CustomQueryDTO dto) {
        Q_EMIT m_eventDispatcher->customQuery()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateCustomQueryCommandHandler::customQueryDetailsUpdated,
                     m_eventDispatcher->customQuery(),
                     &CustomQuerySignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateCustomQueryCommandHandler, UpdateCustomQueryCommand>(CustomQueryInteractor::tr("Update customQuery"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customQuery"_L1);

    // async wait for result signal
    const std::optional<CustomQueryDTO> optional_result =
        co_await qCoro(handler, &UpdateCustomQueryCommandHandler::customQueryUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CustomQueryDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> CustomQueryInteractor::remove(int id)
{
    RemoveCustomQueryCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceCustomQueryRepository *>(m_repositoryProvider->repository("CustomQuery"));

    auto *handler = new RemoveCustomQueryCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveCustomQueryCommandHandler, RemoveCustomQueryCommand>(CustomQueryInteractor::tr("Remove customQuery"), handler, query);

    // push command
    m_undo_redo_system->push(command, "customQuery"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateCustomQueryDTO CustomQueryInteractor::getCreateDTO()
{
    return CreateCustomQueryDTO();
}

UpdateCustomQueryDTO CustomQueryInteractor::getUpdateDTO()
{
    return UpdateCustomQueryDTO();
}
