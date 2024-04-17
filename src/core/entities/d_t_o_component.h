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

class DTOComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString commonCMakeFolderPath READ commonCMakeFolderPath WRITE setCommonCMakeFolderPath)

public:
    struct MetaData {
        MetaData(DTOComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(DTOComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "commonCMakeFolderPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "commonCMakeFolderPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        DTOComponent *m_entity = nullptr;
    };

    DTOComponent()
        : CommonParent()
        , m_metaData(this)
        , m_commonCMakeFolderPath(QString())
    {
    }

    ~DTOComponent()
    {
    }

    DTOComponent(const int &id, const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate, const QString &commonCMakeFolderPath)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_commonCMakeFolderPath(commonCMakeFolderPath)
    {
    }

    DTOComponent(const DTOComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_commonCMakeFolderPath(other.m_commonCMakeFolderPath)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::DTOComponent;
    }

    DTOComponent &operator=(const DTOComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_commonCMakeFolderPath = other.m_commonCMakeFolderPath;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const DTOComponent &lhs, const DTOComponent &rhs);

    friend uint qHash(const DTOComponent &entity, uint seed) noexcept;

    // ------ commonCMakeFolderPath : -----

    QString commonCMakeFolderPath() const
    {
        return m_commonCMakeFolderPath;
    }

    void setCommonCMakeFolderPath(const QString &commonCMakeFolderPath)
    {
        m_commonCMakeFolderPath = commonCMakeFolderPath;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_commonCMakeFolderPath;
};

inline bool operator==(const DTOComponent &lhs, const DTOComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_commonCMakeFolderPath == rhs.m_commonCMakeFolderPath;
}

inline uint qHash(const DTOComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_commonCMakeFolderPath, seed);

    return hash;
}

/// Schema for DTOComponent entity
inline Qleany::Entities::EntitySchema DTOComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::DTOComponent,
                                                              "DTOComponent"_L1,

                                                              // relationships:
                                                              {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                "Project"_L1,
                                                                QleanyEditor::Entities::Entities::EntityEnum::DTOComponent,
                                                                "DTOComponent"_L1,
                                                                "dtoComponent"_L1,
                                                                RelationshipType::OneToOne,
                                                                RelationshipStrength::Strong,
                                                                RelationshipCardinality::One,
                                                                RelationshipDirection::Backward}},

                                                              // fields:
                                                              {{"id"_L1, FieldType::Integer, true, false},
                                                               {"uuid"_L1, FieldType::Uuid, false, false},
                                                               {"creationDate"_L1, FieldType::DateTime, false, false},
                                                               {"updateDate"_L1, FieldType::DateTime, false, false},
                                                               {"commonCMakeFolderPath"_L1, FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::DTOComponent)