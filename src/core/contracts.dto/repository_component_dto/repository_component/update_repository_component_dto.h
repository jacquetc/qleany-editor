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

class UpdateRepositoryComponentDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QList<RepositoryDTO> repositories READ repositories WRITE setRepositories)
    Q_PROPERTY(QString repositoryFolderPath READ repositoryFolderPath WRITE setRepositoryFolderPath)
    Q_PROPERTY(QString baseFolderPath READ baseFolderPath WRITE setBaseFolderPath)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool repositoriesSet = false;
        bool repositoryFolderPathSet = false;
        bool baseFolderPathSet = false;
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
            if (fieldName == "repositories"_L1) {
                return repositoriesSet;
            }
            if (fieldName == "repositoryFolderPath"_L1) {
                return repositoryFolderPathSet;
            }
            if (fieldName == "baseFolderPath"_L1) {
                return baseFolderPathSet;
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

    UpdateRepositoryComponentDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_repositoryFolderPath(QString())
        , m_baseFolderPath(QString())
    {
    }

    ~UpdateRepositoryComponentDTO()
    {
    }

    UpdateRepositoryComponentDTO(int id,
                                 const QUuid &uuid,
                                 const QDateTime &creationDate,
                                 const QDateTime &updateDate,
                                 const QList<RepositoryDTO> &repositories,
                                 const QString &repositoryFolderPath,
                                 const QString &baseFolderPath)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_repositories(repositories)
        , m_repositoryFolderPath(repositoryFolderPath)
        , m_baseFolderPath(baseFolderPath)
    {
    }

    UpdateRepositoryComponentDTO(const UpdateRepositoryComponentDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_repositories(other.m_repositories)
        , m_repositoryFolderPath(other.m_repositoryFolderPath)
        , m_baseFolderPath(other.m_baseFolderPath)
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

    UpdateRepositoryComponentDTO &operator=(const UpdateRepositoryComponentDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_repositories = other.m_repositories;
            m_repositoryFolderPath = other.m_repositoryFolderPath;
            m_baseFolderPath = other.m_baseFolderPath;
        }
        return *this;
    }

    UpdateRepositoryComponentDTO &operator=(const UpdateRepositoryComponentDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_repositories = other.m_repositories;
            m_repositoryFolderPath = other.m_repositoryFolderPath;
            m_baseFolderPath = other.m_baseFolderPath;
        }
        return *this;
    }

    UpdateRepositoryComponentDTO &mergeWith(const UpdateRepositoryComponentDTO &other)
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
        }
        return *this;
    }

    // import operator
    UpdateRepositoryComponentDTO &operator<<(const UpdateRepositoryComponentDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const UpdateRepositoryComponentDTO &lhs, const UpdateRepositoryComponentDTO &rhs);

    friend uint qHash(const UpdateRepositoryComponentDTO &dto, uint seed) noexcept;

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
    QList<RepositoryDTO> m_repositories;
    QString m_repositoryFolderPath;
    QString m_baseFolderPath;
};

inline bool operator==(const UpdateRepositoryComponentDTO &lhs, const UpdateRepositoryComponentDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_repositories == rhs.m_repositories && lhs.m_repositoryFolderPath == rhs.m_repositoryFolderPath && lhs.m_baseFolderPath == rhs.m_baseFolderPath;
}

inline uint qHash(const UpdateRepositoryComponentDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_repositories, seed);
    hash ^= ::qHash(dto.m_repositoryFolderPath, seed);
    hash ^= ::qHash(dto.m_baseFolderPath, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::RepositoryComponent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::RepositoryComponent::UpdateRepositoryComponentDTO)