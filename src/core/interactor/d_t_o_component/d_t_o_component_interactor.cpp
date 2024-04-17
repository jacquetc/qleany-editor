// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "d_t_o_component_interactor.h"

#include "d_t_o_component/commands/create_d_t_o_component_command.h"
#include "d_t_o_component/commands/create_d_t_o_component_command_handler.h"
#include "d_t_o_component/commands/remove_d_t_o_component_command.h"
#include "d_t_o_component/commands/remove_d_t_o_component_command_handler.h"
#include "d_t_o_component/commands/update_d_t_o_component_command.h"
#include "d_t_o_component/commands/update_d_t_o_component_command_handler.h"
#include "d_t_o_component/queries/get_d_t_o_component_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::DTOComponent;
using namespace QleanyEditor::Application::Features::DTOComponent::Commands;
using namespace QleanyEditor::Application::Features::DTOComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<DTOComponentInteractor> DTOComponentInteractor::s_instance = nullptr;

DTOComponentInteractor::DTOComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

DTOComponentInteractor *DTOComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<DTOComponentDTO> DTOComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetDTOComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceDTOComponentRepository *>(m_repositoryProvider->repository("DTOComponent"));
        GetDTOComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->dTOComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "dTOComponent"_L1);

    // async wait for result signal
    const std::optional<DTOComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->dTOComponent(), &DTOComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return DTOComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<DTOComponentDTO> DTOComponentInteractor::create(const CreateDTOComponentDTO &dto)
{
    CreateDTOComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceDTOComponentRepository *>(m_repositoryProvider->repository("DTOComponent"));

    auto *handler = new CreateDTOComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateDTOComponentCommandHandler::dTOComponentCreated, m_eventDispatcher->dTOComponent(), &DTOComponentSignals::created);

    QObject::connect(handler, &CreateDTOComponentCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::DtoComponent, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->project()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateDTOComponentCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ProjectRelationDTO(ownerId, ProjectRelationDTO::RelationField::DtoComponent, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->project()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateDTOComponentCommandHandler::dTOComponentRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->dTOComponent()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreateDTOComponentCommandHandler, CreateDTOComponentCommand>(DTOComponentInteractor::tr("Create dTOComponent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "dTOComponent"_L1);

    // async wait for result signal
    const std::optional<DTOComponentDTO> optional_result =
        co_await qCoro(handler, &CreateDTOComponentCommandHandler::dTOComponentCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return DTOComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<DTOComponentDTO> DTOComponentInteractor::update(const UpdateDTOComponentDTO &dto)
{
    UpdateDTOComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceDTOComponentRepository *>(m_repositoryProvider->repository("DTOComponent"));

    auto *handler = new UpdateDTOComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateDTOComponentCommandHandler::dTOComponentUpdated, this, [this](DTOComponentDTO dto) {
        Q_EMIT m_eventDispatcher->dTOComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateDTOComponentCommandHandler::dTOComponentDetailsUpdated,
                     m_eventDispatcher->dTOComponent(),
                     &DTOComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdateDTOComponentCommandHandler, UpdateDTOComponentCommand>(DTOComponentInteractor::tr("Update dTOComponent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "dTOComponent"_L1);

    // async wait for result signal
    const std::optional<DTOComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateDTOComponentCommandHandler::dTOComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return DTOComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> DTOComponentInteractor::remove(int id)
{
    RemoveDTOComponentCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceDTOComponentRepository *>(m_repositoryProvider->repository("DTOComponent"));

    auto *handler = new RemoveDTOComponentCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemoveDTOComponentCommandHandler, RemoveDTOComponentCommand>(DTOComponentInteractor::tr("Remove dTOComponent"), handler, query);

    // push command
    m_undo_redo_system->push(command, "dTOComponent"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateDTOComponentDTO DTOComponentInteractor::getCreateDTO()
{
    return CreateDTOComponentDTO();
}

UpdateDTOComponentDTO DTOComponentInteractor::getUpdateDTO()
{
    return UpdateDTOComponentDTO();
}
