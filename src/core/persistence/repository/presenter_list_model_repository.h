// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_entity_field_repository.h"
#include "repository/interface_entity_repository.h"
#include "repository/interface_presenter_list_model_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT PresenterListModelRepository final
    : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::PresenterListModel>,
      public QleanyEditor::Contracts::Repository::InterfacePresenterListModelRepository
{
public:
    explicit PresenterListModelRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::PresenterListModel> *presenterListModelDatabase,
                                          InterfaceEntityFieldRepository *entityFieldRepository,
                                          InterfaceEntityRepository *entityRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::PresenterListModel> update(QleanyEditor::Entities::PresenterListModel &&entity) override;
    Result<QleanyEditor::Entities::PresenterListModel> getWithDetails(int entityId) override;

    QleanyEditor::Entities::PresenterListModel::DisplayedFieldLoader fetchDisplayedFieldLoader() override;

    QleanyEditor::Entities::PresenterListModel::RelationFieldNameLoader fetchRelationFieldNameLoader() override;

    QleanyEditor::Entities::PresenterListModel::EntityLoader fetchEntityLoader() override;

    QleanyEditor::Entities::PresenterListModel::InRelationOfLoader fetchInRelationOfLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceEntityFieldRepository *m_entityFieldRepository;
    InterfaceEntityRepository *m_entityRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository