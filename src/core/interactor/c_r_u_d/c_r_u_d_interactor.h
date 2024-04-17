// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/c_r_u_d_dto.h"
#include "c_r_u_d/c_r_u_d_with_details_dto.h"
#include "c_r_u_d/create_c_r_u_d_dto.h"
#include "c_r_u_d/update_c_r_u_d_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::CRUD;

namespace QleanyEditor::Interactor::CRUD
{

class QLEANY_EDITOR_INTERACTOR_EXPORT CRUDInteractor : public QObject
{
    Q_OBJECT
public:
    explicit CRUDInteractor(InterfaceRepositoryProvider *repositoryProvider,
                            ThreadedUndoRedoSystem *undo_redo_system,
                            QSharedPointer<EventDispatcher> eventDispatcher);

    static CRUDInteractor *instance();

    Q_INVOKABLE QCoro::Task<CRUDDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<CRUDWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::CRUD::CreateCRUDDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::CRUD::UpdateCRUDDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<CRUDDTO> create(const CreateCRUDDTO &dto);

    QCoro::Task<CRUDDTO> update(const UpdateCRUDDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<CRUDInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    CRUDInteractor() = delete;
    CRUDInteractor(const CRUDInteractor &) = delete;
    CRUDInteractor &operator=(const CRUDInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::CRUD