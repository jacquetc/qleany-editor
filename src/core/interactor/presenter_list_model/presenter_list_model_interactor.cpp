// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "presenter_list_model_interactor.h"

#include "presenter_list_model/commands/create_presenter_list_model_command.h"
#include "presenter_list_model/commands/create_presenter_list_model_command_handler.h"
#include "presenter_list_model/commands/remove_presenter_list_model_command.h"
#include "presenter_list_model/commands/remove_presenter_list_model_command_handler.h"
#include "presenter_list_model/commands/update_presenter_list_model_command.h"
#include "presenter_list_model/commands/update_presenter_list_model_command_handler.h"
#include "presenter_list_model/queries/get_presenter_list_model_query_handler.h"
#include "presenter_list_model/queries/get_presenter_list_model_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::PresenterListModel;
using namespace QleanyEditor::Application::Features::PresenterListModel::Commands;
using namespace QleanyEditor::Application::Features::PresenterListModel::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<PresenterListModelInteractor> PresenterListModelInteractor::s_instance = nullptr;

PresenterListModelInteractor::PresenterListModelInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

PresenterListModelInteractor *PresenterListModelInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<PresenterListModelDTO> PresenterListModelInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetPresenterListModelQuery query;
        query.id = id;
        auto interface = static_cast<InterfacePresenterListModelRepository *>(m_repositoryProvider->repository("PresenterListModel"));
        GetPresenterListModelQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->presenterListModel()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "presenterListModel"_L1);

    // async wait for result signal
    const std::optional<PresenterListModelDTO> optional_result =
        co_await qCoro(m_eventDispatcher->presenterListModel(), &PresenterListModelSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return PresenterListModelDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterListModelWithDetailsDTO> PresenterListModelInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetPresenterListModelQuery query;
        query.id = id;
        auto interface = static_cast<InterfacePresenterListModelRepository *>(m_repositoryProvider->repository("PresenterListModel"));
        GetPresenterListModelWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->presenterListModel()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "presenterListModel"_L1);

    // async wait for result signal
    const std::optional<PresenterListModelWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->presenterListModel(), &PresenterListModelSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return PresenterListModelWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterListModelDTO> PresenterListModelInteractor::create(const CreatePresenterListModelDTO &dto)
{
    CreatePresenterListModelCommand query;

    query.req = dto;

    auto repository = static_cast<InterfacePresenterListModelRepository *>(m_repositoryProvider->repository("PresenterListModel"));

    auto *handler = new CreatePresenterListModelCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreatePresenterListModelCommandHandler::presenterListModelCreated,
                     m_eventDispatcher->presenterListModel(),
                     &PresenterListModelSignals::created);

    QObject::connect(handler, &CreatePresenterListModelCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = PresenterComponentRelationDTO(ownerId, PresenterComponentRelationDTO::RelationField::ListModels, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->presenterComponent()->relationInserted(dto);
    });
    QObject::connect(handler, &CreatePresenterListModelCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = PresenterComponentRelationDTO(ownerId, PresenterComponentRelationDTO::RelationField::ListModels, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->presenterComponent()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreatePresenterListModelCommandHandler::presenterListModelRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->presenterListModel()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreatePresenterListModelCommandHandler, CreatePresenterListModelCommand>(PresenterListModelInteractor::tr("Create presenterListModel"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "presenterListModel"_L1);

    // async wait for result signal
    const std::optional<PresenterListModelDTO> optional_result =
        co_await qCoro(handler, &CreatePresenterListModelCommandHandler::presenterListModelCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return PresenterListModelDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterListModelDTO> PresenterListModelInteractor::update(const UpdatePresenterListModelDTO &dto)
{
    UpdatePresenterListModelCommand query;

    query.req = dto;

    auto repository = static_cast<InterfacePresenterListModelRepository *>(m_repositoryProvider->repository("PresenterListModel"));

    auto *handler = new UpdatePresenterListModelCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdatePresenterListModelCommandHandler::presenterListModelUpdated, this, [this](PresenterListModelDTO dto) {
        Q_EMIT m_eventDispatcher->presenterListModel()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdatePresenterListModelCommandHandler::presenterListModelDetailsUpdated,
                     m_eventDispatcher->presenterListModel(),
                     &PresenterListModelSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdatePresenterListModelCommandHandler, UpdatePresenterListModelCommand>(PresenterListModelInteractor::tr("Update presenterListModel"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "presenterListModel"_L1);

    // async wait for result signal
    const std::optional<PresenterListModelDTO> optional_result =
        co_await qCoro(handler, &UpdatePresenterListModelCommandHandler::presenterListModelUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return PresenterListModelDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> PresenterListModelInteractor::remove(int id)
{
    RemovePresenterListModelCommand query;

    query.id = id;

    auto repository = static_cast<InterfacePresenterListModelRepository *>(m_repositoryProvider->repository("PresenterListModel"));

    auto *handler = new RemovePresenterListModelCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemovePresenterListModelCommandHandler, RemovePresenterListModelCommand>(PresenterListModelInteractor::tr("Remove presenterListModel"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "presenterListModel"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreatePresenterListModelDTO PresenterListModelInteractor::getCreateDTO()
{
    return CreatePresenterListModelDTO();
}

UpdatePresenterListModelDTO PresenterListModelInteractor::getUpdateDTO()
{
    return UpdatePresenterListModelDTO();
}
