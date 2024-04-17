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

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "relativeFolderPath"_L1) {
                return true;
            }
            if (fieldName == "entities"_L1) {
                return entitiesSet;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "relativeFolderPath"_L1) {
                return true;
            }
            if (fieldName == "entities"_L1) {
                return entitiesLoaded;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        EntityComponent *m_entity = nullptr;
    };

    EntityComponent()
        : CommonParent()
        , m_metaData(this)
        , m_relativeFolderPath(QString())
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
        , m_metaData(this)
        , m_relativeFolderPath(relativeFolderPath)
        , m_entities(entities)
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
                                                                 "EntityComponent"_L1,

                                                                 // relationships:
                                                                 {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                   "Project"_L1,
                                                                   QleanyEditor::Entities::Entities::EntityEnum::EntityComponent,
                                                                   "EntityComponent"_L1,
                                                                   "entityComponent"_L1,
                                                                   RelationshipType::OneToOne,
                                                                   RelationshipStrength::Strong,
                                                                   RelationshipCardinality::One,
                                                                   RelationshipDirection::Backward},
                                                                  {QleanyEditor::Entities::Entities::EntityEnum::EntityComponent,
                                                                   "EntityComponent"_L1,
                                                                   QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                                   "Entity"_L1,
                                                                   "entities"_L1,
                                                                   RelationshipType::OneToMany,
                                                                   RelationshipStrength::Strong,
                                                                   RelationshipCardinality::ManyOrdered,
                                                                   RelationshipDirection::Forward}},

                                                                 // fields:
                                                                 {{"id"_L1, FieldType::Integer, true, false},
                                                                  {"uuid"_L1, FieldType::Uuid, false, false},
                                                                  {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                  {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                  {"relativeFolderPath"_L1, FieldType::String, false, false},
                                                                  {"entities"_L1, FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::EntityComponent)