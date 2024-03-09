// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "qleany_editor_interactor_export.h"
#include "recent_project/recent_project_dto.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::RecentProject;

namespace QleanyEditor::Interactor::RecentProject
{

class QLEANY_EDITOR_INTERACTOR_EXPORT RecentProjectInteractor : public QObject
{
    Q_OBJECT
public:
    explicit RecentProjectInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                     ThreadedUndoRedoSystem *undo_redo_system,
                                     QSharedPointer<EventDispatcher> eventDispatcher);

    static RecentProjectInteractor *instance();

    Q_INVOKABLE QCoro::Task<RecentProjectDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<QList<RecentProjectDTO>> getAll() const;

public Q_SLOTS:

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<RecentProjectInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    RecentProjectInteractor() = delete;
    RecentProjectInteractor(const RecentProjectInteractor &) = delete;
    RecentProjectInteractor &operator=(const RecentProjectInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::RecentProject