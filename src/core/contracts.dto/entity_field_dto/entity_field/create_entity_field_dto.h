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

class CreateEntityFieldDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString type READ type WRITE setType)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(bool ordered READ ordered WRITE setOrdered)
    Q_PROPERTY(bool strong READ strong WRITE setStrong)
    Q_PROPERTY(int entityId READ entityId WRITE setEntityId)
    Q_PROPERTY(int position READ position WRITE setPosition)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool typeSet = false;
        bool nameSet = false;
        bool orderedSet = false;
        bool strongSet = false;
        bool entityIdSet = false;
        bool positionSet = false;
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
            if (fieldName == "entityId"_L1) {
                return entityIdSet;
            }
            if (fieldName == "position"_L1) {
                return positionSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    CreateEntityFieldDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_type(QString())
        , m_name(QString())
        , m_ordered(false)
        , m_strong(false)
        , m_entityId(0)
        , m_position(0)
    {
    }

    ~CreateEntityFieldDTO()
    {
    }

    CreateEntityFieldDTO(const QUuid &uuid,
                         const QDateTime &creationDate,
                         const QDateTime &updateDate,
                         const QString &type,
                         const QString &name,
                         bool ordered,
                         bool strong,
                         int entityId,
                         int position)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_type(type)
        , m_name(name)
        , m_ordered(ordered)
        , m_strong(strong)
        , m_entityId(entityId)
        , m_position(position)
    {
    }

    CreateEntityFieldDTO(const CreateEntityFieldDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_type(other.m_type)
        , m_name(other.m_name)
        , m_ordered(other.m_ordered)
        , m_strong(other.m_strong)
        , m_entityId(other.m_entityId)
        , m_position(other.m_position)
    {
    }

    CreateEntityFieldDTO &operator=(const CreateEntityFieldDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_type = other.m_type;
            m_name = other.m_name;
            m_ordered = other.m_ordered;
            m_strong = other.m_strong;
            m_entityId = other.m_entityId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreateEntityFieldDTO &operator=(const CreateEntityFieldDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_type = other.m_type;
            m_name = other.m_name;
            m_ordered = other.m_ordered;
            m_strong = other.m_strong;
            m_entityId = other.m_entityId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreateEntityFieldDTO &mergeWith(const CreateEntityFieldDTO &other)
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
            if (other.m_metaData.entityIdSet) {
                m_entityId = other.m_entityId;
                m_metaData.entityIdSet = true;
            }
            if (other.m_metaData.positionSet) {
                m_position = other.m_position;
                m_metaData.positionSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateEntityFieldDTO &operator<<(const CreateEntityFieldDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateEntityFieldDTO &lhs, const CreateEntityFieldDTO &rhs);

    friend uint qHash(const CreateEntityFieldDTO &dto, uint seed) noexcept;

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

    // ------ entityId : -----

    int entityId() const
    {
        return m_entityId;
    }

    void setEntityId(int entityId)
    {
        m_entityId = entityId;
        m_metaData.entityIdSet = true;
    }

    // ------ position : -----

    int position() const
    {
        return m_position;
    }

    void setPosition(int position)
    {
        m_position = position;
        m_metaData.positionSet = true;
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
    QString m_type;
    QString m_name;
    bool m_ordered;
    bool m_strong;
    int m_entityId;
    int m_position;
};

inline bool operator==(const CreateEntityFieldDTO &lhs, const CreateEntityFieldDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_type == rhs.m_type
        && lhs.m_name == rhs.m_name && lhs.m_ordered == rhs.m_ordered && lhs.m_strong == rhs.m_strong && lhs.m_entityId == rhs.m_entityId
        && lhs.m_position == rhs.m_position;
}

inline uint qHash(const CreateEntityFieldDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_type, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_ordered, seed);
    hash ^= ::qHash(dto.m_strong, seed);
    hash ^= ::qHash(dto.m_entityId, seed);
    hash ^= ::qHash(dto.m_position, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::EntityField
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::EntityField::CreateEntityFieldDTO)