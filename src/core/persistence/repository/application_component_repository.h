// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_application_component_repository.h"
#include "repository/interface_application_feature_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT ApplicationComponentRepository final
    : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::ApplicationComponent>,
      public QleanyEditor::Contracts::Repository::InterfaceApplicationComponentRepository
{
public:
    explicit ApplicationComponentRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::ApplicationComponent> *applicationComponentDatabase,
                                            InterfaceApplicationFeatureRepository *applicationFeatureRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::ApplicationComponent> update(QleanyEditor::Entities::ApplicationComponent &&entity) override;
    Result<QleanyEditor::Entities::ApplicationComponent> getWithDetails(int entityId) override;

    QleanyEditor::Entities::ApplicationComponent::FeaturesLoader fetchFeaturesLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceApplicationFeatureRepository *m_applicationFeatureRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository