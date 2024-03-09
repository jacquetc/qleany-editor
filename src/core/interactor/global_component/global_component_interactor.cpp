// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "global_component_interactor.h"

#include "global_component/commands/update_global_component_command.h"
#include "global_component/commands/update_global_component_command_handler.h"
#include "global_component/queries/get_global_component_query_handler.h"
#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::GlobalComponent;
using namespace QleanyEditor::Application::Features::GlobalComponent::Commands;
using namespace QleanyEditor::Application::Features::GlobalComponent::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<GlobalComponentInteractor> GlobalComponentInteractor::s_instance = nullptr;

GlobalComponentInteractor::GlobalComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

GlobalComponentInteractor *GlobalComponentInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<GlobalComponentDTO> GlobalComponentInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get"_L1);

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetGlobalComponentQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceGlobalComponentRepository *>(m_repositoryProvider->repository("GlobalComponent"));
        GetGlobalComponentQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            Q_EMIT m_eventDispatcher->globalComponent()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "globalComponent"_L1);

    // async wait for result signal
    const std::optional<GlobalComponentDTO> optional_result =
        co_await qCoro(m_eventDispatcher->globalComponent(), &GlobalComponentSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return GlobalComponentDTO();
    }

    co_return optional_result.value();
}

QCoro::Task<GlobalComponentDTO> GlobalComponentInteractor::update(const UpdateGlobalComponentDTO &dto)
{
    UpdateGlobalComponentCommand query;

    query.req = dto;

    auto repository = static_cast<InterfaceGlobalComponentRepository *>(m_repositoryProvider->repository("GlobalComponent"));

    auto *handler = new UpdateGlobalComponentCommandHandler(repository);

    // connect
    QObject::connect(handler, &UpdateGlobalComponentCommandHandler::globalComponentUpdated, this, [this](GlobalComponentDTO dto) {
        Q_EMIT m_eventDispatcher->globalComponent()->updated(dto);
    });
    QObject::connect(handler,
                     &UpdateGlobalComponentCommandHandler::globalComponentDetailsUpdated,
                     m_eventDispatcher->globalComponent(),
                     &GlobalComponentSignals::allRelationsInvalidated);

    // Create specialized UndoRedoCommand
    auto command = new AlterCommand<UpdateGlobalComponentCommandHandler, UpdateGlobalComponentCommand>(GlobalComponentInteractor::tr("Update globalComponent"),
                                                                                                       handler,
                                                                                                       query);

    // push command
    m_undo_redo_system->push(command, "globalComponent"_L1);

    // async wait for result signal
    const std::optional<GlobalComponentDTO> optional_result =
        co_await qCoro(handler, &UpdateGlobalComponentCommandHandler::globalComponentUpdated, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        co_return GlobalComponentDTO();
    }

    co_return optional_result.value();
}

UpdateGlobalComponentDTO GlobalComponentInteractor::getUpdateDTO()
{
    return UpdateGlobalComponentDTO();
}
