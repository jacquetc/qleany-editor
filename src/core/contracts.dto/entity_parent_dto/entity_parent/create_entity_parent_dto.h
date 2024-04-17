// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QDateTime>
#include <QObject>
#include <QUuid>

namespace QleanyEditor::Contracts::DTO::EntityParent
{
using namespace Qt::Literals::StringLiterals;

class CreateEntityParentDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(int parent READ parent WRITE setParent)
    Q_PROPERTY(int entityId READ entityId WRITE setEntityId)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool parentSet = false;
        bool entityIdSet = false;
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
            if (fieldName == "parent"_L1) {
                return parentSet;
            }
            if (fieldName == "entityId"_L1) {
                return entityIdSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    CreateEntityParentDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_parent(0)
        , m_entityId(0)
    {
    }

    ~CreateEntityParentDTO()
    {
    }

    CreateEntityParentDTO(const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate, int parent, int entityId)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_parent(parent)
        , m_entityId(entityId)
    {
    }

    CreateEntityParentDTO(const CreateEntityParentDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_parent(other.m_parent)
        , m_entityId(other.m_entityId)
    {
    }

    CreateEntityParentDTO &operator=(const CreateEntityParentDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_parent = other.m_parent;
            m_entityId = other.m_entityId;
        }
        return *this;
    }

    CreateEntityParentDTO &operator=(const CreateEntityParentDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_parent = other.m_parent;
            m_entityId = other.m_entityId;
        }
        return *this;
    }

    CreateEntityParentDTO &mergeWith(const CreateEntityParentDTO &other)
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
            if (other.m_metaData.parentSet) {
                m_parent = other.m_parent;
                m_metaData.parentSet = true;
            }
            if (other.m_metaData.entityIdSet) {
                m_entityId = other.m_entityId;
                m_metaData.entityIdSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateEntityParentDTO &operator<<(const CreateEntityParentDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateEntityParentDTO &lhs, const CreateEntityParentDTO &rhs);

    friend uint qHash(const CreateEntityParentDTO &dto, uint seed) noexcept;

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

    // ------ parent : -----

    int parent() const
    {
        return m_parent;
    }

    void setParent(int parent)
    {
        m_parent = parent;
        m_metaData.parentSet = true;
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

    MetaData metaData() const
    {
        return m_metaData;
    }

private:
    MetaData m_metaData;

    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
    int m_parent;
    int m_entityId;
};

inline bool operator==(const CreateEntityParentDTO &lhs, const CreateEntityParentDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_parent == rhs.m_parent
        && lhs.m_entityId == rhs.m_entityId;
}

inline uint qHash(const CreateEntityParentDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_parent, seed);
    hash ^= ::qHash(dto.m_entityId, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::EntityParent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::EntityParent::CreateEntityParentDTO)