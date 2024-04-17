// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "presenter_component/create_presenter_component_dto.h"
#include "presenter_component/presenter_component_dto.h"
#include "presenter_component/presenter_component_with_details_dto.h"
#include "presenter_component/update_presenter_component_dto.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::PresenterComponent;

namespace QleanyEditor::Interactor::PresenterComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT PresenterComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit PresenterComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                          ThreadedUndoRedoSystem *undo_redo_system,
                                          QSharedPointer<EventDispatcher> eventDispatcher);

    static PresenterComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<PresenterComponentDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<PresenterComponentWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::PresenterComponent::CreatePresenterComponentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::PresenterComponent::UpdatePresenterComponentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<PresenterComponentDTO> create(const CreatePresenterComponentDTO &dto);

    QCoro::Task<PresenterComponentDTO> update(const UpdatePresenterComponentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<PresenterComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    PresenterComponentInteractor() = delete;
    PresenterComponentInteractor(const PresenterComponentInteractor &) = delete;
    PresenterComponentInteractor &operator=(const PresenterComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::PresenterComponent