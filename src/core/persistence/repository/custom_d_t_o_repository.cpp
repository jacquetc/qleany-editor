// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "custom_d_t_o_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

CustomDTORepository::CustomDTORepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::CustomDTO> *customDTODatabase,
                                         InterfaceCustomDTOFieldRepository *customDTOFieldRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::CustomDTO>(customDTODatabase)
    , m_customDTOFieldRepository(customDTOFieldRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *CustomDTORepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::CustomDTO> CustomDTORepository::update(Entities::CustomDTO &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().fieldsSet) {
        Result<QList<Entities::CustomDTOField>> fieldsResult =
            m_customDTOFieldRepository->updateEntitiesInRelationOf(Entities::CustomDTO::schema, entity.id(), "fields"_L1, entity.fields());

#ifdef QT_DEBUG
        if (fieldsResult.isError()) {
            qCritical() << fieldsResult.error().code() << fieldsResult.error().message() << fieldsResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::CustomDTO, fieldsResult)
    }

    return Qleany::Repository::GenericRepository<Entities::CustomDTO>::update(std::move(entity));
}

Result<QleanyEditor::Entities::CustomDTO> CustomDTORepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::CustomDTO>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::CustomDTO entity = getResult.value();

    Result<QList<Entities::CustomDTOField>> fieldsResult =
        m_customDTOFieldRepository->getEntitiesInRelationOf(Entities::CustomDTO::schema, entity.id(), "fields"_L1);

#ifdef QT_DEBUG
    if (fieldsResult.isError()) {
        qCritical() << fieldsResult.error().code() << fieldsResult.error().message() << fieldsResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::CustomDTO, fieldsResult)

    entity.setFields(fieldsResult.value());

    return Result<Entities::CustomDTO>(entity);
}

QleanyEditor::Entities::CustomDTO::FieldsLoader CustomDTORepository::fetchFieldsLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "fields" property in the entity CustomDTO using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::CustomDTO::staticMetaObject.indexOfProperty("fields");
    if (propertyIndex == -1) {
        qCritical() << "The entity CustomDTO doesn't have a property named fields";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult =
            m_customDTOFieldRepository->getEntitiesInRelationOf(QleanyEditor::Entities::CustomDTO::schema, entityId, QString::fromLatin1("fields"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::CustomDTOField>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> CustomDTORepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the fields in cascade

    Qleany::Entities::RelationshipInfo customDTOFieldFieldsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CustomDTO::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomDTOField && relationship.fieldName == "fields"_L1) {
            customDTOFieldFieldsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customDTOFieldFieldsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::CustomDTOField> foreignFields = this->fetchFieldsLoader().operator()(entityId);

            if (foreignFields.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &customDTOField : foreignFields) {
                foreignIds.append(customDTOField.id());
            }

            auto removalResult = m_customDTOFieldRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::CustomDTO, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> CustomDTORepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the fields in cascade

    Qleany::Entities::RelationshipInfo customDTOFieldFieldsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::CustomDTO::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CustomDTOField && relationship.fieldName == QString::fromLatin1("fields")) {
            customDTOFieldFieldsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (customDTOFieldFieldsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::CustomDTOField> foreignFields = this->fetchFieldsLoader().operator()(entityId);

            if (foreignFields.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &customDTOField : foreignFields) {
                foreignIds.append(customDTOField.id());
            }

            auto changeResult = m_customDTOFieldRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::CustomDTO, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}