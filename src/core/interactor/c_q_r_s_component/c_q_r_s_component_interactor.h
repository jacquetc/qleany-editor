// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_q_r_s_component/c_q_r_s_component_dto.h"
#include "c_q_r_s_component/create_c_q_r_s_component_dto.h"
#include "c_q_r_s_component/update_c_q_r_s_component_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::CQRSComponent;

namespace QleanyEditor::Interactor::CQRSComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT CQRSComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit CQRSComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                     ThreadedUndoRedoSystem *undo_redo_system,
                                     QSharedPointer<EventDispatcher> eventDispatcher);

    static CQRSComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<CQRSComponentDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::CQRSComponent::CreateCQRSComponentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::CQRSComponent::UpdateCQRSComponentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<CQRSComponentDTO> create(const CreateCQRSComponentDTO &dto);

    QCoro::Task<CQRSComponentDTO> update(const UpdateCQRSComponentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<CQRSComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    CQRSComponentInteractor() = delete;
    CQRSComponentInteractor(const CQRSComponentInteractor &) = delete;
    CQRSComponentInteractor &operator=(const CQRSComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::CQRSComponent
