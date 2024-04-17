// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field.h"
#include "entity_parent.h"
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

    Q_PROPERTY(EntityParent parent READ parent WRITE setParent)

    Q_PROPERTY(QList<EntityField> fields READ fields WRITE setFields)

    Q_PROPERTY(bool onlyForHeritage READ onlyForHeritage WRITE setOnlyForHeritage)

public:
    struct MetaData {
        MetaData(Entity *entity)
            : m_entity(entity)
        {
        }
        MetaData(Entity *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->parentSet = other.parentSet;
            this->parentLoaded = other.parentLoaded;
            this->fieldsSet = other.fieldsSet;
            this->fieldsLoaded = other.fieldsLoaded;
        }

        bool parentSet = false;
        bool parentLoaded = false;

        bool fieldsSet = false;
        bool fieldsLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "name"_L1) {
                return true;
            }
            if (fieldName == "parent"_L1) {
                return parentSet;
            }
            if (fieldName == "fields"_L1) {
                return fieldsSet;
            }
            if (fieldName == "onlyForHeritage"_L1) {
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
            if (fieldName == "parent"_L1) {
                return parentLoaded;
            }
            if (fieldName == "fields"_L1) {
                return fieldsLoaded;
            }
            if (fieldName == "onlyForHeritage"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        Entity *m_entity = nullptr;
    };

    Entity()
        : CommonParent()
        , m_metaData(this)
        , m_name(QString())
        , m_onlyForHeritage(false)
    {
    }

    ~Entity()
    {
    }

    Entity(const int &id,
           const QUuid &uuid,
           const QDateTime &creationDate,
           const QDateTime &updateDate,
           const QString &name,
           const EntityParent &parent,
           const QList<EntityField> &fields,
           bool onlyForHeritage)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_name(name)
        , m_parent(parent)
        , m_fields(fields)
        , m_onlyForHeritage(onlyForHeritage)
    {
    }

    Entity(const Entity &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_name(other.m_name)
        , m_parent(other.m_parent)
        , m_fields(other.m_fields)
        , m_onlyForHeritage(other.m_onlyForHeritage)
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
            m_parent = other.m_parent;
            m_fields = other.m_fields;
            m_onlyForHeritage = other.m_onlyForHeritage;

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

    // ------ parent : -----

    EntityParent parent()
    {
        if (!m_metaData.parentLoaded && m_parentLoader) {
            m_parent = m_parentLoader(this->id());
            m_metaData.parentLoaded = true;
        }
        return m_parent;
    }

    void setParent(const EntityParent &parent)
    {
        m_parent = parent;

        m_metaData.parentSet = true;
    }

    using ParentLoader = std::function<EntityParent(int entityId)>;

    void setParentLoader(const ParentLoader &loader)
    {
        m_parentLoader = loader;
    }

    // ------ fields : -----

    QList<EntityField> fields()
    {
        if (!m_metaData.fieldsLoaded && m_fieldsLoader) {
            m_fields = m_fieldsLoader(this->id());
            m_metaData.fieldsLoaded = true;
        }
        return m_fields;
    }

    void setFields(const QList<EntityField> &fields)
    {
        m_fields = fields;

        m_metaData.fieldsSet = true;
    }

    using FieldsLoader = std::function<QList<EntityField>(int entityId)>;

    void setFieldsLoader(const FieldsLoader &loader)
    {
        m_fieldsLoader = loader;
    }

    // ------ onlyForHeritage : -----

    bool onlyForHeritage() const
    {
        return m_onlyForHeritage;
    }

    void setOnlyForHeritage(bool onlyForHeritage)
    {
        m_onlyForHeritage = onlyForHeritage;
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
    EntityParent m_parent;
    ParentLoader m_parentLoader;
    QList<EntityField> m_fields;
    FieldsLoader m_fieldsLoader;
    bool m_onlyForHeritage;
};

inline bool operator==(const Entity &lhs, const Entity &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_name == rhs.m_name && lhs.m_parent == rhs.m_parent && lhs.m_fields == rhs.m_fields && lhs.m_onlyForHeritage == rhs.m_onlyForHeritage;
}

inline uint qHash(const Entity &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_name, seed);
    hash ^= ::qHash(entity.m_parent, seed);
    hash ^= ::qHash(entity.m_fields, seed);
    hash ^= ::qHash(entity.m_onlyForHeritage, seed);

    return hash;
}

/// Schema for Entity entity
inline Qleany::Entities::EntitySchema Entity::schema = {QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                        "Entity"_L1,

                                                        // relationships:
                                                        {{QleanyEditor::Entities::Entities::EntityEnum::EntityComponent,
                                                          "EntityComponent"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          "entities"_L1,
                                                          RelationshipType::OneToMany,
                                                          RelationshipStrength::Strong,
                                                          RelationshipCardinality::ManyOrdered,
                                                          RelationshipDirection::Backward},
                                                         {QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::EntityParent,
                                                          "EntityParent"_L1,
                                                          "parent"_L1,
                                                          RelationshipType::OneToOne,
                                                          RelationshipStrength::Strong,
                                                          RelationshipCardinality::One,
                                                          RelationshipDirection::Forward},
                                                         {QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::EntityField,
                                                          "EntityField"_L1,
                                                          "fields"_L1,
                                                          RelationshipType::OneToMany,
                                                          RelationshipStrength::Strong,
                                                          RelationshipCardinality::ManyOrdered,
                                                          RelationshipDirection::Forward},
                                                         {QleanyEditor::Entities::Entities::EntityEnum::Repository,
                                                          "Repository"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          "entity"_L1,
                                                          RelationshipType::OneToOne,
                                                          RelationshipStrength::Strong,
                                                          RelationshipCardinality::One,
                                                          RelationshipDirection::Backward},
                                                         {QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                          "ApplicationFeature"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          "dtoIdenticalToEntity"_L1,
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
                                                          RelationshipDirection::Backward},
                                                         {QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                          "CustomCommand"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          "entities"_L1,
                                                          RelationshipType::OneToMany,
                                                          RelationshipStrength::Strong,
                                                          RelationshipCardinality::ManyOrdered,
                                                          RelationshipDirection::Backward},
                                                         {QleanyEditor::Entities::Entities::EntityEnum::CustomQuery,
                                                          "CustomQuery"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          "entities"_L1,
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
                                                          RelationshipDirection::Backward},
                                                         {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                          "PresenterListModel"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          "entity"_L1,
                                                          RelationshipType::OneToOne,
                                                          RelationshipStrength::Strong,
                                                          RelationshipCardinality::One,
                                                          RelationshipDirection::Backward},
                                                         {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                          "PresenterListModel"_L1,
                                                          QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                          "Entity"_L1,
                                                          "inRelationOf"_L1,
                                                          RelationshipType::OneToOne,
                                                          RelationshipStrength::Strong,
                                                          RelationshipCardinality::One,
                                                          RelationshipDirection::Backward}},

                                                        // fields:
                                                        {{"id"_L1, FieldType::Integer, true, false},
                                                         {"uuid"_L1, FieldType::Uuid, false, false},
                                                         {"creationDate"_L1, FieldType::DateTime, false, false},
                                                         {"updateDate"_L1, FieldType::DateTime, false, false},
                                                         {"name"_L1, FieldType::String, false, false},
                                                         {"parent"_L1, FieldType::Entity, false, true},
                                                         {"fields"_L1, FieldType::Entity, false, true},
                                                         {"onlyForHeritage"_L1, FieldType::Bool, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::Entity)