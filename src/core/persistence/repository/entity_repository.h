// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_entity_field_repository.h"
#include "repository/interface_entity_parent_repository.h"
#include "repository/interface_entity_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT EntityRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::Entity>,
                                                                public QleanyEditor::Contracts::Repository::InterfaceEntityRepository
{
public:
    explicit EntityRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Entity> *entityDatabase,
                              InterfaceEntityFieldRepository *entityFieldRepository,
                              InterfaceEntityParentRepository *entityParentRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::Entity> update(QleanyEditor::Entities::Entity &&entity) override;
    Result<QleanyEditor::Entities::Entity> getWithDetails(int entityId) override;

    QleanyEditor::Entities::Entity::ParentLoader fetchParentLoader() override;

    QleanyEditor::Entities::Entity::FieldsLoader fetchFieldsLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceEntityParentRepository *m_entityParentRepository;
    InterfaceEntityFieldRepository *m_entityFieldRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository