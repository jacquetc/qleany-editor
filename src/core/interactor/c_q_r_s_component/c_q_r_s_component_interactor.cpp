// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "c_q_r_s_component_interactor.h"

#include "c_q_r_s_component/commands/create_c_q_r_s_component_command.h"
#include "c_q_r_s_component/commands/create_c_q_r_s_component_command_handler.h"
#include "c_q_r_s_component/commands/remove_c_q_r_s_component_command.h"
#include "c_q_r_s_component/commands/remove_c_q_r_s_component_command_handler.h"
#include "c_q_r_s_component/commands/update_c_q_r_s_component_command.h"
#include "c_q_r_s_component/commands/update_c_q_r_s_component_command_handler.h"
#include "c_q_r_s_component/queries/get_c_q_r_s_component_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::CQRSComponent;
using namespace QleanyEditor::Application::Features::CQRSComponent::Commands;
using namespace QleanyEditor::Application::Features::CQRSComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<CQRSComponentInteractor> CQRSComponentInteractor::s_instance = nullptr;

CQRSComponentInteractor::CQRSComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

CQRSComponentInteractor *CQRSComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<CQRSComponentDTO> CQRSComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCQRSComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCQRSComponentRepository *>(m_repositoryProvider->repository("CQRSComponent"));
        GetCQRSComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->cQRSComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "cQRSComponent"_L1);

    // async wait for result signal
    const std::optional<CQRSComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->cQRSComponent(), &CQRSComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CQRSComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CQRSComponentDTO> CQRSComponentInteractor::create(const CreateCQRSComponentDTO &dto)
{
    CreateCQRSComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCQRSComponentRepository *>(m_repositoryProvider->repository("CQRSComponent"));

    auto *handler = new CreateCQRSComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateCQRSComponentCommandHandler::cQRSComponentCreated, m_eventDispatcher->cQRSComponent(), &CQRSComponentSignals::created);

    QObject::connect(handler, &CreateCQRSComponentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::CqrsComponent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->project()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateCQRSComponentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::CqrsComponent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->project()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateCQRSComponentCommandHandler::cQRSComponentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->cQRSComponent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreateCQRSComponentCommandHandler, CreateCQRSComponentCommand>(CQRSComponentInteractor::tr("Create cQRSComponent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "cQRSComponent"_L1);

    // async wait for result signal
    const std::optional<CQRSComponentDTO> optional_result =
        co_await qCoro(handler, &CreateCQRSComponentCommandHandler::cQRSComponentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CQRSComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CQRSComponentDTO> CQRSComponentInteractor::update(const UpdateCQRSComponentDTO &dto)
{
    UpdateCQRSComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCQRSComponentRepository *>(m_repositoryProvider->repository("CQRSComponent"));

    auto *handler = new UpdateCQRSComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateCQRSComponentCommandHandler::cQRSComponentUpdated, this, [this](CQRSComponentDTO dto) {
        Q_EMIT m_eventDispatcher->cQRSComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateCQRSComponentCommandHandler::cQRSComponentDetailsUpdated,
                     m_eventDispatcher->cQRSComponent(),
                     &CQRSComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdateCQRSComponentCommandHandler, UpdateCQRSComponentCommand>(CQRSComponentInteractor::tr("Update cQRSComponent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "cQRSComponent"_L1);

    // async wait for result signal
    const std::optional<CQRSComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateCQRSComponentCommandHandler::cQRSComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CQRSComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> CQRSComponentInteractor::remove(int id)
{
    RemoveCQRSComponentCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceCQRSComponentRepository *>(m_repositoryProvider->repository("CQRSComponent"));

    auto *handler = new RemoveCQRSComponentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemoveCQRSComponentCommandHandler, RemoveCQRSComponentCommand>(CQRSComponentInteractor::tr("Remove cQRSComponent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "cQRSComponent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateCQRSComponentDTO CQRSComponentInteractor::getCreateDTO()
{
    return CreateCQRSComponentDTO();
}

UpdateCQRSComponentDTO CQRSComponentInteractor::getUpdateDTO()
{
    return UpdateCQRSComponentDTO();
}
