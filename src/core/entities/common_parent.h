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
        }

        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("uuid")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("creationDate")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("updateDate")) {
                return true;
            }
            return m_entity->EntityBase::metaData().getSet(fieldName);
        }

        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("uuid")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("creationDate")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("updateDate")) {
                return true;
            }
            return m_entity->EntityBase::metaData().getLoaded(fieldName);
        }

    private:
        CommonParent *m_entity = nullptr;
    };

    CommonParent()
        : EntityBase()
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_metaData(this)
    {
    }

    ~CommonParent()
    {
    }

    CommonParent(const int &id, const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate)
        : EntityBase(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_metaData(this)
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
                                                              QString::fromUtf8("CommonParent"),

                                                              // relationships:
                                                              {

                                                              },

                                                              // fields:
                                                              {{QString::fromUtf8("id"), FieldType::Integer, true, false},
                                                               {QString::fromUtf8("uuid"), FieldType::Uuid, false, false},
                                                               {QString::fromUtf8("creationDate"), FieldType::DateTime, false, false},
                                                               {QString::fromUtf8("updateDate"), FieldType::DateTime, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::CommonParent)