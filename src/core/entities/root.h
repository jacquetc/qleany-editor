// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project.h"
#include "recent_project.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class Root : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString content READ content WRITE setContent)

    Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath)

    Q_PROPERTY(QList<RecentProject> recentProjects READ recentProjects WRITE setRecentProjects)

    Q_PROPERTY(Project project READ project WRITE setProject)

public:
    struct MetaData {
        MetaData(Root *entity)
            : m_entity(entity)
        {
        }
        MetaData(Root *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->recentProjectsSet = other.recentProjectsSet;
            this->recentProjectsLoaded = other.recentProjectsLoaded;
            this->projectSet = other.projectSet;
            this->projectLoaded = other.projectLoaded;
        }

        bool recentProjectsSet = false;
        bool recentProjectsLoaded = false;

        bool projectSet = false;
        bool projectLoaded = false;

        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("content")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("rootPath")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("recentProjects")) {
                return recentProjectsSet;
            }
            if (fieldName == QString::fromUtf8("project")) {
                return projectSet;
            }
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("content")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("rootPath")) {
                return true;
            }
            if (fieldName == QString::fromUtf8("recentProjects")) {
                return recentProjectsLoaded;
            }
            if (fieldName == QString::fromUtf8("project")) {
                return projectLoaded;
            }
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        Root *m_entity = nullptr;
    };

    Root()
        : CommonParent()
        , m_content(QString())
        , m_rootPath(QString())
        , m_metaData(this)
    {
    }

    ~Root()
    {
    }

    Root(const int &id,
         const QUuid &uuid,
         const QDateTime &creationDate,
         const QDateTime &updateDate,
         const QString &content,
         const QString &rootPath,
         const QList<RecentProject> &recentProjects,
         const Project &project)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_content(content)
        , m_rootPath(rootPath)
        , m_recentProjects(recentProjects)
        , m_project(project)
        , m_metaData(this)
    {
    }

    Root(const Root &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_content(other.m_content)
        , m_rootPath(other.m_rootPath)
        , m_recentProjects(other.m_recentProjects)
        , m_project(other.m_project)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::Root;
    }

    Root &operator=(const Root &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_content = other.m_content;
            m_rootPath = other.m_rootPath;
            m_recentProjects = other.m_recentProjects;
            m_project = other.m_project;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const Root &lhs, const Root &rhs);

    friend uint qHash(const Root &entity, uint seed) noexcept;

    // ------ content : -----

    QString content() const
    {
        return m_content;
    }

    void setContent(const QString &content)
    {
        m_content = content;
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

    // ------ recentProjects : -----

    QList<RecentProject> recentProjects()
    {
        if (!m_metaData.recentProjectsLoaded && m_recentProjectsLoader) {
            m_recentProjects = m_recentProjectsLoader(this->id());
            m_metaData.recentProjectsLoaded = true;
        }
        return m_recentProjects;
    }

    void setRecentProjects(const QList<RecentProject> &recentProjects)
    {
        m_recentProjects = recentProjects;

        m_metaData.recentProjectsSet = true;
    }

    using RecentProjectsLoader = std::function<QList<RecentProject>(int entityId)>;

    void setRecentProjectsLoader(const RecentProjectsLoader &loader)
    {
        m_recentProjectsLoader = loader;
    }

    // ------ project : -----

    Project project()
    {
        if (!m_metaData.projectLoaded && m_projectLoader) {
            m_project = m_projectLoader(this->id());
            m_metaData.projectLoaded = true;
        }
        return m_project;
    }

    void setProject(const Project &project)
    {
        m_project = project;

        m_metaData.projectSet = true;
    }

    using ProjectLoader = std::function<Project(int entityId)>;

    void setProjectLoader(const ProjectLoader &loader)
    {
        m_projectLoader = loader;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_content;
    QString m_rootPath;
    QList<RecentProject> m_recentProjects;
    RecentProjectsLoader m_recentProjectsLoader;
    Project m_project;
    ProjectLoader m_projectLoader;
};

inline bool operator==(const Root &lhs, const Root &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_content == rhs.m_content && lhs.m_rootPath == rhs.m_rootPath && lhs.m_recentProjects == rhs.m_recentProjects && lhs.m_project == rhs.m_project;
}

inline uint qHash(const Root &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_content, seed);
    hash ^= ::qHash(entity.m_rootPath, seed);
    hash ^= ::qHash(entity.m_recentProjects, seed);
    hash ^= ::qHash(entity.m_project, seed);

    return hash;
}

/// Schema for Root entity
inline Qleany::Entities::EntitySchema Root::schema = {QleanyEditor::Entities::Entities::EntityEnum::Root,
                                                      QString::fromUtf8("Root"),

                                                      // relationships:
                                                      {{QleanyEditor::Entities::Entities::EntityEnum::Root,
                                                        QString::fromUtf8("Root"),
                                                        QleanyEditor::Entities::Entities::EntityEnum::RecentProject,
                                                        QString::fromUtf8("RecentProject"),
                                                        QString::fromUtf8("recentProjects"),
                                                        RelationshipType::OneToMany,
                                                        RelationshipStrength::Strong,
                                                        RelationshipCardinality::ManyUnordered,
                                                        RelationshipDirection::Forward},
                                                       {QleanyEditor::Entities::Entities::EntityEnum::Root,
                                                        QString::fromUtf8("Root"),
                                                        QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                        QString::fromUtf8("Project"),
                                                        QString::fromUtf8("project"),
                                                        RelationshipType::OneToOne,
                                                        RelationshipStrength::Strong,
                                                        RelationshipCardinality::One,
                                                        RelationshipDirection::Forward}},

                                                      // fields:
                                                      {{QString::fromUtf8("id"), FieldType::Integer, true, false},
                                                       {QString::fromUtf8("uuid"), FieldType::Uuid, false, false},
                                                       {QString::fromUtf8("creationDate"), FieldType::DateTime, false, false},
                                                       {QString::fromUtf8("updateDate"), FieldType::DateTime, false, false},
                                                       {QString::fromUtf8("content"), FieldType::String, false, false},
                                                       {QString::fromUtf8("rootPath"), FieldType::String, false, false},
                                                       {QString::fromUtf8("recentProjects"), FieldType::Entity, false, true},
                                                       {QString::fromUtf8("project"), FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::Root)