// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QDateTime>
#include <QUuid>

#include "entities.h"
#include <qleany/entities/entity_base.h>
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class CommonParent : public EntityBase
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)

    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)

    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)

public:
    struct MetaData {
        MetaData(CommonParent *entity)
            : m_entity(entity)
        {
        }
        MetaData(CommonParent *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "uuid"_L1) {
                return true;
            }
            if (fieldName == "creationDate"_L1) {
                return true;
            }
            if (fieldName == "updateDate"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->EntityBase::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "uuid"_L1) {
                return true;
            }
            if (fieldName == "creationDate"_L1) {
                return true;
            }
            if (fieldName == "updateDate"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->EntityBase::metaData().getLoaded(fieldName);
        }

    private:
        CommonParent *m_entity = nullptr;
    };

    CommonParent()
        : EntityBase()
        , m_metaData(this)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
    {
    }

    ~CommonParent()
    {
    }

    CommonParent(const int &id, const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate)
        : EntityBase(id)
        , m_metaData(this)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
    {
    }

    CommonParent(const CommonParent &other)
        : EntityBase(other)
        , m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::CommonParent;
    }

    CommonParent &operator=(const CommonParent &other)
    {
        if (this != &other) {
            EntityBase::operator=(other);
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const CommonParent &lhs, const CommonParent &rhs);

    friend uint qHash(const CommonParent &entity, uint seed) noexcept;

    // ------ uuid : -----

    QUuid uuid() const
    {
        return m_uuid;
    }

    void setUuid(const QUuid &uuid)
    {
        m_uuid = uuid;
    }

    // ------ creationDate : -----

    QDateTime creationDate() const
    {
        return m_creationDate;
    }

    void setCreationDate(const QDateTime &creationDate)
    {
        m_creationDate = creationDate;
    }

    // ------ updateDate : -----

    QDateTime updateDate() const
    {
        return m_updateDate;
    }

    void setUpdateDate(const QDateTime &updateDate)
    {
        m_updateDate = updateDate;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
};

inline bool operator==(const CommonParent &lhs, const CommonParent &rhs)
{
    return static_cast<const EntityBase &>(lhs) == static_cast<const EntityBase &>(rhs) &&

        lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate;
}

inline uint qHash(const CommonParent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const EntityBase &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_uuid, seed);
    hash ^= ::qHash(entity.m_creationDate, seed);
    hash ^= ::qHash(entity.m_updateDate, seed);

    return hash;
}

/// Schema for CommonParent entity
inline Qleany::Entities::EntitySchema CommonParent::schema = {QleanyEditor::Entities::Entities::EntityEnum::CommonParent,
                                                              "CommonParent"_L1,

                                                              // relationships:
                                                              {

                                                              },

                                                              // fields:
                                                              {{"id"_L1, FieldType::Integer, true, false},
                                                               {"uuid"_L1, FieldType::Uuid, false, false},
                                                               {"creationDate"_L1, FieldType::DateTime, false, false},
                                                               {"updateDate"_L1, FieldType::DateTime, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::CommonParent)