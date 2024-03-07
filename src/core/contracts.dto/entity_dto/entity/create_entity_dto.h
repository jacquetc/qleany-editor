// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

namespace QleanyEditor::Contracts::DTO::Entity
{

class CreateEntityDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(int entityComponentId READ entityComponentId WRITE setEntityComponentId)
    Q_PROPERTY(int position READ position WRITE setPosition)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool nameSet = false;
        bool entityComponentIdSet = false;
        bool positionSet = false;
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("uuid")) {
                return uuidSet;
            }
            if (fieldName == QString::fromUtf8("creationDate")) {
                return creationDateSet;
            }
            if (fieldName == QString::fromUtf8("updateDate")) {
                return updateDateSet;
            }
            if (fieldName == QString::fromUtf8("name")) {
                return nameSet;
            }
            if (fieldName == QString::fromUtf8("entityComponentId")) {
                return entityComponentIdSet;
            }
            if (fieldName == QString::fromUtf8("position")) {
                return positionSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    CreateEntityDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_name(QString())
        , m_entityComponentId(0)
        , m_position(0)
    {
    }

    ~CreateEntityDTO()
    {
    }

    CreateEntityDTO(const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate, const QString &name, int entityComponentId, int position)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_name(name)
        , m_entityComponentId(entityComponentId)
        , m_position(position)
    {
    }

    CreateEntityDTO(const CreateEntityDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_name(other.m_name)
        , m_entityComponentId(other.m_entityComponentId)
        , m_position(other.m_position)
    {
    }

    CreateEntityDTO &operator=(const CreateEntityDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_entityComponentId = other.m_entityComponentId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreateEntityDTO &operator=(const CreateEntityDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_entityComponentId = other.m_entityComponentId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreateEntityDTO &mergeWith(const CreateEntityDTO &other)
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
            if (other.m_metaData.nameSet) {
                m_name = other.m_name;
                m_metaData.nameSet = true;
            }
            if (other.m_metaData.entityComponentIdSet) {
                m_entityComponentId = other.m_entityComponentId;
                m_metaData.entityComponentIdSet = true;
            }
            if (other.m_metaData.positionSet) {
                m_position = other.m_position;
                m_metaData.positionSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateEntityDTO &operator<<(const CreateEntityDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateEntityDTO &lhs, const CreateEntityDTO &rhs);

    friend uint qHash(const CreateEntityDTO &dto, uint seed) noexcept;

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

    // ------ entityComponentId : -----

    int entityComponentId() const
    {
        return m_entityComponentId;
    }

    void setEntityComponentId(int entityComponentId)
    {
        m_entityComponentId = entityComponentId;
        m_metaData.entityComponentIdSet = true;
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
    QString m_name;
    int m_entityComponentId;
    int m_position;
};

inline bool operator==(const CreateEntityDTO &lhs, const CreateEntityDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_name == rhs.m_name
        && lhs.m_entityComponentId == rhs.m_entityComponentId && lhs.m_position == rhs.m_position;
}

inline uint qHash(const CreateEntityDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_entityComponentId, seed);
    hash ^= ::qHash(dto.m_position, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Entity
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Entity::CreateEntityDTO)