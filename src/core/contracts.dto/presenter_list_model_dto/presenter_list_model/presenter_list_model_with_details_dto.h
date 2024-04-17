// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/entity_dto.h"
#include "entity_field/entity_field_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::DTO::EntityField;
using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::DTO::EntityField;

namespace QleanyEditor::Contracts::DTO::PresenterListModel
{
using namespace Qt::Literals::StringLiterals;

class PresenterListModelWithDetailsDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(EntityDTO entity READ entity WRITE setEntity)
    Q_PROPERTY(EntityFieldDTO displayedField READ displayedField WRITE setDisplayedField)
    Q_PROPERTY(EntityDTO inRelationOf READ inRelationOf WRITE setInRelationOf)
    Q_PROPERTY(EntityFieldDTO relationFieldName READ relationFieldName WRITE setRelationFieldName)
    Q_PROPERTY(bool readOnly READ readOnly WRITE setReadOnly)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool nameSet = false;
        bool entitySet = false;
        bool displayedFieldSet = false;
        bool inRelationOfSet = false;
        bool relationFieldNameSet = false;
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
            if (fieldName == "entity"_L1) {
                return entitySet;
            }
            if (fieldName == "displayedField"_L1) {
                return displayedFieldSet;
            }
            if (fieldName == "inRelationOf"_L1) {
                return inRelationOfSet;
            }
            if (fieldName == "relationFieldName"_L1) {
                return relationFieldNameSet;
            }
            if (fieldName == "readOnly"_L1) {
                return readOnlySet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (entitySet)
                return true;

            if (displayedFieldSet)
                return true;

            if (inRelationOfSet)
                return true;

            if (relationFieldNameSet)
                return true;

            return false;
        }
    };

    PresenterListModelWithDetailsDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_name(QString())
        , m_readOnly(false)
    {
    }

    ~PresenterListModelWithDetailsDTO()
    {
    }

    PresenterListModelWithDetailsDTO(int id,
                                     const QUuid &uuid,
                                     const QDateTime &creationDate,
                                     const QDateTime &updateDate,
                                     const QString &name,
                                     const EntityDTO &entity,
                                     const EntityFieldDTO &displayedField,
                                     const EntityDTO &inRelationOf,
                                     const EntityFieldDTO &relationFieldName,
                                     bool readOnly)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_name(name)
        , m_entity(entity)
        , m_displayedField(displayedField)
        , m_inRelationOf(inRelationOf)
        , m_relationFieldName(relationFieldName)
        , m_readOnly(readOnly)
    {
    }

    PresenterListModelWithDetailsDTO(const PresenterListModelWithDetailsDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_name(other.m_name)
        , m_entity(other.m_entity)
        , m_displayedField(other.m_displayedField)
        , m_inRelationOf(other.m_inRelationOf)
        , m_relationFieldName(other.m_relationFieldName)
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

    PresenterListModelWithDetailsDTO &operator=(const PresenterListModelWithDetailsDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_entity = other.m_entity;
            m_displayedField = other.m_displayedField;
            m_inRelationOf = other.m_inRelationOf;
            m_relationFieldName = other.m_relationFieldName;
            m_readOnly = other.m_readOnly;
        }
        return *this;
    }

    PresenterListModelWithDetailsDTO &operator=(const PresenterListModelWithDetailsDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_entity = other.m_entity;
            m_displayedField = other.m_displayedField;
            m_inRelationOf = other.m_inRelationOf;
            m_relationFieldName = other.m_relationFieldName;
            m_readOnly = other.m_readOnly;
        }
        return *this;
    }

    PresenterListModelWithDetailsDTO &mergeWith(const PresenterListModelWithDetailsDTO &other)
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
            if (other.m_metaData.entitySet) {
                m_entity = other.m_entity;
                m_metaData.entitySet = true;
            }
            if (other.m_metaData.displayedFieldSet) {
                m_displayedField = other.m_displayedField;
                m_metaData.displayedFieldSet = true;
            }
            if (other.m_metaData.inRelationOfSet) {
                m_inRelationOf = other.m_inRelationOf;
                m_metaData.inRelationOfSet = true;
            }
            if (other.m_metaData.relationFieldNameSet) {
                m_relationFieldName = other.m_relationFieldName;
                m_metaData.relationFieldNameSet = true;
            }
            if (other.m_metaData.readOnlySet) {
                m_readOnly = other.m_readOnly;
                m_metaData.readOnlySet = true;
            }
        }
        return *this;
    }

    // import operator
    PresenterListModelWithDetailsDTO &operator<<(const PresenterListModelWithDetailsDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const PresenterListModelWithDetailsDTO &lhs, const PresenterListModelWithDetailsDTO &rhs);

    friend uint qHash(const PresenterListModelWithDetailsDTO &dto, uint seed) noexcept;

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

    // ------ displayedField : -----

    EntityFieldDTO displayedField() const
    {
        return m_displayedField;
    }

    void setDisplayedField(const EntityFieldDTO &displayedField)
    {
        m_displayedField = displayedField;
        m_metaData.displayedFieldSet = true;
    }

    // ------ inRelationOf : -----

    EntityDTO inRelationOf() const
    {
        return m_inRelationOf;
    }

    void setInRelationOf(const EntityDTO &inRelationOf)
    {
        m_inRelationOf = inRelationOf;
        m_metaData.inRelationOfSet = true;
    }

    // ------ relationFieldName : -----

    EntityFieldDTO relationFieldName() const
    {
        return m_relationFieldName;
    }

    void setRelationFieldName(const EntityFieldDTO &relationFieldName)
    {
        m_relationFieldName = relationFieldName;
        m_metaData.relationFieldNameSet = true;
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
    EntityDTO m_entity;
    EntityFieldDTO m_displayedField;
    EntityDTO m_inRelationOf;
    EntityFieldDTO m_relationFieldName;
    bool m_readOnly;
};

inline bool operator==(const PresenterListModelWithDetailsDTO &lhs, const PresenterListModelWithDetailsDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_name == rhs.m_name && lhs.m_entity == rhs.m_entity && lhs.m_displayedField == rhs.m_displayedField && lhs.m_inRelationOf == rhs.m_inRelationOf
        && lhs.m_relationFieldName == rhs.m_relationFieldName && lhs.m_readOnly == rhs.m_readOnly;
}

inline uint qHash(const PresenterListModelWithDetailsDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_entity, seed);
    hash ^= ::qHash(dto.m_displayedField, seed);
    hash ^= ::qHash(dto.m_inRelationOf, seed);
    hash ^= ::qHash(dto.m_relationFieldName, seed);
    hash ^= ::qHash(dto.m_readOnly, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::PresenterListModel
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::PresenterListModel::PresenterListModelWithDetailsDTO)