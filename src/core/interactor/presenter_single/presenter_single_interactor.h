// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "presenter_single/create_presenter_single_dto.h"
#include "presenter_single/presenter_single_dto.h"
#include "presenter_single/presenter_single_with_details_dto.h"
#include "presenter_single/update_presenter_single_dto.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::PresenterSingle;

namespace QleanyEditor::Interactor::PresenterSingle
{

class QLEANY_EDITOR_INTERACTOR_EXPORT PresenterSingleInteractor : public QObject
{
    Q_OBJECT
public:
    explicit PresenterSingleInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                       ThreadedUndoRedoSystem *undo_redo_system,
                                       QSharedPointer<EventDispatcher> eventDispatcher);

    static PresenterSingleInteractor *instance();

    Q_INVOKABLE QCoro::Task<PresenterSingleDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<PresenterSingleWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::PresenterSingle::CreatePresenterSingleDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::PresenterSingle::UpdatePresenterSingleDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<PresenterSingleDTO> create(const CreatePresenterSingleDTO &dto);

    QCoro::Task<PresenterSingleDTO> update(const UpdatePresenterSingleDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<PresenterSingleInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    PresenterSingleInteractor() = delete;
    PresenterSingleInteractor(const PresenterSingleInteractor &) = delete;
    PresenterSingleInteractor &operator=(const PresenterSingleInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::PresenterSingle