// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.

#include "root_interactor.h"

#include "qleany/tools/undo_redo/alter_command.h"
#include "qleany/tools/undo_redo/query_command.h"
#include "root/queries/get_root_query_handler.h"
#include <QCoroSignal>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Interactor::Root;
using namespace QleanyEditor::Application::Features::Root::Queries;
using namespace Qleany::Tools::UndoRedo;
using namespace Qleany::Contracts::Repository;

QPointer<RootInteractor> RootInteractor::s_instance = nullptr;

RootInteractor::RootInteractor(InterfaceRepositoryProvider *repositoryProvider,
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

RootInteractor *RootInteractor::instance()
{
    return s_instance.data();
}

QCoro::Task<RootDTO> RootInteractor::get(int id) const
{
    auto queryCommand = new QueryCommand("get");

    queryCommand->setQueryFunction([this, id](QPromise<Result<void>> &progressPromise) {
        GetRootQuery query;
        query.id = id;
        auto interface = static_cast<InterfaceRootRepository *>(m_repositoryProvider->repository("Root"));
        GetRootQueryHandler handler(interface);
        auto result = handler.handle(progressPromise, query);

        if (result.isSuccess()) {
            emit m_eventDispatcher->root()->getReplied(result.value());
        }
        return Result<void>(result.error());
    });

    m_undo_redo_system->push(queryCommand, "root");

    // async wait for result signal
    const std::optional<RootDTO> optional_result = co_await qCoro(m_eventDispatcher->root(), &RootSignals::getReplied, std::chrono::milliseconds(1000));

    if (!optional_result.has_value()) {
        // for now, I insert one invalid item to the list to show that there was an error
        co_return RootDTO();
    }

    co_return optional_result.value();
}
