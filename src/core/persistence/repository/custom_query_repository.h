// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_query.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_custom_d_t_o_repository.h"
#include "repository/interface_custom_query_repository.h"
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

class QLEANY_EDITOR_PERSISTENCE_EXPORT CustomQueryRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::CustomQuery>,
                                                                     public QleanyEditor::Contracts::Repository::InterfaceCustomQueryRepository
{
public:
    explicit CustomQueryRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::CustomQuery> *customQueryDatabase,
                                   InterfaceCustomDTORepository *customDTORepository,
                                   InterfaceEntityRepository *entityRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::CustomQuery> update(QleanyEditor::Entities::CustomQuery &&entity) override;
    Result<QleanyEditor::Entities::CustomQuery> getWithDetails(int entityId) override;

    QleanyEditor::Entities::CustomQuery::DtoInLoader fetchDtoInLoader() override;

    QleanyEditor::Entities::CustomQuery::DtoOutLoader fetchDtoOutLoader() override;

    QleanyEditor::Entities::CustomQuery::EntitiesLoader fetchEntitiesLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceCustomDTORepository *m_customDTORepository;
    InterfaceEntityRepository *m_entityRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository