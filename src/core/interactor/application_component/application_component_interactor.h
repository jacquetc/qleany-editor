// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/application_component_dto.h"
#include "application_component/application_component_with_details_dto.h"
#include "application_component/create_application_component_dto.h"
#include "application_component/update_application_component_dto.h"
#include "event_dispatcher.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;

namespace QleanyEditor::Interactor::ApplicationComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT ApplicationComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                            ThreadedUndoRedoSystem *undo_redo_system,
                                            QSharedPointer<EventDispatcher> eventDispatcher);

    static ApplicationComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<ApplicationComponentDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<ApplicationComponentWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::ApplicationComponent::CreateApplicationComponentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::ApplicationComponent::UpdateApplicationComponentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<ApplicationComponentDTO> create(const CreateApplicationComponentDTO &dto);

    QCoro::Task<ApplicationComponentDTO> update(const UpdateApplicationComponentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<ApplicationComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    ApplicationComponentInteractor() = delete;
    ApplicationComponentInteractor(const ApplicationComponentInteractor &) = delete;
    ApplicationComponentInteractor &operator=(const ApplicationComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::ApplicationComponent