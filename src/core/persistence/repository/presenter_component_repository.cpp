// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "presenter_component_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

PresenterComponentRepository::PresenterComponentRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::PresenterComponent> *presenterComponentDatabase,
                                                           InterfacePresenterListModelRepository *presenterListModelRepository,
                                                           InterfacePresenterSingleRepository *presenterSingleRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::PresenterComponent>(presenterComponentDatabase)
    , m_presenterListModelRepository(presenterListModelRepository)
    , m_presenterSingleRepository(presenterSingleRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *PresenterComponentRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::PresenterComponent> PresenterComponentRepository::update(Entities::PresenterComponent &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().listModelsSet) {
        Result<QList<Entities::PresenterListModel>> listModelsResult =
            m_presenterListModelRepository->updateEntitiesInRelationOf(Entities::PresenterComponent::schema, entity.id(), "listModels"_L1, entity.listModels());

#ifdef QT_DEBUG
        if (listModelsResult.isError()) {
            qCritical() << listModelsResult.error().code() << listModelsResult.error().message() << listModelsResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::PresenterComponent, listModelsResult)
    }

    if (entity.metaData().singlesSet) {
        Result<QList<Entities::PresenterSingle>> singlesResult =
            m_presenterSingleRepository->updateEntitiesInRelationOf(Entities::PresenterComponent::schema, entity.id(), "singles"_L1, entity.singles());

#ifdef QT_DEBUG
        if (singlesResult.isError()) {
            qCritical() << singlesResult.error().code() << singlesResult.error().message() << singlesResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::PresenterComponent, singlesResult)
    }

    return Qleany::Repository::GenericRepository<Entities::PresenterComponent>::update(std::move(entity));
}

Result<QleanyEditor::Entities::PresenterComponent> PresenterComponentRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::PresenterComponent>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::PresenterComponent entity = getResult.value();

    Result<QList<Entities::PresenterListModel>> listModelsResult =
        m_presenterListModelRepository->getEntitiesInRelationOf(Entities::PresenterComponent::schema, entity.id(), "listModels"_L1);

#ifdef QT_DEBUG
    if (listModelsResult.isError()) {
        qCritical() << listModelsResult.error().code() << listModelsResult.error().message() << listModelsResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::PresenterComponent, listModelsResult)

    entity.setListModels(listModelsResult.value());

    Result<QList<Entities::PresenterSingle>> singlesResult =
        m_presenterSingleRepository->getEntitiesInRelationOf(Entities::PresenterComponent::schema, entity.id(), "singles"_L1);

#ifdef QT_DEBUG
    if (singlesResult.isError()) {
        qCritical() << singlesResult.error().code() << singlesResult.error().message() << singlesResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::PresenterComponent, singlesResult)

    entity.setSingles(singlesResult.value());

    return Result<Entities::PresenterComponent>(entity);
}

QleanyEditor::Entities::PresenterComponent::ListModelsLoader PresenterComponentRepository::fetchListModelsLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "listModels" property in the entity PresenterComponent using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::PresenterComponent::staticMetaObject.indexOfProperty("listModels");
    if (propertyIndex == -1) {
        qCritical() << "The entity PresenterComponent doesn't have a property named listModels";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult = m_presenterListModelRepository->getEntitiesInRelationOf(QleanyEditor::Entities::PresenterComponent::schema,
                                                                                             entityId,
                                                                                             QString::fromLatin1("listModels"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::PresenterListModel>();
        }

        return foreignEntitiesResult.value();
    };
}

QleanyEditor::Entities::PresenterComponent::SinglesLoader PresenterComponentRepository::fetchSinglesLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "singles" property in the entity PresenterComponent using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::PresenterComponent::staticMetaObject.indexOfProperty("singles");
    if (propertyIndex == -1) {
        qCritical() << "The entity PresenterComponent doesn't have a property named singles";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult =
            m_presenterSingleRepository->getEntitiesInRelationOf(QleanyEditor::Entities::PresenterComponent::schema, entityId, QString::fromLatin1("singles"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::PresenterSingle>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> PresenterComponentRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the listModels in cascade

    Qleany::Entities::RelationshipInfo presenterListModelListModelsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::PresenterListModel && relationship.fieldName == "listModels"_L1) {
            presenterListModelListModelsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (presenterListModelListModelsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::PresenterListModel> foreignListModels = this->fetchListModelsLoader().operator()(entityId);

            if (foreignListModels.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &presenterListModel : foreignListModels) {
                foreignIds.append(presenterListModel.id());
            }

            auto removalResult = m_presenterListModelRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the singles in cascade

    Qleany::Entities::RelationshipInfo presenterSingleSinglesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::PresenterSingle && relationship.fieldName == "singles"_L1) {
            presenterSingleSinglesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (presenterSingleSinglesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::PresenterSingle> foreignSingles = this->fetchSinglesLoader().operator()(entityId);

            if (foreignSingles.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &presenterSingle : foreignSingles) {
                foreignIds.append(presenterSingle.id());
            }

            auto removalResult = m_presenterSingleRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::PresenterComponent, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> PresenterComponentRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the listModels in cascade

    Qleany::Entities::RelationshipInfo presenterListModelListModelsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::PresenterListModel && relationship.fieldName == QString::fromLatin1("listModels")) {
            presenterListModelListModelsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (presenterListModelListModelsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::PresenterListModel> foreignListModels = this->fetchListModelsLoader().operator()(entityId);

            if (foreignListModels.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &presenterListModel : foreignListModels) {
                foreignIds.append(presenterListModel.id());
            }

            auto changeResult = m_presenterListModelRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the singles in cascade

    Qleany::Entities::RelationshipInfo presenterSingleSinglesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::PresenterComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::PresenterSingle && relationship.fieldName == QString::fromLatin1("singles")) {
            presenterSingleSinglesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (presenterSingleSinglesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::PresenterSingle> foreignSingles = this->fetchSinglesLoader().operator()(entityId);

            if (foreignSingles.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &presenterSingle : foreignSingles) {
                foreignIds.append(presenterSingle.id());
            }

            auto changeResult = m_presenterSingleRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::PresenterComponent, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}