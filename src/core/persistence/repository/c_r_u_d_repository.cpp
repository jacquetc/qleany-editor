// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "c_r_u_d_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

CRUDRepository::CRUDRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::CRUD> *cRUDDatabase, InterfaceEntityRepository *entityRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::CRUD>(cRUDDatabase)
    , m_entityRepository(entityRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *CRUDRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::CRUD> CRUDRepository::update(Entities::CRUD &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().entityMappableWithSet) {
        Result<Entities::Entity> entityMappableWithResult =
            m_entityRepository->updateEntityInRelationOf(Entities::CRUD::schema, entity.id(), "entityMappableWith"_L1, entity.entityMappableWith());

#ifdef QT_DEBUG
        if (entityMappableWithResult.isError()) {
            qCritical() << entityMappableWithResult.error().code() << entityMappableWithResult.error().message() << entityMappableWithResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::CRUD, entityMappableWithResult)
    }

    return Qleany::Repository::GenericRepository<Entities::CRUD>::update(std::move(entity));
}

Result<QleanyEditor::Entities::CRUD> CRUDRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::CRUD>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::CRUD entity = getResult.value();

    Result<Entities::Entity> entityMappableWithResult = m_entityRepository->getEntityInRelationOf(Entities::CRUD::schema, entity.id(), "entityMappableWith"_L1);

#ifdef QT_DEBUG
    if (entityMappableWithResult.isError()) {
        qCritical() << entityMappableWithResult.error().code() << entityMappableWithResult.error().message() << entityMappableWithResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::CRUD, entityMappableWithResult)

    entity.setEntityMappableWith(entityMappableWithResult.value());

    return Result<Entities::CRUD>(entity);
}

QleanyEditor::Entities::CRUD::EntityMappableWithLoader CRUDRepository::fetchEntityMappableWithLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "entityMappableWith" property in the entity CRUD using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::CRUD::staticMetaObject.indexOfProperty("entityMappableWith");
    if (propertyIndex == -1) {
        qCritical() << "The entity CRUD doesn't have a property named entityMappableWith";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_entityRepository->getEntityInRelationOf(QleanyEditor::Entities::CRUD::schema, entityId, "entityMappableWith"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::Entity();
        }

        return foreignEntityResult.value();
    };
}

Result<QHash<int, QList<int>>> CRUDRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the entityMappableWith in cascade

    Qleany::Entities::RelationshipInfo entityEntityMappableWithRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CRUD::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == "entityMappableWith"_L1) {
            entityEntityMappableWithRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityEntityMappableWithRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Entity foreignEntityMappableWith = this->fetchEntityMappableWithLoader().operator()(entityId);

            if (!foreignEntityMappableWith.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignEntityMappableWith.id());

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

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::CRUD, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> CRUDRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the entityMappableWith in cascade

    Qleany::Entities::RelationshipInfo entityEntityMappableWithRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CRUD::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == QString::fromLatin1("entityMappableWith")) {
            entityEntityMappableWithRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityEntityMappableWithRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Entity foreignEntityMappableWith = this->fetchEntityMappableWithLoader().operator()(entityId);

            if (!foreignEntityMappableWith.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignEntityMappableWith.id());

            auto changeResult = m_entityRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::CRUD, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}