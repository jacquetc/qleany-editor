// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "entity_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

EntityRepository::EntityRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Entity> *entityDatabase,
                                   InterfaceEntityFieldRepository *entityFieldRepository,
                                   InterfaceEntityParentRepository *entityParentRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::Entity>(entityDatabase)
    , m_entityParentRepository(entityParentRepository)
    , m_entityFieldRepository(entityFieldRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *EntityRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::Entity> EntityRepository::update(Entities::Entity &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().parentSet) {
        Result<Entities::EntityParent> parentResult =
            m_entityParentRepository->updateEntityInRelationOf(Entities::Entity::schema, entity.id(), "parent"_L1, entity.parent());

#ifdef QT_DEBUG
        if (parentResult.isError()) {
            qCritical() << parentResult.error().code() << parentResult.error().message() << parentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Entity, parentResult)
    }

    if (entity.metaData().fieldsSet) {
        Result<QList<Entities::EntityField>> fieldsResult =
            m_entityFieldRepository->updateEntitiesInRelationOf(Entities::Entity::schema, entity.id(), "fields"_L1, entity.fields());

#ifdef QT_DEBUG
        if (fieldsResult.isError()) {
            qCritical() << fieldsResult.error().code() << fieldsResult.error().message() << fieldsResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Entity, fieldsResult)
    }

    return Qleany::Repository::GenericRepository<Entities::Entity>::update(std::move(entity));
}

Result<QleanyEditor::Entities::Entity> EntityRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::Entity>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::Entity entity = getResult.value();

    Result<Entities::EntityParent> parentResult = m_entityParentRepository->getEntityInRelationOf(Entities::Entity::schema, entity.id(), "parent"_L1);

#ifdef QT_DEBUG
    if (parentResult.isError()) {
        qCritical() << parentResult.error().code() << parentResult.error().message() << parentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Entity, parentResult)

    entity.setParent(parentResult.value());

    Result<QList<Entities::EntityField>> fieldsResult = m_entityFieldRepository->getEntitiesInRelationOf(Entities::Entity::schema, entity.id(), "fields"_L1);

#ifdef QT_DEBUG
    if (fieldsResult.isError()) {
        qCritical() << fieldsResult.error().code() << fieldsResult.error().message() << fieldsResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Entity, fieldsResult)

    entity.setFields(fieldsResult.value());

    return Result<Entities::Entity>(entity);
}

QleanyEditor::Entities::Entity::ParentLoader EntityRepository::fetchParentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "parent" property in the entity Entity using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Entity::staticMetaObject.indexOfProperty("parent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Entity doesn't have a property named parent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_entityParentRepository->getEntityInRelationOf(QleanyEditor::Entities::Entity::schema, entityId, "parent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::EntityParent();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::Entity::FieldsLoader EntityRepository::fetchFieldsLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "fields" property in the entity Entity using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Entity::staticMetaObject.indexOfProperty("fields");
    if (propertyIndex == -1) {
        qCritical() << "The entity Entity doesn't have a property named fields";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult =
            m_entityFieldRepository->getEntitiesInRelationOf(QleanyEditor::Entities::Entity::schema, entityId, QString::fromLatin1("fields"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::EntityField>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> EntityRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the parent in cascade

    Qleany::Entities::RelationshipInfo entityParentParentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Entity::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityParent && relationship.fieldName == "parent"_L1) {
            entityParentParentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityParentParentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::EntityParent foreignParent = this->fetchParentLoader().operator()(entityId);

            if (!foreignParent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignParent.id());

            auto removalResult = m_entityParentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the fields in cascade

    Qleany::Entities::RelationshipInfo entityFieldFieldsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Entity::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityField && relationship.fieldName == "fields"_L1) {
            entityFieldFieldsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityFieldFieldsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::EntityField> foreignFields = this->fetchFieldsLoader().operator()(entityId);

            if (foreignFields.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &entityField : foreignFields) {
                foreignIds.append(entityField.id());
            }

            auto removalResult = m_entityFieldRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::Entity, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> EntityRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the parent in cascade

    Qleany::Entities::RelationshipInfo entityParentParentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Entity::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityParent && relationship.fieldName == QString::fromLatin1("parent")) {
            entityParentParentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityParentParentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::EntityParent foreignParent = this->fetchParentLoader().operator()(entityId);

            if (!foreignParent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignParent.id());

            auto changeResult = m_entityParentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the fields in cascade

    Qleany::Entities::RelationshipInfo entityFieldFieldsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Entity::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityField && relationship.fieldName == QString::fromLatin1("fields")) {
            entityFieldFieldsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityFieldFieldsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::EntityField> foreignFields = this->fetchFieldsLoader().operator()(entityId);

            if (foreignFields.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &entityField : foreignFields) {
                foreignIds.append(entityField.id());
            }

            auto changeResult = m_entityFieldRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::Entity, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}