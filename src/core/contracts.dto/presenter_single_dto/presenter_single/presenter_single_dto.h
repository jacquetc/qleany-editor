// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

namespace QleanyEditor::Contracts::DTO::PresenterSingle
{
using namespace Qt::Literals::StringLiterals;

class PresenterSingleDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(bool readOnly READ readOnly WRITE setReadOnly)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool nameSet = false;
        bool readOnlySet = false;
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
            if (fieldName == "name"_L1) {
                return nameSet;
            }
            if (fieldName == "readOnly"_L1) {
                return readOnlySet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    PresenterSingleDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_name(QString())
        , m_readOnly(false)
    {
    }

    ~PresenterSingleDTO()
    {
    }

    PresenterSingleDTO(int id, const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate, const QString &name, bool readOnly)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_name(name)
        , m_readOnly(readOnly)
    {
    }

    PresenterSingleDTO(const PresenterSingleDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_name(other.m_name)
        , m_readOnly(other.m_readOnly)
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

    PresenterSingleDTO &operator=(const PresenterSingleDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_readOnly = other.m_readOnly;
        }
        return *this;
    }

    PresenterSingleDTO &operator=(const PresenterSingleDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_readOnly = other.m_readOnly;
        }
        return *this;
    }

    PresenterSingleDTO &mergeWith(const PresenterSingleDTO &other)
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
            if (other.m_metaData.nameSet) {
                m_name = other.m_name;
                m_metaData.nameSet = true;
            }
            if (other.m_metaData.readOnlySet) {
                m_readOnly = other.m_readOnly;
                m_metaData.readOnlySet = true;
            }
        }
        return *this;
    }

    // import operator
    PresenterSingleDTO &operator<<(const PresenterSingleDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const PresenterSingleDTO &lhs, const PresenterSingleDTO &rhs);

    friend uint qHash(const PresenterSingleDTO &dto, uint seed) noexcept;

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

    // ------ name : -----

    QString name() const
    {
        return m_name;
    }

    void setName(const QString &name)
    {
        m_name = name;
        m_metaData.nameSet = true;
    }

    // ------ readOnly : -----

    bool readOnly() const
    {
        return m_readOnly;
    }

    void setReadOnly(bool readOnly)
    {
        m_readOnly = readOnly;
        m_metaData.readOnlySet = true;
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
    QString m_name;
    bool m_readOnly;
};

inline bool operator==(const PresenterSingleDTO &lhs, const PresenterSingleDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_name == rhs.m_name && lhs.m_readOnly == rhs.m_readOnly;
}

inline uint qHash(const PresenterSingleDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_readOnly, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::PresenterSingle
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::PresenterSingle::PresenterSingleDTO)