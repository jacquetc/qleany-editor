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

class UpdateContractsComponentDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString invertedAppDomain READ invertedAppDomain WRITE setInvertedAppDomain)
    Q_PROPERTY(QString folderPath READ folderPath WRITE setFolderPath)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool invertedAppDomainSet = false;
        bool folderPathSet = false;
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
            if (fieldName == "invertedAppDomain"_L1) {
                return invertedAppDomainSet;
            }
            if (fieldName == "folderPath"_L1) {
                return folderPathSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    UpdateContractsComponentDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_invertedAppDomain(QString())
        , m_folderPath(QString())
    {
    }

    ~UpdateContractsComponentDTO()
    {
    }

    UpdateContractsComponentDTO(int id,
                                const QUuid &uuid,
                                const QDateTime &creationDate,
                                const QDateTime &updateDate,
                                const QString &invertedAppDomain,
                                const QString &folderPath)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_invertedAppDomain(invertedAppDomain)
        , m_folderPath(folderPath)
    {
    }

    UpdateContractsComponentDTO(const UpdateContractsComponentDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_invertedAppDomain(other.m_invertedAppDomain)
        , m_folderPath(other.m_folderPath)
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

    UpdateContractsComponentDTO &operator=(const UpdateContractsComponentDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_invertedAppDomain = other.m_invertedAppDomain;
            m_folderPath = other.m_folderPath;
        }
        return *this;
    }

    UpdateContractsComponentDTO &operator=(const UpdateContractsComponentDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_invertedAppDomain = other.m_invertedAppDomain;
            m_folderPath = other.m_folderPath;
        }
        return *this;
    }

    UpdateContractsComponentDTO &mergeWith(const UpdateContractsComponentDTO &other)
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
            if (other.m_metaData.invertedAppDomainSet) {
                m_invertedAppDomain = other.m_invertedAppDomain;
                m_metaData.invertedAppDomainSet = true;
            }
            if (other.m_metaData.folderPathSet) {
                m_folderPath = other.m_folderPath;
                m_metaData.folderPathSet = true;
            }
        }
        return *this;
    }

    // import operator
    UpdateContractsComponentDTO &operator<<(const UpdateContractsComponentDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const UpdateContractsComponentDTO &lhs, const UpdateContractsComponentDTO &rhs);

    friend uint qHash(const UpdateContractsComponentDTO &dto, uint seed) noexcept;

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
    QString m_invertedAppDomain;
    QString m_folderPath;
};

inline bool operator==(const UpdateContractsComponentDTO &lhs, const UpdateContractsComponentDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_invertedAppDomain == rhs.m_invertedAppDomain && lhs.m_folderPath == rhs.m_folderPath;
}

inline uint qHash(const UpdateContractsComponentDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_invertedAppDomain, seed);
    hash ^= ::qHash(dto.m_folderPath, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::ContractsComponent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::ContractsComponent::UpdateContractsComponentDTO)