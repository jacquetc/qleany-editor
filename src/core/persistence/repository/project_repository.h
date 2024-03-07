// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_global_component_repository.h"
#include "repository/interface_project_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT ProjectRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::Project>,
                                                                 public QleanyEditor::Contracts::Repository::InterfaceProjectRepository
{
public:
    explicit ProjectRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Project> *projectDatabase,
                               InterfaceGlobalComponentRepository *globalComponentRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::Project> update(QleanyEditor::Entities::Project &&entity) override;
    Result<QleanyEditor::Entities::Project> getWithDetails(int entityId) override;

    QleanyEditor::Entities::Project::GlobalComponentLoader fetchGlobalComponentLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceGlobalComponentRepository *m_globalComponentRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository