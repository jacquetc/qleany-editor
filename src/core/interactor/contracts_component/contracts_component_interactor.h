// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "contracts_component/contracts_component_dto.h"
#include "contracts_component/create_contracts_component_dto.h"
#include "contracts_component/update_contracts_component_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::ContractsComponent;

namespace QleanyEditor::Interactor::ContractsComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT ContractsComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit ContractsComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                          ThreadedUndoRedoSystem *undo_redo_system,
                                          QSharedPointer<EventDispatcher> eventDispatcher);

    static ContractsComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<ContractsComponentDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::ContractsComponent::CreateContractsComponentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::ContractsComponent::UpdateContractsComponentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<ContractsComponentDTO> create(const CreateContractsComponentDTO &dto);

    QCoro::Task<ContractsComponentDTO> update(const UpdateContractsComponentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<ContractsComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    ContractsComponentInteractor() = delete;
    ContractsComponentInteractor(const ContractsComponentInteractor &) = delete;
    ContractsComponentInteractor &operator=(const ContractsComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::ContractsComponent