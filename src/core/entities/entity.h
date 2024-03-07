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

class Entity : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString name READ name WRITE setName)

public:
    struct MetaData {
        MetaData(Entity *entity)
            : m_entity(entity)
        {
        }
        MetaData(Entity *entity, const MetaData &other)
            : m_entity(entity)
        {
        }

        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("name")) {
                return true;
            }
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("name")) {
                return true;
            }
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        Entity *m_entity = nullptr;
    };

    Entity()
        : CommonParent()
        , m_name(QString())
        , m_metaData(this)
    {
    }

    ~Entity()
    {
    }

    Entity(const int &id, const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate, const QString &name)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_name(name)
        , m_metaData(this)
    {
    }

    Entity(const Entity &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_name(other.m_name)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::Entity;
    }

    Entity &operator=(const Entity &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_name = other.m_name;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const Entity &lhs, const Entity &rhs);

    friend uint qHash(const Entity &entity, uint seed) noexcept;

    // ------ name : -----

    QString name() const
    {
        return m_name;
    }

    void setName(const QString &name)
    {
        m_name = name;
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
};

inline bool operator==(const Entity &lhs, const Entity &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_name == rhs.m_name;
}

inline uint qHash(const Entity &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_name, seed);

    return hash;
}

/// Schema for Entity entity
inline Qleany::Entities::EntitySchema Entity::schema = {QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                        QString::fromUtf8("Entity"),

                                                        // relationships:
                                                        {{QleanyEditor::Entities::Entities::EntityEnum::EntityComponent,
                                                          QString::fromUtf8("EntityComponent"),
                                                          QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          QString::fromUtf8("Entity"),
                                                          QString::fromUtf8("entities"),
                                                          RelationshipType::OneToMany,
                                                          RelationshipStrength::Strong,
                                                          RelationshipCardinality::ManyOrdered,
                                                          RelationshipDirection::Backward}},

                                                        // fields:
                                                        {{QString::fromUtf8("id"), FieldType::Integer, true, false},
                                                         {QString::fromUtf8("uuid"), FieldType::Uuid, false, false},
                                                         {QString::fromUtf8("creationDate"), FieldType::DateTime, false, false},
                                                         {QString::fromUtf8("updateDate"), FieldType::DateTime, false, false},
                                                         {QString::fromUtf8("name"), FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::Entity)