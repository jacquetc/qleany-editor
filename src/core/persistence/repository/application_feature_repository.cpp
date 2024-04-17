// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "application_feature_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

ApplicationFeatureRepository::ApplicationFeatureRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::ApplicationFeature> *applicationFeatureDatabase,
                                                           InterfaceCRUDRepository *cRUDRepository,
                                                           InterfaceCustomCommandRepository *customCommandRepository,
                                                           InterfaceCustomQueryRepository *customQueryRepository,
                                                           InterfaceEntityRepository *entityRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::ApplicationFeature>(applicationFeatureDatabase)
    , m_cRUDRepository(cRUDRepository)
    , m_entityRepository(entityRepository)
    , m_customCommandRepository(customCommandRepository)
    , m_customQueryRepository(customQueryRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *ApplicationFeatureRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::ApplicationFeature> ApplicationFeatureRepository::update(Entities::ApplicationFeature &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().crudSet) {
        Result<Entities::CRUD> crudResult =
            m_cRUDRepository->updateEntityInRelationOf(Entities::ApplicationFeature::schema, entity.id(), "crud"_L1, entity.crud());

#ifdef QT_DEBUG
        if (crudResult.isError()) {
            qCritical() << crudResult.error().code() << crudResult.error().message() << crudResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::ApplicationFeature, crudResult)
    }

    if (entity.metaData().dtoIdenticalToEntitySet) {
        Result<Entities::Entity> dtoIdenticalToEntityResult = m_entityRepository->updateEntityInRelationOf(Entities::ApplicationFeature::schema,
                                                                                                           entity.id(),
                                                                                                           "dtoIdenticalToEntity"_L1,
                                                                                                           entity.dtoIdenticalToEntity());

#ifdef QT_DEBUG
        if (dtoIdenticalToEntityResult.isError()) {
            qCritical() << dtoIdenticalToEntityResult.error().code() << dtoIdenticalToEntityResult.error().message()
                        << dtoIdenticalToEntityResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::ApplicationFeature, dtoIdenticalToEntityResult)
    }

    if (entity.metaData().customCommandsSet) {
        Result<QList<Entities::CustomCommand>> customCommandsResult =
            m_customCommandRepository->updateEntitiesInRelationOf(Entities::ApplicationFeature::schema,
                                                                  entity.id(),
                                                                  "customCommands"_L1,
                                                                  entity.customCommands());

#ifdef QT_DEBUG
        if (customCommandsResult.isError()) {
            qCritical() << customCommandsResult.error().code() << customCommandsResult.error().message() << customCommandsResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::ApplicationFeature, customCommandsResult)
    }

    if (entity.metaData().customQueriesSet) {
        Result<QList<Entities::CustomQuery>> customQueriesResult =
            m_customQueryRepository->updateEntitiesInRelationOf(Entities::ApplicationFeature::schema, entity.id(), "customQueries"_L1, entity.customQueries());

#ifdef QT_DEBUG
        if (customQueriesResult.isError()) {
            qCritical() << customQueriesResult.error().code() << customQueriesResult.error().message() << customQueriesResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::ApplicationFeature, customQueriesResult)
    }

    return Qleany::Repository::GenericRepository<Entities::ApplicationFeature>::update(std::move(entity));
}

Result<QleanyEditor::Entities::ApplicationFeature> ApplicationFeatureRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::ApplicationFeature>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::ApplicationFeature entity = getResult.value();

    Result<Entities::CRUD> crudResult = m_cRUDRepository->getEntityInRelationOf(Entities::ApplicationFeature::schema, entity.id(), "crud"_L1);

#ifdef QT_DEBUG
    if (crudResult.isError()) {
        qCritical() << crudResult.error().code() << crudResult.error().message() << crudResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::ApplicationFeature, crudResult)

    entity.setCrud(crudResult.value());

    Result<Entities::Entity> dtoIdenticalToEntityResult =
        m_entityRepository->getEntityInRelationOf(Entities::ApplicationFeature::schema, entity.id(), "dtoIdenticalToEntity"_L1);

#ifdef QT_DEBUG
    if (dtoIdenticalToEntityResult.isError()) {
        qCritical() << dtoIdenticalToEntityResult.error().code() << dtoIdenticalToEntityResult.error().message() << dtoIdenticalToEntityResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::ApplicationFeature, dtoIdenticalToEntityResult)

    entity.setDtoIdenticalToEntity(dtoIdenticalToEntityResult.value());

    Result<QList<Entities::CustomCommand>> customCommandsResult =
        m_customCommandRepository->getEntitiesInRelationOf(Entities::ApplicationFeature::schema, entity.id(), "customCommands"_L1);

#ifdef QT_DEBUG
    if (customCommandsResult.isError()) {
        qCritical() << customCommandsResult.error().code() << customCommandsResult.error().message() << customCommandsResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::ApplicationFeature, customCommandsResult)

    entity.setCustomCommands(customCommandsResult.value());

    Result<QList<Entities::CustomQuery>> customQueriesResult =
        m_customQueryRepository->getEntitiesInRelationOf(Entities::ApplicationFeature::schema, entity.id(), "customQueries"_L1);

#ifdef QT_DEBUG
    if (customQueriesResult.isError()) {
        qCritical() << customQueriesResult.error().code() << customQueriesResult.error().message() << customQueriesResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::ApplicationFeature, customQueriesResult)

    entity.setCustomQueries(customQueriesResult.value());

    return Result<Entities::ApplicationFeature>(entity);
}

QleanyEditor::Entities::ApplicationFeature::CrudLoader ApplicationFeatureRepository::fetchCrudLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "crud" property in the entity ApplicationFeature using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::ApplicationFeature::staticMetaObject.indexOfProperty("crud");
    if (propertyIndex == -1) {
        qCritical() << "The entity ApplicationFeature doesn't have a property named crud";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_cRUDRepository->getEntityInRelationOf(QleanyEditor::Entities::ApplicationFeature::schema, entityId, "crud"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::CRUD();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::ApplicationFeature::DtoIdenticalToEntityLoader ApplicationFeatureRepository::fetchDtoIdenticalToEntityLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "dtoIdenticalToEntity" property in the entity ApplicationFeature using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::ApplicationFeature::staticMetaObject.indexOfProperty("dtoIdenticalToEntity");
    if (propertyIndex == -1) {
        qCritical() << "The entity ApplicationFeature doesn't have a property named dtoIdenticalToEntity";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult =
            m_entityRepository->getEntityInRelationOf(QleanyEditor::Entities::ApplicationFeature::schema, entityId, "dtoIdenticalToEntity"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::Entity();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::ApplicationFeature::CustomCommandsLoader ApplicationFeatureRepository::fetchCustomCommandsLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "customCommands" property in the entity ApplicationFeature using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::ApplicationFeature::staticMetaObject.indexOfProperty("customCommands");
    if (propertyIndex == -1) {
        qCritical() << "The entity ApplicationFeature doesn't have a property named customCommands";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult = m_customCommandRepository->getEntitiesInRelationOf(QleanyEditor::Entities::ApplicationFeature::schema,
                                                                                        entityId,
                                                                                        QString::fromLatin1("customCommands"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::CustomCommand>();
        }

        return foreignEntitiesResult.value();
    };
}

QleanyEditor::Entities::ApplicationFeature::CustomQueriesLoader ApplicationFeatureRepository::fetchCustomQueriesLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "customQueries" property in the entity ApplicationFeature using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::ApplicationFeature::staticMetaObject.indexOfProperty("customQueries");
    if (propertyIndex == -1) {
        qCritical() << "The entity ApplicationFeature doesn't have a property named customQueries";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult = m_customQueryRepository->getEntitiesInRelationOf(QleanyEditor::Entities::ApplicationFeature::schema,
                                                                                      entityId,
                                                                                      QString::fromLatin1("customQueries"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::CustomQuery>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> ApplicationFeatureRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the crud in cascade

    Qleany::Entities::RelationshipInfo cRUDCrudRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationFeature::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CRUD && relationship.fieldName == "crud"_L1) {
            cRUDCrudRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (cRUDCrudRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::CRUD foreignCrud = this->fetchCrudLoader().operator()(entityId);

            if (!foreignCrud.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignCrud.id());

            auto removalResult = m_cRUDRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the dtoIdenticalToEntity in cascade

    Qleany::Entities::RelationshipInfo entityDtoIdenticalToEntityRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationFeature::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == "dtoIdenticalToEntity"_L1) {
            entityDtoIdenticalToEntityRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityDtoIdenticalToEntityRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Entity foreignDtoIdenticalToEntity = this->fetchDtoIdenticalToEntityLoader().operator()(entityId);

            if (!foreignDtoIdenticalToEntity.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDtoIdenticalToEntity.id());

            auto removalResult = m_entityRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the customCommands in cascade

    Qleany::Entities::RelationshipInfo customCommandCustomCommandsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationFeature::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomCommand && relationship.fieldName == "customCommands"_L1) {
            customCommandCustomCommandsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customCommandCustomCommandsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::CustomCommand> foreignCustomCommands = this->fetchCustomCommandsLoader().operator()(entityId);

            if (foreignCustomCommands.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &customCommand : foreignCustomCommands) {
                foreignIds.append(customCommand.id());
            }

            auto removalResult = m_customCommandRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the customQueries in cascade

    Qleany::Entities::RelationshipInfo customQueryCustomQueriesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationFeature::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomQuery && relationship.fieldName == "customQueries"_L1) {
            customQueryCustomQueriesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customQueryCustomQueriesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::CustomQuery> foreignCustomQueries = this->fetchCustomQueriesLoader().operator()(entityId);

            if (foreignCustomQueries.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &customQuery : foreignCustomQueries) {
                foreignIds.append(customQuery.id());
            }

            auto removalResult = m_customQueryRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::ApplicationFeature, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> ApplicationFeatureRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the crud in cascade

    Qleany::Entities::RelationshipInfo cRUDCrudRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationFeature::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CRUD && relationship.fieldName == QString::fromLatin1("crud")) {
            cRUDCrudRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (cRUDCrudRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::CRUD foreignCrud = this->fetchCrudLoader().operator()(entityId);

            if (!foreignCrud.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignCrud.id());

            auto changeResult = m_cRUDRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the dtoIdenticalToEntity in cascade

    Qleany::Entities::RelationshipInfo entityDtoIdenticalToEntityRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationFeature::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Entity && relationship.fieldName == QString::fromLatin1("dtoIdenticalToEntity")) {
            entityDtoIdenticalToEntityRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityDtoIdenticalToEntityRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Entity foreignDtoIdenticalToEntity = this->fetchDtoIdenticalToEntityLoader().operator()(entityId);

            if (!foreignDtoIdenticalToEntity.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDtoIdenticalToEntity.id());

            auto changeResult = m_entityRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the customCommands in cascade

    Qleany::Entities::RelationshipInfo customCommandCustomCommandsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationFeature::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomCommand && relationship.fieldName == QString::fromLatin1("customCommands")) {
            customCommandCustomCommandsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customCommandCustomCommandsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::CustomCommand> foreignCustomCommands = this->fetchCustomCommandsLoader().operator()(entityId);

            if (foreignCustomCommands.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &customCommand : foreignCustomCommands) {
                foreignIds.append(customCommand.id());
            }

            auto changeResult = m_customCommandRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the customQueries in cascade

    Qleany::Entities::RelationshipInfo customQueryCustomQueriesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationFeature::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomQuery && relationship.fieldName == QString::fromLatin1("customQueries")) {
            customQueryCustomQueriesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customQueryCustomQueriesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::CustomQuery> foreignCustomQueries = this->fetchCustomQueriesLoader().operator()(entityId);

            if (foreignCustomQueries.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &customQuery : foreignCustomQueries) {
                foreignIds.append(customQuery.id());
            }

            auto changeResult = m_customQueryRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::ApplicationFeature, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}