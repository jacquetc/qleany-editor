// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "qleany_editor_interactor_export.h"
#include "root/root_dto.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::Root;

namespace QleanyEditor::Interactor::Root
{

class QLEANY_EDITOR_INTERACTOR_EXPORT RootInteractor : public QObject
{
    Q_OBJECT
public:
    explicit RootInteractor(InterfaceRepositoryProvider *repositoryProvider,
                            ThreadedUndoRedoSystem *undo_redo_system,
                            QSharedPointer<EventDispatcher> eventDispatcher);

    static RootInteractor *instance();

    Q_INVOKABLE QCoro::Task<RootDTO> get(int id) const;

public slots:

private:
    static QPointer<RootInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    RootInteractor() = delete;
    RootInteractor(const RootInteractor &) = delete;
    RootInteractor &operator=(const RootInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::Root