// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

namespace QleanyEditor::Contracts::DTO::EntityField
{
using namespace Qt::Literals::StringLiterals;

class UpdateEntityFieldDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString type READ type WRITE setType)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(bool ordered READ ordered WRITE setOrdered)
    Q_PROPERTY(bool strong READ strong WRITE setStrong)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool typeSet = false;
        bool nameSet = false;
        bool orderedSet = false;
        bool strongSet = false;
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
            if (fieldName == "type"_L1) {
                return typeSet;
            }
            if (fieldName == "name"_L1) {
                return nameSet;
            }
            if (fieldName == "ordered"_L1) {
                return orderedSet;
            }
            if (fieldName == "strong"_L1) {
                return strongSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    UpdateEntityFieldDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_type(QString())
        , m_name(QString())
        , m_ordered(false)
        , m_strong(false)
    {
    }

    ~UpdateEntityFieldDTO()
    {
    }

    UpdateEntityFieldDTO(int id,
                         const QUuid &uuid,
                         const QDateTime &creationDate,
                         const QDateTime &updateDate,
                         const QString &type,
                         const QString &name,
                         bool ordered,
                         bool strong)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_type(type)
        , m_name(name)
        , m_ordered(ordered)
        , m_strong(strong)
    {
    }

    UpdateEntityFieldDTO(const UpdateEntityFieldDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_type(other.m_type)
        , m_name(other.m_name)
        , m_ordered(other.m_ordered)
        , m_strong(other.m_strong)
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

    UpdateEntityFieldDTO &operator=(const UpdateEntityFieldDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_type = other.m_type;
            m_name = other.m_name;
            m_ordered = other.m_ordered;
            m_strong = other.m_strong;
        }
        return *this;
    }

    UpdateEntityFieldDTO &operator=(const UpdateEntityFieldDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_type = other.m_type;
            m_name = other.m_name;
            m_ordered = other.m_ordered;
            m_strong = other.m_strong;
        }
        return *this;
    }

    UpdateEntityFieldDTO &mergeWith(const UpdateEntityFieldDTO &other)
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
            if (other.m_metaData.typeSet) {
                m_type = other.m_type;
                m_metaData.typeSet = true;
            }
            if (other.m_metaData.nameSet) {
                m_name = other.m_name;
                m_metaData.nameSet = true;
            }
            if (other.m_metaData.orderedSet) {
                m_ordered = other.m_ordered;
                m_metaData.orderedSet = true;
            }
            if (other.m_metaData.strongSet) {
                m_strong = other.m_strong;
                m_metaData.strongSet = true;
            }
        }
        return *this;
    }

    // import operator
    UpdateEntityFieldDTO &operator<<(const UpdateEntityFieldDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const UpdateEntityFieldDTO &lhs, const UpdateEntityFieldDTO &rhs);

    friend uint qHash(const UpdateEntityFieldDTO &dto, uint seed) noexcept;

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

    // ------ type : -----

    QString type() const
    {
        return m_type;
    }

    void setType(const QString &type)
    {
        m_type = type;
        m_metaData.typeSet = true;
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

    // ------ ordered : -----

    bool ordered() const
    {
        return m_ordered;
    }

    void setOrdered(bool ordered)
    {
        m_ordered = ordered;
        m_metaData.orderedSet = true;
    }

    // ------ strong : -----

    bool strong() const
    {
        return m_strong;
    }

    void setStrong(bool strong)
    {
        m_strong = strong;
        m_metaData.strongSet = true;
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
    QString m_type;
    QString m_name;
    bool m_ordered;
    bool m_strong;
};

inline bool operator==(const UpdateEntityFieldDTO &lhs, const UpdateEntityFieldDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_type == rhs.m_type && lhs.m_name == rhs.m_name && lhs.m_ordered == rhs.m_ordered && lhs.m_strong == rhs.m_strong;
}

inline uint qHash(const UpdateEntityFieldDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_type, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_ordered, seed);
    hash ^= ::qHash(dto.m_strong, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::EntityField
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::EntityField::UpdateEntityFieldDTO)