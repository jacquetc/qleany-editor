// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_component.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_entity_component_repository.h"
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

class QLEANY_EDITOR_PERSISTENCE_EXPORT EntityComponentRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::EntityComponent>,
                                                                         public QleanyEditor::Contracts::Repository::InterfaceEntityComponentRepository
{
public:
    explicit EntityComponentRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::EntityComponent> *entityComponentDatabase,
                                       InterfaceEntityRepository *entityRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::EntityComponent> update(QleanyEditor::Entities::EntityComponent &&entity) override;
    Result<QleanyEditor::Entities::EntityComponent> getWithDetails(int entityId) override;

    QleanyEditor::Entities::EntityComponent::EntitiesLoader fetchEntitiesLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceEntityRepository *m_entityRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository