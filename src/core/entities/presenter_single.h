// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class PresenterSingle : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString name READ name WRITE setName)

    Q_PROPERTY(Entity entity READ entity WRITE setEntity)

    Q_PROPERTY(bool readOnly READ readOnly WRITE setReadOnly)

public:
    struct MetaData {
        MetaData(PresenterSingle *entity)
            : m_entity(entity)
        {
        }
        MetaData(PresenterSingle *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->entitySet = other.entitySet;
            this->entityLoaded = other.entityLoaded;
        }

        bool entitySet = false;
        bool entityLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "name"_L1) {
                return true;
            }
            if (fieldName == "entity"_L1) {
                return entitySet;
            }
            if (fieldName == "readOnly"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "name"_L1) {
                return true;
            }
            if (fieldName == "entity"_L1) {
                return entityLoaded;
            }
            if (fieldName == "readOnly"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        PresenterSingle *m_entity = nullptr;
    };

    PresenterSingle()
        : CommonParent()
        , m_metaData(this)
        , m_name(QString())
        , m_readOnly(false)
    {
    }

    ~PresenterSingle()
    {
    }

    PresenterSingle(const int &id,
                    const QUuid &uuid,
                    const QDateTime &creationDate,
                    const QDateTime &updateDate,
                    const QString &name,
                    const Entity &entity,
                    bool readOnly)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_name(name)
        , m_entity(entity)
        , m_readOnly(readOnly)
    {
    }

    PresenterSingle(const PresenterSingle &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_name(other.m_name)
        , m_entity(other.m_entity)
        , m_readOnly(other.m_readOnly)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::PresenterSingle;
    }

    PresenterSingle &operator=(const PresenterSingle &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_name = other.m_name;
            m_entity = other.m_entity;
            m_readOnly = other.m_readOnly;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const PresenterSingle &lhs, const PresenterSingle &rhs);

    friend uint qHash(const PresenterSingle &entity, uint seed) noexcept;

    // ------ name : -----

    QString name() const
    {
        return m_name;
    }

    void setName(const QString &name)
    {
        m_name = name;
    }

    // ------ entity : -----

    Entity entity()
    {
        if (!m_metaData.entityLoaded && m_entityLoader) {
            m_entity = m_entityLoader(this->id());
            m_metaData.entityLoaded = true;
        }
        return m_entity;
    }

    void setEntity(const Entity &entity)
    {
        m_entity = entity;

        m_metaData.entitySet = true;
    }

    using EntityLoader = std::function<Entity(int entityId)>;

    void setEntityLoader(const EntityLoader &loader)
    {
        m_entityLoader = loader;
    }

    // ------ readOnly : -----

    bool readOnly() const
    {
        return m_readOnly;
    }

    void setReadOnly(bool readOnly)
    {
        m_readOnly = readOnly;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_name;
    Entity m_entity;
    EntityLoader m_entityLoader;
    bool m_readOnly;
};

inline bool operator==(const PresenterSingle &lhs, const PresenterSingle &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_name == rhs.m_name && lhs.m_entity == rhs.m_entity && lhs.m_readOnly == rhs.m_readOnly;
}

inline uint qHash(const PresenterSingle &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_name, seed);
    hash ^= ::qHash(entity.m_entity, seed);
    hash ^= ::qHash(entity.m_readOnly, seed);

    return hash;
}

/// Schema for PresenterSingle entity
inline Qleany::Entities::EntitySchema PresenterSingle::schema = {QleanyEditor::Entities::Entities::EntityEnum::PresenterSingle,
                                                                 "PresenterSingle"_L1,

                                                                 // relationships:
                                                                 {{QleanyEditor::Entities::Entities::EntityEnum::PresenterComponent,
                                                                   "PresenterComponent"_L1,
                                                                   QleanyEditor::Entities::Entities::EntityEnum::PresenterSingle,
                                                                   "PresenterSingle"_L1,
                                                                   "singles"_L1,
                                                                   RelationshipType::OneToMany,
                                                                   RelationshipStrength::Strong,
                                                                   RelationshipCardinality::ManyOrdered,
                                                                   RelationshipDirection::Backward},
                                                                  {QleanyEditor::Entities::Entities::EntityEnum::PresenterSingle,
                                                                   "PresenterSingle"_L1,
                                                                   QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                                   "Entity"_L1,
                                                                   "entity"_L1,
                                                                   RelationshipType::OneToOne,
                                                                   RelationshipStrength::Strong,
                                                                   RelationshipCardinality::One,
                                                                   RelationshipDirection::Forward}},

                                                                 // fields:
                                                                 {{"id"_L1, FieldType::Integer, true, false},
                                                                  {"uuid"_L1, FieldType::Uuid, false, false},
                                                                  {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                  {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                  {"name"_L1, FieldType::String, false, false},
                                                                  {"entity"_L1, FieldType::Entity, false, true},
                                                                  {"readOnly"_L1, FieldType::Bool, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::PresenterSingle)