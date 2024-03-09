// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "project_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

ProjectRepository::ProjectRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Project> *projectDatabase,
                                     InterfaceGlobalComponentRepository *globalComponentRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::Project>(projectDatabase)
    , m_globalComponentRepository(globalComponentRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *ProjectRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::Project> ProjectRepository::update(Entities::Project &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().globalComponentSet) {
        Result<Entities::GlobalComponent> globalComponentResult =
            m_globalComponentRepository->updateEntityInRelationOf(Entities::Project::schema, entity.id(), "globalComponent"_L1, entity.globalComponent());

#ifdef QT_DEBUG
        if (globalComponentResult.isError()) {
            qCritical() << globalComponentResult.error().code() << globalComponentResult.error().message() << globalComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, globalComponentResult)
    }

    return Qleany::Repository::GenericRepository<Entities::Project>::update(std::move(entity));
}

Result<QleanyEditor::Entities::Project> ProjectRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::Project>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::Project entity = getResult.value();

    Result<Entities::GlobalComponent> globalComponentResult =
        m_globalComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "globalComponent"_L1);

#ifdef QT_DEBUG
    if (globalComponentResult.isError()) {
        qCritical() << globalComponentResult.error().code() << globalComponentResult.error().message() << globalComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, globalComponentResult)

    entity.setGlobalComponent(globalComponentResult.value());

    return Result<Entities::Project>(entity);
}

QleanyEditor::Entities::Project::GlobalComponentLoader ProjectRepository::fetchGlobalComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "globalComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("globalComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named globalComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_globalComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "globalComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::GlobalComponent();
        }

        return foreignEntityResult.value();
    };
}

Result<QHash<int, QList<int>>> ProjectRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the globalComponent in cascade

    Qleany::Entities::RelationshipInfo globalComponentGlobalComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::GlobalComponent && relationship.fieldName == "globalComponent"_L1) {
            globalComponentGlobalComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (globalComponentGlobalComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::GlobalComponent foreignGlobalComponent = this->fetchGlobalComponentLoader().operator()(entityId);

            if (!foreignGlobalComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignGlobalComponent.id());

            auto removalResult = m_globalComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::Project, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> ProjectRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the globalComponent in cascade

    Qleany::Entities::RelationshipInfo globalComponentGlobalComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::GlobalComponent
            && relationship.fieldName == QString::fromLatin1("globalComponent")) {
            globalComponentGlobalComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (globalComponentGlobalComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::GlobalComponent foreignGlobalComponent = this->fetchGlobalComponentLoader().operator()(entityId);

            if (!foreignGlobalComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignGlobalComponent.id());

            auto changeResult = m_globalComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::Project, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}