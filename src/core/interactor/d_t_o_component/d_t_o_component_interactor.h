// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "d_t_o_component/create_d_t_o_component_dto.h"
#include "d_t_o_component/d_t_o_component_dto.h"
#include "d_t_o_component/update_d_t_o_component_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::DTOComponent;

namespace QleanyEditor::Interactor::DTOComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT DTOComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit DTOComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                    ThreadedUndoRedoSystem *undo_redo_system,
                                    QSharedPointer<EventDispatcher> eventDispatcher);

    static DTOComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<DTOComponentDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::DTOComponent::CreateDTOComponentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::DTOComponent::UpdateDTOComponentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<DTOComponentDTO> create(const CreateDTOComponentDTO &dto);

    QCoro::Task<DTOComponentDTO> update(const UpdateDTOComponentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<DTOComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    DTOComponentInteractor() = delete;
    DTOComponentInteractor(const DTOComponentInteractor &) = delete;
    DTOComponentInteractor &operator=(const DTOComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::DTOComponent