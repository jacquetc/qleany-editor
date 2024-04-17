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

class FrontEndComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString frontName READ frontName WRITE setFrontName)

    Q_PROPERTY(QString folderPath READ folderPath WRITE setFolderPath)

public:
    struct MetaData {
        MetaData(FrontEndComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(FrontEndComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "frontName"_L1) {
                return true;
            }
            if (fieldName == "folderPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "frontName"_L1) {
                return true;
            }
            if (fieldName == "folderPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        FrontEndComponent *m_entity = nullptr;
    };

    FrontEndComponent()
        : CommonParent()
        , m_metaData(this)
        , m_frontName(QString())
        , m_folderPath(QString())
    {
    }

    ~FrontEndComponent()
    {
    }

    FrontEndComponent(const int &id,
                      const QUuid &uuid,
                      const QDateTime &creationDate,
                      const QDateTime &updateDate,
                      const QString &frontName,
                      const QString &folderPath)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_frontName(frontName)
        , m_folderPath(folderPath)
    {
    }

    FrontEndComponent(const FrontEndComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_frontName(other.m_frontName)
        , m_folderPath(other.m_folderPath)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::FrontEndComponent;
    }

    FrontEndComponent &operator=(const FrontEndComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_frontName = other.m_frontName;
            m_folderPath = other.m_folderPath;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const FrontEndComponent &lhs, const FrontEndComponent &rhs);

    friend uint qHash(const FrontEndComponent &entity, uint seed) noexcept;

    // ------ frontName : -----

    QString frontName() const
    {
        return m_frontName;
    }

    void setFrontName(const QString &frontName)
    {
        m_frontName = frontName;
    }

    // ------ folderPath : -----

    QString folderPath() const
    {
        return m_folderPath;
    }

    void setFolderPath(const QString &folderPath)
    {
        m_folderPath = folderPath;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_frontName;
    QString m_folderPath;
};

inline bool operator==(const FrontEndComponent &lhs, const FrontEndComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_frontName == rhs.m_frontName && lhs.m_folderPath == rhs.m_folderPath;
}

inline uint qHash(const FrontEndComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_frontName, seed);
    hash ^= ::qHash(entity.m_folderPath, seed);

    return hash;
}

/// Schema for FrontEndComponent entity
inline Qleany::Entities::EntitySchema FrontEndComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::FrontEndComponent,
                                                                   "FrontEndComponent"_L1,

                                                                   // relationships:
                                                                   {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                     "Project"_L1,
                                                                     QleanyEditor::Entities::Entities::EntityEnum::FrontEndComponent,
                                                                     "FrontEndComponent"_L1,
                                                                     "frontEndComponent"_L1,
                                                                     RelationshipType::OneToMany,
                                                                     RelationshipStrength::Strong,
                                                                     RelationshipCardinality::ManyUnordered,
                                                                     RelationshipDirection::Backward}},

                                                                   // fields:
                                                                   {{"id"_L1, FieldType::Integer, true, false},
                                                                    {"uuid"_L1, FieldType::Uuid, false, false},
                                                                    {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                    {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                    {"frontName"_L1, FieldType::String, false, false},
                                                                    {"folderPath"_L1, FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::FrontEndComponent)