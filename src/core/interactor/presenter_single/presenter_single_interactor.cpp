// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "presenter_single_interactor.h"

#include "presenter_single/commands/create_presenter_single_command.h"
#include "presenter_single/commands/create_presenter_single_command_handler.h"
#include "presenter_single/commands/remove_presenter_single_command.h"
#include "presenter_single/commands/remove_presenter_single_command_handler.h"
#include "presenter_single/commands/update_presenter_single_command.h"
#include "presenter_single/commands/update_presenter_single_command_handler.h"
#include "presenter_single/queries/get_presenter_single_query_handler.h"
#include "presenter_single/queries/get_presenter_single_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::PresenterSingle;
using namespace QleanyEditor::Application::Features::PresenterSingle::Commands;
using namespace QleanyEditor::Application::Features::PresenterSingle::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<PresenterSingleInteractor> PresenterSingleInteractor::s_instance = nullptr;

PresenterSingleInteractor::PresenterSingleInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

PresenterSingleInteractor *PresenterSingleInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<PresenterSingleDTO> PresenterSingleInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetPresenterSingleQuery query;
        query.id = id;
        auto interface = static_cast<InterfacePresenterSingleRepository *>(m_repositoryProvider->repository("PresenterSingle"));
        GetPresenterSingleQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->presenterSingle()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "presenterSingle"_L1);

    // async wait for result signal
    const std::optional<PresenterSingleDTO> optional_result =
        co_await qCoro(m_eventDispatcher->presenterSingle(), &PresenterSingleSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return PresenterSingleDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterSingleWithDetailsDTO> PresenterSingleInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetPresenterSingleQuery query;
        query.id = id;
        auto interface = static_cast<InterfacePresenterSingleRepository *>(m_repositoryProvider->repository("PresenterSingle"));
        GetPresenterSingleWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->presenterSingle()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "presenterSingle"_L1);

    // async wait for result signal
    const std::optional<PresenterSingleWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->presenterSingle(), &PresenterSingleSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return PresenterSingleWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterSingleDTO> PresenterSingleInteractor::create(const CreatePresenterSingleDTO &dto)
{
    CreatePresenterSingleCommand query;

    query.req = dto;

    auto repository = static_cast<InterfacePresenterSingleRepository *>(m_repositoryProvider->repository("PresenterSingle"));

    auto *handler = new CreatePresenterSingleCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreatePresenterSingleCommandHandler::presenterSingleCreated,
                     m_eventDispatcher->presenterSingle(),
                     &PresenterSingleSignals::created);

    QObject::connect(handler, &CreatePresenterSingleCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = PresenterComponentRelationDTO(ownerId, PresenterComponentRelationDTO::RelationField::Singles, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->presenterComponent()->relationInserted(dto);
    });
    QObject::connect(handler, &CreatePresenterSingleCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = PresenterComponentRelationDTO(ownerId, PresenterComponentRelationDTO::RelationField::Singles, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->presenterComponent()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreatePresenterSingleCommandHandler::presenterSingleRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->presenterSingle()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreatePresenterSingleCommandHandler, CreatePresenterSingleCommand>(PresenterSingleInteractor::tr("Create presenterSingle"),
                                                                                                       handler,
                                                                                                       query);

    // push command
    m_undo_redo_system->push(command, "presenterSingle"_L1);

    // async wait for result signal
    const std::optional<PresenterSingleDTO> optional_result =
        co_await qCoro(handler, &CreatePresenterSingleCommandHandler::presenterSingleCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return PresenterSingleDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterSingleDTO> PresenterSingleInteractor::update(const UpdatePresenterSingleDTO &dto)
{
    UpdatePresenterSingleCommand query;

    query.req = dto;

    auto repository = static_cast<InterfacePresenterSingleRepository *>(m_repositoryProvider->repository("PresenterSingle"));

    auto *handler = new UpdatePresenterSingleCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdatePresenterSingleCommandHandler::presenterSingleUpdated, this, [this](PresenterSingleDTO dto) {
        Q_EMIT m_eventDispatcher->presenterSingle()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdatePresenterSingleCommandHandler::presenterSingleDetailsUpdated,
                     m_eventDispatcher->presenterSingle(),
                     &PresenterSingleSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdatePresenterSingleCommandHandler, UpdatePresenterSingleCommand>(PresenterSingleInteractor::tr("Update presenterSingle"),
                                                                                                       handler,
                                                                                                       query);

    // push command
    m_undo_redo_system->push(command, "presenterSingle"_L1);

    // async wait for result signal
    const std::optional<PresenterSingleDTO> optional_result =
        co_await qCoro(handler, &UpdatePresenterSingleCommandHandler::presenterSingleUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return PresenterSingleDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> PresenterSingleInteractor::remove(int id)
{
    RemovePresenterSingleCommand query;

    query.id = id;

    auto repository = static_cast<InterfacePresenterSingleRepository *>(m_repositoryProvider->repository("PresenterSingle"));

    auto *handler = new RemovePresenterSingleCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemovePresenterSingleCommandHandler, RemovePresenterSingleCommand>(PresenterSingleInteractor::tr("Remove presenterSingle"),
                                                                                                       handler,
                                                                                                       query);

    // push command
    m_undo_redo_system->push(command, "presenterSingle"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreatePresenterSingleDTO PresenterSingleInteractor::getCreateDTO()
{
    return CreatePresenterSingleDTO();
}

UpdatePresenterSingleDTO PresenterSingleInteractor::getUpdateDTO()
{
    return UpdatePresenterSingleDTO();
}
