// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity.h"
#include "entity_field.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class PresenterListModel : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString name READ name WRITE setName)

    Q_PROPERTY(Entity entity READ entity WRITE setEntity)

    Q_PROPERTY(EntityField displayedField READ displayedField WRITE setDisplayedField)

    Q_PROPERTY(Entity inRelationOf READ inRelationOf WRITE setInRelationOf)

    Q_PROPERTY(EntityField relationFieldName READ relationFieldName WRITE setRelationFieldName)

    Q_PROPERTY(bool readOnly READ readOnly WRITE setReadOnly)

public:
    struct MetaData {
        MetaData(PresenterListModel *entity)
            : m_entity(entity)
        {
        }
        MetaData(PresenterListModel *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->entitySet = other.entitySet;
            this->entityLoaded = other.entityLoaded;
            this->displayedFieldSet = other.displayedFieldSet;
            this->displayedFieldLoaded = other.displayedFieldLoaded;
            this->inRelationOfSet = other.inRelationOfSet;
            this->inRelationOfLoaded = other.inRelationOfLoaded;
            this->relationFieldNameSet = other.relationFieldNameSet;
            this->relationFieldNameLoaded = other.relationFieldNameLoaded;
        }

        bool entitySet = false;
        bool entityLoaded = false;

        bool displayedFieldSet = false;
        bool displayedFieldLoaded = false;

        bool inRelationOfSet = false;
        bool inRelationOfLoaded = false;

        bool relationFieldNameSet = false;
        bool relationFieldNameLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "name"_L1) {
                return true;
            }
            if (fieldName == "entity"_L1) {
                return entitySet;
            }
            if (fieldName == "displayedField"_L1) {
                return displayedFieldSet;
            }
            if (fieldName == "inRelationOf"_L1) {
                return inRelationOfSet;
            }
            if (fieldName == "relationFieldName"_L1) {
                return relationFieldNameSet;
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
            if (fieldName == "displayedField"_L1) {
                return displayedFieldLoaded;
            }
            if (fieldName == "inRelationOf"_L1) {
                return inRelationOfLoaded;
            }
            if (fieldName == "relationFieldName"_L1) {
                return relationFieldNameLoaded;
            }
            if (fieldName == "readOnly"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        PresenterListModel *m_entity = nullptr;
    };

    PresenterListModel()
        : CommonParent()
        , m_metaData(this)
        , m_name(QString())
        , m_readOnly(false)
    {
    }

    ~PresenterListModel()
    {
    }

    PresenterListModel(const int &id,
                       const QUuid &uuid,
                       const QDateTime &creationDate,
                       const QDateTime &updateDate,
                       const QString &name,
                       const Entity &entity,
                       const EntityField &displayedField,
                       const Entity &inRelationOf,
                       const EntityField &relationFieldName,
                       bool readOnly)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_name(name)
        , m_entity(entity)
        , m_displayedField(displayedField)
        , m_inRelationOf(inRelationOf)
        , m_relationFieldName(relationFieldName)
        , m_readOnly(readOnly)
    {
    }

    PresenterListModel(const PresenterListModel &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_name(other.m_name)
        , m_entity(other.m_entity)
        , m_displayedField(other.m_displayedField)
        , m_inRelationOf(other.m_inRelationOf)
        , m_relationFieldName(other.m_relationFieldName)
        , m_readOnly(other.m_readOnly)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel;
    }

    PresenterListModel &operator=(const PresenterListModel &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_name = other.m_name;
            m_entity = other.m_entity;
            m_displayedField = other.m_displayedField;
            m_inRelationOf = other.m_inRelationOf;
            m_relationFieldName = other.m_relationFieldName;
            m_readOnly = other.m_readOnly;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const PresenterListModel &lhs, const PresenterListModel &rhs);

    friend uint qHash(const PresenterListModel &entity, uint seed) noexcept;

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

    // ------ displayedField : -----

    EntityField displayedField()
    {
        if (!m_metaData.displayedFieldLoaded && m_displayedFieldLoader) {
            m_displayedField = m_displayedFieldLoader(this->id());
            m_metaData.displayedFieldLoaded = true;
        }
        return m_displayedField;
    }

    void setDisplayedField(const EntityField &displayedField)
    {
        m_displayedField = displayedField;

        m_metaData.displayedFieldSet = true;
    }

    using DisplayedFieldLoader = std::function<EntityField(int entityId)>;

    void setDisplayedFieldLoader(const DisplayedFieldLoader &loader)
    {
        m_displayedFieldLoader = loader;
    }

    // ------ inRelationOf : -----

    Entity inRelationOf()
    {
        if (!m_metaData.inRelationOfLoaded && m_inRelationOfLoader) {
            m_inRelationOf = m_inRelationOfLoader(this->id());
            m_metaData.inRelationOfLoaded = true;
        }
        return m_inRelationOf;
    }

    void setInRelationOf(const Entity &inRelationOf)
    {
        m_inRelationOf = inRelationOf;

        m_metaData.inRelationOfSet = true;
    }

    using InRelationOfLoader = std::function<Entity(int entityId)>;

    void setInRelationOfLoader(const InRelationOfLoader &loader)
    {
        m_inRelationOfLoader = loader;
    }

    // ------ relationFieldName : -----

    EntityField relationFieldName()
    {
        if (!m_metaData.relationFieldNameLoaded && m_relationFieldNameLoader) {
            m_relationFieldName = m_relationFieldNameLoader(this->id());
            m_metaData.relationFieldNameLoaded = true;
        }
        return m_relationFieldName;
    }

    void setRelationFieldName(const EntityField &relationFieldName)
    {
        m_relationFieldName = relationFieldName;

        m_metaData.relationFieldNameSet = true;
    }

    using RelationFieldNameLoader = std::function<EntityField(int entityId)>;

    void setRelationFieldNameLoader(const RelationFieldNameLoader &loader)
    {
        m_relationFieldNameLoader = loader;
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
    EntityField m_displayedField;
    DisplayedFieldLoader m_displayedFieldLoader;
    Entity m_inRelationOf;
    InRelationOfLoader m_inRelationOfLoader;
    EntityField m_relationFieldName;
    RelationFieldNameLoader m_relationFieldNameLoader;
    bool m_readOnly;
};

inline bool operator==(const PresenterListModel &lhs, const PresenterListModel &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_name == rhs.m_name && lhs.m_entity == rhs.m_entity && lhs.m_displayedField == rhs.m_displayedField && lhs.m_inRelationOf == rhs.m_inRelationOf
        && lhs.m_relationFieldName == rhs.m_relationFieldName && lhs.m_readOnly == rhs.m_readOnly;
}

inline uint qHash(const PresenterListModel &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_name, seed);
    hash ^= ::qHash(entity.m_entity, seed);
    hash ^= ::qHash(entity.m_displayedField, seed);
    hash ^= ::qHash(entity.m_inRelationOf, seed);
    hash ^= ::qHash(entity.m_relationFieldName, seed);
    hash ^= ::qHash(entity.m_readOnly, seed);

    return hash;
}

/// Schema for PresenterListModel entity
inline Qleany::Entities::EntitySchema PresenterListModel::schema = {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                                    "PresenterListModel"_L1,

                                                                    // relationships:
                                                                    {{QleanyEditor::Entities::Entities::EntityEnum::PresenterComponent,
                                                                      "PresenterComponent"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                                      "PresenterListModel"_L1,
                                                                      "listModels"_L1,
                                                                      RelationshipType::OneToMany,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::ManyOrdered,
                                                                      RelationshipDirection::Backward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                                      "PresenterListModel"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                                      "Entity"_L1,
                                                                      "entity"_L1,
                                                                      RelationshipType::OneToOne,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::One,
                                                                      RelationshipDirection::Forward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                                      "PresenterListModel"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::EntityField,
                                                                      "EntityField"_L1,
                                                                      "displayedField"_L1,
                                                                      RelationshipType::OneToOne,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::One,
                                                                      RelationshipDirection::Forward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                                      "PresenterListModel"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                                      "Entity"_L1,
                                                                      "inRelationOf"_L1,
                                                                      RelationshipType::OneToOne,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::One,
                                                                      RelationshipDirection::Forward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                                      "PresenterListModel"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::EntityField,
                                                                      "EntityField"_L1,
                                                                      "relationFieldName"_L1,
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
                                                                     {"displayedField"_L1, FieldType::Entity, false, true},
                                                                     {"inRelationOf"_L1, FieldType::Entity, false, true},
                                                                     {"relationFieldName"_L1, FieldType::Entity, false, true},
                                                                     {"readOnly"_L1, FieldType::Bool, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::PresenterListModel)