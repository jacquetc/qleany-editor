// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "application_feature_interactor.h"

#include "application_feature/commands/create_application_feature_command.h"
#include "application_feature/commands/create_application_feature_command_handler.h"
#include "application_feature/commands/remove_application_feature_command.h"
#include "application_feature/commands/remove_application_feature_command_handler.h"
#include "application_feature/commands/update_application_feature_command.h"
#include "application_feature/commands/update_application_feature_command_handler.h"
#include "application_feature/queries/get_application_feature_query_handler.h"
#include "application_feature/queries/get_application_feature_with_details_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::ApplicationFeature;
using namespace QleanyEditor::Application::Features::ApplicationFeature::Commands;
using namespace QleanyEditor::Application::Features::ApplicationFeature::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<ApplicationFeatureInteractor> ApplicationFeatureInteractor::s_instance = nullptr;

ApplicationFeatureInteractor::ApplicationFeatureInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

ApplicationFeatureInteractor *ApplicationFeatureInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<ApplicationFeatureDTO> ApplicationFeatureInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetApplicationFeatureQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceApplicationFeatureRepository *>(m_repositoryProvider->repository("ApplicationFeature"));
        GetApplicationFeatureQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->applicationFeature()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "applicationFeature"_L1);

    // async wait for result signal
    const std::optional<ApplicationFeatureDTO> optional_result =
        co_await qCoro(m_eventDispatcher->applicationFeature(), &ApplicationFeatureSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return ApplicationFeatureDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<ApplicationFeatureWithDetailsDTO> ApplicationFeatureInteractor::getWithDetails(int id) const
{
    auto queryCommand = new QueryCommand("getWithDetails"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetApplicationFeatureQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceApplicationFeatureRepository *>(m_repositoryProvider->repository("ApplicationFeature"));
        GetApplicationFeatureWithDetailsQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->applicationFeature()->getWithDetailsReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "applicationFeature"_L1);

    // async wait for result signal
    const std::optional<ApplicationFeatureWithDetailsDTO> optional_result =
        co_await qCoro(m_eventDispatcher.get()->applicationFeature(), &ApplicationFeatureSignals::getWithDetailsReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return ApplicationFeatureWithDetailsDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<ApplicationFeatureDTO> ApplicationFeatureInteractor::create(const CreateApplicationFeatureDTO &dto)
{
    CreateApplicationFeatureCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceApplicationFeatureRepository *>(m_repositoryProvider->repository("ApplicationFeature"));

    auto *handler = new CreateApplicationFeatureCommandHandler(repository);

    // connect
    QObject::connect(handler,
                     &CreateApplicationFeatureCommandHandler::applicationFeatureCreated,
                     m_eventDispatcher->applicationFeature(),
                     &ApplicationFeatureSignals::created);

    QObject::connect(handler, &CreateApplicationFeatureCommandHandler::relationWithOwnerInserted, this, [this](int id, int ownerId, int position) {
        auto dto = ApplicationComponentRelationDTO(ownerId, ApplicationComponentRelationDTO::RelationField::Features, QList<int>() << id, position);
        Q_EMIT m_eventDispatcher->applicationComponent()->relationInserted(dto);
    });
    QObject::connect(handler, &CreateApplicationFeatureCommandHandler::relationWithOwnerRemoved, this, [this](int id, int ownerId) {
        auto dto = ApplicationComponentRelationDTO(ownerId, ApplicationComponentRelationDTO::RelationField::Features, QList<int>() << id, -1);
        Q_EMIT m_eventDispatcher->applicationComponent()->relationRemoved(dto);
    });

    QObject::connect(handler, &CreateApplicationFeatureCommandHandler::applicationFeatureRemoved, this, [this](int removedId) {
        Q_EMIT m_eventDispatcher->applicationFeature()->removed(QList<int>() << removedId);
    });

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<CreateApplicationFeatureCommandHandler, CreateApplicationFeatureCommand>(ApplicationFeatureInteractor::tr("Create applicationFeature"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "applicationFeature"_L1);

    // async wait for result signal
    const std::optional<ApplicationFeatureDTO> optional_result =
        co_await qCoro(handler, &CreateApplicationFeatureCommandHandler::applicationFeatureCreated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return ApplicationFeatureDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<ApplicationFeatureDTO> ApplicationFeatureInteractor::update(const UpdateApplicationFeatureDTO &dto)
{
    UpdateApplicationFeatureCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceApplicationFeatureRepository *>(m_repositoryProvider->repository("ApplicationFeature"));

    auto *handler = new UpdateApplicationFeatureCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateApplicationFeatureCommandHandler::applicationFeatureUpdated, this, [this](ApplicationFeatureDTO dto) {
        Q_EMIT m_eventDispatcher->applicationFeature()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateApplicationFeatureCommandHandler::applicationFeatureDetailsUpdated,
                     m_eventDispatcher->applicationFeature(),
                     &ApplicationFeatureSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<UpdateApplicationFeatureCommandHandler, UpdateApplicationFeatureCommand>(ApplicationFeatureInteractor::tr("Update applicationFeature"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "applicationFeature"_L1);

    // async wait for result signal
    const std::optional<ApplicationFeatureDTO> optional_result =
        co_await qCoro(handler, &UpdateApplicationFeatureCommandHandler::applicationFeatureUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return ApplicationFeatureDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<bool> ApplicationFeatureInteractor::remove(int id)
{
    RemoveApplicationFeatureCommand query;

    query.id = id;

    auto repository = static_cast<InterfaceApplicationFeatureRepository *>(m_repositoryProvider->repository("ApplicationFeature"));

    auto *handler = new RemoveApplicationFeatureCommandHandler(repository);

    // connect
    // no need to connect to removed signal, because it will be emitted by the repository itself

    // Create specialized UndoRedoCommand
    auto command =
        new AlterCommand<RemoveApplicationFeatureCommandHandler, RemoveApplicationFeatureCommand>(ApplicationFeatureInteractor::tr("Remove applicationFeature"),
                                                                                                  handler,
                                                                                                  query);

    // push command
    m_undo_redo_system->push(command, "applicationFeature"_L1);

    // async wait for result signal
    const std::optional<QList<int>> optional_result = co_await qCoro(repository->signalHolder(), &SignalHolder::removed, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return false;
    }

    co_return true;
}

CreateApplicationFeatureDTO ApplicationFeatureInteractor::getCreateDTO()
{
    return CreateApplicationFeatureDTO();
}

UpdateApplicationFeatureDTO ApplicationFeatureInteractor::getUpdateDTO()
{
    return UpdateApplicationFeatureDTO();
}
