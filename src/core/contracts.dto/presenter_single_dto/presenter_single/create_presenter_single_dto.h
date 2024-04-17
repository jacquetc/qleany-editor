// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/entity_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::Entity;

namespace QleanyEditor::Contracts::DTO::PresenterSingle
{
using namespace Qt::Literals::StringLiterals;

class CreatePresenterSingleDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(EntityDTO entity READ entity WRITE setEntity)
    Q_PROPERTY(bool readOnly READ readOnly WRITE setReadOnly)
    Q_PROPERTY(int presenterComponentId READ presenterComponentId WRITE setPresenterComponentId)
    Q_PROPERTY(int position READ position WRITE setPosition)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool nameSet = false;
        bool entitySet = false;
        bool readOnlySet = false;
        bool presenterComponentIdSet = false;
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
            if (fieldName == "entity"_L1) {
                return entitySet;
            }
            if (fieldName == "readOnly"_L1) {
                return readOnlySet;
            }
            if (fieldName == "presenterComponentId"_L1) {
                return presenterComponentIdSet;
            }
            if (fieldName == "position"_L1) {
                return positionSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (entitySet)
                return true;

            return false;
        }
    };

    CreatePresenterSingleDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_name(QString())
        , m_readOnly(false)
        , m_presenterComponentId(0)
        , m_position(0)
    {
    }

    ~CreatePresenterSingleDTO()
    {
    }

    CreatePresenterSingleDTO(const QUuid &uuid,
                             const QDateTime &creationDate,
                             const QDateTime &updateDate,
                             const QString &name,
                             const EntityDTO &entity,
                             bool readOnly,
                             int presenterComponentId,
                             int position)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_name(name)
        , m_entity(entity)
        , m_readOnly(readOnly)
        , m_presenterComponentId(presenterComponentId)
        , m_position(position)
    {
    }

    CreatePresenterSingleDTO(const CreatePresenterSingleDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_name(other.m_name)
        , m_entity(other.m_entity)
        , m_readOnly(other.m_readOnly)
        , m_presenterComponentId(other.m_presenterComponentId)
        , m_position(other.m_position)
    {
    }

    CreatePresenterSingleDTO &operator=(const CreatePresenterSingleDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_entity = other.m_entity;
            m_readOnly = other.m_readOnly;
            m_presenterComponentId = other.m_presenterComponentId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreatePresenterSingleDTO &operator=(const CreatePresenterSingleDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_entity = other.m_entity;
            m_readOnly = other.m_readOnly;
            m_presenterComponentId = other.m_presenterComponentId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreatePresenterSingleDTO &mergeWith(const CreatePresenterSingleDTO &other)
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
            if (other.m_metaData.entitySet) {
                m_entity = other.m_entity;
                m_metaData.entitySet = true;
            }
            if (other.m_metaData.readOnlySet) {
                m_readOnly = other.m_readOnly;
                m_metaData.readOnlySet = true;
            }
            if (other.m_metaData.presenterComponentIdSet) {
                m_presenterComponentId = other.m_presenterComponentId;
                m_metaData.presenterComponentIdSet = true;
            }
            if (other.m_metaData.positionSet) {
                m_position = other.m_position;
                m_metaData.positionSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreatePresenterSingleDTO &operator<<(const CreatePresenterSingleDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreatePresenterSingleDTO &lhs, const CreatePresenterSingleDTO &rhs);

    friend uint qHash(const CreatePresenterSingleDTO &dto, uint seed) noexcept;

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

    // ------ entity : -----

    EntityDTO entity() const
    {
        return m_entity;
    }

    void setEntity(const EntityDTO &entity)
    {
        m_entity = entity;
        m_metaData.entitySet = true;
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

    // ------ presenterComponentId : -----

    int presenterComponentId() const
    {
        return m_presenterComponentId;
    }

    void setPresenterComponentId(int presenterComponentId)
    {
        m_presenterComponentId = presenterComponentId;
        m_metaData.presenterComponentIdSet = true;
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
    EntityDTO m_entity;
    bool m_readOnly;
    int m_presenterComponentId;
    int m_position;
};

inline bool operator==(const CreatePresenterSingleDTO &lhs, const CreatePresenterSingleDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_name == rhs.m_name
        && lhs.m_entity == rhs.m_entity && lhs.m_readOnly == rhs.m_readOnly && lhs.m_presenterComponentId == rhs.m_presenterComponentId
        && lhs.m_position == rhs.m_position;
}

inline uint qHash(const CreatePresenterSingleDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_entity, seed);
    hash ^= ::qHash(dto.m_readOnly, seed);
    hash ^= ::qHash(dto.m_presenterComponentId, seed);
    hash ^= ::qHash(dto.m_position, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::PresenterSingle
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::PresenterSingle::CreatePresenterSingleDTO)