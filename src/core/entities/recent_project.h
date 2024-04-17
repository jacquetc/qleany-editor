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

class RecentProject : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)

    Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath)

public:
    struct MetaData {
        MetaData(RecentProject *entity)
            : m_entity(entity)
        {
        }
        MetaData(RecentProject *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "fileName"_L1) {
                return true;
            }
            if (fieldName == "rootPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "fileName"_L1) {
                return true;
            }
            if (fieldName == "rootPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        RecentProject *m_entity = nullptr;
    };

    RecentProject()
        : CommonParent()
        , m_metaData(this)
        , m_fileName(QString())
        , m_rootPath(QString())
    {
    }

    ~RecentProject()
    {
    }

    RecentProject(const int &id,
                  const QUuid &uuid,
                  const QDateTime &creationDate,
                  const QDateTime &updateDate,
                  const QString &fileName,
                  const QString &rootPath)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_fileName(fileName)
        , m_rootPath(rootPath)
    {
    }

    RecentProject(const RecentProject &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_fileName(other.m_fileName)
        , m_rootPath(other.m_rootPath)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::RecentProject;
    }

    RecentProject &operator=(const RecentProject &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_fileName = other.m_fileName;
            m_rootPath = other.m_rootPath;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const RecentProject &lhs, const RecentProject &rhs);

    friend uint qHash(const RecentProject &entity, uint seed) noexcept;

    // ------ fileName : -----

    QString fileName() const
    {
        return m_fileName;
    }

    void setFileName(const QString &fileName)
    {
        m_fileName = fileName;
    }

    // ------ rootPath : -----

    QString rootPath() const
    {
        return m_rootPath;
    }

    void setRootPath(const QString &rootPath)
    {
        m_rootPath = rootPath;
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
    QString m_rootPath;
};

inline bool operator==(const RecentProject &lhs, const RecentProject &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_fileName == rhs.m_fileName && lhs.m_rootPath == rhs.m_rootPath;
}

inline uint qHash(const RecentProject &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_fileName, seed);
    hash ^= ::qHash(entity.m_rootPath, seed);

    return hash;
}

/// Schema for RecentProject entity
inline Qleany::Entities::EntitySchema RecentProject::schema = {QleanyEditor::Entities::Entities::EntityEnum::RecentProject,
                                                               "RecentProject"_L1,

                                                               // relationships:
                                                               {{QleanyEditor::Entities::Entities::EntityEnum::Root,
                                                                 "Root"_L1,
                                                                 QleanyEditor::Entities::Entities::EntityEnum::RecentProject,
                                                                 "RecentProject"_L1,
                                                                 "recentProjects"_L1,
                                                                 RelationshipType::OneToMany,
                                                                 RelationshipStrength::Strong,
                                                                 RelationshipCardinality::ManyUnordered,
                                                                 RelationshipDirection::Backward}},

                                                               // fields:
                                                               {{"id"_L1, FieldType::Integer, true, false},
                                                                {"uuid"_L1, FieldType::Uuid, false, false},
                                                                {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                {"fileName"_L1, FieldType::String, false, false},
                                                                {"rootPath"_L1, FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::RecentProject)