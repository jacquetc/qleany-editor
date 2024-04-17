// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity.h"

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class CRUD : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled)

    Q_PROPERTY(Entity entityMappableWith READ entityMappableWith WRITE setEntityMappableWith)

    Q_PROPERTY(bool getEnabled READ getEnabled WRITE setGetEnabled)

    Q_PROPERTY(bool getAllEnabled READ getAllEnabled WRITE setGetAllEnabled)

    Q_PROPERTY(bool getWithDetailsEnabled READ getWithDetailsEnabled WRITE setGetWithDetailsEnabled)

    Q_PROPERTY(bool createEnabled READ createEnabled WRITE setCreateEnabled)

    Q_PROPERTY(bool updateEnabled READ updateEnabled WRITE setUpdateEnabled)

    Q_PROPERTY(bool removeEnabled READ removeEnabled WRITE setRemoveEnabled)

public:
    struct MetaData {
        MetaData(CRUD *entity)
            : m_entity(entity)
        {
        }
        MetaData(CRUD *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->entityMappableWithSet = other.entityMappableWithSet;
            this->entityMappableWithLoaded = other.entityMappableWithLoaded;
        }

        bool entityMappableWithSet = false;
        bool entityMappableWithLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "enabled"_L1) {
                return true;
            }
            if (fieldName == "entityMappableWith"_L1) {
                return entityMappableWithSet;
            }
            if (fieldName == "getEnabled"_L1) {
                return true;
            }
            if (fieldName == "getAllEnabled"_L1) {
                return true;
            }
            if (fieldName == "getWithDetailsEnabled"_L1) {
                return true;
            }
            if (fieldName == "createEnabled"_L1) {
                return true;
            }
            if (fieldName == "updateEnabled"_L1) {
                return true;
            }
            if (fieldName == "removeEnabled"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "enabled"_L1) {
                return true;
            }
            if (fieldName == "entityMappableWith"_L1) {
                return entityMappableWithLoaded;
            }
            if (fieldName == "getEnabled"_L1) {
                return true;
            }
            if (fieldName == "getAllEnabled"_L1) {
                return true;
            }
            if (fieldName == "getWithDetailsEnabled"_L1) {
                return true;
            }
            if (fieldName == "createEnabled"_L1) {
                return true;
            }
            if (fieldName == "updateEnabled"_L1) {
                return true;
            }
            if (fieldName == "removeEnabled"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        CRUD *m_entity = nullptr;
    };

    CRUD()
        : CommonParent()
        , m_metaData(this)
        , m_enabled(false)
        , m_getEnabled(false)
        , m_getAllEnabled(false)
        , m_getWithDetailsEnabled(false)
        , m_createEnabled(false)
        , m_updateEnabled(false)
        , m_removeEnabled(false)
    {
    }

    ~CRUD()
    {
    }

    CRUD(const int &id,
         const QUuid &uuid,
         const QDateTime &creationDate,
         const QDateTime &updateDate,
         bool enabled,
         const Entity &entityMappableWith,
         bool getEnabled,
         bool getAllEnabled,
         bool getWithDetailsEnabled,
         bool createEnabled,
         bool updateEnabled,
         bool removeEnabled)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_enabled(enabled)
        , m_entityMappableWith(entityMappableWith)
        , m_getEnabled(getEnabled)
        , m_getAllEnabled(getAllEnabled)
        , m_getWithDetailsEnabled(getWithDetailsEnabled)
        , m_createEnabled(createEnabled)
        , m_updateEnabled(updateEnabled)
        , m_removeEnabled(removeEnabled)
    {
    }

    CRUD(const CRUD &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_enabled(other.m_enabled)
        , m_entityMappableWith(other.m_entityMappableWith)
        , m_getEnabled(other.m_getEnabled)
        , m_getAllEnabled(other.m_getAllEnabled)
        , m_getWithDetailsEnabled(other.m_getWithDetailsEnabled)
        , m_createEnabled(other.m_createEnabled)
        , m_updateEnabled(other.m_updateEnabled)
        , m_removeEnabled(other.m_removeEnabled)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::CRUD;
    }

    CRUD &operator=(const CRUD &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_enabled = other.m_enabled;
            m_entityMappableWith = other.m_entityMappableWith;
            m_getEnabled = other.m_getEnabled;
            m_getAllEnabled = other.m_getAllEnabled;
            m_getWithDetailsEnabled = other.m_getWithDetailsEnabled;
            m_createEnabled = other.m_createEnabled;
            m_updateEnabled = other.m_updateEnabled;
            m_removeEnabled = other.m_removeEnabled;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const CRUD &lhs, const CRUD &rhs);

    friend uint qHash(const CRUD &entity, uint seed) noexcept;

    // ------ enabled : -----

    bool enabled() const
    {
        return m_enabled;
    }

    void setEnabled(bool enabled)
    {
        m_enabled = enabled;
    }

    // ------ entityMappableWith : -----

    Entity entityMappableWith()
    {
        if (!m_metaData.entityMappableWithLoaded && m_entityMappableWithLoader) {
            m_entityMappableWith = m_entityMappableWithLoader(this->id());
            m_metaData.entityMappableWithLoaded = true;
        }
        return m_entityMappableWith;
    }

    void setEntityMappableWith(const Entity &entityMappableWith)
    {
        m_entityMappableWith = entityMappableWith;

        m_metaData.entityMappableWithSet = true;
    }

    using EntityMappableWithLoader = std::function<Entity(int entityId)>;

    void setEntityMappableWithLoader(const EntityMappableWithLoader &loader)
    {
        m_entityMappableWithLoader = loader;
    }

    // ------ getEnabled : -----

    bool getEnabled() const
    {
        return m_getEnabled;
    }

    void setGetEnabled(bool getEnabled)
    {
        m_getEnabled = getEnabled;
    }

    // ------ getAllEnabled : -----

    bool getAllEnabled() const
    {
        return m_getAllEnabled;
    }

    void setGetAllEnabled(bool getAllEnabled)
    {
        m_getAllEnabled = getAllEnabled;
    }

    // ------ getWithDetailsEnabled : -----

    bool getWithDetailsEnabled() const
    {
        return m_getWithDetailsEnabled;
    }

    void setGetWithDetailsEnabled(bool getWithDetailsEnabled)
    {
        m_getWithDetailsEnabled = getWithDetailsEnabled;
    }

    // ------ createEnabled : -----

    bool createEnabled() const
    {
        return m_createEnabled;
    }

    void setCreateEnabled(bool createEnabled)
    {
        m_createEnabled = createEnabled;
    }

    // ------ updateEnabled : -----

    bool updateEnabled() const
    {
        return m_updateEnabled;
    }

    void setUpdateEnabled(bool updateEnabled)
    {
        m_updateEnabled = updateEnabled;
    }

    // ------ removeEnabled : -----

    bool removeEnabled() const
    {
        return m_removeEnabled;
    }

    void setRemoveEnabled(bool removeEnabled)
    {
        m_removeEnabled = removeEnabled;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    bool m_enabled;
    Entity m_entityMappableWith;
    EntityMappableWithLoader m_entityMappableWithLoader;
    bool m_getEnabled;
    bool m_getAllEnabled;
    bool m_getWithDetailsEnabled;
    bool m_createEnabled;
    bool m_updateEnabled;
    bool m_removeEnabled;
};

inline bool operator==(const CRUD &lhs, const CRUD &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_enabled == rhs.m_enabled && lhs.m_entityMappableWith == rhs.m_entityMappableWith && lhs.m_getEnabled == rhs.m_getEnabled
        && lhs.m_getAllEnabled == rhs.m_getAllEnabled && lhs.m_getWithDetailsEnabled == rhs.m_getWithDetailsEnabled
        && lhs.m_createEnabled == rhs.m_createEnabled && lhs.m_updateEnabled == rhs.m_updateEnabled && lhs.m_removeEnabled == rhs.m_removeEnabled;
}

inline uint qHash(const CRUD &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_enabled, seed);
    hash ^= ::qHash(entity.m_entityMappableWith, seed);
    hash ^= ::qHash(entity.m_getEnabled, seed);
    hash ^= ::qHash(entity.m_getAllEnabled, seed);
    hash ^= ::qHash(entity.m_getWithDetailsEnabled, seed);
    hash ^= ::qHash(entity.m_createEnabled, seed);
    hash ^= ::qHash(entity.m_updateEnabled, seed);
    hash ^= ::qHash(entity.m_removeEnabled, seed);

    return hash;
}

/// Schema for CRUD entity
inline Qleany::Entities::EntitySchema CRUD::schema = {QleanyEditor::Entities::Entities::EntityEnum::CRUD,
                                                      "CRUD"_L1,

                                                      // relationships:
                                                      {{QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                        "ApplicationFeature"_L1,
                                                        QleanyEditor::Entities::Entities::EntityEnum::CRUD,
                                                        "CRUD"_L1,
                                                        "crud"_L1,
                                                        RelationshipType::OneToOne,
                                                        RelationshipStrength::Strong,
                                                        RelationshipCardinality::One,
                                                        RelationshipDirection::Backward},
                                                       {QleanyEditor::Entities::Entities::EntityEnum::CRUD,
                                                        "CRUD"_L1,
                                                        QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                        "Entity"_L1,
                                                        "entityMappableWith"_L1,
                                                        RelationshipType::OneToOne,
                                                        RelationshipStrength::Strong,
                                                        RelationshipCardinality::One,
                                                        RelationshipDirection::Forward}},

                                                      // fields:
                                                      {{"id"_L1, FieldType::Integer, true, false},
                                                       {"uuid"_L1, FieldType::Uuid, false, false},
                                                       {"creationDate"_L1, FieldType::DateTime, false, false},
                                                       {"updateDate"_L1, FieldType::DateTime, false, false},
                                                       {"enabled"_L1, FieldType::Bool, false, false},
                                                       {"entityMappableWith"_L1, FieldType::Entity, false, true},
                                                       {"getEnabled"_L1, FieldType::Bool, false, false},
                                                       {"getAllEnabled"_L1, FieldType::Bool, false, false},
                                                       {"getWithDetailsEnabled"_L1, FieldType::Bool, false, false},
                                                       {"createEnabled"_L1, FieldType::Bool, false, false},
                                                       {"updateEnabled"_L1, FieldType::Bool, false, false},
                                                       {"removeEnabled"_L1, FieldType::Bool, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::CRUD)