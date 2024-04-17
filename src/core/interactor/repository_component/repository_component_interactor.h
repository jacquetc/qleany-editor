// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "qleany_editor_interactor_export.h"
#include "repository_component/create_repository_component_dto.h"
#include "repository_component/repository_component_dto.h"
#include "repository_component/repository_component_with_details_dto.h"
#include "repository_component/update_repository_component_dto.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;

namespace QleanyEditor::Interactor::RepositoryComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT RepositoryComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit RepositoryComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                           ThreadedUndoRedoSystem *undo_redo_system,
                                           QSharedPointer<EventDispatcher> eventDispatcher);

    static RepositoryComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<RepositoryComponentDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<RepositoryComponentWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::RepositoryComponent::CreateRepositoryComponentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::RepositoryComponent::UpdateRepositoryComponentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<RepositoryComponentDTO> create(const CreateRepositoryComponentDTO &dto);

    QCoro::Task<RepositoryComponentDTO> update(const UpdateRepositoryComponentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<RepositoryComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    RepositoryComponentInteractor() = delete;
    RepositoryComponentInteractor(const RepositoryComponentInteractor &) = delete;
    RepositoryComponentInteractor &operator=(const RepositoryComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::RepositoryComponent