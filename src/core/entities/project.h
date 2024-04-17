// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component.h"
#include "c_q_r_s_component.h"
#include "contracts_component.h"
#include "d_t_o_component.h"
#include "entity_component.h"
#include "front_end_component.h"
#include "global_component.h"
#include "interactor_component.h"
#include "presenter_component.h"
#include "repository_component.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class Project : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)

    Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath)

    Q_PROPERTY(GlobalComponent globalComponent READ globalComponent WRITE setGlobalComponent)

    Q_PROPERTY(EntityComponent entityComponent READ entityComponent WRITE setEntityComponent)

    Q_PROPERTY(RepositoryComponent repositoryComponent READ repositoryComponent WRITE setRepositoryComponent)

    Q_PROPERTY(InteractorComponent interactorComponent READ interactorComponent WRITE setInteractorComponent)

    Q_PROPERTY(ApplicationComponent applicationComponent READ applicationComponent WRITE setApplicationComponent)

    Q_PROPERTY(DTOComponent dtoComponent READ dtoComponent WRITE setDtoComponent)

    Q_PROPERTY(CQRSComponent cqrsComponent READ cqrsComponent WRITE setCqrsComponent)

    Q_PROPERTY(ContractsComponent contractsComponent READ contractsComponent WRITE setContractsComponent)

    Q_PROPERTY(PresenterComponent presenterComponent READ presenterComponent WRITE setPresenterComponent)

    Q_PROPERTY(QList<FrontEndComponent> frontEndComponent READ frontEndComponent WRITE setFrontEndComponent)

public:
    struct MetaData {
        MetaData(Project *entity)
            : m_entity(entity)
        {
        }
        MetaData(Project *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->globalComponentSet = other.globalComponentSet;
            this->globalComponentLoaded = other.globalComponentLoaded;
            this->entityComponentSet = other.entityComponentSet;
            this->entityComponentLoaded = other.entityComponentLoaded;
            this->repositoryComponentSet = other.repositoryComponentSet;
            this->repositoryComponentLoaded = other.repositoryComponentLoaded;
            this->interactorComponentSet = other.interactorComponentSet;
            this->interactorComponentLoaded = other.interactorComponentLoaded;
            this->applicationComponentSet = other.applicationComponentSet;
            this->applicationComponentLoaded = other.applicationComponentLoaded;
            this->dtoComponentSet = other.dtoComponentSet;
            this->dtoComponentLoaded = other.dtoComponentLoaded;
            this->cqrsComponentSet = other.cqrsComponentSet;
            this->cqrsComponentLoaded = other.cqrsComponentLoaded;
            this->contractsComponentSet = other.contractsComponentSet;
            this->contractsComponentLoaded = other.contractsComponentLoaded;
            this->presenterComponentSet = other.presenterComponentSet;
            this->presenterComponentLoaded = other.presenterComponentLoaded;
            this->frontEndComponentSet = other.frontEndComponentSet;
            this->frontEndComponentLoaded = other.frontEndComponentLoaded;
        }

        bool globalComponentSet = false;
        bool globalComponentLoaded = false;

        bool entityComponentSet = false;
        bool entityComponentLoaded = false;

        bool repositoryComponentSet = false;
        bool repositoryComponentLoaded = false;

        bool interactorComponentSet = false;
        bool interactorComponentLoaded = false;

        bool applicationComponentSet = false;
        bool applicationComponentLoaded = false;

        bool dtoComponentSet = false;
        bool dtoComponentLoaded = false;

        bool cqrsComponentSet = false;
        bool cqrsComponentLoaded = false;

        bool contractsComponentSet = false;
        bool contractsComponentLoaded = false;

        bool presenterComponentSet = false;
        bool presenterComponentLoaded = false;

        bool frontEndComponentSet = false;
        bool frontEndComponentLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "fileName"_L1) {
                return true;
            }
            if (fieldName == "rootPath"_L1) {
                return true;
            }
            if (fieldName == "globalComponent"_L1) {
                return globalComponentSet;
            }
            if (fieldName == "entityComponent"_L1) {
                return entityComponentSet;
            }
            if (fieldName == "repositoryComponent"_L1) {
                return repositoryComponentSet;
            }
            if (fieldName == "interactorComponent"_L1) {
                return interactorComponentSet;
            }
            if (fieldName == "applicationComponent"_L1) {
                return applicationComponentSet;
            }
            if (fieldName == "dtoComponent"_L1) {
                return dtoComponentSet;
            }
            if (fieldName == "cqrsComponent"_L1) {
                return cqrsComponentSet;
            }
            if (fieldName == "contractsComponent"_L1) {
                return contractsComponentSet;
            }
            if (fieldName == "presenterComponent"_L1) {
                return presenterComponentSet;
            }
            if (fieldName == "frontEndComponent"_L1) {
                return frontEndComponentSet;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "fileName"_L1) {
                return true;
            }
            if (fieldName == "rootPath"_L1) {
                return true;
            }
            if (fieldName == "globalComponent"_L1) {
                return globalComponentLoaded;
            }
            if (fieldName == "entityComponent"_L1) {
                return entityComponentLoaded;
            }
            if (fieldName == "repositoryComponent"_L1) {
                return repositoryComponentLoaded;
            }
            if (fieldName == "interactorComponent"_L1) {
                return interactorComponentLoaded;
            }
            if (fieldName == "applicationComponent"_L1) {
                return applicationComponentLoaded;
            }
            if (fieldName == "dtoComponent"_L1) {
                return dtoComponentLoaded;
            }
            if (fieldName == "cqrsComponent"_L1) {
                return cqrsComponentLoaded;
            }
            if (fieldName == "contractsComponent"_L1) {
                return contractsComponentLoaded;
            }
            if (fieldName == "presenterComponent"_L1) {
                return presenterComponentLoaded;
            }
            if (fieldName == "frontEndComponent"_L1) {
                return frontEndComponentLoaded;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        Project *m_entity = nullptr;
    };

    Project()
        : CommonParent()
        , m_metaData(this)
        , m_fileName(QString())
        , m_rootPath(QString())
    {
    }

    ~Project()
    {
    }

    Project(const int &id,
            const QUuid &uuid,
            const QDateTime &creationDate,
            const QDateTime &updateDate,
            const QString &fileName,
            const QString &rootPath,
            const GlobalComponent &globalComponent,
            const EntityComponent &entityComponent,
            const RepositoryComponent &repositoryComponent,
            const InteractorComponent &interactorComponent,
            const ApplicationComponent &applicationComponent,
            const DTOComponent &dtoComponent,
            const CQRSComponent &cqrsComponent,
            const ContractsComponent &contractsComponent,
            const PresenterComponent &presenterComponent,
            const QList<FrontEndComponent> &frontEndComponent)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_fileName(fileName)
        , m_rootPath(rootPath)
        , m_globalComponent(globalComponent)
        , m_entityComponent(entityComponent)
        , m_repositoryComponent(repositoryComponent)
        , m_interactorComponent(interactorComponent)
        , m_applicationComponent(applicationComponent)
        , m_dtoComponent(dtoComponent)
        , m_cqrsComponent(cqrsComponent)
        , m_contractsComponent(contractsComponent)
        , m_presenterComponent(presenterComponent)
        , m_frontEndComponent(frontEndComponent)
    {
    }

    Project(const Project &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_fileName(other.m_fileName)
        , m_rootPath(other.m_rootPath)
        , m_globalComponent(other.m_globalComponent)
        , m_entityComponent(other.m_entityComponent)
        , m_repositoryComponent(other.m_repositoryComponent)
        , m_interactorComponent(other.m_interactorComponent)
        , m_applicationComponent(other.m_applicationComponent)
        , m_dtoComponent(other.m_dtoComponent)
        , m_cqrsComponent(other.m_cqrsComponent)
        , m_contractsComponent(other.m_contractsComponent)
        , m_presenterComponent(other.m_presenterComponent)
        , m_frontEndComponent(other.m_frontEndComponent)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::Project;
    }

    Project &operator=(const Project &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_fileName = other.m_fileName;
            m_rootPath = other.m_rootPath;
            m_globalComponent = other.m_globalComponent;
            m_entityComponent = other.m_entityComponent;
            m_repositoryComponent = other.m_repositoryComponent;
            m_interactorComponent = other.m_interactorComponent;
            m_applicationComponent = other.m_applicationComponent;
            m_dtoComponent = other.m_dtoComponent;
            m_cqrsComponent = other.m_cqrsComponent;
            m_contractsComponent = other.m_contractsComponent;
            m_presenterComponent = other.m_presenterComponent;
            m_frontEndComponent = other.m_frontEndComponent;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const Project &lhs, const Project &rhs);

    friend uint qHash(const Project &entity, uint seed) noexcept;

    // ------ fileName : -----

    QString fileName() const
    {
        return m_fileName;
    }

    void setFileName(const QString &fileName)
    {
        m_fileName = fileName;
    }

    // ------ rootPath : -----

    QString rootPath() const
    {
        return m_rootPath;
    }

    void setRootPath(const QString &rootPath)
    {
        m_rootPath = rootPath;
    }

    // ------ globalComponent : -----

    GlobalComponent globalComponent()
    {
        if (!m_metaData.globalComponentLoaded && m_globalComponentLoader) {
            m_globalComponent = m_globalComponentLoader(this->id());
            m_metaData.globalComponentLoaded = true;
        }
        return m_globalComponent;
    }

    void setGlobalComponent(const GlobalComponent &globalComponent)
    {
        m_globalComponent = globalComponent;

        m_metaData.globalComponentSet = true;
    }

    using GlobalComponentLoader = std::function<GlobalComponent(int entityId)>;

    void setGlobalComponentLoader(const GlobalComponentLoader &loader)
    {
        m_globalComponentLoader = loader;
    }

    // ------ entityComponent : -----

    EntityComponent entityComponent()
    {
        if (!m_metaData.entityComponentLoaded && m_entityComponentLoader) {
            m_entityComponent = m_entityComponentLoader(this->id());
            m_metaData.entityComponentLoaded = true;
        }
        return m_entityComponent;
    }

    void setEntityComponent(const EntityComponent &entityComponent)
    {
        m_entityComponent = entityComponent;

        m_metaData.entityComponentSet = true;
    }

    using EntityComponentLoader = std::function<EntityComponent(int entityId)>;

    void setEntityComponentLoader(const EntityComponentLoader &loader)
    {
        m_entityComponentLoader = loader;
    }

    // ------ repositoryComponent : -----

    RepositoryComponent repositoryComponent()
    {
        if (!m_metaData.repositoryComponentLoaded && m_repositoryComponentLoader) {
            m_repositoryComponent = m_repositoryComponentLoader(this->id());
            m_metaData.repositoryComponentLoaded = true;
        }
        return m_repositoryComponent;
    }

    void setRepositoryComponent(const RepositoryComponent &repositoryComponent)
    {
        m_repositoryComponent = repositoryComponent;

        m_metaData.repositoryComponentSet = true;
    }

    using RepositoryComponentLoader = std::function<RepositoryComponent(int entityId)>;

    void setRepositoryComponentLoader(const RepositoryComponentLoader &loader)
    {
        m_repositoryComponentLoader = loader;
    }

    // ------ interactorComponent : -----

    InteractorComponent interactorComponent()
    {
        if (!m_metaData.interactorComponentLoaded && m_interactorComponentLoader) {
            m_interactorComponent = m_interactorComponentLoader(this->id());
            m_metaData.interactorComponentLoaded = true;
        }
        return m_interactorComponent;
    }

    void setInteractorComponent(const InteractorComponent &interactorComponent)
    {
        m_interactorComponent = interactorComponent;

        m_metaData.interactorComponentSet = true;
    }

    using InteractorComponentLoader = std::function<InteractorComponent(int entityId)>;

    void setInteractorComponentLoader(const InteractorComponentLoader &loader)
    {
        m_interactorComponentLoader = loader;
    }

    // ------ applicationComponent : -----

    ApplicationComponent applicationComponent()
    {
        if (!m_metaData.applicationComponentLoaded && m_applicationComponentLoader) {
            m_applicationComponent = m_applicationComponentLoader(this->id());
            m_metaData.applicationComponentLoaded = true;
        }
        return m_applicationComponent;
    }

    void setApplicationComponent(const ApplicationComponent &applicationComponent)
    {
        m_applicationComponent = applicationComponent;

        m_metaData.applicationComponentSet = true;
    }

    using ApplicationComponentLoader = std::function<ApplicationComponent(int entityId)>;

    void setApplicationComponentLoader(const ApplicationComponentLoader &loader)
    {
        m_applicationComponentLoader = loader;
    }

    // ------ dtoComponent : -----

    DTOComponent dtoComponent()
    {
        if (!m_metaData.dtoComponentLoaded && m_dtoComponentLoader) {
            m_dtoComponent = m_dtoComponentLoader(this->id());
            m_metaData.dtoComponentLoaded = true;
        }
        return m_dtoComponent;
    }

    void setDtoComponent(const DTOComponent &dtoComponent)
    {
        m_dtoComponent = dtoComponent;

        m_metaData.dtoComponentSet = true;
    }

    using DtoComponentLoader = std::function<DTOComponent(int entityId)>;

    void setDtoComponentLoader(const DtoComponentLoader &loader)
    {
        m_dtoComponentLoader = loader;
    }

    // ------ cqrsComponent : -----

    CQRSComponent cqrsComponent()
    {
        if (!m_metaData.cqrsComponentLoaded && m_cqrsComponentLoader) {
            m_cqrsComponent = m_cqrsComponentLoader(this->id());
            m_metaData.cqrsComponentLoaded = true;
        }
        return m_cqrsComponent;
    }

    void setCqrsComponent(const CQRSComponent &cqrsComponent)
    {
        m_cqrsComponent = cqrsComponent;

        m_metaData.cqrsComponentSet = true;
    }

    using CqrsComponentLoader = std::function<CQRSComponent(int entityId)>;

    void setCqrsComponentLoader(const CqrsComponentLoader &loader)
    {
        m_cqrsComponentLoader = loader;
    }

    // ------ contractsComponent : -----

    ContractsComponent contractsComponent()
    {
        if (!m_metaData.contractsComponentLoaded && m_contractsComponentLoader) {
            m_contractsComponent = m_contractsComponentLoader(this->id());
            m_metaData.contractsComponentLoaded = true;
        }
        return m_contractsComponent;
    }

    void setContractsComponent(const ContractsComponent &contractsComponent)
    {
        m_contractsComponent = contractsComponent;

        m_metaData.contractsComponentSet = true;
    }

    using ContractsComponentLoader = std::function<ContractsComponent(int entityId)>;

    void setContractsComponentLoader(const ContractsComponentLoader &loader)
    {
        m_contractsComponentLoader = loader;
    }

    // ------ presenterComponent : -----

    PresenterComponent presenterComponent()
    {
        if (!m_metaData.presenterComponentLoaded && m_presenterComponentLoader) {
            m_presenterComponent = m_presenterComponentLoader(this->id());
            m_metaData.presenterComponentLoaded = true;
        }
        return m_presenterComponent;
    }

    void setPresenterComponent(const PresenterComponent &presenterComponent)
    {
        m_presenterComponent = presenterComponent;

        m_metaData.presenterComponentSet = true;
    }

    using PresenterComponentLoader = std::function<PresenterComponent(int entityId)>;

    void setPresenterComponentLoader(const PresenterComponentLoader &loader)
    {
        m_presenterComponentLoader = loader;
    }

    // ------ frontEndComponent : -----

    QList<FrontEndComponent> frontEndComponent()
    {
        if (!m_metaData.frontEndComponentLoaded && m_frontEndComponentLoader) {
            m_frontEndComponent = m_frontEndComponentLoader(this->id());
            m_metaData.frontEndComponentLoaded = true;
        }
        return m_frontEndComponent;
    }

    void setFrontEndComponent(const QList<FrontEndComponent> &frontEndComponent)
    {
        m_frontEndComponent = frontEndComponent;

        m_metaData.frontEndComponentSet = true;
    }

    using FrontEndComponentLoader = std::function<QList<FrontEndComponent>(int entityId)>;

    void setFrontEndComponentLoader(const FrontEndComponentLoader &loader)
    {
        m_frontEndComponentLoader = loader;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_fileName;
    QString m_rootPath;
    GlobalComponent m_globalComponent;
    GlobalComponentLoader m_globalComponentLoader;
    EntityComponent m_entityComponent;
    EntityComponentLoader m_entityComponentLoader;
    RepositoryComponent m_repositoryComponent;
    RepositoryComponentLoader m_repositoryComponentLoader;
    InteractorComponent m_interactorComponent;
    InteractorComponentLoader m_interactorComponentLoader;
    ApplicationComponent m_applicationComponent;
    ApplicationComponentLoader m_applicationComponentLoader;
    DTOComponent m_dtoComponent;
    DtoComponentLoader m_dtoComponentLoader;
    CQRSComponent m_cqrsComponent;
    CqrsComponentLoader m_cqrsComponentLoader;
    ContractsComponent m_contractsComponent;
    ContractsComponentLoader m_contractsComponentLoader;
    PresenterComponent m_presenterComponent;
    PresenterComponentLoader m_presenterComponentLoader;
    QList<FrontEndComponent> m_frontEndComponent;
    FrontEndComponentLoader m_frontEndComponentLoader;
};

inline bool operator==(const Project &lhs, const Project &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_fileName == rhs.m_fileName && lhs.m_rootPath == rhs.m_rootPath && lhs.m_globalComponent == rhs.m_globalComponent
        && lhs.m_entityComponent == rhs.m_entityComponent && lhs.m_repositoryComponent == rhs.m_repositoryComponent
        && lhs.m_interactorComponent == rhs.m_interactorComponent && lhs.m_applicationComponent == rhs.m_applicationComponent
        && lhs.m_dtoComponent == rhs.m_dtoComponent && lhs.m_cqrsComponent == rhs.m_cqrsComponent && lhs.m_contractsComponent == rhs.m_contractsComponent
        && lhs.m_presenterComponent == rhs.m_presenterComponent && lhs.m_frontEndComponent == rhs.m_frontEndComponent;
}

inline uint qHash(const Project &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_fileName, seed);
    hash ^= ::qHash(entity.m_rootPath, seed);
    hash ^= ::qHash(entity.m_globalComponent, seed);
    hash ^= ::qHash(entity.m_entityComponent, seed);
    hash ^= ::qHash(entity.m_repositoryComponent, seed);
    hash ^= ::qHash(entity.m_interactorComponent, seed);
    hash ^= ::qHash(entity.m_applicationComponent, seed);
    hash ^= ::qHash(entity.m_dtoComponent, seed);
    hash ^= ::qHash(entity.m_cqrsComponent, seed);
    hash ^= ::qHash(entity.m_contractsComponent, seed);
    hash ^= ::qHash(entity.m_presenterComponent, seed);
    hash ^= ::qHash(entity.m_frontEndComponent, seed);

    return hash;
}

/// Schema for Project entity
inline Qleany::Entities::EntitySchema Project::schema = {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                         "Project"_L1,

                                                         // relationships:
                                                         {{QleanyEditor::Entities::Entities::EntityEnum::Root,
                                                           "Root"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           "project"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Backward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::GlobalComponent,
                                                           "GlobalComponent"_L1,
                                                           "globalComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::EntityComponent,
                                                           "EntityComponent"_L1,
                                                           "entityComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::RepositoryComponent,
                                                           "RepositoryComponent"_L1,
                                                           "repositoryComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::InteractorComponent,
                                                           "InteractorComponent"_L1,
                                                           "interactorComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::ApplicationComponent,
                                                           "ApplicationComponent"_L1,
                                                           "applicationComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::DTOComponent,
                                                           "DTOComponent"_L1,
                                                           "dtoComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::CQRSComponent,
                                                           "CQRSComponent"_L1,
                                                           "cqrsComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::ContractsComponent,
                                                           "ContractsComponent"_L1,
                                                           "contractsComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::PresenterComponent,
                                                           "PresenterComponent"_L1,
                                                           "presenterComponent"_L1,
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           "Project"_L1,
                                                           QleanyEditor::Entities::Entities::EntityEnum::FrontEndComponent,
                                                           "FrontEndComponent"_L1,
                                                           "frontEndComponent"_L1,
                                                           RelationshipType::OneToMany,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::ManyUnordered,
                                                           RelationshipDirection::Forward}},

                                                         // fields:
                                                         {{"id"_L1, FieldType::Integer, true, false},
                                                          {"uuid"_L1, FieldType::Uuid, false, false},
                                                          {"creationDate"_L1, FieldType::DateTime, false, false},
                                                          {"updateDate"_L1, FieldType::DateTime, false, false},
                                                          {"fileName"_L1, FieldType::String, false, false},
                                                          {"rootPath"_L1, FieldType::String, false, false},
                                                          {"globalComponent"_L1, FieldType::Entity, false, true},
                                                          {"entityComponent"_L1, FieldType::Entity, false, true},
                                                          {"repositoryComponent"_L1, FieldType::Entity, false, true},
                                                          {"interactorComponent"_L1, FieldType::Entity, false, true},
                                                          {"applicationComponent"_L1, FieldType::Entity, false, true},
                                                          {"dtoComponent"_L1, FieldType::Entity, false, true},
                                                          {"cqrsComponent"_L1, FieldType::Entity, false, true},
                                                          {"contractsComponent"_L1, FieldType::Entity, false, true},
                                                          {"presenterComponent"_L1, FieldType::Entity, false, true},
                                                          {"frontEndComponent"_L1, FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::Project)