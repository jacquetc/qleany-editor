// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "global_component.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class Project : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)

    Q_PROPERTY(GlobalComponent globalComponent READ globalComponent WRITE setGlobalComponent)

public:
    struct MetaData {
        MetaData(Project *entity)
            : m_entity(entity)
        {
        }
        MetaData(Project *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->globalComponentSet = other.globalComponentSet;
            this->globalComponentLoaded = other.globalComponentLoaded;
        }

        bool globalComponentSet = false;
        bool globalComponentLoaded = false;

        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("fileName")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("globalComponent")) {
                return globalComponentSet;
            }
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("fileName")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("globalComponent")) {
                return globalComponentLoaded;
            }
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        Project *m_entity = nullptr;
    };

    Project()
        : CommonParent()
        , m_fileName(QString())
        , m_metaData(this)
    {
    }

    ~Project()
    {
    }

    Project(const int &id,
            const QUuid &uuid,
            const QDateTime &creationDate,
            const QDateTime &updateDate,
            const QString &fileName,
            const GlobalComponent &globalComponent)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_fileName(fileName)
        , m_globalComponent(globalComponent)
        , m_metaData(this)
    {
    }

    Project(const Project &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_fileName(other.m_fileName)
        , m_globalComponent(other.m_globalComponent)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::Project;
    }

    Project &operator=(const Project &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_fileName = other.m_fileName;
            m_globalComponent = other.m_globalComponent;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const Project &lhs, const Project &rhs);

    friend uint qHash(const Project &entity, uint seed) noexcept;

    // ------ fileName : -----

    QString fileName() const
    {
        return m_fileName;
    }

    void setFileName(const QString &fileName)
    {
        m_fileName = fileName;
    }

    // ------ globalComponent : -----

    GlobalComponent globalComponent()
    {
        if (!m_metaData.globalComponentLoaded && m_globalComponentLoader) {
            m_globalComponent = m_globalComponentLoader(this->id());
            m_metaData.globalComponentLoaded = true;
        }
        return m_globalComponent;
    }

    void setGlobalComponent(const GlobalComponent &globalComponent)
    {
        m_globalComponent = globalComponent;

        m_metaData.globalComponentSet = true;
    }

    using GlobalComponentLoader = std::function<GlobalComponent(int entityId)>;

    void setGlobalComponentLoader(const GlobalComponentLoader &loader)
    {
        m_globalComponentLoader = loader;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_fileName;
    GlobalComponent m_globalComponent;
    GlobalComponentLoader m_globalComponentLoader;
};

inline bool operator==(const Project &lhs, const Project &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_fileName == rhs.m_fileName && lhs.m_globalComponent == rhs.m_globalComponent;
}

inline uint qHash(const Project &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_fileName, seed);
    hash ^= ::qHash(entity.m_globalComponent, seed);

    return hash;
}

/// Schema for Project entity
inline Qleany::Entities::EntitySchema Project::schema = {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                         QString::fromUtf8("Project"),

                                                         // relationships:
                                                         {{QleanyEditor::Entities::Entities::EntityEnum::Root,
                                                           QString::fromUtf8("Root"),
                                                           QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           QString::fromUtf8("Project"),
                                                           QString::fromUtf8("project"),
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Backward},
                                                          {QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                           QString::fromUtf8("Project"),
                                                           QleanyEditor::Entities::Entities::EntityEnum::GlobalComponent,
                                                           QString::fromUtf8("GlobalComponent"),
                                                           QString::fromUtf8("globalComponent"),
                                                           RelationshipType::OneToOne,
                                                           RelationshipStrength::Strong,
                                                           RelationshipCardinality::One,
                                                           RelationshipDirection::Forward}},

                                                         // fields:
                                                         {{QString::fromUtf8("id"), FieldType::Integer, true, false},
                                                          {QString::fromUtf8("uuid"), FieldType::Uuid, false, false},
                                                          {QString::fromUtf8("creationDate"), FieldType::DateTime, false, false},
                                                          {QString::fromUtf8("updateDate"), FieldType::DateTime, false, false},
                                                          {QString::fromUtf8("fileName"), FieldType::String, false, false},
                                                          {QString::fromUtf8("globalComponent"), FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::Project)