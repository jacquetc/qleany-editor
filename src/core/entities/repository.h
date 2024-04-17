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

class Repository : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString entityName READ entityName WRITE setEntityName)

    Q_PROPERTY(bool lazyLoaders READ lazyLoaders WRITE setLazyLoaders)

    Q_PROPERTY(Entity entity READ entity WRITE setEntity)

public:
    struct MetaData {
        MetaData(Repository *entity)
            : m_entity(entity)
        {
        }
        MetaData(Repository *entity, const MetaData &other)
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
            if (fieldName == "entityName"_L1) {
                return true;
            }
            if (fieldName == "lazyLoaders"_L1) {
                return true;
            }
            if (fieldName == "entity"_L1) {
                return entitySet;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "entityName"_L1) {
                return true;
            }
            if (fieldName == "lazyLoaders"_L1) {
                return true;
            }
            if (fieldName == "entity"_L1) {
                return entityLoaded;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        Repository *m_entity = nullptr;
    };

    Repository()
        : CommonParent()
        , m_metaData(this)
        , m_entityName(QString())
        , m_lazyLoaders(false)
    {
    }

    ~Repository()
    {
    }

    Repository(const int &id,
               const QUuid &uuid,
               const QDateTime &creationDate,
               const QDateTime &updateDate,
               const QString &entityName,
               bool lazyLoaders,
               const Entity &entity)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_entityName(entityName)
        , m_lazyLoaders(lazyLoaders)
        , m_entity(entity)
    {
    }

    Repository(const Repository &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_entityName(other.m_entityName)
        , m_lazyLoaders(other.m_lazyLoaders)
        , m_entity(other.m_entity)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::Repository;
    }

    Repository &operator=(const Repository &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_entityName = other.m_entityName;
            m_lazyLoaders = other.m_lazyLoaders;
            m_entity = other.m_entity;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const Repository &lhs, const Repository &rhs);

    friend uint qHash(const Repository &entity, uint seed) noexcept;

    // ------ entityName : -----

    QString entityName() const
    {
        return m_entityName;
    }

    void setEntityName(const QString &entityName)
    {
        m_entityName = entityName;
    }

    // ------ lazyLoaders : -----

    bool lazyLoaders() const
    {
        return m_lazyLoaders;
    }

    void setLazyLoaders(bool lazyLoaders)
    {
        m_lazyLoaders = lazyLoaders;
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

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_entityName;
    bool m_lazyLoaders;
    Entity m_entity;
    EntityLoader m_entityLoader;
};

inline bool operator==(const Repository &lhs, const Repository &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_entityName == rhs.m_entityName && lhs.m_lazyLoaders == rhs.m_lazyLoaders && lhs.m_entity == rhs.m_entity;
}

inline uint qHash(const Repository &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_entityName, seed);
    hash ^= ::qHash(entity.m_lazyLoaders, seed);
    hash ^= ::qHash(entity.m_entity, seed);

    return hash;
}

/// Schema for Repository entity
inline Qleany::Entities::EntitySchema Repository::schema = {QleanyEditor::Entities::Entities::EntityEnum::Repository,
                                                            "Repository"_L1,

                                                            // relationships:
                                                            {{QleanyEditor::Entities::Entities::EntityEnum::RepositoryComponent,
                                                              "RepositoryComponent"_L1,
                                                              QleanyEditor::Entities::Entities::EntityEnum::Repository,
                                                              "Repository"_L1,
                                                              "repositories"_L1,
                                                              RelationshipType::OneToMany,
                                                              RelationshipStrength::Strong,
                                                              RelationshipCardinality::ManyOrdered,
                                                              RelationshipDirection::Backward},
                                                             {QleanyEditor::Entities::Entities::EntityEnum::Repository,
                                                              "Repository"_L1,
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
                                                             {"entityName"_L1, FieldType::String, false, false},
                                                             {"lazyLoaders"_L1, FieldType::Bool, false, false},
                                                             {"entity"_L1, FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::Repository)