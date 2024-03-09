// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "entity_component_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

EntityComponentRepository::EntityComponentRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::EntityComponent> *entityComponentDatabase,
                                                     InterfaceEntityRepository *entityRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::EntityComponent>(entityComponentDatabase)
    , m_entityRepository(entityRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *EntityComponentRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::EntityComponent> EntityComponentRepository::update(Entities::EntityComponent &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().entitiesSet) {
        Result<QList<Entities::Entity>> entitiesResult =
            m_entityRepository->updateEntitiesInRelationOf(Entities::EntityComponent::schema, entity.id(), "entities"_L1, entity.entities());

#ifdef QT_DEBUG
        if (entitiesResult.isError()) {
            qCritical() << entitiesResult.error().code() << entitiesResult.error().message() << entitiesResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::EntityComponent, entitiesResult)
    }

    return Qleany::Repository::GenericRepository<Entities::EntityComponent>::update(std::move(entity));
}

Result<QleanyEditor::Entities::EntityComponent> EntityComponentRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::EntityComponent>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::EntityComponent entity = getResult.value();

    Result<QList<Entities::Entity>> entitiesResult = m_entityRepository->getEntitiesInRelationOf(Entities::EntityComponent::schema, entity.id(), "entities"_L1);

#ifdef QT_DEBUG
    if (entitiesResult.isError()) {
        qCritical() << entitiesResult.error().code() << entitiesResult.error().message() << entitiesResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::EntityComponent, entitiesResult)

    entity.setEntities(entitiesResult.value());

    return Result<Entities::EntityComponent>(entity);
}

QleanyEditor::Entities::EntityComponent::EntitiesLoader EntityComponentRepository::fetchEntitiesLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "entities" property in the entity EntityComponent using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::EntityComponent::staticMetaObject.indexOfProperty("entities");
    if (propertyIndex == -1) {
        qCritical() << "The entity EntityComponent doesn't have a property named entities";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult =
            m_entityRepository->getEntitiesInRelationOf(QleanyEditor::Entities::EntityComponent::schema, entityId, QString::fromLatin1("entities"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::Entity>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> EntityComponentRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the entities in cascade

    Qleany::Entities::RelationshipInfo entityEntitiesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::EntityComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == "entities"_L1) {
            entityEntitiesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityEntitiesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::Entity> foreignEntities = this->fetchEntitiesLoader().operator()(entityId);

            if (foreignEntities.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &entity : foreignEntities) {
                foreignIds.append(entity.id());
            }

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

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::EntityComponent, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> EntityComponentRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the entities in cascade

    Qleany::Entities::RelationshipInfo entityEntitiesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::EntityComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == QString::fromLatin1("entities")) {
            entityEntitiesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityEntitiesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::Entity> foreignEntities = this->fetchEntitiesLoader().operator()(entityId);

            if (foreignEntities.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &entity : foreignEntities) {
                foreignIds.append(entity.id());
            }

            auto changeResult = m_entityRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::EntityComponent, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}