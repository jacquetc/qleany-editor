// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "global_component/global_component_dto.h"
#include "global_component/update_global_component_dto.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::GlobalComponent;

namespace QleanyEditor::Interactor::GlobalComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT GlobalComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit GlobalComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                       ThreadedUndoRedoSystem *undo_redo_system,
                                       QSharedPointer<EventDispatcher> eventDispatcher);

    static GlobalComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<GlobalComponentDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::GlobalComponent::UpdateGlobalComponentDTO getUpdateDTO();

public slots:

    QCoro::Task<GlobalComponentDTO> update(const UpdateGlobalComponentDTO &dto);

private:
    static QPointer<GlobalComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    GlobalComponentInteractor() = delete;
    GlobalComponentInteractor(const GlobalComponentInteractor &) = delete;
    GlobalComponentInteractor &operator=(const GlobalComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::GlobalComponent