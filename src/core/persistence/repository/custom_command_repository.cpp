// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "custom_command_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

CustomCommandRepository::CustomCommandRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::CustomCommand> *customCommandDatabase,
                                                 InterfaceCustomDTORepository *customDTORepository,
                                                 InterfaceEntityRepository *entityRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::CustomCommand>(customCommandDatabase)
    , m_customDTORepository(customDTORepository)
    , m_entityRepository(entityRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *CustomCommandRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::CustomCommand> CustomCommandRepository::update(Entities::CustomCommand &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().dtoInSet) {
        Result<Entities::CustomDTO> dtoInResult =
            m_customDTORepository->updateEntityInRelationOf(Entities::CustomCommand::schema, entity.id(), "dtoIn"_L1, entity.dtoIn());

#ifdef QT_DEBUG
        if (dtoInResult.isError()) {
            qCritical() << dtoInResult.error().code() << dtoInResult.error().message() << dtoInResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::CustomCommand, dtoInResult)
    }

    if (entity.metaData().dtoOutSet) {
        Result<Entities::CustomDTO> dtoOutResult =
            m_customDTORepository->updateEntityInRelationOf(Entities::CustomCommand::schema, entity.id(), "dtoOut"_L1, entity.dtoOut());

#ifdef QT_DEBUG
        if (dtoOutResult.isError()) {
            qCritical() << dtoOutResult.error().code() << dtoOutResult.error().message() << dtoOutResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::CustomCommand, dtoOutResult)
    }

    if (entity.metaData().entitiesSet) {
        Result<QList<Entities::Entity>> entitiesResult =
            m_entityRepository->updateEntitiesInRelationOf(Entities::CustomCommand::schema, entity.id(), "entities"_L1, entity.entities());

#ifdef QT_DEBUG
        if (entitiesResult.isError()) {
            qCritical() << entitiesResult.error().code() << entitiesResult.error().message() << entitiesResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::CustomCommand, entitiesResult)
    }

    return Qleany::Repository::GenericRepository<Entities::CustomCommand>::update(std::move(entity));
}

Result<QleanyEditor::Entities::CustomCommand> CustomCommandRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::CustomCommand>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::CustomCommand entity = getResult.value();

    Result<Entities::CustomDTO> dtoInResult = m_customDTORepository->getEntityInRelationOf(Entities::CustomCommand::schema, entity.id(), "dtoIn"_L1);

#ifdef QT_DEBUG
    if (dtoInResult.isError()) {
        qCritical() << dtoInResult.error().code() << dtoInResult.error().message() << dtoInResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::CustomCommand, dtoInResult)

    entity.setDtoIn(dtoInResult.value());

    Result<Entities::CustomDTO> dtoOutResult = m_customDTORepository->getEntityInRelationOf(Entities::CustomCommand::schema, entity.id(), "dtoOut"_L1);

#ifdef QT_DEBUG
    if (dtoOutResult.isError()) {
        qCritical() << dtoOutResult.error().code() << dtoOutResult.error().message() << dtoOutResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::CustomCommand, dtoOutResult)

    entity.setDtoOut(dtoOutResult.value());

    Result<QList<Entities::Entity>> entitiesResult = m_entityRepository->getEntitiesInRelationOf(Entities::CustomCommand::schema, entity.id(), "entities"_L1);

#ifdef QT_DEBUG
    if (entitiesResult.isError()) {
        qCritical() << entitiesResult.error().code() << entitiesResult.error().message() << entitiesResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::CustomCommand, entitiesResult)

    entity.setEntities(entitiesResult.value());

    return Result<Entities::CustomCommand>(entity);
}

QleanyEditor::Entities::CustomCommand::DtoInLoader CustomCommandRepository::fetchDtoInLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "dtoIn" property in the entity CustomCommand using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::CustomCommand::staticMetaObject.indexOfProperty("dtoIn");
    if (propertyIndex == -1) {
        qCritical() << "The entity CustomCommand doesn't have a property named dtoIn";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_customDTORepository->getEntityInRelationOf(QleanyEditor::Entities::CustomCommand::schema, entityId, "dtoIn"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::CustomDTO();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::CustomCommand::DtoOutLoader CustomCommandRepository::fetchDtoOutLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "dtoOut" property in the entity CustomCommand using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::CustomCommand::staticMetaObject.indexOfProperty("dtoOut");
    if (propertyIndex == -1) {
        qCritical() << "The entity CustomCommand doesn't have a property named dtoOut";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_customDTORepository->getEntityInRelationOf(QleanyEditor::Entities::CustomCommand::schema, entityId, "dtoOut"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::CustomDTO();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::CustomCommand::EntitiesLoader CustomCommandRepository::fetchEntitiesLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "entities" property in the entity CustomCommand using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::CustomCommand::staticMetaObject.indexOfProperty("entities");
    if (propertyIndex == -1) {
        qCritical() << "The entity CustomCommand doesn't have a property named entities";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult =
            m_entityRepository->getEntitiesInRelationOf(QleanyEditor::Entities::CustomCommand::schema, entityId, QString::fromLatin1("entities"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::Entity>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> CustomCommandRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the dtoIn in cascade

    Qleany::Entities::RelationshipInfo customDTODtoInRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CustomCommand::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomDTO && relationship.fieldName == "dtoIn"_L1) {
            customDTODtoInRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customDTODtoInRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::CustomDTO foreignDtoIn = this->fetchDtoInLoader().operator()(entityId);

            if (!foreignDtoIn.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDtoIn.id());

            auto removalResult = m_customDTORepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the dtoOut in cascade

    Qleany::Entities::RelationshipInfo customDTODtoOutRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CustomCommand::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomDTO && relationship.fieldName == "dtoOut"_L1) {
            customDTODtoOutRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customDTODtoOutRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::CustomDTO foreignDtoOut = this->fetchDtoOutLoader().operator()(entityId);

            if (!foreignDtoOut.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDtoOut.id());

            auto removalResult = m_customDTORepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the entities in cascade

    Qleany::Entities::RelationshipInfo entityEntitiesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CustomCommand::schema.relationships) {
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

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::CustomCommand, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> CustomCommandRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the dtoIn in cascade

    Qleany::Entities::RelationshipInfo customDTODtoInRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CustomCommand::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomDTO && relationship.fieldName == QString::fromLatin1("dtoIn")) {
            customDTODtoInRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customDTODtoInRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::CustomDTO foreignDtoIn = this->fetchDtoInLoader().operator()(entityId);

            if (!foreignDtoIn.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDtoIn.id());

            auto changeResult = m_customDTORepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the dtoOut in cascade

    Qleany::Entities::RelationshipInfo customDTODtoOutRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CustomCommand::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomDTO && relationship.fieldName == QString::fromLatin1("dtoOut")) {
            customDTODtoOutRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customDTODtoOutRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::CustomDTO foreignDtoOut = this->fetchDtoOutLoader().operator()(entityId);

            if (!foreignDtoOut.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDtoOut.id());

            auto changeResult = m_customDTORepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the entities in cascade

    Qleany::Entities::RelationshipInfo entityEntitiesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CustomCommand::schema.relationships) {
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

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::CustomCommand, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}