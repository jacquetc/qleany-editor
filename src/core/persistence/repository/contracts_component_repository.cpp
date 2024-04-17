// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "contracts_component_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

ContractsComponentRepository::ContractsComponentRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::ContractsComponent> *contractsComponentDatabase)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::ContractsComponent>(contractsComponentDatabase)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *ContractsComponentRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QHash<int, QList<int>>> ContractsComponentRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::ContractsComponent, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> ContractsComponentRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::ContractsComponent, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}