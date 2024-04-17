// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "repository_component_repository.h"
#ifdef QT_DEBUG
#include <QDebug>
#include <QObject>
#endif

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Persistence::Repository;
using namespace QleanyEditor::Contracts::Repository;

RepositoryComponentRepository::RepositoryComponentRepository(
    InterfaceDatabaseTableGroup<QleanyEditor::Entities::RepositoryComponent> *repositoryComponentDatabase,
    InterfaceRepositoryRepository *repositoryRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::RepositoryComponent>(repositoryComponentDatabase)
    , m_repositoryRepository(repositoryRepository)
{
    m_signalHolder.reset(new SignalHolder(nullptr));
}

SignalHolder *RepositoryComponentRepository::signalHolder()
{
    QReadLocker locker(&m_lock);
    return m_signalHolder.data();
}

Result<QleanyEditor::Entities::RepositoryComponent> RepositoryComponentRepository::update(Entities::RepositoryComponent &&entity)
{
    QWriteLocker locker(&m_lock);

    if (entity.metaData().repositoriesSet) {
        Result<QList<Entities::Repository>> repositoriesResult =
            m_repositoryRepository->updateEntitiesInRelationOf(Entities::RepositoryComponent::schema, entity.id(), "repositories"_L1, entity.repositories());

#ifdef QT_DEBUG
        if (repositoriesResult.isError()) {
            qCritical() << repositoriesResult.error().code() << repositoriesResult.error().message() << repositoriesResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::RepositoryComponent, repositoriesResult)
    }

    return Qleany::Repository::GenericRepository<Entities::RepositoryComponent>::update(std::move(entity));
}

Result<QleanyEditor::Entities::RepositoryComponent> RepositoryComponentRepository::getWithDetails(int entityId)
{
    QWriteLocker locker(&m_lock);
    auto getResult = Qleany::Repository::GenericRepository<Entities::RepositoryComponent>::get(entityId);

    if (getResult.isError()) {
        return getResult;
    }

    Entities::RepositoryComponent entity = getResult.value();

    Result<QList<Entities::Repository>> repositoriesResult =
        m_repositoryRepository->getEntitiesInRelationOf(Entities::RepositoryComponent::schema, entity.id(), "repositories"_L1);

#ifdef QT_DEBUG
    if (repositoriesResult.isError()) {
        qCritical() << repositoriesResult.error().code() << repositoriesResult.error().message() << repositoriesResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::RepositoryComponent, repositoriesResult)

    entity.setRepositories(repositoriesResult.value());

    return Result<Entities::RepositoryComponent>(entity);
}

QleanyEditor::Entities::RepositoryComponent::RepositoriesLoader RepositoryComponentRepository::fetchRepositoriesLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "repositories" property in the entity RepositoryComponent using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::RepositoryComponent::staticMetaObject.indexOfProperty("repositories");
    if (propertyIndex == -1) {
        qCritical() << "The entity RepositoryComponent doesn't have a property named repositories";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult =
            m_repositoryRepository->getEntitiesInRelationOf(QleanyEditor::Entities::RepositoryComponent::schema, entityId, QString::fromLatin1("repositories"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::Repository>();
        }

        return foreignEntitiesResult.value();
    };
}

Result<QHash<int, QList<int>>> RepositoryComponentRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the repositories in cascade

    Qleany::Entities::RelationshipInfo repositoryRepositoriesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::RepositoryComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Repository && relationship.fieldName == "repositories"_L1) {
            repositoryRepositoriesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (repositoryRepositoriesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::Repository> foreignRepositories = this->fetchRepositoriesLoader().operator()(entityId);

            if (foreignRepositories.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &repository : foreignRepositories) {
                foreignIds.append(repository.id());
            }

            auto removalResult = m_repositoryRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // finally remove the entites of this repository

    Result<void> associationRemovalResult = this->databaseTable()->removeAssociationsWith(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, associationRemovalResult)
    Result<QList<int>> removedIdsResult = this->databaseTable()->remove(ids);
    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removedIdsResult)

    returnedHashOfEntityWithRemovedIds.insert(QleanyEditor::Entities::Entities::RepositoryComponent, removedIdsResult.value());

    Q_EMIT m_signalHolder->removed(removedIdsResult.value());

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithRemovedIds);
}

Result<QHash<int, QList<int>>> RepositoryComponentRepository::changeActiveStatusInCascade(QList<int> ids, bool active)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithActiveChangedIds;

    // cahnge active status of the repositories in cascade

    Qleany::Entities::RelationshipInfo repositoryRepositoriesRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::RepositoryComponent::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::Repository && relationship.fieldName == QString::fromLatin1("repositories")) {
            repositoryRepositoriesRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (repositoryRepositoriesRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::Repository> foreignRepositories = this->fetchRepositoriesLoader().operator()(entityId);

            if (foreignRepositories.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &repository : foreignRepositories) {
                foreignIds.append(repository.id());
            }

            auto changeResult = m_repositoryRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // finally change the entites of this repository

    Result<QList<int>> changedIdsResult = this->databaseTable()->changeActiveStatus(ids, active);

    QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changedIdsResult)

    returnedHashOfEntityWithActiveChangedIds.insert(QleanyEditor::Entities::Entities::RepositoryComponent, changedIdsResult.value());
    Q_EMIT m_signalHolder->activeStatusChanged(changedIdsResult.value(), active);

    return Result<QHash<int, QList<int>>>(returnedHashOfEntityWithActiveChangedIds);
}