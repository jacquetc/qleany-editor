// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "presenter_component_interactor.h"

#include "presenter_component/commands/create_presenter_component_command.h"
#include "presenter_component/commands/create_presenter_component_command_handler.h"
#include "presenter_component/commands/remove_presenter_component_command.h"
#include "presenter_component/commands/remove_presenter_component_command_handler.h"
#include "presenter_component/commands/update_presenter_component_command.h"
#include "presenter_component/commands/update_presenter_component_command_handler.h"
#include "presenter_component/queries/get_presenter_component_query_handler.h"
#include "presenter_component/queries/get_presenter_component_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::PresenterComponent;
using namespace QleanyEditor::Application::Features::PresenterComponent::Commands;
using namespace QleanyEditor::Application::Features::PresenterComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<PresenterComponentInteractor> PresenterComponentInteractor::s_instance = nullptr;

PresenterComponentInteractor::PresenterComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

PresenterComponentInteractor *PresenterComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<PresenterComponentDTO> PresenterComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetPresenterComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfacePresenterComponentRepository *>(m_repositoryProvider->repository("PresenterComponent"));
        GetPresenterComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->presenterComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "presenterComponent"_L1);

    // async wait for result signal
    const std::optional<PresenterComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->presenterComponent(), &PresenterComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return PresenterComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterComponentWithDetailsDTO> PresenterComponentInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetPresenterComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfacePresenterComponentRepository *>(m_repositoryProvider->repository("PresenterComponent"));
        GetPresenterComponentWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->presenterComponent()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "presenterComponent"_L1);

    // async wait for result signal
    const std::optional<PresenterComponentWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->presenterComponent(), &PresenterComponentSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return PresenterComponentWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterComponentDTO> PresenterComponentInteractor::create(const CreatePresenterComponentDTO &dto)
{
    CreatePresenterComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfacePresenterComponentRepository *>(m_repositoryProvider->repository("PresenterComponent"));

    auto *handler = new CreatePresenterComponentCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreatePresenterComponentCommandHandler::presenterComponentCreated,
                     m_eventDispatcher->presenterComponent(),
                     &PresenterComponentSignals::created);

    QObject::connect(handler, &CreatePresenterComponentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::PresenterComponent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->project()->relationInserted(dto);
    });
    QObject::connect(handler, &CreatePresenterComponentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::PresenterComponent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->project()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreatePresenterComponentCommandHandler::presenterComponentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->presenterComponent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreatePresenterComponentCommandHandler, CreatePresenterComponentCommand>(PresenterComponentInteractor::tr("Create presenterComponent"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "presenterComponent"_L1);

    // async wait for result signal
    const std::optional<PresenterComponentDTO> optional_result =
        co_await qCoro(handler, &CreatePresenterComponentCommandHandler::presenterComponentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return PresenterComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<PresenterComponentDTO> PresenterComponentInteractor::update(const UpdatePresenterComponentDTO &dto)
{
    UpdatePresenterComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfacePresenterComponentRepository *>(m_repositoryProvider->repository("PresenterComponent"));

    auto *handler = new UpdatePresenterComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdatePresenterComponentCommandHandler::presenterComponentUpdated, this, [this](PresenterComponentDTO dto) {
        Q_EMIT m_eventDispatcher->presenterComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdatePresenterComponentCommandHandler::presenterComponentDetailsUpdated,
                     m_eventDispatcher->presenterComponent(),
                     &PresenterComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdatePresenterComponentCommandHandler, UpdatePresenterComponentCommand>(PresenterComponentInteractor::tr("Update presenterComponent"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "presenterComponent"_L1);

    // async wait for result signal
    const std::optional<PresenterComponentDTO> optional_result =
        co_await qCoro(handler, &UpdatePresenterComponentCommandHandler::presenterComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return PresenterComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> PresenterComponentInteractor::remove(int id)
{
    RemovePresenterComponentCommand query;

    query.id = id;

    auto repository = static_cast<InterfacePresenterComponentRepository *>(m_repositoryProvider->repository("PresenterComponent"));

    auto *handler = new RemovePresenterComponentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemovePresenterComponentCommandHandler, RemovePresenterComponentCommand>(PresenterComponentInteractor::tr("Remove presenterComponent"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "presenterComponent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreatePresenterComponentDTO PresenterComponentInteractor::getCreateDTO()
{
    return CreatePresenterComponentDTO();
}

UpdatePresenterComponentDTO PresenterComponentInteractor::getUpdateDTO()
{
    return UpdatePresenterComponentDTO();
}
