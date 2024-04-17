// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository/repository_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::Repository;

namespace QleanyEditor::Contracts::DTO::RepositoryComponent
{
using namespace Qt::Literals::StringLiterals;

class CreateRepositoryComponentDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QList<RepositoryDTO> repositories READ repositories WRITE setRepositories)
    Q_PROPERTY(QString repositoryFolderPath READ repositoryFolderPath WRITE setRepositoryFolderPath)
    Q_PROPERTY(QString baseFolderPath READ baseFolderPath WRITE setBaseFolderPath)
    Q_PROPERTY(int projectId READ projectId WRITE setProjectId)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool repositoriesSet = false;
        bool repositoryFolderPathSet = false;
        bool baseFolderPathSet = false;
        bool projectIdSet = false;
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "uuid"_L1) {
                return uuidSet;
            }
            if (fieldName == "creationDate"_L1) {
                return creationDateSet;
            }
            if (fieldName == "updateDate"_L1) {
                return updateDateSet;
            }
            if (fieldName == "repositories"_L1) {
                return repositoriesSet;
            }
            if (fieldName == "repositoryFolderPath"_L1) {
                return repositoryFolderPathSet;
            }
            if (fieldName == "baseFolderPath"_L1) {
                return baseFolderPathSet;
            }
            if (fieldName == "projectId"_L1) {
                return projectIdSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (repositoriesSet)
                return true;

            return false;
        }
    };

    CreateRepositoryComponentDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_repositoryFolderPath(QString())
        , m_baseFolderPath(QString())
        , m_projectId(0)
    {
    }

    ~CreateRepositoryComponentDTO()
    {
    }

    CreateRepositoryComponentDTO(const QUuid &uuid,
                                 const QDateTime &creationDate,
                                 const QDateTime &updateDate,
                                 const QList<RepositoryDTO> &repositories,
                                 const QString &repositoryFolderPath,
                                 const QString &baseFolderPath,
                                 int projectId)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_repositories(repositories)
        , m_repositoryFolderPath(repositoryFolderPath)
        , m_baseFolderPath(baseFolderPath)
        , m_projectId(projectId)
    {
    }

    CreateRepositoryComponentDTO(const CreateRepositoryComponentDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_repositories(other.m_repositories)
        , m_repositoryFolderPath(other.m_repositoryFolderPath)
        , m_baseFolderPath(other.m_baseFolderPath)
        , m_projectId(other.m_projectId)
    {
    }

    CreateRepositoryComponentDTO &operator=(const CreateRepositoryComponentDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_repositories = other.m_repositories;
            m_repositoryFolderPath = other.m_repositoryFolderPath;
            m_baseFolderPath = other.m_baseFolderPath;
            m_projectId = other.m_projectId;
        }
        return *this;
    }

    CreateRepositoryComponentDTO &operator=(const CreateRepositoryComponentDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_repositories = other.m_repositories;
            m_repositoryFolderPath = other.m_repositoryFolderPath;
            m_baseFolderPath = other.m_baseFolderPath;
            m_projectId = other.m_projectId;
        }
        return *this;
    }

    CreateRepositoryComponentDTO &mergeWith(const CreateRepositoryComponentDTO &other)
    {
        if (this != &other) {
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
            if (other.m_metaData.repositoriesSet) {
                m_repositories = other.m_repositories;
                m_metaData.repositoriesSet = true;
            }
            if (other.m_metaData.repositoryFolderPathSet) {
                m_repositoryFolderPath = other.m_repositoryFolderPath;
                m_metaData.repositoryFolderPathSet = true;
            }
            if (other.m_metaData.baseFolderPathSet) {
                m_baseFolderPath = other.m_baseFolderPath;
                m_metaData.baseFolderPathSet = true;
            }
            if (other.m_metaData.projectIdSet) {
                m_projectId = other.m_projectId;
                m_metaData.projectIdSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateRepositoryComponentDTO &operator<<(const CreateRepositoryComponentDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateRepositoryComponentDTO &lhs, const CreateRepositoryComponentDTO &rhs);

    friend uint qHash(const CreateRepositoryComponentDTO &dto, uint seed) noexcept;

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

    // ------ repositories : -----

    QList<RepositoryDTO> repositories() const
    {
        return m_repositories;
    }

    void setRepositories(const QList<RepositoryDTO> &repositories)
    {
        m_repositories = repositories;
        m_metaData.repositoriesSet = true;
    }

    // ------ repositoryFolderPath : -----

    QString repositoryFolderPath() const
    {
        return m_repositoryFolderPath;
    }

    void setRepositoryFolderPath(const QString &repositoryFolderPath)
    {
        m_repositoryFolderPath = repositoryFolderPath;
        m_metaData.repositoryFolderPathSet = true;
    }

    // ------ baseFolderPath : -----

    QString baseFolderPath() const
    {
        return m_baseFolderPath;
    }

    void setBaseFolderPath(const QString &baseFolderPath)
    {
        m_baseFolderPath = baseFolderPath;
        m_metaData.baseFolderPathSet = true;
    }

    // ------ projectId : -----

    int projectId() const
    {
        return m_projectId;
    }

    void setProjectId(int projectId)
    {
        m_projectId = projectId;
        m_metaData.projectIdSet = true;
    }

    MetaData metaData() const
    {
        return m_metaData;
    }

private:
    MetaData m_metaData;

    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
    QList<RepositoryDTO> m_repositories;
    QString m_repositoryFolderPath;
    QString m_baseFolderPath;
    int m_projectId;
};

inline bool operator==(const CreateRepositoryComponentDTO &lhs, const CreateRepositoryComponentDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_repositories == rhs.m_repositories && lhs.m_repositoryFolderPath == rhs.m_repositoryFolderPath && lhs.m_baseFolderPath == rhs.m_baseFolderPath
        && lhs.m_projectId == rhs.m_projectId;
}

inline uint qHash(const CreateRepositoryComponentDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_repositories, seed);
    hash ^= ::qHash(dto.m_repositoryFolderPath, seed);
    hash ^= ::qHash(dto.m_baseFolderPath, seed);
    hash ^= ::qHash(dto.m_projectId, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::RepositoryComponent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::RepositoryComponent::CreateRepositoryComponentDTO)