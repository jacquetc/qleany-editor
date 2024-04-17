// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_presenter_component_repository.h"
#include "repository/interface_presenter_list_model_repository.h"
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

class QLEANY_EDITOR_PERSISTENCE_EXPORT PresenterComponentRepository final
    : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::PresenterComponent>,
      public QleanyEditor::Contracts::Repository::InterfacePresenterComponentRepository
{
public:
    explicit PresenterComponentRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::PresenterComponent> *presenterComponentDatabase,
                                          InterfacePresenterListModelRepository *presenterListModelRepository,
                                          InterfacePresenterSingleRepository *presenterSingleRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::PresenterComponent> update(QleanyEditor::Entities::PresenterComponent &&entity) override;
    Result<QleanyEditor::Entities::PresenterComponent> getWithDetails(int entityId) override;

    QleanyEditor::Entities::PresenterComponent::ListModelsLoader fetchListModelsLoader() override;

    QleanyEditor::Entities::PresenterComponent::SinglesLoader fetchSinglesLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfacePresenterListModelRepository *m_presenterListModelRepository;
    InterfacePresenterSingleRepository *m_presenterSingleRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository