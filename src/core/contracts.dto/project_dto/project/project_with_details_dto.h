// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/application_component_dto.h"
#include "c_q_r_s_component/c_q_r_s_component_dto.h"
#include "contracts_component/contracts_component_dto.h"
#include "d_t_o_component/d_t_o_component_dto.h"
#include "entity_component/entity_component_dto.h"
#include "front_end_component/front_end_component_dto.h"
#include "global_component/global_component_dto.h"
#include "interactor_component/interactor_component_dto.h"
#include "presenter_component/presenter_component_dto.h"
#include "repository_component/repository_component_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::GlobalComponent;
using namespace QleanyEditor::Contracts::DTO::EntityComponent;
using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;
using namespace QleanyEditor::Contracts::DTO::InteractorComponent;
using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;
using namespace QleanyEditor::Contracts::DTO::DTOComponent;
using namespace QleanyEditor::Contracts::DTO::CQRSComponent;
using namespace QleanyEditor::Contracts::DTO::ContractsComponent;
using namespace QleanyEditor::Contracts::DTO::PresenterComponent;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;

namespace QleanyEditor::Contracts::DTO::Project
{
using namespace Qt::Literals::StringLiterals;

class ProjectWithDetailsDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath)
    Q_PROPERTY(GlobalComponentDTO globalComponent READ globalComponent WRITE setGlobalComponent)
    Q_PROPERTY(EntityComponentDTO entityComponent READ entityComponent WRITE setEntityComponent)
    Q_PROPERTY(RepositoryComponentDTO repositoryComponent READ repositoryComponent WRITE setRepositoryComponent)
    Q_PROPERTY(InteractorComponentDTO interactorComponent READ interactorComponent WRITE setInteractorComponent)
    Q_PROPERTY(ApplicationComponentDTO applicationComponent READ applicationComponent WRITE setApplicationComponent)
    Q_PROPERTY(DTOComponentDTO dtoComponent READ dtoComponent WRITE setDtoComponent)
    Q_PROPERTY(CQRSComponentDTO cqrsComponent READ cqrsComponent WRITE setCqrsComponent)
    Q_PROPERTY(ContractsComponentDTO contractsComponent READ contractsComponent WRITE setContractsComponent)
    Q_PROPERTY(PresenterComponentDTO presenterComponent READ presenterComponent WRITE setPresenterComponent)
    Q_PROPERTY(QList<FrontEndComponentDTO> frontEndComponent READ frontEndComponent WRITE setFrontEndComponent)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool fileNameSet = false;
        bool rootPathSet = false;
        bool globalComponentSet = false;
        bool entityComponentSet = false;
        bool repositoryComponentSet = false;
        bool interactorComponentSet = false;
        bool applicationComponentSet = false;
        bool dtoComponentSet = false;
        bool cqrsComponentSet = false;
        bool contractsComponentSet = false;
        bool presenterComponentSet = false;
        bool frontEndComponentSet = false;
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "id"_L1) {
                return idSet;
            }
            if (fieldName == "uuid"_L1) {
                return uuidSet;
            }
            if (fieldName == "creationDate"_L1) {
                return creationDateSet;
            }
            if (fieldName == "updateDate"_L1) {
                return updateDateSet;
            }
            if (fieldName == "fileName"_L1) {
                return fileNameSet;
            }
            if (fieldName == "rootPath"_L1) {
                return rootPathSet;
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
            return false;
        }

        bool areDetailsSet() const
        {
            if (globalComponentSet)
                return true;

            if (entityComponentSet)
                return true;

            if (repositoryComponentSet)
                return true;

            if (interactorComponentSet)
                return true;

            if (applicationComponentSet)
                return true;

            if (dtoComponentSet)
                return true;

            if (cqrsComponentSet)
                return true;

            if (contractsComponentSet)
                return true;

            if (presenterComponentSet)
                return true;

            if (frontEndComponentSet)
                return true;

            return false;
        }
    };

    ProjectWithDetailsDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_fileName(QString())
        , m_rootPath(QString())
    {
    }

    ~ProjectWithDetailsDTO()
    {
    }

    ProjectWithDetailsDTO(int id,
                          const QUuid &uuid,
                          const QDateTime &creationDate,
                          const QDateTime &updateDate,
                          const QString &fileName,
                          const QString &rootPath,
                          const GlobalComponentDTO &globalComponent,
                          const EntityComponentDTO &entityComponent,
                          const RepositoryComponentDTO &repositoryComponent,
                          const InteractorComponentDTO &interactorComponent,
                          const ApplicationComponentDTO &applicationComponent,
                          const DTOComponentDTO &dtoComponent,
                          const CQRSComponentDTO &cqrsComponent,
                          const ContractsComponentDTO &contractsComponent,
                          const PresenterComponentDTO &presenterComponent,
                          const QList<FrontEndComponentDTO> &frontEndComponent)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
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

    ProjectWithDetailsDTO(const ProjectWithDetailsDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
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
    }

    Q_INVOKABLE bool isValid() const
    {
        return m_id > 0;
    }

    Q_INVOKABLE bool isNull() const
    {
        return !isValid();
    }

    Q_INVOKABLE bool isInvalid() const
    {
        return !isValid();
    }

    ProjectWithDetailsDTO &operator=(const ProjectWithDetailsDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
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
        }
        return *this;
    }

    ProjectWithDetailsDTO &operator=(const ProjectWithDetailsDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
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
        }
        return *this;
    }

    ProjectWithDetailsDTO &mergeWith(const ProjectWithDetailsDTO &other)
    {
        if (this != &other) {
            if (other.m_metaData.idSet) {
                m_id = other.m_id;
                m_metaData.idSet = true;
            }
            if (other.m_metaData.uuidSet) {
                m_uuid = other.m_uuid;
                m_metaData.uuidSet = true;
            }
            if (other.m_metaData.creationDateSet) {
                m_creationDate = other.m_creationDate;
                m_metaData.creationDateSet = true;
            }
            if (other.m_metaData.updateDateSet) {
                m_updateDate = other.m_updateDate;
                m_metaData.updateDateSet = true;
            }
            if (other.m_metaData.fileNameSet) {
                m_fileName = other.m_fileName;
                m_metaData.fileNameSet = true;
            }
            if (other.m_metaData.rootPathSet) {
                m_rootPath = other.m_rootPath;
                m_metaData.rootPathSet = true;
            }
            if (other.m_metaData.globalComponentSet) {
                m_globalComponent = other.m_globalComponent;
                m_metaData.globalComponentSet = true;
            }
            if (other.m_metaData.entityComponentSet) {
                m_entityComponent = other.m_entityComponent;
                m_metaData.entityComponentSet = true;
            }
            if (other.m_metaData.repositoryComponentSet) {
                m_repositoryComponent = other.m_repositoryComponent;
                m_metaData.repositoryComponentSet = true;
            }
            if (other.m_metaData.interactorComponentSet) {
                m_interactorComponent = other.m_interactorComponent;
                m_metaData.interactorComponentSet = true;
            }
            if (other.m_metaData.applicationComponentSet) {
                m_applicationComponent = other.m_applicationComponent;
                m_metaData.applicationComponentSet = true;
            }
            if (other.m_metaData.dtoComponentSet) {
                m_dtoComponent = other.m_dtoComponent;
                m_metaData.dtoComponentSet = true;
            }
            if (other.m_metaData.cqrsComponentSet) {
                m_cqrsComponent = other.m_cqrsComponent;
                m_metaData.cqrsComponentSet = true;
            }
            if (other.m_metaData.contractsComponentSet) {
                m_contractsComponent = other.m_contractsComponent;
                m_metaData.contractsComponentSet = true;
            }
            if (other.m_metaData.presenterComponentSet) {
                m_presenterComponent = other.m_presenterComponent;
                m_metaData.presenterComponentSet = true;
            }
            if (other.m_metaData.frontEndComponentSet) {
                m_frontEndComponent = other.m_frontEndComponent;
                m_metaData.frontEndComponentSet = true;
            }
        }
        return *this;
    }

    // import operator
    ProjectWithDetailsDTO &operator<<(const ProjectWithDetailsDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const ProjectWithDetailsDTO &lhs, const ProjectWithDetailsDTO &rhs);

    friend uint qHash(const ProjectWithDetailsDTO &dto, uint seed) noexcept;

    // ------ id : -----

    int id() const
    {
        return m_id;
    }

    void setId(int id)
    {
        m_id = id;
        m_metaData.idSet = true;
    }

    // ------ uuid : -----

    QUuid uuid() const
    {
        return m_uuid;
    }

    void setUuid(const QUuid &uuid)
    {
        m_uuid = uuid;
        m_metaData.uuidSet = true;
    }

    // ------ creationDate : -----

    QDateTime creationDate() const
    {
        return m_creationDate;
    }

    void setCreationDate(const QDateTime &creationDate)
    {
        m_creationDate = creationDate;
        m_metaData.creationDateSet = true;
    }

    // ------ updateDate : -----

    QDateTime updateDate() const
    {
        return m_updateDate;
    }

    void setUpdateDate(const QDateTime &updateDate)
    {
        m_updateDate = updateDate;
        m_metaData.updateDateSet = true;
    }

    // ------ fileName : -----

    QString fileName() const
    {
        return m_fileName;
    }

    void setFileName(const QString &fileName)
    {
        m_fileName = fileName;
        m_metaData.fileNameSet = true;
    }

    // ------ rootPath : -----

    QString rootPath() const
    {
        return m_rootPath;
    }

    void setRootPath(const QString &rootPath)
    {
        m_rootPath = rootPath;
        m_metaData.rootPathSet = true;
    }

    // ------ globalComponent : -----

    GlobalComponentDTO globalComponent() const
    {
        return m_globalComponent;
    }

    void setGlobalComponent(const GlobalComponentDTO &globalComponent)
    {
        m_globalComponent = globalComponent;
        m_metaData.globalComponentSet = true;
    }

    // ------ entityComponent : -----

    EntityComponentDTO entityComponent() const
    {
        return m_entityComponent;
    }

    void setEntityComponent(const EntityComponentDTO &entityComponent)
    {
        m_entityComponent = entityComponent;
        m_metaData.entityComponentSet = true;
    }

    // ------ repositoryComponent : -----

    RepositoryComponentDTO repositoryComponent() const
    {
        return m_repositoryComponent;
    }

    void setRepositoryComponent(const RepositoryComponentDTO &repositoryComponent)
    {
        m_repositoryComponent = repositoryComponent;
        m_metaData.repositoryComponentSet = true;
    }

    // ------ interactorComponent : -----

    InteractorComponentDTO interactorComponent() const
    {
        return m_interactorComponent;
    }

    void setInteractorComponent(const InteractorComponentDTO &interactorComponent)
    {
        m_interactorComponent = interactorComponent;
        m_metaData.interactorComponentSet = true;
    }

    // ------ applicationComponent : -----

    ApplicationComponentDTO applicationComponent() const
    {
        return m_applicationComponent;
    }

    void setApplicationComponent(const ApplicationComponentDTO &applicationComponent)
    {
        m_applicationComponent = applicationComponent;
        m_metaData.applicationComponentSet = true;
    }

    // ------ dtoComponent : -----

    DTOComponentDTO dtoComponent() const
    {
        return m_dtoComponent;
    }

    void setDtoComponent(const DTOComponentDTO &dtoComponent)
    {
        m_dtoComponent = dtoComponent;
        m_metaData.dtoComponentSet = true;
    }

    // ------ cqrsComponent : -----

    CQRSComponentDTO cqrsComponent() const
    {
        return m_cqrsComponent;
    }

    void setCqrsComponent(const CQRSComponentDTO &cqrsComponent)
    {
        m_cqrsComponent = cqrsComponent;
        m_metaData.cqrsComponentSet = true;
    }

    // ------ contractsComponent : -----

    ContractsComponentDTO contractsComponent() const
    {
        return m_contractsComponent;
    }

    void setContractsComponent(const ContractsComponentDTO &contractsComponent)
    {
        m_contractsComponent = contractsComponent;
        m_metaData.contractsComponentSet = true;
    }

    // ------ presenterComponent : -----

    PresenterComponentDTO presenterComponent() const
    {
        return m_presenterComponent;
    }

    void setPresenterComponent(const PresenterComponentDTO &presenterComponent)
    {
        m_presenterComponent = presenterComponent;
        m_metaData.presenterComponentSet = true;
    }

    // ------ frontEndComponent : -----

    QList<FrontEndComponentDTO> frontEndComponent() const
    {
        return m_frontEndComponent;
    }

    void setFrontEndComponent(const QList<FrontEndComponentDTO> &frontEndComponent)
    {
        m_frontEndComponent = frontEndComponent;
        m_metaData.frontEndComponentSet = true;
    }

    MetaData metaData() const
    {
        return m_metaData;
    }

private:
    MetaData m_metaData;

    int m_id;
    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
    QString m_fileName;
    QString m_rootPath;
    GlobalComponentDTO m_globalComponent;
    EntityComponentDTO m_entityComponent;
    RepositoryComponentDTO m_repositoryComponent;
    InteractorComponentDTO m_interactorComponent;
    ApplicationComponentDTO m_applicationComponent;
    DTOComponentDTO m_dtoComponent;
    CQRSComponentDTO m_cqrsComponent;
    ContractsComponentDTO m_contractsComponent;
    PresenterComponentDTO m_presenterComponent;
    QList<FrontEndComponentDTO> m_frontEndComponent;
};

inline bool operator==(const ProjectWithDetailsDTO &lhs, const ProjectWithDetailsDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_fileName == rhs.m_fileName && lhs.m_rootPath == rhs.m_rootPath && lhs.m_globalComponent == rhs.m_globalComponent
        && lhs.m_entityComponent == rhs.m_entityComponent && lhs.m_repositoryComponent == rhs.m_repositoryComponent
        && lhs.m_interactorComponent == rhs.m_interactorComponent && lhs.m_applicationComponent == rhs.m_applicationComponent
        && lhs.m_dtoComponent == rhs.m_dtoComponent && lhs.m_cqrsComponent == rhs.m_cqrsComponent && lhs.m_contractsComponent == rhs.m_contractsComponent
        && lhs.m_presenterComponent == rhs.m_presenterComponent && lhs.m_frontEndComponent == rhs.m_frontEndComponent;
}

inline uint qHash(const ProjectWithDetailsDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_fileName, seed);
    hash ^= ::qHash(dto.m_rootPath, seed);
    hash ^= ::qHash(dto.m_globalComponent, seed);
    hash ^= ::qHash(dto.m_entityComponent, seed);
    hash ^= ::qHash(dto.m_repositoryComponent, seed);
    hash ^= ::qHash(dto.m_interactorComponent, seed);
    hash ^= ::qHash(dto.m_applicationComponent, seed);
    hash ^= ::qHash(dto.m_dtoComponent, seed);
    hash ^= ::qHash(dto.m_cqrsComponent, seed);
    hash ^= ::qHash(dto.m_contractsComponent, seed);
    hash ^= ::qHash(dto.m_presenterComponent, seed);
    hash ^= ::qHash(dto.m_frontEndComponent, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Project
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Project::ProjectWithDetailsDTO)
