// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o.h"
#include "entity.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class CustomCommand : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString name READ name WRITE setName)

    Q_PROPERTY(QList<Entity> entities READ entities WRITE setEntities)

    Q_PROPERTY(bool validator READ validator WRITE setValidator)

    Q_PROPERTY(bool undo READ undo WRITE setUndo)

    Q_PROPERTY(CustomDTO dtoIn READ dtoIn WRITE setDtoIn)

    Q_PROPERTY(CustomDTO dtoOut READ dtoOut WRITE setDtoOut)

public:
    struct MetaData {
        MetaData(CustomCommand *entity)
            : m_entity(entity)
        {
        }
        MetaData(CustomCommand *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->entitiesSet = other.entitiesSet;
            this->entitiesLoaded = other.entitiesLoaded;
            this->dtoInSet = other.dtoInSet;
            this->dtoInLoaded = other.dtoInLoaded;
            this->dtoOutSet = other.dtoOutSet;
            this->dtoOutLoaded = other.dtoOutLoaded;
        }

        bool entitiesSet = false;
        bool entitiesLoaded = false;

        bool dtoInSet = false;
        bool dtoInLoaded = false;

        bool dtoOutSet = false;
        bool dtoOutLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "name"_L1) {
                return true;
            }
            if (fieldName == "entities"_L1) {
                return entitiesSet;
            }
            if (fieldName == "validator"_L1) {
                return true;
            }
            if (fieldName == "undo"_L1) {
                return true;
            }
            if (fieldName == "dtoIn"_L1) {
                return dtoInSet;
            }
            if (fieldName == "dtoOut"_L1) {
                return dtoOutSet;
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
            if (fieldName == "entities"_L1) {
                return entitiesLoaded;
            }
            if (fieldName == "validator"_L1) {
                return true;
            }
            if (fieldName == "undo"_L1) {
                return true;
            }
            if (fieldName == "dtoIn"_L1) {
                return dtoInLoaded;
            }
            if (fieldName == "dtoOut"_L1) {
                return dtoOutLoaded;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        CustomCommand *m_entity = nullptr;
    };

    CustomCommand()
        : CommonParent()
        , m_metaData(this)
        , m_name(QString())
        , m_validator(false)
        , m_undo(false)
    {
    }

    ~CustomCommand()
    {
    }

    CustomCommand(const int &id,
                  const QUuid &uuid,
                  const QDateTime &creationDate,
                  const QDateTime &updateDate,
                  const QString &name,
                  const QList<Entity> &entities,
                  bool validator,
                  bool undo,
                  const CustomDTO &dtoIn,
                  const CustomDTO &dtoOut)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_name(name)
        , m_entities(entities)
        , m_validator(validator)
        , m_undo(undo)
        , m_dtoIn(dtoIn)
        , m_dtoOut(dtoOut)
    {
    }

    CustomCommand(const CustomCommand &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_name(other.m_name)
        , m_entities(other.m_entities)
        , m_validator(other.m_validator)
        , m_undo(other.m_undo)
        , m_dtoIn(other.m_dtoIn)
        , m_dtoOut(other.m_dtoOut)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::CustomCommand;
    }

    CustomCommand &operator=(const CustomCommand &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_name = other.m_name;
            m_entities = other.m_entities;
            m_validator = other.m_validator;
            m_undo = other.m_undo;
            m_dtoIn = other.m_dtoIn;
            m_dtoOut = other.m_dtoOut;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const CustomCommand &lhs, const CustomCommand &rhs);

    friend uint qHash(const CustomCommand &entity, uint seed) noexcept;

    // ------ name : -----

    QString name() const
    {
        return m_name;
    }

    void setName(const QString &name)
    {
        m_name = name;
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

    // ------ validator : -----

    bool validator() const
    {
        return m_validator;
    }

    void setValidator(bool validator)
    {
        m_validator = validator;
    }

    // ------ undo : -----

    bool undo() const
    {
        return m_undo;
    }

    void setUndo(bool undo)
    {
        m_undo = undo;
    }

    // ------ dtoIn : -----

    CustomDTO dtoIn()
    {
        if (!m_metaData.dtoInLoaded && m_dtoInLoader) {
            m_dtoIn = m_dtoInLoader(this->id());
            m_metaData.dtoInLoaded = true;
        }
        return m_dtoIn;
    }

    void setDtoIn(const CustomDTO &dtoIn)
    {
        m_dtoIn = dtoIn;

        m_metaData.dtoInSet = true;
    }

    using DtoInLoader = std::function<CustomDTO(int entityId)>;

    void setDtoInLoader(const DtoInLoader &loader)
    {
        m_dtoInLoader = loader;
    }

    // ------ dtoOut : -----

    CustomDTO dtoOut()
    {
        if (!m_metaData.dtoOutLoaded && m_dtoOutLoader) {
            m_dtoOut = m_dtoOutLoader(this->id());
            m_metaData.dtoOutLoaded = true;
        }
        return m_dtoOut;
    }

    void setDtoOut(const CustomDTO &dtoOut)
    {
        m_dtoOut = dtoOut;

        m_metaData.dtoOutSet = true;
    }

    using DtoOutLoader = std::function<CustomDTO(int entityId)>;

    void setDtoOutLoader(const DtoOutLoader &loader)
    {
        m_dtoOutLoader = loader;
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
    QList<Entity> m_entities;
    EntitiesLoader m_entitiesLoader;
    bool m_validator;
    bool m_undo;
    CustomDTO m_dtoIn;
    DtoInLoader m_dtoInLoader;
    CustomDTO m_dtoOut;
    DtoOutLoader m_dtoOutLoader;
};

inline bool operator==(const CustomCommand &lhs, const CustomCommand &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_name == rhs.m_name && lhs.m_entities == rhs.m_entities && lhs.m_validator == rhs.m_validator && lhs.m_undo == rhs.m_undo
        && lhs.m_dtoIn == rhs.m_dtoIn && lhs.m_dtoOut == rhs.m_dtoOut;
}

inline uint qHash(const CustomCommand &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_name, seed);
    hash ^= ::qHash(entity.m_entities, seed);
    hash ^= ::qHash(entity.m_validator, seed);
    hash ^= ::qHash(entity.m_undo, seed);
    hash ^= ::qHash(entity.m_dtoIn, seed);
    hash ^= ::qHash(entity.m_dtoOut, seed);

    return hash;
}

/// Schema for CustomCommand entity
inline Qleany::Entities::EntitySchema CustomCommand::schema = {QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                               "CustomCommand"_L1,

                                                               // relationships:
                                                               {{QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                                 "ApplicationFeature"_L1,
                                                                 QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                                 "CustomCommand"_L1,
                                                                 "customCommands"_L1,
                                                                 RelationshipType::OneToMany,
                                                                 RelationshipStrength::Strong,
                                                                 RelationshipCardinality::ManyOrdered,
                                                                 RelationshipDirection::Backward},
                                                                {QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                                 "CustomCommand"_L1,
                                                                 QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                                 "Entity"_L1,
                                                                 "entities"_L1,
                                                                 RelationshipType::OneToMany,
                                                                 RelationshipStrength::Strong,
                                                                 RelationshipCardinality::ManyOrdered,
                                                                 RelationshipDirection::Forward},
                                                                {QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                                 "CustomCommand"_L1,
                                                                 QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                                 "CustomDTO"_L1,
                                                                 "dtoIn"_L1,
                                                                 RelationshipType::OneToOne,
                                                                 RelationshipStrength::Strong,
                                                                 RelationshipCardinality::One,
                                                                 RelationshipDirection::Forward},
                                                                {QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                                 "CustomCommand"_L1,
                                                                 QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                                 "CustomDTO"_L1,
                                                                 "dtoOut"_L1,
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
                                                                {"entities"_L1, FieldType::Entity, false, true},
                                                                {"validator"_L1, FieldType::Bool, false, false},
                                                                {"undo"_L1, FieldType::Bool, false, false},
                                                                {"dtoIn"_L1, FieldType::Entity, false, true},
                                                                {"dtoOut"_L1, FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::CustomCommand)