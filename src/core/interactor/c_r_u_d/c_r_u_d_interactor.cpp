// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "c_r_u_d_interactor.h"

#include "c_r_u_d/commands/create_c_r_u_d_command.h"
#include "c_r_u_d/commands/create_c_r_u_d_command_handler.h"
#include "c_r_u_d/commands/remove_c_r_u_d_command.h"
#include "c_r_u_d/commands/remove_c_r_u_d_command_handler.h"
#include "c_r_u_d/commands/update_c_r_u_d_command.h"
#include "c_r_u_d/commands/update_c_r_u_d_command_handler.h"
#include "c_r_u_d/queries/get_c_r_u_d_query_handler.h"
#include "c_r_u_d/queries/get_c_r_u_d_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::CRUD;
using namespace QleanyEditor::Application::Features::CRUD::Commands;
using namespace QleanyEditor::Application::Features::CRUD::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<CRUDInteractor> CRUDInteractor::s_instance = nullptr;

CRUDInteractor::CRUDInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

CRUDInteractor *CRUDInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<CRUDDTO> CRUDInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCRUDQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCRUDRepository *>(m_repositoryProvider->repository("CRUD"));
        GetCRUDQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->cRUD()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "cRUD"_L1);

    // async wait for result signal
    const std::optional<CRUDDTO> optional_result = co_await qCoro(m_eventDispatcher->cRUD(), &CRUDSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CRUDDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CRUDWithDetailsDTO> CRUDInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetCRUDQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceCRUDRepository *>(m_repositoryProvider->repository("CRUD"));
        GetCRUDWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->cRUD()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "cRUD"_L1);

    // async wait for result signal
    const std::optional<CRUDWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->cRUD(), &CRUDSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return CRUDWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CRUDDTO> CRUDInteractor::create(const CreateCRUDDTO &dto)
{
    CreateCRUDCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCRUDRepository *>(m_repositoryProvider->repository("CRUD"));

    auto *handler = new CreateCRUDCommandHandler(repository);

    // connect
    QObject::connect(handler, &CreateCRUDCommandHandler::cRUDCreated, m_eventDispatcher->cRUD(), &CRUDSignals::created);

    QObject::connect(handler, &CreateCRUDCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ApplicationFeatureRelationDTO(ownerId, ApplicationFeatureRelationDTO::RelationField::Crud, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->applicationFeature()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateCRUDCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ApplicationFeatureRelationDTO(ownerId, ApplicationFeatureRelationDTO::RelationField::Crud, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->applicationFeature()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateCRUDCommandHandler::cRUDRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->cRUD()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<CreateCRUDCommandHandler, CreateCRUDCommand>(CRUDInteractor::tr("Create cRUD"), handler, query);

    // push command
    m_undo_redo_system->push(command, "cRUD"_L1);

    // async wait for result signal
    const std::optional<CRUDDTO> optional_result = co_await qCoro(handler, &CreateCRUDCommandHandler::cRUDCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CRUDDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<CRUDDTO> CRUDInteractor::update(const UpdateCRUDDTO &dto)
{
    UpdateCRUDCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceCRUDRepository *>(m_repositoryProvider->repository("CRUD"));

    auto *handler = new UpdateCRUDCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateCRUDCommandHandler::cRUDUpdated, this, [this](CRUDDTO dto) {
        Q_EMIT m_eventDispatcher->cRUD()->updated(dto);
    });
    QObject::connect(handler, &UpdateCRUDCommandHandler::cRUDDetailsUpdated, m_eventDispatcher->cRUD(), &CRUDSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateCRUDCommandHandler, UpdateCRUDCommand>(CRUDInteractor::tr("Update cRUD"), handler, query);

    // push command
    m_undo_redo_system->push(command, "cRUD"_L1);

    // async wait for result signal
    const std::optional<CRUDDTO> optional_result = co_await qCoro(handler, &UpdateCRUDCommandHandler::cRUDUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return CRUDDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> CRUDInteractor::remove(int id)
{
    RemoveCRUDCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceCRUDRepository *>(m_repositoryProvider->repository("CRUD"));

    auto *handler = new RemoveCRUDCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<RemoveCRUDCommandHandler, RemoveCRUDCommand>(CRUDInteractor::tr("Remove cRUD"), handler, query);

    // push command
    m_undo_redo_system->push(command, "cRUD"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateCRUDDTO CRUDInteractor::getCreateDTO()
{
    return CreateCRUDDTO();
}

UpdateCRUDDTO CRUDInteractor::getUpdateDTO()
{
    return UpdateCRUDDTO();
}
