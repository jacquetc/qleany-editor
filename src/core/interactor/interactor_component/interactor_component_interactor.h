// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "interactor_component/create_interactor_component_dto.h"
#include "interactor_component/interactor_component_dto.h"
#include "interactor_component/update_interactor_component_dto.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::InteractorComponent;

namespace QleanyEditor::Interactor::InteractorComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT InteractorComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit InteractorComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                           ThreadedUndoRedoSystem *undo_redo_system,
                                           QSharedPointer<EventDispatcher> eventDispatcher);

    static InteractorComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<InteractorComponentDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::InteractorComponent::CreateInteractorComponentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::InteractorComponent::UpdateInteractorComponentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<InteractorComponentDTO> create(const CreateInteractorComponentDTO &dto);

    QCoro::Task<InteractorComponentDTO> update(const UpdateInteractorComponentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<InteractorComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    InteractorComponentInteractor() = delete;
    InteractorComponentInteractor(const InteractorComponentInteractor &) = delete;
    InteractorComponentInteractor &operator=(const InteractorComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::InteractorComponent