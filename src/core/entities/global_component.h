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

class GlobalComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString applicationName READ applicationName WRITE setApplicationName)

    Q_PROPERTY(QString applicationCppDomainName READ applicationCppDomainName WRITE setApplicationCppDomainName)

    Q_PROPERTY(QString organisationName READ organisationName WRITE setOrganisationName)

    Q_PROPERTY(QString organisationDomain READ organisationDomain WRITE setOrganisationDomain)

public:
    struct MetaData {
        MetaData(GlobalComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(GlobalComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "applicationName"_L1) {
                return true;
            }
            if (fieldName == "applicationCppDomainName"_L1) {
                return true;
            }
            if (fieldName == "organisationName"_L1) {
                return true;
            }
            if (fieldName == "organisationDomain"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "applicationName"_L1) {
                return true;
            }
            if (fieldName == "applicationCppDomainName"_L1) {
                return true;
            }
            if (fieldName == "organisationName"_L1) {
                return true;
            }
            if (fieldName == "organisationDomain"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        GlobalComponent *m_entity = nullptr;
    };

    GlobalComponent()
        : CommonParent()
        , m_metaData(this)
        , m_applicationName(QString())
        , m_applicationCppDomainName(QString())
        , m_organisationName(QString())
        , m_organisationDomain(QString())
    {
    }

    ~GlobalComponent()
    {
    }

    GlobalComponent(const int &id,
                    const QUuid &uuid,
                    const QDateTime &creationDate,
                    const QDateTime &updateDate,
                    const QString &applicationName,
                    const QString &applicationCppDomainName,
                    const QString &organisationName,
                    const QString &organisationDomain)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_applicationName(applicationName)
        , m_applicationCppDomainName(applicationCppDomainName)
        , m_organisationName(organisationName)
        , m_organisationDomain(organisationDomain)
    {
    }

    GlobalComponent(const GlobalComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_applicationName(other.m_applicationName)
        , m_applicationCppDomainName(other.m_applicationCppDomainName)
        , m_organisationName(other.m_organisationName)
        , m_organisationDomain(other.m_organisationDomain)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::GlobalComponent;
    }

    GlobalComponent &operator=(const GlobalComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_applicationName = other.m_applicationName;
            m_applicationCppDomainName = other.m_applicationCppDomainName;
            m_organisationName = other.m_organisationName;
            m_organisationDomain = other.m_organisationDomain;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const GlobalComponent &lhs, const GlobalComponent &rhs);

    friend uint qHash(const GlobalComponent &entity, uint seed) noexcept;

    // ------ applicationName : -----

    QString applicationName() const
    {
        return m_applicationName;
    }

    void setApplicationName(const QString &applicationName)
    {
        m_applicationName = applicationName;
    }

    // ------ applicationCppDomainName : -----

    QString applicationCppDomainName() const
    {
        return m_applicationCppDomainName;
    }

    void setApplicationCppDomainName(const QString &applicationCppDomainName)
    {
        m_applicationCppDomainName = applicationCppDomainName;
    }

    // ------ organisationName : -----

    QString organisationName() const
    {
        return m_organisationName;
    }

    void setOrganisationName(const QString &organisationName)
    {
        m_organisationName = organisationName;
    }

    // ------ organisationDomain : -----

    QString organisationDomain() const
    {
        return m_organisationDomain;
    }

    void setOrganisationDomain(const QString &organisationDomain)
    {
        m_organisationDomain = organisationDomain;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_applicationName;
    QString m_applicationCppDomainName;
    QString m_organisationName;
    QString m_organisationDomain;
};

inline bool operator==(const GlobalComponent &lhs, const GlobalComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_applicationName == rhs.m_applicationName && lhs.m_applicationCppDomainName == rhs.m_applicationCppDomainName
        && lhs.m_organisationName == rhs.m_organisationName && lhs.m_organisationDomain == rhs.m_organisationDomain;
}

inline uint qHash(const GlobalComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_applicationName, seed);
    hash ^= ::qHash(entity.m_applicationCppDomainName, seed);
    hash ^= ::qHash(entity.m_organisationName, seed);
    hash ^= ::qHash(entity.m_organisationDomain, seed);

    return hash;
}

/// Schema for GlobalComponent entity
inline Qleany::Entities::EntitySchema GlobalComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::GlobalComponent,
                                                                 "GlobalComponent"_L1,

                                                                 // relationships:
                                                                 {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                   "Project"_L1,
                                                                   QleanyEditor::Entities::Entities::EntityEnum::GlobalComponent,
                                                                   "GlobalComponent"_L1,
                                                                   "globalComponent"_L1,
                                                                   RelationshipType::OneToOne,
                                                                   RelationshipStrength::Strong,
                                                                   RelationshipCardinality::One,
                                                                   RelationshipDirection::Backward}},

                                                                 // fields:
                                                                 {{"id"_L1, FieldType::Integer, true, false},
                                                                  {"uuid"_L1, FieldType::Uuid, false, false},
                                                                  {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                  {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                  {"applicationName"_L1, FieldType::String, false, false},
                                                                  {"applicationCppDomainName"_L1, FieldType::String, false, false},
                                                                  {"organisationName"_L1, FieldType::String, false, false},
                                                                  {"organisationDomain"_L1, FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::GlobalComponent)