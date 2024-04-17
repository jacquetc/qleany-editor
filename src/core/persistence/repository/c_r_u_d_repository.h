// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_c_r_u_d_repository.h"
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

class QLEANY_EDITOR_PERSISTENCE_EXPORT CRUDRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::CRUD>,
                                                              public QleanyEditor::Contracts::Repository::InterfaceCRUDRepository
{
public:
    explicit CRUDRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::CRUD> *cRUDDatabase, InterfaceEntityRepository *entityRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::CRUD> update(QleanyEditor::Entities::CRUD &&entity) override;
    Result<QleanyEditor::Entities::CRUD> getWithDetails(int entityId) override;

    QleanyEditor::Entities::CRUD::EntityMappableWithLoader fetchEntityMappableWithLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceEntityRepository *m_entityRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository