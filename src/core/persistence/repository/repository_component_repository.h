// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_persistence_export.h"
#include "repository/interface_repository_component_repository.h"
#include "repository/interface_repository_repository.h"
#include "repository_component.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT RepositoryComponentRepository final
    : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::RepositoryComponent>,
      public QleanyEditor::Contracts::Repository::InterfaceRepositoryComponentRepository
{
public:
    explicit RepositoryComponentRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::RepositoryComponent> *repositoryComponentDatabase,
                                           InterfaceRepositoryRepository *repositoryRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::RepositoryComponent> update(QleanyEditor::Entities::RepositoryComponent &&entity) override;
    Result<QleanyEditor::Entities::RepositoryComponent> getWithDetails(int entityId) override;

    QleanyEditor::Entities::RepositoryComponent::RepositoriesLoader fetchRepositoriesLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceRepositoryRepository *m_repositoryRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository