// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "application_component_interactor.h"

#include "application_component/commands/create_application_component_command.h"
#include "application_component/commands/create_application_component_command_handler.h"
#include "application_component/commands/remove_application_component_command.h"
#include "application_component/commands/remove_application_component_command_handler.h"
#include "application_component/commands/update_application_component_command.h"
#include "application_component/commands/update_application_component_command_handler.h"
#include "application_component/queries/get_application_component_query_handler.h"
#include "application_component/queries/get_application_component_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::ApplicationComponent;
using namespace QleanyEditor::Application::Features::ApplicationComponent::Commands;
using namespace QleanyEditor::Application::Features::ApplicationComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<ApplicationComponentInteractor> ApplicationComponentInteractor::s_instance = nullptr;

ApplicationComponentInteractor::ApplicationComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

ApplicationComponentInteractor *ApplicationComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<ApplicationComponentDTO> ApplicationComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetApplicationComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceApplicationComponentRepository *>(m_repositoryProvider->repository("ApplicationComponent"));
        GetApplicationComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->applicationComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "applicationComponent"_L1);

    // async wait for result signal
    const std::optional<ApplicationComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->applicationComponent(), &ApplicationComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return ApplicationComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<ApplicationComponentWithDetailsDTO> ApplicationComponentInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetApplicationComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceApplicationComponentRepository *>(m_repositoryProvider->repository("ApplicationComponent"));
        GetApplicationComponentWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->applicationComponent()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "applicationComponent"_L1);

    // async wait for result signal
    const std::optional<ApplicationComponentWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->applicationComponent(), &ApplicationComponentSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return ApplicationComponentWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<ApplicationComponentDTO> ApplicationComponentInteractor::create(const CreateApplicationComponentDTO &dto)
{
    CreateApplicationComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceApplicationComponentRepository *>(m_repositoryProvider->repository("ApplicationComponent"));

    auto *handler = new CreateApplicationComponentCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreateApplicationComponentCommandHandler::applicationComponentCreated,
                     m_eventDispatcher->applicationComponent(),
                     &ApplicationComponentSignals::created);

    QObject::connect(handler, &CreateApplicationComponentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::ApplicationComponent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->project()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateApplicationComponentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::ApplicationComponent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->project()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateApplicationComponentCommandHandler::applicationComponentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->applicationComponent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateApplicationComponentCommandHandler, CreateApplicationComponentCommand>(
        ApplicationComponentInteractor::tr("Create applicationComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "applicationComponent"_L1);

    // async wait for result signal
    const std::optional<ApplicationComponentDTO> optional_result =
        co_await qCoro(handler, &CreateApplicationComponentCommandHandler::applicationComponentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return ApplicationComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<ApplicationComponentDTO> ApplicationComponentInteractor::update(const UpdateApplicationComponentDTO &dto)
{
    UpdateApplicationComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceApplicationComponentRepository *>(m_repositoryProvider->repository("ApplicationComponent"));

    auto *handler = new UpdateApplicationComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateApplicationComponentCommandHandler::applicationComponentUpdated, this, [this](ApplicationComponentDTO dto) {
        Q_EMIT m_eventDispatcher->applicationComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateApplicationComponentCommandHandler::applicationComponentDetailsUpdated,
                     m_eventDispatcher->applicationComponent(),
                     &ApplicationComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateApplicationComponentCommandHandler, UpdateApplicationComponentCommand>(
        ApplicationComponentInteractor::tr("Update applicationComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "applicationComponent"_L1);

    // async wait for result signal
    const std::optional<ApplicationComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateApplicationComponentCommandHandler::applicationComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return ApplicationComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> ApplicationComponentInteractor::remove(int id)
{
    RemoveApplicationComponentCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceApplicationComponentRepository *>(m_repositoryProvider->repository("ApplicationComponent"));

    auto *handler = new RemoveApplicationComponentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveApplicationComponentCommandHandler, RemoveApplicationComponentCommand>(
        ApplicationComponentInteractor::tr("Remove applicationComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "applicationComponent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateApplicationComponentDTO ApplicationComponentInteractor::getCreateDTO()
{
    return CreateApplicationComponentDTO();
}

UpdateApplicationComponentDTO ApplicationComponentInteractor::getUpdateDTO()
{
    return UpdateApplicationComponentDTO();
}
