// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d.h"
#include "custom_command.h"
#include "custom_query.h"
#include "entity.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class ApplicationFeature : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString name READ name WRITE setName)

    Q_PROPERTY(Entity dtoIdenticalToEntity READ dtoIdenticalToEntity WRITE setDtoIdenticalToEntity)

    Q_PROPERTY(CRUD crud READ crud WRITE setCrud)

    Q_PROPERTY(QList<CustomCommand> customCommands READ customCommands WRITE setCustomCommands)

    Q_PROPERTY(QList<CustomQuery> customQueries READ customQueries WRITE setCustomQueries)

public:
    struct MetaData {
        MetaData(ApplicationFeature *entity)
            : m_entity(entity)
        {
        }
        MetaData(ApplicationFeature *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->dtoIdenticalToEntitySet = other.dtoIdenticalToEntitySet;
            this->dtoIdenticalToEntityLoaded = other.dtoIdenticalToEntityLoaded;
            this->crudSet = other.crudSet;
            this->crudLoaded = other.crudLoaded;
            this->customCommandsSet = other.customCommandsSet;
            this->customCommandsLoaded = other.customCommandsLoaded;
            this->customQueriesSet = other.customQueriesSet;
            this->customQueriesLoaded = other.customQueriesLoaded;
        }

        bool dtoIdenticalToEntitySet = false;
        bool dtoIdenticalToEntityLoaded = false;

        bool crudSet = false;
        bool crudLoaded = false;

        bool customCommandsSet = false;
        bool customCommandsLoaded = false;

        bool customQueriesSet = false;
        bool customQueriesLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "name"_L1) {
                return true;
            }
            if (fieldName == "dtoIdenticalToEntity"_L1) {
                return dtoIdenticalToEntitySet;
            }
            if (fieldName == "crud"_L1) {
                return crudSet;
            }
            if (fieldName == "customCommands"_L1) {
                return customCommandsSet;
            }
            if (fieldName == "customQueries"_L1) {
                return customQueriesSet;
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
            if (fieldName == "dtoIdenticalToEntity"_L1) {
                return dtoIdenticalToEntityLoaded;
            }
            if (fieldName == "crud"_L1) {
                return crudLoaded;
            }
            if (fieldName == "customCommands"_L1) {
                return customCommandsLoaded;
            }
            if (fieldName == "customQueries"_L1) {
                return customQueriesLoaded;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        ApplicationFeature *m_entity = nullptr;
    };

    ApplicationFeature()
        : CommonParent()
        , m_metaData(this)
        , m_name(QString())
    {
    }

    ~ApplicationFeature()
    {
    }

    ApplicationFeature(const int &id,
                       const QUuid &uuid,
                       const QDateTime &creationDate,
                       const QDateTime &updateDate,
                       const QString &name,
                       const Entity &dtoIdenticalToEntity,
                       const CRUD &crud,
                       const QList<CustomCommand> &customCommands,
                       const QList<CustomQuery> &customQueries)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_name(name)
        , m_dtoIdenticalToEntity(dtoIdenticalToEntity)
        , m_crud(crud)
        , m_customCommands(customCommands)
        , m_customQueries(customQueries)
    {
    }

    ApplicationFeature(const ApplicationFeature &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_name(other.m_name)
        , m_dtoIdenticalToEntity(other.m_dtoIdenticalToEntity)
        , m_crud(other.m_crud)
        , m_customCommands(other.m_customCommands)
        , m_customQueries(other.m_customQueries)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature;
    }

    ApplicationFeature &operator=(const ApplicationFeature &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_name = other.m_name;
            m_dtoIdenticalToEntity = other.m_dtoIdenticalToEntity;
            m_crud = other.m_crud;
            m_customCommands = other.m_customCommands;
            m_customQueries = other.m_customQueries;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const ApplicationFeature &lhs, const ApplicationFeature &rhs);

    friend uint qHash(const ApplicationFeature &entity, uint seed) noexcept;

    // ------ name : -----

    QString name() const
    {
        return m_name;
    }

    void setName(const QString &name)
    {
        m_name = name;
    }

    // ------ dtoIdenticalToEntity : -----

    Entity dtoIdenticalToEntity()
    {
        if (!m_metaData.dtoIdenticalToEntityLoaded && m_dtoIdenticalToEntityLoader) {
            m_dtoIdenticalToEntity = m_dtoIdenticalToEntityLoader(this->id());
            m_metaData.dtoIdenticalToEntityLoaded = true;
        }
        return m_dtoIdenticalToEntity;
    }

    void setDtoIdenticalToEntity(const Entity &dtoIdenticalToEntity)
    {
        m_dtoIdenticalToEntity = dtoIdenticalToEntity;

        m_metaData.dtoIdenticalToEntitySet = true;
    }

    using DtoIdenticalToEntityLoader = std::function<Entity(int entityId)>;

    void setDtoIdenticalToEntityLoader(const DtoIdenticalToEntityLoader &loader)
    {
        m_dtoIdenticalToEntityLoader = loader;
    }

    // ------ crud : -----

    CRUD crud()
    {
        if (!m_metaData.crudLoaded && m_crudLoader) {
            m_crud = m_crudLoader(this->id());
            m_metaData.crudLoaded = true;
        }
        return m_crud;
    }

    void setCrud(const CRUD &crud)
    {
        m_crud = crud;

        m_metaData.crudSet = true;
    }

    using CrudLoader = std::function<CRUD(int entityId)>;

    void setCrudLoader(const CrudLoader &loader)
    {
        m_crudLoader = loader;
    }

    // ------ customCommands : -----

    QList<CustomCommand> customCommands()
    {
        if (!m_metaData.customCommandsLoaded && m_customCommandsLoader) {
            m_customCommands = m_customCommandsLoader(this->id());
            m_metaData.customCommandsLoaded = true;
        }
        return m_customCommands;
    }

    void setCustomCommands(const QList<CustomCommand> &customCommands)
    {
        m_customCommands = customCommands;

        m_metaData.customCommandsSet = true;
    }

    using CustomCommandsLoader = std::function<QList<CustomCommand>(int entityId)>;

    void setCustomCommandsLoader(const CustomCommandsLoader &loader)
    {
        m_customCommandsLoader = loader;
    }

    // ------ customQueries : -----

    QList<CustomQuery> customQueries()
    {
        if (!m_metaData.customQueriesLoaded && m_customQueriesLoader) {
            m_customQueries = m_customQueriesLoader(this->id());
            m_metaData.customQueriesLoaded = true;
        }
        return m_customQueries;
    }

    void setCustomQueries(const QList<CustomQuery> &customQueries)
    {
        m_customQueries = customQueries;

        m_metaData.customQueriesSet = true;
    }

    using CustomQueriesLoader = std::function<QList<CustomQuery>(int entityId)>;

    void setCustomQueriesLoader(const CustomQueriesLoader &loader)
    {
        m_customQueriesLoader = loader;
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
    Entity m_dtoIdenticalToEntity;
    DtoIdenticalToEntityLoader m_dtoIdenticalToEntityLoader;
    CRUD m_crud;
    CrudLoader m_crudLoader;
    QList<CustomCommand> m_customCommands;
    CustomCommandsLoader m_customCommandsLoader;
    QList<CustomQuery> m_customQueries;
    CustomQueriesLoader m_customQueriesLoader;
};

inline bool operator==(const ApplicationFeature &lhs, const ApplicationFeature &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_name == rhs.m_name && lhs.m_dtoIdenticalToEntity == rhs.m_dtoIdenticalToEntity && lhs.m_crud == rhs.m_crud
        && lhs.m_customCommands == rhs.m_customCommands && lhs.m_customQueries == rhs.m_customQueries;
}

inline uint qHash(const ApplicationFeature &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_name, seed);
    hash ^= ::qHash(entity.m_dtoIdenticalToEntity, seed);
    hash ^= ::qHash(entity.m_crud, seed);
    hash ^= ::qHash(entity.m_customCommands, seed);
    hash ^= ::qHash(entity.m_customQueries, seed);

    return hash;
}

/// Schema for ApplicationFeature entity
inline Qleany::Entities::EntitySchema ApplicationFeature::schema = {QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                                    "ApplicationFeature"_L1,

                                                                    // relationships:
                                                                    {{QleanyEditor::Entities::Entities::EntityEnum::ApplicationComponent,
                                                                      "ApplicationComponent"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                                      "ApplicationFeature"_L1,
                                                                      "features"_L1,
                                                                      RelationshipType::OneToMany,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::ManyOrdered,
                                                                      RelationshipDirection::Backward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                                      "ApplicationFeature"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::Entity,
                                                                      "Entity"_L1,
                                                                      "dtoIdenticalToEntity"_L1,
                                                                      RelationshipType::OneToOne,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::One,
                                                                      RelationshipDirection::Forward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                                      "ApplicationFeature"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::CRUD,
                                                                      "CRUD"_L1,
                                                                      "crud"_L1,
                                                                      RelationshipType::OneToOne,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::One,
                                                                      RelationshipDirection::Forward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                                      "ApplicationFeature"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                                      "CustomCommand"_L1,
                                                                      "customCommands"_L1,
                                                                      RelationshipType::OneToMany,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::ManyOrdered,
                                                                      RelationshipDirection::Forward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                                      "ApplicationFeature"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::CustomQuery,
                                                                      "CustomQuery"_L1,
                                                                      "customQueries"_L1,
                                                                      RelationshipType::OneToMany,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::ManyOrdered,
                                                                      RelationshipDirection::Forward}},

                                                                    // fields:
                                                                    {{"id"_L1, FieldType::Integer, true, false},
                                                                     {"uuid"_L1, FieldType::Uuid, false, false},
                                                                     {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                     {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                     {"name"_L1, FieldType::String, false, false},
                                                                     {"dtoIdenticalToEntity"_L1, FieldType::Entity, false, true},
                                                                     {"crud"_L1, FieldType::Entity, false, true},
                                                                     {"customCommands"_L1, FieldType::Entity, false, true},
                                                                     {"customQueries"_L1, FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::ApplicationFeature)