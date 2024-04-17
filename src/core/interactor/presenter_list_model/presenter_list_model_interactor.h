// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "presenter_list_model/create_presenter_list_model_dto.h"
#include "presenter_list_model/presenter_list_model_dto.h"
#include "presenter_list_model/presenter_list_model_with_details_dto.h"
#include "presenter_list_model/update_presenter_list_model_dto.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::PresenterListModel;

namespace QleanyEditor::Interactor::PresenterListModel
{

class QLEANY_EDITOR_INTERACTOR_EXPORT PresenterListModelInteractor : public QObject
{
    Q_OBJECT
public:
    explicit PresenterListModelInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                          ThreadedUndoRedoSystem *undo_redo_system,
                                          QSharedPointer<EventDispatcher> eventDispatcher);

    static PresenterListModelInteractor *instance();

    Q_INVOKABLE QCoro::Task<PresenterListModelDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<PresenterListModelWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::PresenterListModel::CreatePresenterListModelDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::PresenterListModel::UpdatePresenterListModelDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<PresenterListModelDTO> create(const CreatePresenterListModelDTO &dto);

    QCoro::Task<PresenterListModelDTO> update(const UpdatePresenterListModelDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<PresenterListModelInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    PresenterListModelInteractor() = delete;
    PresenterListModelInteractor(const PresenterListModelInteractor &) = delete;
    PresenterListModelInteractor &operator=(const PresenterListModelInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::PresenterListModel