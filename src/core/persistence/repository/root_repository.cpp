// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "root_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

RootRepository::RootRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Root> *rootDatabase,
                               InterfaceProjectRepository *projectRepository,
                               InterfaceRecentProjectRepository *recentProjectRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::Root>(rootDatabase)
    , m_projectRepository(projectRepository)
    , m_recentProjectRepository(recentProjectRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *RootRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::Root> RootRepository::update(Entities::Root &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().projectSet) {
        Result<Entities::Project> projectResult =
            m_projectRepository->updateEntityInRelationOf(Entities::Root::schema, entity.id(), "project"_L1, entity.project());

#ifdef QT_DEBUG
        if (projectResult.isError()) {
            qCritical() << projectResult.error().code() << projectResult.error().message() << projectResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Root, projectResult)
    }

    if (entity.metaData().recentProjectsSet) {
        Result<QList<Entities::RecentProject>> recentProjectsResult =
            m_recentProjectRepository->updateEntitiesInRelationOf(Entities::Root::schema, entity.id(), "recentProjects"_L1, entity.recentProjects());

#ifdef QT_DEBUG
        if (recentProjectsResult.isError()) {
            qCritical() << recentProjectsResult.error().code() << recentProjectsResult.error().message() << recentProjectsResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Root, recentProjectsResult)
    }

    return Qleany::Repository::GenericRepository<Entities::Root>::update(std::move(entity));
}

Result<QleanyEditor::Entities::Root> RootRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::Root>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::Root entity = getResult.value();

    Result<Entities::Project> projectResult = m_projectRepository->getEntityInRelationOf(Entities::Root::schema, entity.id(), "project"_L1);

#ifdef QT_DEBUG
    if (projectResult.isError()) {
        qCritical() << projectResult.error().code() << projectResult.error().message() << projectResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Root, projectResult)

    entity.setProject(projectResult.value());

    Result<QList<Entities::RecentProject>> recentProjectsResult =
        m_recentProjectRepository->getEntitiesInRelationOf(Entities::Root::schema, entity.id(), "recentProjects"_L1);

#ifdef QT_DEBUG
    if (recentProjectsResult.isError()) {
        qCritical() << recentProjectsResult.error().code() << recentProjectsResult.error().message() << recentProjectsResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Root, recentProjectsResult)

    entity.setRecentProjects(recentProjectsResult.value());

    return Result<Entities::Root>(entity);
}

QleanyEditor::Entities::Root::ProjectLoader RootRepository::fetchProjectLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "project" property in the entity Root using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Root::staticMetaObject.indexOfProperty("project");
    if (propertyIndex == -1) {
        qCritical() << "The entity Root doesn't have a property named project";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_projectRepository->getEntityInRelationOf(QleanyEditor::Entities::Root::schema, entityId, "project"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::Project();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::Root::RecentProjectsLoader RootRepository::fetchRecentProjectsLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "recentProjects" property in the entity Root using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Root::staticMetaObject.indexOfProperty("recentProjects");
    if (propertyIndex == -1) {
        qCritical() << "The entity Root doesn't have a property named recentProjects";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult =
            m_recentProjectRepository->getEntitiesInRelationOf(QleanyEditor::Entities::Root::schema, entityId, QString::fromLatin1("recentProjects"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::RecentProject>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> RootRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the project in cascade

    Qleany::Entities::RelationshipInfo projectProjectRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Root::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Project && relationship.fieldName == "project"_L1) {
            projectProjectRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (projectProjectRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Project foreignProject = this->fetchProjectLoader().operator()(entityId);

            if (!foreignProject.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignProject.id());

            auto removalResult = m_projectRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the recentProjects in cascade

    Qleany::Entities::RelationshipInfo recentProjectRecentProjectsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Root::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::RecentProject && relationship.fieldName == "recentProjects"_L1) {
            recentProjectRecentProjectsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (recentProjectRecentProjectsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::RecentProject> foreignRecentProjects = this->fetchRecentProjectsLoader().operator()(entityId);

            if (foreignRecentProjects.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &recentProject : foreignRecentProjects) {
                foreignIds.append(recentProject.id());
            }

            auto removalResult = m_recentProjectRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::Root, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> RootRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the project in cascade

    Qleany::Entities::RelationshipInfo projectProjectRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Root::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Project && relationship.fieldName == QString::fromLatin1("project")) {
            projectProjectRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (projectProjectRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::Project foreignProject = this->fetchProjectLoader().operator()(entityId);

            if (!foreignProject.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignProject.id());

            auto changeResult = m_projectRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the recentProjects in cascade

    Qleany::Entities::RelationshipInfo recentProjectRecentProjectsRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Root::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::RecentProject && relationship.fieldName == QString::fromLatin1("recentProjects")) {
            recentProjectRecentProjectsRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (recentProjectRecentProjectsRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::RecentProject> foreignRecentProjects = this->fetchRecentProjectsLoader().operator()(entityId);

            if (foreignRecentProjects.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &recentProject : foreignRecentProjects) {
                foreignIds.append(recentProject.id());
            }

            auto changeResult = m_recentProjectRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::Root, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}