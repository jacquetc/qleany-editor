// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "qleany_editor_interactor_export.h"
#include "repository/create_repository_dto.h"
#include "repository/repository_dto.h"
#include "repository/repository_with_details_dto.h"
#include "repository/update_repository_dto.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::Repository;

namespace QleanyEditor::Interactor::Repository
{

class QLEANY_EDITOR_INTERACTOR_EXPORT RepositoryInteractor : public QObject
{
    Q_OBJECT
public:
    explicit RepositoryInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                  ThreadedUndoRedoSystem *undo_redo_system,
                                  QSharedPointer<EventDispatcher> eventDispatcher);

    static RepositoryInteractor *instance();

    Q_INVOKABLE QCoro::Task<RepositoryDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<RepositoryWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE QCoro::Task<QList<RepositoryDTO>> getAll() const;

    Q_INVOKABLE static Contracts::DTO::Repository::CreateRepositoryDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::Repository::UpdateRepositoryDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<RepositoryDTO> create(const CreateRepositoryDTO &dto);

    QCoro::Task<RepositoryDTO> update(const UpdateRepositoryDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<RepositoryInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    RepositoryInteractor() = delete;
    RepositoryInteractor(const RepositoryInteractor &) = delete;
    RepositoryInteractor &operator=(const RepositoryInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::Repository