// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "application_component_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

ApplicationComponentRepository::ApplicationComponentRepository(
    InterfaceDatabaseTableGroup<QleanyEditor::Entities::ApplicationComponent> *applicationComponentDatabase,
    InterfaceApplicationFeatureRepository *applicationFeatureRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::ApplicationComponent>(applicationComponentDatabase)
    , m_applicationFeatureRepository(applicationFeatureRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *ApplicationComponentRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::ApplicationComponent> ApplicationComponentRepository::update(Entities::ApplicationComponent &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().featuresSet) {
        Result<QList<Entities::ApplicationFeature>> featuresResult =
            m_applicationFeatureRepository->updateEntitiesInRelationOf(Entities::ApplicationComponent::schema, entity.id(), "features"_L1, entity.features());

#ifdef QT_DEBUG
        if (featuresResult.isError()) {
            qCritical() << featuresResult.error().code() << featuresResult.error().message() << featuresResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::ApplicationComponent, featuresResult)
    }

    return Qleany::Repository::GenericRepository<Entities::ApplicationComponent>::update(std::move(entity));
}

Result<QleanyEditor::Entities::ApplicationComponent> ApplicationComponentRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::ApplicationComponent>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::ApplicationComponent entity = getResult.value();

    Result<QList<Entities::ApplicationFeature>> featuresResult =
        m_applicationFeatureRepository->getEntitiesInRelationOf(Entities::ApplicationComponent::schema, entity.id(), "features"_L1);

#ifdef QT_DEBUG
    if (featuresResult.isError()) {
        qCritical() << featuresResult.error().code() << featuresResult.error().message() << featuresResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::ApplicationComponent, featuresResult)

    entity.setFeatures(featuresResult.value());

    return Result<Entities::ApplicationComponent>(entity);
}

QleanyEditor::Entities::ApplicationComponent::FeaturesLoader ApplicationComponentRepository::fetchFeaturesLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "features" property in the entity ApplicationComponent using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::ApplicationComponent::staticMetaObject.indexOfProperty("features");
    if (propertyIndex == -1) {
        qCritical() << "The entity ApplicationComponent doesn't have a property named features";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult = m_applicationFeatureRepository->getEntitiesInRelationOf(QleanyEditor::Entities::ApplicationComponent::schema,
                                                                                             entityId,
                                                                                             QString::fromLatin1("features"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::ApplicationFeature>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> ApplicationComponentRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the features in cascade

    Qleany::Entities::RelationshipInfo applicationFeatureFeaturesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::ApplicationFeature && relationship.fieldName == "features"_L1) {
            applicationFeatureFeaturesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (applicationFeatureFeaturesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::ApplicationFeature> foreignFeatures = this->fetchFeaturesLoader().operator()(entityId);

            if (foreignFeatures.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &applicationFeature : foreignFeatures) {
                foreignIds.append(applicationFeature.id());
            }

            auto removalResult = m_applicationFeatureRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::ApplicationComponent, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> ApplicationComponentRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the features in cascade

    Qleany::Entities::RelationshipInfo applicationFeatureFeaturesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::ApplicationComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::ApplicationFeature && relationship.fieldName == QString::fromLatin1("features")) {
            applicationFeatureFeaturesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (applicationFeatureFeaturesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::ApplicationFeature> foreignFeatures = this->fetchFeaturesLoader().operator()(entityId);

            if (foreignFeatures.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &applicationFeature : foreignFeatures) {
                foreignIds.append(applicationFeature.id());
            }

            auto changeResult = m_applicationFeatureRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::ApplicationComponent, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}