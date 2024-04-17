// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "repository_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

RepositoryRepository::RepositoryRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Repository> *repositoryDatabase,
                                           InterfaceEntityRepository *entityRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::Repository>(repositoryDatabase)
    , m_entityRepository(entityRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *RepositoryRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::Repository> RepositoryRepository::update(Entities::Repository &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().entitySet) {
        Result<Entities::Entity> entityResult =
            m_entityRepository->updateEntityInRelationOf(Entities::Repository::schema, entity.id(), "entity"_L1, entity.entity());

#ifdef QT_DEBUG
        if (entityResult.isError()) {
            qCritical() << entityResult.error().code() << entityResult.error().message() << entityResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Repository, entityResult)
    }

    return Qleany::Repository::GenericRepository<Entities::Repository>::update(std::move(entity));
}

Result<QleanyEditor::Entities::Repository> RepositoryRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::Repository>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::Repository entity = getResult.value();

    Result<Entities::Entity> entityResult = m_entityRepository->getEntityInRelationOf(Entities::Repository::schema, entity.id(), "entity"_L1);

#ifdef QT_DEBUG
    if (entityResult.isError()) {
        qCritical() << entityResult.error().code() << entityResult.error().message() << entityResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Repository, entityResult)

    entity.setEntity(entityResult.value());

    return Result<Entities::Repository>(entity);
}

QleanyEditor::Entities::Repository::EntityLoader RepositoryRepository::fetchEntityLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "entity" property in the entity Repository using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Repository::staticMetaObject.indexOfProperty("entity");
    if (propertyIndex == -1) {
        qCritical() << "The entity Repository doesn't have a property named entity";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_entityRepository->getEntityInRelationOf(QleanyEditor::Entities::Repository::schema, entityId, "entity"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::Entity();
        }

        return foreignEntityResult.value();
    };
}

Result<QHash<int, QList<int>>> RepositoryRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the entity in cascade

    Qleany::Entities::RelationshipInfo entityEntityRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Repository::schema.relationships) {
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

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::Repository, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> RepositoryRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the entity in cascade

    Qleany::Entities::RelationshipInfo entityEntityRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Repository::schema.relationships) {
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

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::Repository, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}