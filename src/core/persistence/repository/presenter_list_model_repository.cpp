// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "presenter_list_model_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

PresenterListModelRepository::PresenterListModelRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::PresenterListModel> *presenterListModelDatabase,
                                                           InterfaceEntityFieldRepository *entityFieldRepository,
                                                           InterfaceEntityRepository *entityRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::PresenterListModel>(presenterListModelDatabase)
    , m_entityFieldRepository(entityFieldRepository)
    , m_entityRepository(entityRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *PresenterListModelRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::PresenterListModel> PresenterListModelRepository::update(Entities::PresenterListModel &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().displayedFieldSet) {
        Result<Entities::EntityField> displayedFieldResult =
            m_entityFieldRepository->updateEntityInRelationOf(Entities::PresenterListModel::schema, entity.id(), "displayedField"_L1, entity.displayedField());

#ifdef QT_DEBUG
        if (displayedFieldResult.isError()) {
            qCritical() << displayedFieldResult.error().code() << displayedFieldResult.error().message() << displayedFieldResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::PresenterListModel, displayedFieldResult)
    }

    if (entity.metaData().relationFieldNameSet) {
        Result<Entities::EntityField> relationFieldNameResult = m_entityFieldRepository->updateEntityInRelationOf(Entities::PresenterListModel::schema,
                                                                                                                  entity.id(),
                                                                                                                  "relationFieldName"_L1,
                                                                                                                  entity.relationFieldName());

#ifdef QT_DEBUG
        if (relationFieldNameResult.isError()) {
            qCritical() << relationFieldNameResult.error().code() << relationFieldNameResult.error().message() << relationFieldNameResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::PresenterListModel, relationFieldNameResult)
    }

    if (entity.metaData().entitySet) {
        Result<Entities::Entity> entityResult =
            m_entityRepository->updateEntityInRelationOf(Entities::PresenterListModel::schema, entity.id(), "entity"_L1, entity.entity());

#ifdef QT_DEBUG
        if (entityResult.isError()) {
            qCritical() << entityResult.error().code() << entityResult.error().message() << entityResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::PresenterListModel, entityResult)
    }

    if (entity.metaData().inRelationOfSet) {
        Result<Entities::Entity> inRelationOfResult =
            m_entityRepository->updateEntityInRelationOf(Entities::PresenterListModel::schema, entity.id(), "inRelationOf"_L1, entity.inRelationOf());

#ifdef QT_DEBUG
        if (inRelationOfResult.isError()) {
            qCritical() << inRelationOfResult.error().code() << inRelationOfResult.error().message() << inRelationOfResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::PresenterListModel, inRelationOfResult)
    }

    return Qleany::Repository::GenericRepository<Entities::PresenterListModel>::update(std::move(entity));
}

Result<QleanyEditor::Entities::PresenterListModel> PresenterListModelRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::PresenterListModel>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::PresenterListModel entity = getResult.value();

    Result<Entities::EntityField> displayedFieldResult =
        m_entityFieldRepository->getEntityInRelationOf(Entities::PresenterListModel::schema, entity.id(), "displayedField"_L1);

#ifdef QT_DEBUG
    if (displayedFieldResult.isError()) {
        qCritical() << displayedFieldResult.error().code() << displayedFieldResult.error().message() << displayedFieldResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::PresenterListModel, displayedFieldResult)

    entity.setDisplayedField(displayedFieldResult.value());

    Result<Entities::EntityField> relationFieldNameResult =
        m_entityFieldRepository->getEntityInRelationOf(Entities::PresenterListModel::schema, entity.id(), "relationFieldName"_L1);

#ifdef QT_DEBUG
    if (relationFieldNameResult.isError()) {
        qCritical() << relationFieldNameResult.error().code() << relationFieldNameResult.error().message() << relationFieldNameResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::PresenterListModel, relationFieldNameResult)

    entity.setRelationFieldName(relationFieldNameResult.value());

    Result<Entities::Entity> entityResult = m_entityRepository->getEntityInRelationOf(Entities::PresenterListModel::schema, entity.id(), "entity"_L1);

#ifdef QT_DEBUG
    if (entityResult.isError()) {
        qCritical() << entityResult.error().code() << entityResult.error().message() << entityResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::PresenterListModel, entityResult)

    entity.setEntity(entityResult.value());

    Result<Entities::Entity> inRelationOfResult =
        m_entityRepository->getEntityInRelationOf(Entities::PresenterListModel::schema, entity.id(), "inRelationOf"_L1);

#ifdef QT_DEBUG
    if (inRelationOfResult.isError()) {
        qCritical() << inRelationOfResult.error().code() << inRelationOfResult.error().message() << inRelationOfResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::PresenterListModel, inRelationOfResult)

    entity.setInRelationOf(inRelationOfResult.value());

    return Result<Entities::PresenterListModel>(entity);
}

QleanyEditor::Entities::PresenterListModel::DisplayedFieldLoader PresenterListModelRepository::fetchDisplayedFieldLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "displayedField" property in the entity PresenterListModel using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::PresenterListModel::staticMetaObject.indexOfProperty("displayedField");
    if (propertyIndex == -1) {
        qCritical() << "The entity PresenterListModel doesn't have a property named displayedField";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult =
            m_entityFieldRepository->getEntityInRelationOf(QleanyEditor::Entities::PresenterListModel::schema, entityId, "displayedField"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::EntityField();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::PresenterListModel::RelationFieldNameLoader PresenterListModelRepository::fetchRelationFieldNameLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "relationFieldName" property in the entity PresenterListModel using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::PresenterListModel::staticMetaObject.indexOfProperty("relationFieldName");
    if (propertyIndex == -1) {
        qCritical() << "The entity PresenterListModel doesn't have a property named relationFieldName";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult =
            m_entityFieldRepository->getEntityInRelationOf(QleanyEditor::Entities::PresenterListModel::schema, entityId, "relationFieldName"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::EntityField();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::PresenterListModel::EntityLoader PresenterListModelRepository::fetchEntityLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "entity" property in the entity PresenterListModel using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::PresenterListModel::staticMetaObject.indexOfProperty("entity");
    if (propertyIndex == -1) {
        qCritical() << "The entity PresenterListModel doesn't have a property named entity";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_entityRepository->getEntityInRelationOf(QleanyEditor::Entities::PresenterListModel::schema, entityId, "entity"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::Entity();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::PresenterListModel::InRelationOfLoader PresenterListModelRepository::fetchInRelationOfLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "inRelationOf" property in the entity PresenterListModel using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::PresenterListModel::staticMetaObject.indexOfProperty("inRelationOf");
    if (propertyIndex == -1) {
        qCritical() << "The entity PresenterListModel doesn't have a property named inRelationOf";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_entityRepository->getEntityInRelationOf(QleanyEditor::Entities::PresenterListModel::schema, entityId, "inRelationOf"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::Entity();
        }

        return foreignEntityResult.value();
    };
}

Result<QHash<int, QList<int>>> PresenterListModelRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the displayedField in cascade

    Qleany::Entities::RelationshipInfo entityFieldDisplayedFieldRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterListModel::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityField && relationship.fieldName == "displayedField"_L1) {
            entityFieldDisplayedFieldRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityFieldDisplayedFieldRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::EntityField foreignDisplayedField = this->fetchDisplayedFieldLoader().operator()(entityId);

            if (!foreignDisplayedField.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDisplayedField.id());

            auto removalResult = m_entityFieldRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the relationFieldName in cascade

    Qleany::Entities::RelationshipInfo entityFieldRelationFieldNameRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterListModel::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityField && relationship.fieldName == "relationFieldName"_L1) {
            entityFieldRelationFieldNameRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityFieldRelationFieldNameRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::EntityField foreignRelationFieldName = this->fetchRelationFieldNameLoader().operator()(entityId);

            if (!foreignRelationFieldName.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignRelationFieldName.id());

            auto removalResult = m_entityFieldRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the entity in cascade

    Qleany::Entities::RelationshipInfo entityEntityRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterListModel::schema.relationships) {
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

    // remove the inRelationOf in cascade

    Qleany::Entities::RelationshipInfo entityInRelationOfRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterListModel::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == "inRelationOf"_L1) {
            entityInRelationOfRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityInRelationOfRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Entity foreignInRelationOf = this->fetchInRelationOfLoader().operator()(entityId);

            if (!foreignInRelationOf.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignInRelationOf.id());

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

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::PresenterListModel, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> PresenterListModelRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the displayedField in cascade

    Qleany::Entities::RelationshipInfo entityFieldDisplayedFieldRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterListModel::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityField && relationship.fieldName == QString::fromLatin1("displayedField")) {
            entityFieldDisplayedFieldRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityFieldDisplayedFieldRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::EntityField foreignDisplayedField = this->fetchDisplayedFieldLoader().operator()(entityId);

            if (!foreignDisplayedField.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDisplayedField.id());

            auto changeResult = m_entityFieldRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the relationFieldName in cascade

    Qleany::Entities::RelationshipInfo entityFieldRelationFieldNameRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterListModel::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityField && relationship.fieldName == QString::fromLatin1("relationFieldName")) {
            entityFieldRelationFieldNameRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityFieldRelationFieldNameRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::EntityField foreignRelationFieldName = this->fetchRelationFieldNameLoader().operator()(entityId);

            if (!foreignRelationFieldName.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignRelationFieldName.id());

            auto changeResult = m_entityFieldRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the entity in cascade

    Qleany::Entities::RelationshipInfo entityEntityRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterListModel::schema.relationships) {
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

    // cahnge active status of the inRelationOf in cascade

    Qleany::Entities::RelationshipInfo entityInRelationOfRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterListModel::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == QString::fromLatin1("inRelationOf")) {
            entityInRelationOfRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityInRelationOfRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Entity foreignInRelationOf = this->fetchInRelationOfLoader().operator()(entityId);

            if (!foreignInRelationOf.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignInRelationOf.id());

            auto changeResult = m_entityRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::PresenterListModel, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}