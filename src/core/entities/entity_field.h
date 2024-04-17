// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class EntityField : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString type READ type WRITE setType)

    Q_PROPERTY(QString name READ name WRITE setName)

    Q_PROPERTY(bool ordered READ ordered WRITE setOrdered)

    Q_PROPERTY(bool strong READ strong WRITE setStrong)

public:
    struct MetaData {
        MetaData(EntityField *entity)
            : m_entity(entity)
        {
        }
        MetaData(EntityField *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "type"_L1) {
                return true;
            }
            if (fieldName == "name"_L1) {
                return true;
            }
            if (fieldName == "ordered"_L1) {
                return true;
            }
            if (fieldName == "strong"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "type"_L1) {
                return true;
            }
            if (fieldName == "name"_L1) {
                return true;
            }
            if (fieldName == "ordered"_L1) {
                return true;
            }
            if (fieldName == "strong"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        EntityField *m_entity = nullptr;
    };

    EntityField()
        : CommonParent()
        , m_metaData(this)
        , m_type(QString())
        , m_name(QString())
        , m_ordered(false)
        , m_strong(false)
    {
    }

    ~EntityField()
    {
    }

    EntityField(const int &id,
                const QUuid &uuid,
                const QDateTime &creationDate,
                const QDateTime &updateDate,
                const QString &type,
                const QString &name,
                bool ordered,
                bool strong)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_type(type)
        , m_name(name)
        , m_ordered(ordered)
        , m_strong(strong)
    {
    }

    EntityField(const EntityField &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_type(other.m_type)
        , m_name(other.m_name)
        , m_ordered(other.m_ordered)
        , m_strong(other.m_strong)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::EntityField;
    }

    EntityField &operator=(const EntityField &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_type = other.m_type;
            m_name = other.m_name;
            m_ordered = other.m_ordered;
            m_strong = other.m_strong;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const EntityField &lhs, const EntityField &rhs);

    friend uint qHash(const EntityField &entity, uint seed) noexcept;

    // ------ type : -----

    QString type() const
    {
        return m_type;
    }

    void setType(const QString &type)
    {
        m_type = type;
    }

    // ------ name : -----

    QString name() const
    {
        return m_name;
    }

    void setName(const QString &name)
    {
        m_name = name;
    }

    // ------ ordered : -----

    bool ordered() const
    {
        return m_ordered;
    }

    void setOrdered(bool ordered)
    {
        m_ordered = ordered;
    }

    // ------ strong : -----

    bool strong() const
    {
        return m_strong;
    }

    void setStrong(bool strong)
    {
        m_strong = strong;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_type;
    QString m_name;
    bool m_ordered;
    bool m_strong;
};

inline bool operator==(const EntityField &lhs, const EntityField &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_type == rhs.m_type && lhs.m_name == rhs.m_name && lhs.m_ordered == rhs.m_ordered && lhs.m_strong == rhs.m_strong;
}

inline uint qHash(const EntityField &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_type, seed);
    hash ^= ::qHash(entity.m_name, seed);
    hash ^= ::qHash(entity.m_ordered, seed);
    hash ^= ::qHash(entity.m_strong, seed);

    return hash;
}

/// Schema for EntityField entity
inline Qleany::Entities::EntitySchema EntityField::schema = {QleanyEditor::Entities::Entities::EntityEnum::EntityField,
                                                             "EntityField"_L1,

                                                             // relationships:
                                                             {{QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                               "Entity"_L1,
                                                               QleanyEditor::Entities::Entities::EntityEnum::EntityField,
                                                               "EntityField"_L1,
                                                               "fields"_L1,
                                                               RelationshipType::OneToMany,
                                                               RelationshipStrength::Strong,
                                                               RelationshipCardinality::ManyOrdered,
                                                               RelationshipDirection::Backward},
                                                              {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                               "PresenterListModel"_L1,
                                                               QleanyEditor::Entities::Entities::EntityEnum::EntityField,
                                                               "EntityField"_L1,
                                                               "displayedField"_L1,
                                                               RelationshipType::OneToOne,
                                                               RelationshipStrength::Strong,
                                                               RelationshipCardinality::One,
                                                               RelationshipDirection::Backward},
                                                              {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                               "PresenterListModel"_L1,
                                                               QleanyEditor::Entities::Entities::EntityEnum::EntityField,
                                                               "EntityField"_L1,
                                                               "relationFieldName"_L1,
                                                               RelationshipType::OneToOne,
                                                               RelationshipStrength::Strong,
                                                               RelationshipCardinality::One,
                                                               RelationshipDirection::Backward}},

                                                             // fields:
                                                             {{"id"_L1, FieldType::Integer, true, false},
                                                              {"uuid"_L1, FieldType::Uuid, false, false},
                                                              {"creationDate"_L1, FieldType::DateTime, false, false},
                                                              {"updateDate"_L1, FieldType::DateTime, false, false},
                                                              {"type"_L1, FieldType::String, false, false},
                                                              {"name"_L1, FieldType::String, false, false},
                                                              {"ordered"_L1, FieldType::Bool, false, false},
                                                              {"strong"_L1, FieldType::Bool, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::EntityField)