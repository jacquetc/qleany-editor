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

class UpdateEntityDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(EntityParentDTO parent READ parent WRITE setParent)
    Q_PROPERTY(QList<EntityFieldDTO> fields READ fields WRITE setFields)
    Q_PROPERTY(bool onlyForHeritage READ onlyForHeritage WRITE setOnlyForHeritage)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool nameSet = false;
        bool parentSet = false;
        bool fieldsSet = false;
        bool onlyForHeritageSet = false;
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
            if (fieldName == "parent"_L1) {
                return parentSet;
            }
            if (fieldName == "fields"_L1) {
                return fieldsSet;
            }
            if (fieldName == "onlyForHeritage"_L1) {
                return onlyForHeritageSet;
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

    UpdateEntityDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_name(QString())
        , m_onlyForHeritage(false)
    {
    }

    ~UpdateEntityDTO()
    {
    }

    UpdateEntityDTO(int id,
                    const QUuid &uuid,
                    const QDateTime &creationDate,
                    const QDateTime &updateDate,
                    const QString &name,
                    const EntityParentDTO &parent,
                    const QList<EntityFieldDTO> &fields,
                    bool onlyForHeritage)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_name(name)
        , m_parent(parent)
        , m_fields(fields)
        , m_onlyForHeritage(onlyForHeritage)
    {
    }

    UpdateEntityDTO(const UpdateEntityDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_name(other.m_name)
        , m_parent(other.m_parent)
        , m_fields(other.m_fields)
        , m_onlyForHeritage(other.m_onlyForHeritage)
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

    UpdateEntityDTO &operator=(const UpdateEntityDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_parent = other.m_parent;
            m_fields = other.m_fields;
            m_onlyForHeritage = other.m_onlyForHeritage;
        }
        return *this;
    }

    UpdateEntityDTO &operator=(const UpdateEntityDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_parent = other.m_parent;
            m_fields = other.m_fields;
            m_onlyForHeritage = other.m_onlyForHeritage;
        }
        return *this;
    }

    UpdateEntityDTO &mergeWith(const UpdateEntityDTO &other)
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
        }
        return *this;
    }

    // import operator
    UpdateEntityDTO &operator<<(const UpdateEntityDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const UpdateEntityDTO &lhs, const UpdateEntityDTO &rhs);

    friend uint qHash(const UpdateEntityDTO &dto, uint seed) noexcept;

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
    EntityParentDTO m_parent;
    QList<EntityFieldDTO> m_fields;
    bool m_onlyForHeritage;
};

inline bool operator==(const UpdateEntityDTO &lhs, const UpdateEntityDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_name == rhs.m_name && lhs.m_parent == rhs.m_parent && lhs.m_fields == rhs.m_fields && lhs.m_onlyForHeritage == rhs.m_onlyForHeritage;
}

inline uint qHash(const UpdateEntityDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_parent, seed);
    hash ^= ::qHash(dto.m_fields, seed);
    hash ^= ::qHash(dto.m_onlyForHeritage, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Entity
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Entity::UpdateEntityDTO)