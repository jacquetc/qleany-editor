// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class CustomDTO : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString typePrefix READ typePrefix WRITE setTypePrefix)

    Q_PROPERTY(QList<CustomDTOField> fields READ fields WRITE setFields)

public:
    struct MetaData {
        MetaData(CustomDTO *entity)
            : m_entity(entity)
        {
        }
        MetaData(CustomDTO *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->fieldsSet = other.fieldsSet;
            this->fieldsLoaded = other.fieldsLoaded;
        }

        bool fieldsSet = false;
        bool fieldsLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "typePrefix"_L1) {
                return true;
            }
            if (fieldName == "fields"_L1) {
                return fieldsSet;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "typePrefix"_L1) {
                return true;
            }
            if (fieldName == "fields"_L1) {
                return fieldsLoaded;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        CustomDTO *m_entity = nullptr;
    };

    CustomDTO()
        : CommonParent()
        , m_metaData(this)
        , m_typePrefix(QString())
    {
    }

    ~CustomDTO()
    {
    }

    CustomDTO(const int &id,
              const QUuid &uuid,
              const QDateTime &creationDate,
              const QDateTime &updateDate,
              const QString &typePrefix,
              const QList<CustomDTOField> &fields)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_typePrefix(typePrefix)
        , m_fields(fields)
    {
    }

    CustomDTO(const CustomDTO &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_typePrefix(other.m_typePrefix)
        , m_fields(other.m_fields)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::CustomDTO;
    }

    CustomDTO &operator=(const CustomDTO &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_typePrefix = other.m_typePrefix;
            m_fields = other.m_fields;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const CustomDTO &lhs, const CustomDTO &rhs);

    friend uint qHash(const CustomDTO &entity, uint seed) noexcept;

    // ------ typePrefix : -----

    QString typePrefix() const
    {
        return m_typePrefix;
    }

    void setTypePrefix(const QString &typePrefix)
    {
        m_typePrefix = typePrefix;
    }

    // ------ fields : -----

    QList<CustomDTOField> fields()
    {
        if (!m_metaData.fieldsLoaded && m_fieldsLoader) {
            m_fields = m_fieldsLoader(this->id());
            m_metaData.fieldsLoaded = true;
        }
        return m_fields;
    }

    void setFields(const QList<CustomDTOField> &fields)
    {
        m_fields = fields;

        m_metaData.fieldsSet = true;
    }

    using FieldsLoader = std::function<QList<CustomDTOField>(int entityId)>;

    void setFieldsLoader(const FieldsLoader &loader)
    {
        m_fieldsLoader = loader;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_typePrefix;
    QList<CustomDTOField> m_fields;
    FieldsLoader m_fieldsLoader;
};

inline bool operator==(const CustomDTO &lhs, const CustomDTO &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_typePrefix == rhs.m_typePrefix && lhs.m_fields == rhs.m_fields;
}

inline uint qHash(const CustomDTO &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_typePrefix, seed);
    hash ^= ::qHash(entity.m_fields, seed);

    return hash;
}

/// Schema for CustomDTO entity
inline Qleany::Entities::EntitySchema CustomDTO::schema = {QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                           "CustomDTO"_L1,

                                                           // relationships:
                                                           {{QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                             "CustomCommand"_L1,
                                                             QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                             "CustomDTO"_L1,
                                                             "dtoIn"_L1,
                                                             RelationshipType::OneToOne,
                                                             RelationshipStrength::Strong,
                                                             RelationshipCardinality::One,
                                                             RelationshipDirection::Backward},
                                                            {QleanyEditor::Entities::Entities::EntityEnum::CustomCommand,
                                                             "CustomCommand"_L1,
                                                             QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                             "CustomDTO"_L1,
                                                             "dtoOut"_L1,
                                                             RelationshipType::OneToOne,
                                                             RelationshipStrength::Strong,
                                                             RelationshipCardinality::One,
                                                             RelationshipDirection::Backward},
                                                            {QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                             "CustomDTO"_L1,
                                                             QleanyEditor::Entities::Entities::EntityEnum::CustomDTOField,
                                                             "CustomDTOField"_L1,
                                                             "fields"_L1,
                                                             RelationshipType::OneToMany,
                                                             RelationshipStrength::Strong,
                                                             RelationshipCardinality::ManyOrdered,
                                                             RelationshipDirection::Forward},
                                                            {QleanyEditor::Entities::Entities::EntityEnum::CustomQuery,
                                                             "CustomQuery"_L1,
                                                             QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                             "CustomDTO"_L1,
                                                             "dtoIn"_L1,
                                                             RelationshipType::OneToOne,
                                                             RelationshipStrength::Strong,
                                                             RelationshipCardinality::One,
                                                             RelationshipDirection::Backward},
                                                            {QleanyEditor::Entities::Entities::EntityEnum::CustomQuery,
                                                             "CustomQuery"_L1,
                                                             QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                             "CustomDTO"_L1,
                                                             "dtoOut"_L1,
                                                             RelationshipType::OneToOne,
                                                             RelationshipStrength::Strong,
                                                             RelationshipCardinality::One,
                                                             RelationshipDirection::Backward}},

                                                           // fields:
                                                           {{"id"_L1, FieldType::Integer, true, false},
                                                            {"uuid"_L1, FieldType::Uuid, false, false},
                                                            {"creationDate"_L1, FieldType::DateTime, false, false},
                                                            {"updateDate"_L1, FieldType::DateTime, false, false},
                                                            {"typePrefix"_L1, FieldType::String, false, false},
                                                            {"fields"_L1, FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::CustomDTO)