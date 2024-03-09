// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

namespace QleanyEditor::Contracts::DTO::GlobalComponent
{
using namespace Qt::Literals::StringLiterals;

class UpdateGlobalComponentDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString applicationName READ applicationName WRITE setApplicationName)
    Q_PROPERTY(QString applicationCppDomainName READ applicationCppDomainName WRITE setApplicationCppDomainName)
    Q_PROPERTY(QString organisationName READ organisationName WRITE setOrganisationName)
    Q_PROPERTY(QString organisationDomain READ organisationDomain WRITE setOrganisationDomain)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool applicationNameSet = false;
        bool applicationCppDomainNameSet = false;
        bool organisationNameSet = false;
        bool organisationDomainSet = false;
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
            if (fieldName == "applicationName"_L1) {
                return applicationNameSet;
            }
            if (fieldName == "applicationCppDomainName"_L1) {
                return applicationCppDomainNameSet;
            }
            if (fieldName == "organisationName"_L1) {
                return organisationNameSet;
            }
            if (fieldName == "organisationDomain"_L1) {
                return organisationDomainSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    UpdateGlobalComponentDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_applicationName(QString())
        , m_applicationCppDomainName(QString())
        , m_organisationName(QString())
        , m_organisationDomain(QString())
    {
    }

    ~UpdateGlobalComponentDTO()
    {
    }

    UpdateGlobalComponentDTO(int id,
                             const QUuid &uuid,
                             const QDateTime &creationDate,
                             const QDateTime &updateDate,
                             const QString &applicationName,
                             const QString &applicationCppDomainName,
                             const QString &organisationName,
                             const QString &organisationDomain)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_applicationName(applicationName)
        , m_applicationCppDomainName(applicationCppDomainName)
        , m_organisationName(organisationName)
        , m_organisationDomain(organisationDomain)
    {
    }

    UpdateGlobalComponentDTO(const UpdateGlobalComponentDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_applicationName(other.m_applicationName)
        , m_applicationCppDomainName(other.m_applicationCppDomainName)
        , m_organisationName(other.m_organisationName)
        , m_organisationDomain(other.m_organisationDomain)
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

    UpdateGlobalComponentDTO &operator=(const UpdateGlobalComponentDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_applicationName = other.m_applicationName;
            m_applicationCppDomainName = other.m_applicationCppDomainName;
            m_organisationName = other.m_organisationName;
            m_organisationDomain = other.m_organisationDomain;
        }
        return *this;
    }

    UpdateGlobalComponentDTO &operator=(const UpdateGlobalComponentDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_applicationName = other.m_applicationName;
            m_applicationCppDomainName = other.m_applicationCppDomainName;
            m_organisationName = other.m_organisationName;
            m_organisationDomain = other.m_organisationDomain;
        }
        return *this;
    }

    UpdateGlobalComponentDTO &mergeWith(const UpdateGlobalComponentDTO &other)
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
            if (other.m_metaData.applicationNameSet) {
                m_applicationName = other.m_applicationName;
                m_metaData.applicationNameSet = true;
            }
            if (other.m_metaData.applicationCppDomainNameSet) {
                m_applicationCppDomainName = other.m_applicationCppDomainName;
                m_metaData.applicationCppDomainNameSet = true;
            }
            if (other.m_metaData.organisationNameSet) {
                m_organisationName = other.m_organisationName;
                m_metaData.organisationNameSet = true;
            }
            if (other.m_metaData.organisationDomainSet) {
                m_organisationDomain = other.m_organisationDomain;
                m_metaData.organisationDomainSet = true;
            }
        }
        return *this;
    }

    // import operator
    UpdateGlobalComponentDTO &operator<<(const UpdateGlobalComponentDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const UpdateGlobalComponentDTO &lhs, const UpdateGlobalComponentDTO &rhs);

    friend uint qHash(const UpdateGlobalComponentDTO &dto, uint seed) noexcept;

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

    // ------ applicationName : -----

    QString applicationName() const
    {
        return m_applicationName;
    }

    void setApplicationName(const QString &applicationName)
    {
        m_applicationName = applicationName;
        m_metaData.applicationNameSet = true;
    }

    // ------ applicationCppDomainName : -----

    QString applicationCppDomainName() const
    {
        return m_applicationCppDomainName;
    }

    void setApplicationCppDomainName(const QString &applicationCppDomainName)
    {
        m_applicationCppDomainName = applicationCppDomainName;
        m_metaData.applicationCppDomainNameSet = true;
    }

    // ------ organisationName : -----

    QString organisationName() const
    {
        return m_organisationName;
    }

    void setOrganisationName(const QString &organisationName)
    {
        m_organisationName = organisationName;
        m_metaData.organisationNameSet = true;
    }

    // ------ organisationDomain : -----

    QString organisationDomain() const
    {
        return m_organisationDomain;
    }

    void setOrganisationDomain(const QString &organisationDomain)
    {
        m_organisationDomain = organisationDomain;
        m_metaData.organisationDomainSet = true;
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
    QString m_applicationName;
    QString m_applicationCppDomainName;
    QString m_organisationName;
    QString m_organisationDomain;
};

inline bool operator==(const UpdateGlobalComponentDTO &lhs, const UpdateGlobalComponentDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_applicationName == rhs.m_applicationName && lhs.m_applicationCppDomainName == rhs.m_applicationCppDomainName
        && lhs.m_organisationName == rhs.m_organisationName && lhs.m_organisationDomain == rhs.m_organisationDomain;
}

inline uint qHash(const UpdateGlobalComponentDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_applicationName, seed);
    hash ^= ::qHash(dto.m_applicationCppDomainName, seed);
    hash ^= ::qHash(dto.m_organisationName, seed);
    hash ^= ::qHash(dto.m_organisationDomain, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::GlobalComponent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::GlobalComponent::UpdateGlobalComponentDTO)