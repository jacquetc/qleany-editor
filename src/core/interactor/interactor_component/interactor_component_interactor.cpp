// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "interactor_component_interactor.h"

#include "interactor_component/commands/create_interactor_component_command.h"
#include "interactor_component/commands/create_interactor_component_command_handler.h"
#include "interactor_component/commands/remove_interactor_component_command.h"
#include "interactor_component/commands/remove_interactor_component_command_handler.h"
#include "interactor_component/commands/update_interactor_component_command.h"
#include "interactor_component/commands/update_interactor_component_command_handler.h"
#include "interactor_component/queries/get_interactor_component_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::InteractorComponent;
using namespace QleanyEditor::Application::Features::InteractorComponent::Commands;
using namespace QleanyEditor::Application::Features::InteractorComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<InteractorComponentInteractor> InteractorComponentInteractor::s_instance = nullptr;

InteractorComponentInteractor::InteractorComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

InteractorComponentInteractor *InteractorComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<InteractorComponentDTO> InteractorComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetInteractorComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceInteractorComponentRepository *>(m_repositoryProvider->repository("InteractorComponent"));
        GetInteractorComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->interactorComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "interactorComponent"_L1);

    // async wait for result signal
    const std::optional<InteractorComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->interactorComponent(), &InteractorComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return InteractorComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<InteractorComponentDTO> InteractorComponentInteractor::create(const CreateInteractorComponentDTO &dto)
{
    CreateInteractorComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceInteractorComponentRepository *>(m_repositoryProvider->repository("InteractorComponent"));

    auto *handler = new CreateInteractorComponentCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreateInteractorComponentCommandHandler::interactorComponentCreated,
                     m_eventDispatcher->interactorComponent(),
                     &InteractorComponentSignals::created);

    QObject::connect(handler, &CreateInteractorComponentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::InteractorComponent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->project()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateInteractorComponentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::InteractorComponent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->project()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateInteractorComponentCommandHandler::interactorComponentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->interactorComponent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateInteractorComponentCommandHandler, CreateInteractorComponentCommand>(
        InteractorComponentInteractor::tr("Create interactorComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "interactorComponent"_L1);

    // async wait for result signal
    const std::optional<InteractorComponentDTO> optional_result =
        co_await qCoro(handler, &CreateInteractorComponentCommandHandler::interactorComponentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return InteractorComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<InteractorComponentDTO> InteractorComponentInteractor::update(const UpdateInteractorComponentDTO &dto)
{
    UpdateInteractorComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceInteractorComponentRepository *>(m_repositoryProvider->repository("InteractorComponent"));

    auto *handler = new UpdateInteractorComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateInteractorComponentCommandHandler::interactorComponentUpdated, this, [this](InteractorComponentDTO dto) {
        Q_EMIT m_eventDispatcher->interactorComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateInteractorComponentCommandHandler::interactorComponentDetailsUpdated,
                     m_eventDispatcher->interactorComponent(),
                     &InteractorComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateInteractorComponentCommandHandler, UpdateInteractorComponentCommand>(
        InteractorComponentInteractor::tr("Update interactorComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "interactorComponent"_L1);

    // async wait for result signal
    const std::optional<InteractorComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateInteractorComponentCommandHandler::interactorComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return InteractorComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> InteractorComponentInteractor::remove(int id)
{
    RemoveInteractorComponentCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceInteractorComponentRepository *>(m_repositoryProvider->repository("InteractorComponent"));

    auto *handler = new RemoveInteractorComponentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveInteractorComponentCommandHandler, RemoveInteractorComponentCommand>(
        InteractorComponentInteractor::tr("Remove interactorComponent"),
        handler,
        query);

    // push command
    m_undo_redo_system->push(command, "interactorComponent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateInteractorComponentDTO InteractorComponentInteractor::getCreateDTO()
{
    return CreateInteractorComponentDTO();
}

UpdateInteractorComponentDTO InteractorComponentInteractor::getUpdateDTO()
{
    return UpdateInteractorComponentDTO();
}
