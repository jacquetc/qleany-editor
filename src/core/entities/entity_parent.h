// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class EntityParent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(int parent READ parent WRITE setParent)

public:
    struct MetaData {
        MetaData(EntityParent *entity)
            : m_entity(entity)
        {
        }
        MetaData(EntityParent *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "parent"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "parent"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        EntityParent *m_entity = nullptr;
    };

    EntityParent()
        : CommonParent()
        , m_metaData(this)
        , m_parent(0)
    {
    }

    ~EntityParent()
    {
    }

    EntityParent(const int &id, const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate, int parent)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_parent(parent)
    {
    }

    EntityParent(const EntityParent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_parent(other.m_parent)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::EntityParent;
    }

    EntityParent &operator=(const EntityParent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_parent = other.m_parent;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const EntityParent &lhs, const EntityParent &rhs);

    friend uint qHash(const EntityParent &entity, uint seed) noexcept;

    // ------ parent : -----

    int parent() const
    {
        return m_parent;
    }

    void setParent(int parent)
    {
        m_parent = parent;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    int m_parent;
};

inline bool operator==(const EntityParent &lhs, const EntityParent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_parent == rhs.m_parent;
}

inline uint qHash(const EntityParent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_parent, seed);

    return hash;
}

/// Schema for EntityParent entity
inline Qleany::Entities::EntitySchema EntityParent::schema = {QleanyEditor::Entities::Entities::EntityEnum::EntityParent,
                                                              "EntityParent"_L1,

                                                              // relationships:
                                                              {{QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                                "Entity"_L1,
                                                                QleanyEditor::Entities::Entities::EntityEnum::EntityParent,
                                                                "EntityParent"_L1,
                                                                "parent"_L1,
                                                                RelationshipType::OneToOne,
                                                                RelationshipStrength::Strong,
                                                                RelationshipCardinality::One,
                                                                RelationshipDirection::Backward}},

                                                              // fields:
                                                              {{"id"_L1, FieldType::Integer, true, false},
                                                               {"uuid"_L1, FieldType::Uuid, false, false},
                                                               {"creationDate"_L1, FieldType::DateTime, false, false},
                                                               {"updateDate"_L1, FieldType::DateTime, false, false},
                                                               {"parent"_L1, FieldType::Integer, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::EntityParent)