// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_query/create_custom_query_dto.h"
#include "custom_query/custom_query_dto.h"
#include "custom_query/custom_query_with_details_dto.h"
#include "custom_query/update_custom_query_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::CustomQuery;

namespace QleanyEditor::Interactor::CustomQuery
{

class QLEANY_EDITOR_INTERACTOR_EXPORT CustomQueryInteractor : public QObject
{
    Q_OBJECT
public:
    explicit CustomQueryInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                   ThreadedUndoRedoSystem *undo_redo_system,
                                   QSharedPointer<EventDispatcher> eventDispatcher);

    static CustomQueryInteractor *instance();

    Q_INVOKABLE QCoro::Task<CustomQueryDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<CustomQueryWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::CustomQuery::CreateCustomQueryDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::CustomQuery::UpdateCustomQueryDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<CustomQueryDTO> create(const CreateCustomQueryDTO &dto);

    QCoro::Task<CustomQueryDTO> update(const UpdateCustomQueryDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<CustomQueryInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    CustomQueryInteractor() = delete;
    CustomQueryInteractor(const CustomQueryInteractor &) = delete;
    CustomQueryInteractor &operator=(const CustomQueryInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::CustomQuery