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
                                     InterfaceApplicationComponentRepository *applicationComponentRepository,
                                     InterfaceCQRSComponentRepository *cQRSComponentRepository,
                                     InterfaceContractsComponentRepository *contractsComponentRepository,
                                     InterfaceDTOComponentRepository *dTOComponentRepository,
                                     InterfaceEntityComponentRepository *entityComponentRepository,
                                     InterfaceFrontEndComponentRepository *frontEndComponentRepository,
                                     InterfaceGlobalComponentRepository *globalComponentRepository,
                                     InterfaceInteractorComponentRepository *interactorComponentRepository,
                                     InterfacePresenterComponentRepository *presenterComponentRepository,
                                     InterfaceRepositoryComponentRepository *repositoryComponentRepository)
    : Qleany::Repository::GenericRepository<QleanyEditor::Entities::Project>(projectDatabase)
    , m_applicationComponentRepository(applicationComponentRepository)
    , m_cQRSComponentRepository(cQRSComponentRepository)
    , m_contractsComponentRepository(contractsComponentRepository)
    , m_dTOComponentRepository(dTOComponentRepository)
    , m_entityComponentRepository(entityComponentRepository)
    , m_globalComponentRepository(globalComponentRepository)
    , m_interactorComponentRepository(interactorComponentRepository)
    , m_presenterComponentRepository(presenterComponentRepository)
    , m_frontEndComponentRepository(frontEndComponentRepository)
    , m_repositoryComponentRepository(repositoryComponentRepository)
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

    if (entity.metaData().applicationComponentSet) {
        Result<Entities::ApplicationComponent> applicationComponentResult =
            m_applicationComponentRepository->updateEntityInRelationOf(Entities::Project::schema,
                                                                       entity.id(),
                                                                       "applicationComponent"_L1,
                                                                       entity.applicationComponent());

#ifdef QT_DEBUG
        if (applicationComponentResult.isError()) {
            qCritical() << applicationComponentResult.error().code() << applicationComponentResult.error().message()
                        << applicationComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, applicationComponentResult)
    }

    if (entity.metaData().cqrsComponentSet) {
        Result<Entities::CQRSComponent> cqrsComponentResult =
            m_cQRSComponentRepository->updateEntityInRelationOf(Entities::Project::schema, entity.id(), "cqrsComponent"_L1, entity.cqrsComponent());

#ifdef QT_DEBUG
        if (cqrsComponentResult.isError()) {
            qCritical() << cqrsComponentResult.error().code() << cqrsComponentResult.error().message() << cqrsComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, cqrsComponentResult)
    }

    if (entity.metaData().contractsComponentSet) {
        Result<Entities::ContractsComponent> contractsComponentResult = m_contractsComponentRepository->updateEntityInRelationOf(Entities::Project::schema,
                                                                                                                                 entity.id(),
                                                                                                                                 "contractsComponent"_L1,
                                                                                                                                 entity.contractsComponent());

#ifdef QT_DEBUG
        if (contractsComponentResult.isError()) {
            qCritical() << contractsComponentResult.error().code() << contractsComponentResult.error().message() << contractsComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, contractsComponentResult)
    }

    if (entity.metaData().dtoComponentSet) {
        Result<Entities::DTOComponent> dtoComponentResult =
            m_dTOComponentRepository->updateEntityInRelationOf(Entities::Project::schema, entity.id(), "dtoComponent"_L1, entity.dtoComponent());

#ifdef QT_DEBUG
        if (dtoComponentResult.isError()) {
            qCritical() << dtoComponentResult.error().code() << dtoComponentResult.error().message() << dtoComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, dtoComponentResult)
    }

    if (entity.metaData().entityComponentSet) {
        Result<Entities::EntityComponent> entityComponentResult =
            m_entityComponentRepository->updateEntityInRelationOf(Entities::Project::schema, entity.id(), "entityComponent"_L1, entity.entityComponent());

#ifdef QT_DEBUG
        if (entityComponentResult.isError()) {
            qCritical() << entityComponentResult.error().code() << entityComponentResult.error().message() << entityComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, entityComponentResult)
    }

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

    if (entity.metaData().interactorComponentSet) {
        Result<Entities::InteractorComponent> interactorComponentResult =
            m_interactorComponentRepository->updateEntityInRelationOf(Entities::Project::schema,
                                                                      entity.id(),
                                                                      "interactorComponent"_L1,
                                                                      entity.interactorComponent());

#ifdef QT_DEBUG
        if (interactorComponentResult.isError()) {
            qCritical() << interactorComponentResult.error().code() << interactorComponentResult.error().message() << interactorComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, interactorComponentResult)
    }

    if (entity.metaData().presenterComponentSet) {
        Result<Entities::PresenterComponent> presenterComponentResult = m_presenterComponentRepository->updateEntityInRelationOf(Entities::Project::schema,
                                                                                                                                 entity.id(),
                                                                                                                                 "presenterComponent"_L1,
                                                                                                                                 entity.presenterComponent());

#ifdef QT_DEBUG
        if (presenterComponentResult.isError()) {
            qCritical() << presenterComponentResult.error().code() << presenterComponentResult.error().message() << presenterComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, presenterComponentResult)
    }

    if (entity.metaData().frontEndComponentSet) {
        Result<QList<Entities::FrontEndComponent>> frontEndComponentResult =
            m_frontEndComponentRepository->updateEntitiesInRelationOf(Entities::Project::schema,
                                                                      entity.id(),
                                                                      "frontEndComponent"_L1,
                                                                      entity.frontEndComponent());

#ifdef QT_DEBUG
        if (frontEndComponentResult.isError()) {
            qCritical() << frontEndComponentResult.error().code() << frontEndComponentResult.error().message() << frontEndComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, frontEndComponentResult)
    }

    if (entity.metaData().repositoryComponentSet) {
        Result<Entities::RepositoryComponent> repositoryComponentResult =
            m_repositoryComponentRepository->updateEntityInRelationOf(Entities::Project::schema,
                                                                      entity.id(),
                                                                      "repositoryComponent"_L1,
                                                                      entity.repositoryComponent());

#ifdef QT_DEBUG
        if (repositoryComponentResult.isError()) {
            qCritical() << repositoryComponentResult.error().code() << repositoryComponentResult.error().message() << repositoryComponentResult.error().data();
            qFatal("Error found. The application will now exit");
        }
#endif
        QLN_RETURN_IF_ERROR(Entities::Project, repositoryComponentResult)
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

    Result<Entities::ApplicationComponent> applicationComponentResult =
        m_applicationComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "applicationComponent"_L1);

#ifdef QT_DEBUG
    if (applicationComponentResult.isError()) {
        qCritical() << applicationComponentResult.error().code() << applicationComponentResult.error().message() << applicationComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, applicationComponentResult)

    entity.setApplicationComponent(applicationComponentResult.value());

    Result<Entities::CQRSComponent> cqrsComponentResult =
        m_cQRSComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "cqrsComponent"_L1);

#ifdef QT_DEBUG
    if (cqrsComponentResult.isError()) {
        qCritical() << cqrsComponentResult.error().code() << cqrsComponentResult.error().message() << cqrsComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, cqrsComponentResult)

    entity.setCqrsComponent(cqrsComponentResult.value());

    Result<Entities::ContractsComponent> contractsComponentResult =
        m_contractsComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "contractsComponent"_L1);

#ifdef QT_DEBUG
    if (contractsComponentResult.isError()) {
        qCritical() << contractsComponentResult.error().code() << contractsComponentResult.error().message() << contractsComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, contractsComponentResult)

    entity.setContractsComponent(contractsComponentResult.value());

    Result<Entities::DTOComponent> dtoComponentResult =
        m_dTOComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "dtoComponent"_L1);

#ifdef QT_DEBUG
    if (dtoComponentResult.isError()) {
        qCritical() << dtoComponentResult.error().code() << dtoComponentResult.error().message() << dtoComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, dtoComponentResult)

    entity.setDtoComponent(dtoComponentResult.value());

    Result<Entities::EntityComponent> entityComponentResult =
        m_entityComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "entityComponent"_L1);

#ifdef QT_DEBUG
    if (entityComponentResult.isError()) {
        qCritical() << entityComponentResult.error().code() << entityComponentResult.error().message() << entityComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, entityComponentResult)

    entity.setEntityComponent(entityComponentResult.value());

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

    Result<Entities::InteractorComponent> interactorComponentResult =
        m_interactorComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "interactorComponent"_L1);

#ifdef QT_DEBUG
    if (interactorComponentResult.isError()) {
        qCritical() << interactorComponentResult.error().code() << interactorComponentResult.error().message() << interactorComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, interactorComponentResult)

    entity.setInteractorComponent(interactorComponentResult.value());

    Result<Entities::PresenterComponent> presenterComponentResult =
        m_presenterComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "presenterComponent"_L1);

#ifdef QT_DEBUG
    if (presenterComponentResult.isError()) {
        qCritical() << presenterComponentResult.error().code() << presenterComponentResult.error().message() << presenterComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, presenterComponentResult)

    entity.setPresenterComponent(presenterComponentResult.value());

    Result<QList<Entities::FrontEndComponent>> frontEndComponentResult =
        m_frontEndComponentRepository->getEntitiesInRelationOf(Entities::Project::schema, entity.id(), "frontEndComponent"_L1);

#ifdef QT_DEBUG
    if (frontEndComponentResult.isError()) {
        qCritical() << frontEndComponentResult.error().code() << frontEndComponentResult.error().message() << frontEndComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, frontEndComponentResult)

    entity.setFrontEndComponent(frontEndComponentResult.value());

    Result<Entities::RepositoryComponent> repositoryComponentResult =
        m_repositoryComponentRepository->getEntityInRelationOf(Entities::Project::schema, entity.id(), "repositoryComponent"_L1);

#ifdef QT_DEBUG
    if (repositoryComponentResult.isError()) {
        qCritical() << repositoryComponentResult.error().code() << repositoryComponentResult.error().message() << repositoryComponentResult.error().data();
        qFatal("Error found. The application will now exit");
    }
#endif
    QLN_RETURN_IF_ERROR(Entities::Project, repositoryComponentResult)

    entity.setRepositoryComponent(repositoryComponentResult.value());

    return Result<Entities::Project>(entity);
}

QleanyEditor::Entities::Project::ApplicationComponentLoader ProjectRepository::fetchApplicationComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "applicationComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("applicationComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named applicationComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult =
            m_applicationComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "applicationComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::ApplicationComponent();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::Project::CqrsComponentLoader ProjectRepository::fetchCqrsComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "cqrsComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("cqrsComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named cqrsComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_cQRSComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "cqrsComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::CQRSComponent();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::Project::ContractsComponentLoader ProjectRepository::fetchContractsComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "contractsComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("contractsComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named contractsComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult =
            m_contractsComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "contractsComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::ContractsComponent();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::Project::DtoComponentLoader ProjectRepository::fetchDtoComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "dtoComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("dtoComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named dtoComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_dTOComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "dtoComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::DTOComponent();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::Project::EntityComponentLoader ProjectRepository::fetchEntityComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "entityComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("entityComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named entityComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult = m_entityComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "entityComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::EntityComponent();
        }

        return foreignEntityResult.value();
    };
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

QleanyEditor::Entities::Project::InteractorComponentLoader ProjectRepository::fetchInteractorComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "interactorComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("interactorComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named interactorComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult =
            m_interactorComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "interactorComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::InteractorComponent();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::Project::PresenterComponentLoader ProjectRepository::fetchPresenterComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "presenterComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("presenterComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named presenterComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult =
            m_presenterComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "presenterComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::PresenterComponent();
        }

        return foreignEntityResult.value();
    };
}

QleanyEditor::Entities::Project::FrontEndComponentLoader ProjectRepository::fetchFrontEndComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "frontEndComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("frontEndComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named frontEndComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntitiesResult =
            m_frontEndComponentRepository->getEntitiesInRelationOf(QleanyEditor::Entities::Project::schema, entityId, QString::fromLatin1("frontEndComponent"));

        if (foreignEntitiesResult.isError()) {
            qCritical() << foreignEntitiesResult.error().code() << foreignEntitiesResult.error().message() << foreignEntitiesResult.error().data();
            return QList<QleanyEditor::Entities::FrontEndComponent>();
        }

        return foreignEntitiesResult.value();
    };
}

QleanyEditor::Entities::Project::RepositoryComponentLoader ProjectRepository::fetchRepositoryComponentLoader()
{
#ifdef QT_DEBUG
    // verify the presence of "repositoryComponent" property in the entity Project using staticMetaObject
    int propertyIndex = QleanyEditor::Entities::Project::staticMetaObject.indexOfProperty("repositoryComponent");
    if (propertyIndex == -1) {
        qCritical() << "The entity Project doesn't have a property named repositoryComponent";
        qFatal("The application will now exit");
    }
#endif

    return [this](int entityId) {
        auto foreignEntityResult =
            m_repositoryComponentRepository->getEntityInRelationOf(QleanyEditor::Entities::Project::schema, entityId, "repositoryComponent"_L1);

        if (foreignEntityResult.isError()) {
            qCritical() << foreignEntityResult.error().code() << foreignEntityResult.error().message() << foreignEntityResult.error().data();
            return QleanyEditor::Entities::RepositoryComponent();
        }

        return foreignEntityResult.value();
    };
}

Result<QHash<int, QList<int>>> ProjectRepository::removeInCascade(QList<int> ids)
{
    QWriteLocker locker(&m_lock);
    QHash<int, QList<int>> returnedHashOfEntityWithRemovedIds;

    // remove the applicationComponent in cascade

    Qleany::Entities::RelationshipInfo applicationComponentApplicationComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::ApplicationComponent && relationship.fieldName == "applicationComponent"_L1) {
            applicationComponentApplicationComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (applicationComponentApplicationComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::ApplicationComponent foreignApplicationComponent = this->fetchApplicationComponentLoader().operator()(entityId);

            if (!foreignApplicationComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignApplicationComponent.id());

            auto removalResult = m_applicationComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the cqrsComponent in cascade

    Qleany::Entities::RelationshipInfo cQRSComponentCqrsComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CQRSComponent && relationship.fieldName == "cqrsComponent"_L1) {
            cQRSComponentCqrsComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (cQRSComponentCqrsComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::CQRSComponent foreignCqrsComponent = this->fetchCqrsComponentLoader().operator()(entityId);

            if (!foreignCqrsComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignCqrsComponent.id());

            auto removalResult = m_cQRSComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the contractsComponent in cascade

    Qleany::Entities::RelationshipInfo contractsComponentContractsComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::ContractsComponent && relationship.fieldName == "contractsComponent"_L1) {
            contractsComponentContractsComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (contractsComponentContractsComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::ContractsComponent foreignContractsComponent = this->fetchContractsComponentLoader().operator()(entityId);

            if (!foreignContractsComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignContractsComponent.id());

            auto removalResult = m_contractsComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the dtoComponent in cascade

    Qleany::Entities::RelationshipInfo dTOComponentDtoComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::DTOComponent && relationship.fieldName == "dtoComponent"_L1) {
            dTOComponentDtoComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (dTOComponentDtoComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::DTOComponent foreignDtoComponent = this->fetchDtoComponentLoader().operator()(entityId);

            if (!foreignDtoComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDtoComponent.id());

            auto removalResult = m_dTOComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the entityComponent in cascade

    Qleany::Entities::RelationshipInfo entityComponentEntityComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityComponent && relationship.fieldName == "entityComponent"_L1) {
            entityComponentEntityComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityComponentEntityComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::EntityComponent foreignEntityComponent = this->fetchEntityComponentLoader().operator()(entityId);

            if (!foreignEntityComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignEntityComponent.id());

            auto removalResult = m_entityComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

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

    // remove the interactorComponent in cascade

    Qleany::Entities::RelationshipInfo interactorComponentInteractorComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::InteractorComponent && relationship.fieldName == "interactorComponent"_L1) {
            interactorComponentInteractorComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (interactorComponentInteractorComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::InteractorComponent foreignInteractorComponent = this->fetchInteractorComponentLoader().operator()(entityId);

            if (!foreignInteractorComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignInteractorComponent.id());

            auto removalResult = m_interactorComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the presenterComponent in cascade

    Qleany::Entities::RelationshipInfo presenterComponentPresenterComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::PresenterComponent && relationship.fieldName == "presenterComponent"_L1) {
            presenterComponentPresenterComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (presenterComponentPresenterComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::PresenterComponent foreignPresenterComponent = this->fetchPresenterComponentLoader().operator()(entityId);

            if (!foreignPresenterComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignPresenterComponent.id());

            auto removalResult = m_presenterComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the frontEndComponent in cascade

    Qleany::Entities::RelationshipInfo frontEndComponentFrontEndComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::FrontEndComponent && relationship.fieldName == "frontEndComponent"_L1) {
            frontEndComponentFrontEndComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (frontEndComponentFrontEndComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::FrontEndComponent> foreignFrontEndComponent = this->fetchFrontEndComponentLoader().operator()(entityId);

            if (foreignFrontEndComponent.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &frontEndComponent : foreignFrontEndComponent) {
                foreignIds.append(frontEndComponent.id());
            }

            auto removalResult = m_frontEndComponentRepository->removeInCascade(foreignIds);
            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, removalResult)

            returnedHashOfEntityWithRemovedIds.insert(removalResult.value());
        }
    }

    // remove the repositoryComponent in cascade

    Qleany::Entities::RelationshipInfo repositoryComponentRepositoryComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::RepositoryComponent && relationship.fieldName == "repositoryComponent"_L1) {
            repositoryComponentRepositoryComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (repositoryComponentRepositoryComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::RepositoryComponent foreignRepositoryComponent = this->fetchRepositoryComponentLoader().operator()(entityId);

            if (!foreignRepositoryComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignRepositoryComponent.id());

            auto removalResult = m_repositoryComponentRepository->removeInCascade(foreignIds);
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

    // cahnge active status of the applicationComponent in cascade

    Qleany::Entities::RelationshipInfo applicationComponentApplicationComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::ApplicationComponent
            && relationship.fieldName == QString::fromLatin1("applicationComponent")) {
            applicationComponentApplicationComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (applicationComponentApplicationComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::ApplicationComponent foreignApplicationComponent = this->fetchApplicationComponentLoader().operator()(entityId);

            if (!foreignApplicationComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignApplicationComponent.id());

            auto changeResult = m_applicationComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the cqrsComponent in cascade

    Qleany::Entities::RelationshipInfo cQRSComponentCqrsComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::CQRSComponent && relationship.fieldName == QString::fromLatin1("cqrsComponent")) {
            cQRSComponentCqrsComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (cQRSComponentCqrsComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::CQRSComponent foreignCqrsComponent = this->fetchCqrsComponentLoader().operator()(entityId);

            if (!foreignCqrsComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignCqrsComponent.id());

            auto changeResult = m_cQRSComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the contractsComponent in cascade

    Qleany::Entities::RelationshipInfo contractsComponentContractsComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::ContractsComponent
            && relationship.fieldName == QString::fromLatin1("contractsComponent")) {
            contractsComponentContractsComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (contractsComponentContractsComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::ContractsComponent foreignContractsComponent = this->fetchContractsComponentLoader().operator()(entityId);

            if (!foreignContractsComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignContractsComponent.id());

            auto changeResult = m_contractsComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the dtoComponent in cascade

    Qleany::Entities::RelationshipInfo dTOComponentDtoComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::DTOComponent && relationship.fieldName == QString::fromLatin1("dtoComponent")) {
            dTOComponentDtoComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (dTOComponentDtoComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::DTOComponent foreignDtoComponent = this->fetchDtoComponentLoader().operator()(entityId);

            if (!foreignDtoComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignDtoComponent.id());

            auto changeResult = m_dTOComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the entityComponent in cascade

    Qleany::Entities::RelationshipInfo entityComponentEntityComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::EntityComponent
            && relationship.fieldName == QString::fromLatin1("entityComponent")) {
            entityComponentEntityComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (entityComponentEntityComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::EntityComponent foreignEntityComponent = this->fetchEntityComponentLoader().operator()(entityId);

            if (!foreignEntityComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignEntityComponent.id());

            auto changeResult = m_entityComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

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

    // cahnge active status of the interactorComponent in cascade

    Qleany::Entities::RelationshipInfo interactorComponentInteractorComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::InteractorComponent
            && relationship.fieldName == QString::fromLatin1("interactorComponent")) {
            interactorComponentInteractorComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (interactorComponentInteractorComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::InteractorComponent foreignInteractorComponent = this->fetchInteractorComponentLoader().operator()(entityId);

            if (!foreignInteractorComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignInteractorComponent.id());

            auto changeResult = m_interactorComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the presenterComponent in cascade

    Qleany::Entities::RelationshipInfo presenterComponentPresenterComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::PresenterComponent
            && relationship.fieldName == QString::fromLatin1("presenterComponent")) {
            presenterComponentPresenterComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (presenterComponentPresenterComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::PresenterComponent foreignPresenterComponent = this->fetchPresenterComponentLoader().operator()(entityId);

            if (!foreignPresenterComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignPresenterComponent.id());

            auto changeResult = m_presenterComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the frontEndComponent in cascade

    Qleany::Entities::RelationshipInfo frontEndComponentFrontEndComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::FrontEndComponent
            && relationship.fieldName == QString::fromLatin1("frontEndComponent")) {
            frontEndComponentFrontEndComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (frontEndComponentFrontEndComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QList<QleanyEditor::Entities::FrontEndComponent> foreignFrontEndComponent = this->fetchFrontEndComponentLoader().operator()(entityId);

            if (foreignFrontEndComponent.isEmpty()) {
                continue;
            }

            QList<int> foreignIds;

            for (const auto &frontEndComponent : foreignFrontEndComponent) {
                foreignIds.append(frontEndComponent.id());
            }

            auto changeResult = m_frontEndComponentRepository->changeActiveStatusInCascade(foreignIds, active);

            QLN_RETURN_IF_ERROR(QHash<int QLN_COMMA QList<int>>, changeResult)

            returnedHashOfEntityWithActiveChangedIds.insert(changeResult.value());
        }
    }

    // cahnge active status of the repositoryComponent in cascade

    Qleany::Entities::RelationshipInfo repositoryComponentRepositoryComponentRelationship;
    for (const Qleany::Entities::RelationshipInfo &relationship : QleanyEditor::Entities::Project::schema.relationships) {
        if (relationship.rightEntityId == QleanyEditor::Entities::Entities::RepositoryComponent
            && relationship.fieldName == QString::fromLatin1("repositoryComponent")) {
            repositoryComponentRepositoryComponentRelationship = relationship;
            break;
        }
    }

    for (int entityId : ids) {
        if (repositoryComponentRepositoryComponentRelationship.strength == Qleany::Entities::RelationshipStrength::Strong) {
            // get foreign entities

            QleanyEditor::Entities::RepositoryComponent foreignRepositoryComponent = this->fetchRepositoryComponentLoader().operator()(entityId);

            if (!foreignRepositoryComponent.isValid()) {
                continue;
            }

            QList<int> foreignIds;

            foreignIds.append(foreignRepositoryComponent.id());

            auto changeResult = m_repositoryComponentRepository->changeActiveStatusInCascade(foreignIds, active);

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