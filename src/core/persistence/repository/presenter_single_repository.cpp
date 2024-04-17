// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "presenter_single_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

PresenterSingleRepository::PresenterSingleRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::PresenterSingle> *presenterSingleDatabase,
                                                     InterfaceEntityRepository *entityRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::PresenterSingle>(presenterSingleDatabase)
    , m_entityRepository(entityRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *PresenterSingleRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::PresenterSingle> PresenterSingleRepository::update(Entities::PresenterSingle &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().entitySet) {
        Result<Entities::Entity> entityResult =
            m_entityRepository->updateEntityInRelationOf(Entities::PresenterSingle::schema, entity.id(), "entity"_L1, entity.entity());

#ifdef QT_DEBUG
        if (entityResult.isError()) {
            qCritical() << entityResult.error().code() << entityResult.error().message() << entityResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::PresenterSingle, entityResult)
    }

    return Qleany::Repository::GenericRepository<Entities::PresenterSingle>::update(std::move(entity));
}

Result<QleanyEditor::Entities::PresenterSingle> PresenterSingleRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::PresenterSingle>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::PresenterSingle entity = getResult.value();

    Result<Entities::Entity> entityResult = m_entityRepository->getEntityInRelationOf(Entities::PresenterSingle::schema, entity.id(), "entity"_L1);

#ifdef QT_DEBUG
    if (entityResult.isError()) {
        qCritical() << entityResult.error().code() << entityResult.error().message() << entityResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::PresenterSingle, entityResult)

    entity.setEntity(entityResult.value());

    return Result<Entities::PresenterSingle>(entity);
}

QleanyEditor::Entities::PresenterSingle::EntityLoader PresenterSingleRepository::fetchEntityLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "entity" property in the entity PresenterSingle using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::PresenterSingle::staticMetaObject.indexOfProperty("entity");
    if (propertyIndex == -1) {
        qCritical() << "The entity PresenterSingle doesn't have a property named entity";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_entityRepository->getEntityInRelationOf(QleanyEditor::Entities::PresenterSingle::schema, entityId, "entity"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::Entity();
        }

        return foreignEntityResult.value();
    };
}

Result<QHash<int, QList<int>>> PresenterSingleRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the entity in cascade

    Qleany::Entities::RelationshipInfo entityEntityRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterSingle::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == "entity"_L1) {
            entityEntityRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityEntityRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Entity foreignEntity = this->fetchEntityLoader().operator()(entityId);

            if (!foreignEntity.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignEntity.id());

            auto removalResult = m_entityRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::PresenterSingle, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> PresenterSingleRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the entity in cascade

    Qleany::Entities::RelationshipInfo entityEntityRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterSingle::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == QString::fromLatin1("entity")) {
            entityEntityRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityEntityRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Entity foreignEntity = this->fetchEntityLoader().operator()(entityId);

            if (!foreignEntity.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignEntity.id());

            auto changeResult = m_entityRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::PresenterSingle, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}