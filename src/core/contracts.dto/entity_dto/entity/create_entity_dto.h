// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field/entity_field_dto.h"
#include "entity_parent/entity_parent_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::EntityParent;
using namespace QleanyEditor::Contracts::DTO::EntityField;

namespace QleanyEditor::Contracts::DTO::Entity
{
using namespace Qt::Literals::StringLiterals;

class CreateEntityDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(EntityParentDTO parent READ parent WRITE setParent)
    Q_PROPERTY(QList<EntityFieldDTO> fields READ fields WRITE setFields)
    Q_PROPERTY(bool onlyForHeritage READ onlyForHeritage WRITE setOnlyForHeritage)
    Q_PROPERTY(int entityComponentId READ entityComponentId WRITE setEntityComponentId)
    Q_PROPERTY(int position READ position WRITE setPosition)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool nameSet = false;
        bool parentSet = false;
        bool fieldsSet = false;
        bool onlyForHeritageSet = false;
        bool entityComponentIdSet = false;
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
            if (fieldName == "name"_L1) {
                return nameSet;
            }
            if (fieldName == "parent"_L1) {
                return parentSet;
            }
            if (fieldName == "fields"_L1) {
                return fieldsSet;
            }
            if (fieldName == "onlyForHeritage"_L1) {
                return onlyForHeritageSet;
            }
            if (fieldName == "entityComponentId"_L1) {
                return entityComponentIdSet;
            }
            if (fieldName == "position"_L1) {
                return positionSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (parentSet)
                return true;

            if (fieldsSet)
                return true;

            return false;
        }
    };

    CreateEntityDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_name(QString())
        , m_onlyForHeritage(false)
        , m_entityComponentId(0)
        , m_position(0)
    {
    }

    ~CreateEntityDTO()
    {
    }

    CreateEntityDTO(const QUuid &uuid,
                    const QDateTime &creationDate,
                    const QDateTime &updateDate,
                    const QString &name,
                    const EntityParentDTO &parent,
                    const QList<EntityFieldDTO> &fields,
                    bool onlyForHeritage,
                    int entityComponentId,
                    int position)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_name(name)
        , m_parent(parent)
        , m_fields(fields)
        , m_onlyForHeritage(onlyForHeritage)
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
        , m_parent(other.m_parent)
        , m_fields(other.m_fields)
        , m_onlyForHeritage(other.m_onlyForHeritage)
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
            m_parent = other.m_parent;
            m_fields = other.m_fields;
            m_onlyForHeritage = other.m_onlyForHeritage;
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
            m_parent = other.m_parent;
            m_fields = other.m_fields;
            m_onlyForHeritage = other.m_onlyForHeritage;
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
            if (other.m_metaData.parentSet) {
                m_parent = other.m_parent;
                m_metaData.parentSet = true;
            }
            if (other.m_metaData.fieldsSet) {
                m_fields = other.m_fields;
                m_metaData.fieldsSet = true;
            }
            if (other.m_metaData.onlyForHeritageSet) {
                m_onlyForHeritage = other.m_onlyForHeritage;
                m_metaData.onlyForHeritageSet = true;
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

    // ------ parent : -----

    EntityParentDTO parent() const
    {
        return m_parent;
    }

    void setParent(const EntityParentDTO &parent)
    {
        m_parent = parent;
        m_metaData.parentSet = true;
    }

    // ------ fields : -----

    QList<EntityFieldDTO> fields() const
    {
        return m_fields;
    }

    void setFields(const QList<EntityFieldDTO> &fields)
    {
        m_fields = fields;
        m_metaData.fieldsSet = true;
    }

    // ------ onlyForHeritage : -----

    bool onlyForHeritage() const
    {
        return m_onlyForHeritage;
    }

    void setOnlyForHeritage(bool onlyForHeritage)
    {
        m_onlyForHeritage = onlyForHeritage;
        m_metaData.onlyForHeritageSet = true;
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
    EntityParentDTO m_parent;
    QList<EntityFieldDTO> m_fields;
    bool m_onlyForHeritage;
    int m_entityComponentId;
    int m_position;
};

inline bool operator==(const CreateEntityDTO &lhs, const CreateEntityDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_name == rhs.m_name
        && lhs.m_parent == rhs.m_parent && lhs.m_fields == rhs.m_fields && lhs.m_onlyForHeritage == rhs.m_onlyForHeritage
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
    hash ^= ::qHash(dto.m_parent, seed);
    hash ^= ::qHash(dto.m_fields, seed);
    hash ^= ::qHash(dto.m_onlyForHeritage, seed);
    hash ^= ::qHash(dto.m_entityComponentId, seed);
    hash ^= ::qHash(dto.m_position, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Entity
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Entity::CreateEntityDTO)