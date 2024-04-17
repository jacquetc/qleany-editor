// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

namespace QleanyEditor::Contracts::DTO::ContractsComponent
{
using namespace Qt::Literals::StringLiterals;

class CreateContractsComponentDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString invertedAppDomain READ invertedAppDomain WRITE setInvertedAppDomain)
    Q_PROPERTY(QString folderPath READ folderPath WRITE setFolderPath)
    Q_PROPERTY(int projectId READ projectId WRITE setProjectId)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool invertedAppDomainSet = false;
        bool folderPathSet = false;
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
            if (fieldName == "invertedAppDomain"_L1) {
                return invertedAppDomainSet;
            }
            if (fieldName == "folderPath"_L1) {
                return folderPathSet;
            }
            if (fieldName == "projectId"_L1) {
                return projectIdSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    CreateContractsComponentDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_invertedAppDomain(QString())
        , m_folderPath(QString())
        , m_projectId(0)
    {
    }

    ~CreateContractsComponentDTO()
    {
    }

    CreateContractsComponentDTO(const QUuid &uuid,
                                const QDateTime &creationDate,
                                const QDateTime &updateDate,
                                const QString &invertedAppDomain,
                                const QString &folderPath,
                                int projectId)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_invertedAppDomain(invertedAppDomain)
        , m_folderPath(folderPath)
        , m_projectId(projectId)
    {
    }

    CreateContractsComponentDTO(const CreateContractsComponentDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_invertedAppDomain(other.m_invertedAppDomain)
        , m_folderPath(other.m_folderPath)
        , m_projectId(other.m_projectId)
    {
    }

    CreateContractsComponentDTO &operator=(const CreateContractsComponentDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_invertedAppDomain = other.m_invertedAppDomain;
            m_folderPath = other.m_folderPath;
            m_projectId = other.m_projectId;
        }
        return *this;
    }

    CreateContractsComponentDTO &operator=(const CreateContractsComponentDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_invertedAppDomain = other.m_invertedAppDomain;
            m_folderPath = other.m_folderPath;
            m_projectId = other.m_projectId;
        }
        return *this;
    }

    CreateContractsComponentDTO &mergeWith(const CreateContractsComponentDTO &other)
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
            if (other.m_metaData.invertedAppDomainSet) {
                m_invertedAppDomain = other.m_invertedAppDomain;
                m_metaData.invertedAppDomainSet = true;
            }
            if (other.m_metaData.folderPathSet) {
                m_folderPath = other.m_folderPath;
                m_metaData.folderPathSet = true;
            }
            if (other.m_metaData.projectIdSet) {
                m_projectId = other.m_projectId;
                m_metaData.projectIdSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateContractsComponentDTO &operator<<(const CreateContractsComponentDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateContractsComponentDTO &lhs, const CreateContractsComponentDTO &rhs);

    friend uint qHash(const CreateContractsComponentDTO &dto, uint seed) noexcept;

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

    // ------ invertedAppDomain : -----

    QString invertedAppDomain() const
    {
        return m_invertedAppDomain;
    }

    void setInvertedAppDomain(const QString &invertedAppDomain)
    {
        m_invertedAppDomain = invertedAppDomain;
        m_metaData.invertedAppDomainSet = true;
    }

    // ------ folderPath : -----

    QString folderPath() const
    {
        return m_folderPath;
    }

    void setFolderPath(const QString &folderPath)
    {
        m_folderPath = folderPath;
        m_metaData.folderPathSet = true;
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
    QString m_invertedAppDomain;
    QString m_folderPath;
    int m_projectId;
};

inline bool operator==(const CreateContractsComponentDTO &lhs, const CreateContractsComponentDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_invertedAppDomain == rhs.m_invertedAppDomain && lhs.m_folderPath == rhs.m_folderPath && lhs.m_projectId == rhs.m_projectId;
}

inline uint qHash(const CreateContractsComponentDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_invertedAppDomain, seed);
    hash ^= ::qHash(dto.m_folderPath, seed);
    hash ^= ::qHash(dto.m_projectId, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::ContractsComponent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::ContractsComponent::CreateContractsComponentDTO)