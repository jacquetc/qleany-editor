// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_entity_repository.h"
#include "repository/interface_presenter_single_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT PresenterSingleRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::PresenterSingle>,
                                                                         public QleanyEditor::Contracts::Repository::InterfacePresenterSingleRepository
{
public:
    explicit PresenterSingleRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::PresenterSingle> *presenterSingleDatabase,
                                       InterfaceEntityRepository *entityRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::PresenterSingle> update(QleanyEditor::Entities::PresenterSingle &&entity) override;
    Result<QleanyEditor::Entities::PresenterSingle> getWithDetails(int entityId) override;

    QleanyEditor::Entities::PresenterSingle::EntityLoader fetchEntityLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceEntityRepository *m_entityRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository