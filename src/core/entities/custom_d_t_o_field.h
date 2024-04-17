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

class CustomDTOField : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString type READ type WRITE setType)

    Q_PROPERTY(QString name READ name WRITE setName)

public:
    struct MetaData {
        MetaData(CustomDTOField *entity)
            : m_entity(entity)
        {
        }
        MetaData(CustomDTOField *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "type"_L1) {
                return true;
            }
            if (fieldName == "name"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "type"_L1) {
                return true;
            }
            if (fieldName == "name"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        CustomDTOField *m_entity = nullptr;
    };

    CustomDTOField()
        : CommonParent()
        , m_metaData(this)
        , m_type(QString())
        , m_name(QString())
    {
    }

    ~CustomDTOField()
    {
    }

    CustomDTOField(const int &id, const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate, const QString &type, const QString &name)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_type(type)
        , m_name(name)
    {
    }

    CustomDTOField(const CustomDTOField &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_type(other.m_type)
        , m_name(other.m_name)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::CustomDTOField;
    }

    CustomDTOField &operator=(const CustomDTOField &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_type = other.m_type;
            m_name = other.m_name;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const CustomDTOField &lhs, const CustomDTOField &rhs);

    friend uint qHash(const CustomDTOField &entity, uint seed) noexcept;

    // ------ type : -----

    QString type() const
    {
        return m_type;
    }

    void setType(const QString &type)
    {
        m_type = type;
    }

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
    QString m_type;
    QString m_name;
};

inline bool operator==(const CustomDTOField &lhs, const CustomDTOField &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_type == rhs.m_type && lhs.m_name == rhs.m_name;
}

inline uint qHash(const CustomDTOField &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_type, seed);
    hash ^= ::qHash(entity.m_name, seed);

    return hash;
}

/// Schema for CustomDTOField entity
inline Qleany::Entities::EntitySchema CustomDTOField::schema = {QleanyEditor::Entities::Entities::EntityEnum::CustomDTOField,
                                                                "CustomDTOField"_L1,

                                                                // relationships:
                                                                {{QleanyEditor::Entities::Entities::EntityEnum::CustomDTO,
                                                                  "CustomDTO"_L1,
                                                                  QleanyEditor::Entities::Entities::EntityEnum::CustomDTOField,
                                                                  "CustomDTOField"_L1,
                                                                  "fields"_L1,
                                                                  RelationshipType::OneToMany,
                                                                  RelationshipStrength::Strong,
                                                                  RelationshipCardinality::ManyOrdered,
                                                                  RelationshipDirection::Backward}},

                                                                // fields:
                                                                {{"id"_L1, FieldType::Integer, true, false},
                                                                 {"uuid"_L1, FieldType::Uuid, false, false},
                                                                 {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                 {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                 {"type"_L1, FieldType::String, false, false},
                                                                 {"name"_L1, FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::CustomDTOField)