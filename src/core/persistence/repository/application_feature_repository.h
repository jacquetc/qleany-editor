// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_application_feature_repository.h"
#include "repository/interface_c_r_u_d_repository.h"
#include "repository/interface_custom_command_repository.h"
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

class QLEANY_EDITOR_PERSISTENCE_EXPORT ApplicationFeatureRepository final
    : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::ApplicationFeature>,
      public QleanyEditor::Contracts::Repository::InterfaceApplicationFeatureRepository
{
public:
    explicit ApplicationFeatureRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::ApplicationFeature> *applicationFeatureDatabase,
                                          InterfaceCRUDRepository *cRUDRepository,
                                          InterfaceCustomCommandRepository *customCommandRepository,
                                          InterfaceCustomQueryRepository *customQueryRepository,
                                          InterfaceEntityRepository *entityRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::ApplicationFeature> update(QleanyEditor::Entities::ApplicationFeature &&entity) override;
    Result<QleanyEditor::Entities::ApplicationFeature> getWithDetails(int entityId) override;

    QleanyEditor::Entities::ApplicationFeature::CrudLoader fetchCrudLoader() override;

    QleanyEditor::Entities::ApplicationFeature::DtoIdenticalToEntityLoader fetchDtoIdenticalToEntityLoader() override;

    QleanyEditor::Entities::ApplicationFeature::CustomCommandsLoader fetchCustomCommandsLoader() override;

    QleanyEditor::Entities::ApplicationFeature::CustomQueriesLoader fetchCustomQueriesLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceCRUDRepository *m_cRUDRepository;
    InterfaceEntityRepository *m_entityRepository;
    InterfaceCustomCommandRepository *m_customCommandRepository;
    InterfaceCustomQueryRepository *m_customQueryRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository