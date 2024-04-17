// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_persistence_export.h"
#include "repository.h"
#include "repository/interface_entity_repository.h"
#include "repository/interface_repository_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT RepositoryRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::Repository>,
                                                                    public QleanyEditor::Contracts::Repository::InterfaceRepositoryRepository
{
public:
    explicit RepositoryRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Repository> *repositoryDatabase,
                                  InterfaceEntityRepository *entityRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::Repository> update(QleanyEditor::Entities::Repository &&entity) override;
    Result<QleanyEditor::Entities::Repository> getWithDetails(int entityId) override;

    QleanyEditor::Entities::Repository::EntityLoader fetchEntityLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceEntityRepository *m_entityRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository