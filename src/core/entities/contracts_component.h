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

class ContractsComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString invertedAppDomain READ invertedAppDomain WRITE setInvertedAppDomain)

    Q_PROPERTY(QString folderPath READ folderPath WRITE setFolderPath)

public:
    struct MetaData {
        MetaData(ContractsComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(ContractsComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "invertedAppDomain"_L1) {
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
            if (fieldName == "invertedAppDomain"_L1) {
                return true;
            }
            if (fieldName == "folderPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        ContractsComponent *m_entity = nullptr;
    };

    ContractsComponent()
        : CommonParent()
        , m_metaData(this)
        , m_invertedAppDomain(QString())
        , m_folderPath(QString())
    {
    }

    ~ContractsComponent()
    {
    }

    ContractsComponent(const int &id,
                       const QUuid &uuid,
                       const QDateTime &creationDate,
                       const QDateTime &updateDate,
                       const QString &invertedAppDomain,
                       const QString &folderPath)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_invertedAppDomain(invertedAppDomain)
        , m_folderPath(folderPath)
    {
    }

    ContractsComponent(const ContractsComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_invertedAppDomain(other.m_invertedAppDomain)
        , m_folderPath(other.m_folderPath)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::ContractsComponent;
    }

    ContractsComponent &operator=(const ContractsComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_invertedAppDomain = other.m_invertedAppDomain;
            m_folderPath = other.m_folderPath;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const ContractsComponent &lhs, const ContractsComponent &rhs);

    friend uint qHash(const ContractsComponent &entity, uint seed) noexcept;

    // ------ invertedAppDomain : -----

    QString invertedAppDomain() const
    {
        return m_invertedAppDomain;
    }

    void setInvertedAppDomain(const QString &invertedAppDomain)
    {
        m_invertedAppDomain = invertedAppDomain;
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
    QString m_invertedAppDomain;
    QString m_folderPath;
};

inline bool operator==(const ContractsComponent &lhs, const ContractsComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_invertedAppDomain == rhs.m_invertedAppDomain && lhs.m_folderPath == rhs.m_folderPath;
}

inline uint qHash(const ContractsComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_invertedAppDomain, seed);
    hash ^= ::qHash(entity.m_folderPath, seed);

    return hash;
}

/// Schema for ContractsComponent entity
inline Qleany::Entities::EntitySchema ContractsComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::ContractsComponent,
                                                                    "ContractsComponent"_L1,

                                                                    // relationships:
                                                                    {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                      "Project"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::ContractsComponent,
                                                                      "ContractsComponent"_L1,
                                                                      "contractsComponent"_L1,
                                                                      RelationshipType::OneToOne,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::One,
                                                                      RelationshipDirection::Backward}},

                                                                    // fields:
                                                                    {{"id"_L1, FieldType::Integer, true, false},
                                                                     {"uuid"_L1, FieldType::Uuid, false, false},
                                                                     {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                     {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                     {"invertedAppDomain"_L1, FieldType::String, false, false},
                                                                     {"folderPath"_L1, FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::ContractsComponent)