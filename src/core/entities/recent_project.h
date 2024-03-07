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
        }

        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("fileName")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("rootPath")) {
                return true;
            }
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("fileName")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("rootPath")) {
                return true;
            }
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        RecentProject *m_entity = nullptr;
    };

    RecentProject()
        : CommonParent()
        , m_fileName(QString())
        , m_rootPath(QString())
        , m_metaData(this)
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
        , m_fileName(fileName)
        , m_rootPath(rootPath)
        , m_metaData(this)
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
                                                               QString::fromUtf8("RecentProject"),

                                                               // relationships:
                                                               {{QleanyEditor::Entities::Entities::EntityEnum::Root,
                                                                 QString::fromUtf8("Root"),
                                                                 QleanyEditor::Entities::Entities::EntityEnum::RecentProject,
                                                                 QString::fromUtf8("RecentProject"),
                                                                 QString::fromUtf8("recentProjects"),
                                                                 RelationshipType::OneToMany,
                                                                 RelationshipStrength::Strong,
                                                                 RelationshipCardinality::ManyUnordered,
                                                                 RelationshipDirection::Backward}},

                                                               // fields:
                                                               {{QString::fromUtf8("id"), FieldType::Integer, true, false},
                                                                {QString::fromUtf8("uuid"), FieldType::Uuid, false, false},
                                                                {QString::fromUtf8("creationDate"), FieldType::DateTime, false, false},
                                                                {QString::fromUtf8("updateDate"), FieldType::DateTime, false, false},
                                                                {QString::fromUtf8("fileName"), FieldType::String, false, false},
                                                                {QString::fromUtf8("rootPath"), FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::RecentProject)