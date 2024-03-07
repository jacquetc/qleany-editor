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

class EntityComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString relativeFolderPath READ relativeFolderPath WRITE setRelativeFolderPath)

    Q_PROPERTY(QList<Entity> entities READ entities WRITE setEntities)

public:
    struct MetaData {
        MetaData(EntityComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(EntityComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->entitiesSet = other.entitiesSet;
            this->entitiesLoaded = other.entitiesLoaded;
        }

        bool entitiesSet = false;
        bool entitiesLoaded = false;

        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("relativeFolderPath")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("entities")) {
                return entitiesSet;
            }
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("relativeFolderPath")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("entities")) {
                return entitiesLoaded;
            }
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        EntityComponent *m_entity = nullptr;
    };

    EntityComponent()
        : CommonParent()
        , m_relativeFolderPath(QString())
        , m_metaData(this)
    {
    }

    ~EntityComponent()
    {
    }

    EntityComponent(const int &id,
                    const QUuid &uuid,
                    const QDateTime &creationDate,
                    const QDateTime &updateDate,
                    const QString &relativeFolderPath,
                    const QList<Entity> &entities)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_relativeFolderPath(relativeFolderPath)
        , m_entities(entities)
        , m_metaData(this)
    {
    }

    EntityComponent(const EntityComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_relativeFolderPath(other.m_relativeFolderPath)
        , m_entities(other.m_entities)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::EntityComponent;
    }

    EntityComponent &operator=(const EntityComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_relativeFolderPath = other.m_relativeFolderPath;
            m_entities = other.m_entities;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const EntityComponent &lhs, const EntityComponent &rhs);

    friend uint qHash(const EntityComponent &entity, uint seed) noexcept;

    // ------ relativeFolderPath : -----

    QString relativeFolderPath() const
    {
        return m_relativeFolderPath;
    }

    void setRelativeFolderPath(const QString &relativeFolderPath)
    {
        m_relativeFolderPath = relativeFolderPath;
    }

    // ------ entities : -----

    QList<Entity> entities()
    {
        if (!m_metaData.entitiesLoaded && m_entitiesLoader) {
            m_entities = m_entitiesLoader(this->id());
            m_metaData.entitiesLoaded = true;
        }
        return m_entities;
    }

    void setEntities(const QList<Entity> &entities)
    {
        m_entities = entities;

        m_metaData.entitiesSet = true;
    }

    using EntitiesLoader = std::function<QList<Entity>(int entityId)>;

    void setEntitiesLoader(const EntitiesLoader &loader)
    {
        m_entitiesLoader = loader;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_relativeFolderPath;
    QList<Entity> m_entities;
    EntitiesLoader m_entitiesLoader;
};

inline bool operator==(const EntityComponent &lhs, const EntityComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_relativeFolderPath == rhs.m_relativeFolderPath && lhs.m_entities == rhs.m_entities;
}

inline uint qHash(const EntityComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_relativeFolderPath, seed);
    hash ^= ::qHash(entity.m_entities, seed);

    return hash;
}

/// Schema for EntityComponent entity
inline Qleany::Entities::EntitySchema EntityComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::EntityComponent,
                                                                 QString::fromUtf8("EntityComponent"),

                                                                 // relationships:
                                                                 {{QleanyEditor::Entities::Entities::EntityEnum::EntityComponent,
                                                                   QString::fromUtf8("EntityComponent"),
                                                                   QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                                   QString::fromUtf8("Entity"),
                                                                   QString::fromUtf8("entities"),
                                                                   RelationshipType::OneToMany,
                                                                   RelationshipStrength::Strong,
                                                                   RelationshipCardinality::ManyOrdered,
                                                                   RelationshipDirection::Forward}},

                                                                 // fields:
                                                                 {{QString::fromUtf8("id"), FieldType::Integer, true, false},
                                                                  {QString::fromUtf8("uuid"), FieldType::Uuid, false, false},
                                                                  {QString::fromUtf8("creationDate"), FieldType::DateTime, false, false},
                                                                  {QString::fromUtf8("updateDate"), FieldType::DateTime, false, false},
                                                                  {QString::fromUtf8("relativeFolderPath"), FieldType::String, false, false},
                                                                  {QString::fromUtf8("entities"), FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::EntityComponent)