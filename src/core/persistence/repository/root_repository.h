// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_persistence_export.h"
#include "repository/interface_project_repository.h"
#include "repository/interface_recent_project_repository.h"
#include "repository/interface_root_repository.h"
#include "root.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT RootRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::Root>,
                                                              public QleanyEditor::Contracts::Repository::InterfaceRootRepository
{
public:
    explicit RootRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Root> *rootDatabase,
                            InterfaceProjectRepository *projectRepository,
                            InterfaceRecentProjectRepository *recentProjectRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::Root> update(QleanyEditor::Entities::Root &&entity) override;
    Result<QleanyEditor::Entities::Root> getWithDetails(int entityId) override;

    QleanyEditor::Entities::Root::ProjectLoader fetchProjectLoader() override;

    QleanyEditor::Entities::Root::RecentProjectsLoader fetchRecentProjectsLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceProjectRepository *m_projectRepository;
    InterfaceRecentProjectRepository *m_recentProjectRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository