// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "front_end_component_interactor.h"

#include "front_end_component/commands/create_front_end_component_command.h"
#include "front_end_component/commands/create_front_end_component_command_handler.h"
#include "front_end_component/commands/remove_front_end_component_command.h"
#include "front_end_component/commands/remove_front_end_component_command_handler.h"
#include "front_end_component/commands/update_front_end_component_command.h"
#include "front_end_component/commands/update_front_end_component_command_handler.h"
#include "front_end_component/queries/get_all_front_end_component_query_handler.h"
#include "front_end_component/queries/get_front_end_component_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::FrontEndComponent;
using namespace QleanyEditor::Application::Features::FrontEndComponent::Commands;
using namespace QleanyEditor::Application::Features::FrontEndComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<FrontEndComponentInteractor> FrontEndComponentInteractor::s_instance = nullptr;

FrontEndComponentInteractor::FrontEndComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

FrontEndComponentInteractor *FrontEndComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<FrontEndComponentDTO> FrontEndComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetFrontEndComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceFrontEndComponentRepository *>(m_repositoryProvider->repository("FrontEndComponent"));
        GetFrontEndComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->frontEndComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "frontEndComponent"_L1);

    // async wait for result signal
    const std::optional<FrontEndComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->frontEndComponent(), &FrontEndComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return FrontEndComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<QList<FrontEndComponentDTO>> FrontEndComponentInteractor::getAll() const
{
    auto queryCommand = new QueryCommand("getAll"_L1);

    queryCommand->setQueryFunction([&](QPromise<Result<void>> &progressPromise) {
        auto interface = static_cast<InterfaceFrontEndComponentRepository *>(m_repositoryProvider->repository("FrontEndComponent"));
        GetAllFrontEndComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->frontEndComponent()->getAllReplied(result.value());
        }
        return Result<void>(result.error());
    });
    m_undo_redo_system->push(queryCommand, "frontEndComponent"_L1);

    // async wait for result signal
    const std::optional<QList<FrontEndComponentDTO>> optional_result =
        co_await qCoro(m_eventDispatcher->frontEndComponent(), &FrontEndComponentSignals::getAllReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return QList<FrontEndComponentDTO>() << FrontEndComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<FrontEndComponentDTO> FrontEndComponentInteractor::create(const CreateFrontEndComponentDTO &dto)
{
    CreateFrontEndComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceFrontEndComponentRepository *>(m_repositoryProvider->repository("FrontEndComponent"));

    auto *handler = new CreateFrontEndComponentCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreateFrontEndComponentCommandHandler::frontEndComponentCreated,
                     m_eventDispatcher->frontEndComponent(),
                     &FrontEndComponentSignals::created);

    QObject::connect(handler, &CreateFrontEndComponentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::FrontEndComponent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->project()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateFrontEndComponentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::FrontEndComponent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->project()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateFrontEndComponentCommandHandler::frontEndComponentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->frontEndComponent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreateFrontEndComponentCommandHandler, CreateFrontEndComponentCommand>(FrontEndComponentInteractor::tr("Create frontEndComponent"),
                                                                                                handler,
                                                                                                query);

    // push command
    m_undo_redo_system->push(command, "frontEndComponent"_L1);

    // async wait for result signal
    const std::optional<FrontEndComponentDTO> optional_result =
        co_await qCoro(handler, &CreateFrontEndComponentCommandHandler::frontEndComponentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return FrontEndComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<FrontEndComponentDTO> FrontEndComponentInteractor::update(const UpdateFrontEndComponentDTO &dto)
{
    UpdateFrontEndComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceFrontEndComponentRepository *>(m_repositoryProvider->repository("FrontEndComponent"));

    auto *handler = new UpdateFrontEndComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateFrontEndComponentCommandHandler::frontEndComponentUpdated, this, [this](FrontEndComponentDTO dto) {
        Q_EMIT m_eventDispatcher->frontEndComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateFrontEndComponentCommandHandler::frontEndComponentDetailsUpdated,
                     m_eventDispatcher->frontEndComponent(),
                     &FrontEndComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdateFrontEndComponentCommandHandler, UpdateFrontEndComponentCommand>(FrontEndComponentInteractor::tr("Update frontEndComponent"),
                                                                                                handler,
                                                                                                query);

    // push command
    m_undo_redo_system->push(command, "frontEndComponent"_L1);

    // async wait for result signal
    const std::optional<FrontEndComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateFrontEndComponentCommandHandler::frontEndComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return FrontEndComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> FrontEndComponentInteractor::remove(int id)
{
    RemoveFrontEndComponentCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceFrontEndComponentRepository *>(m_repositoryProvider->repository("FrontEndComponent"));

    auto *handler = new RemoveFrontEndComponentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemoveFrontEndComponentCommandHandler, RemoveFrontEndComponentCommand>(FrontEndComponentInteractor::tr("Remove frontEndComponent"),
                                                                                                handler,
                                                                                                query);

    // push command
    m_undo_redo_system->push(command, "frontEndComponent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateFrontEndComponentDTO FrontEndComponentInteractor::getCreateDTO()
{
    return CreateFrontEndComponentDTO();
}

UpdateFrontEndComponentDTO FrontEndComponentInteractor::getUpdateDTO()
{
    return UpdateFrontEndComponentDTO();
}
