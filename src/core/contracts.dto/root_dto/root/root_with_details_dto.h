// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project/project_dto.h"
#include "recent_project/recent_project_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::RecentProject;
using namespace QleanyEditor::Contracts::DTO::Project;

namespace QleanyEditor::Contracts::DTO::Root
{

class RootWithDetailsDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString content READ content WRITE setContent)
    Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath)
    Q_PROPERTY(QList<RecentProjectDTO> recentProjects READ recentProjects WRITE setRecentProjects)
    Q_PROPERTY(ProjectDTO project READ project WRITE setProject)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool contentSet = false;
        bool rootPathSet = false;
        bool recentProjectsSet = false;
        bool projectSet = false;
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("id")) {
                return idSet;
            }
            if (fieldName == QString::fromUtf8("uuid")) {
                return uuidSet;
            }
            if (fieldName == QString::fromUtf8("creationDate")) {
                return creationDateSet;
            }
            if (fieldName == QString::fromUtf8("updateDate")) {
                return updateDateSet;
            }
            if (fieldName == QString::fromUtf8("content")) {
                return contentSet;
            }
            if (fieldName == QString::fromUtf8("rootPath")) {
                return rootPathSet;
            }
            if (fieldName == QString::fromUtf8("recentProjects")) {
                return recentProjectsSet;
            }
            if (fieldName == QString::fromUtf8("project")) {
                return projectSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (recentProjectsSet)
                return true;

            if (projectSet)
                return true;

            return false;
        }
    };

    RootWithDetailsDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_content(QString())
        , m_rootPath(QString())
    {
    }

    ~RootWithDetailsDTO()
    {
    }

    RootWithDetailsDTO(int id,
                       const QUuid &uuid,
                       const QDateTime &creationDate,
                       const QDateTime &updateDate,
                       const QString &content,
                       const QString &rootPath,
                       const QList<RecentProjectDTO> &recentProjects,
                       const ProjectDTO &project)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_content(content)
        , m_rootPath(rootPath)
        , m_recentProjects(recentProjects)
        , m_project(project)
    {
    }

    RootWithDetailsDTO(const RootWithDetailsDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_content(other.m_content)
        , m_rootPath(other.m_rootPath)
        , m_recentProjects(other.m_recentProjects)
        , m_project(other.m_project)
    {
    }

    Q_INVOKABLE bool isValid() const
    {
        return m_id > 0;
    }

    Q_INVOKABLE bool isNull() const
    {
        return !isValid();
    }

    Q_INVOKABLE bool isInvalid() const
    {
        return !isValid();
    }

    RootWithDetailsDTO &operator=(const RootWithDetailsDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_content = other.m_content;
            m_rootPath = other.m_rootPath;
            m_recentProjects = other.m_recentProjects;
            m_project = other.m_project;
        }
        return *this;
    }

    RootWithDetailsDTO &operator=(const RootWithDetailsDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_content = other.m_content;
            m_rootPath = other.m_rootPath;
            m_recentProjects = other.m_recentProjects;
            m_project = other.m_project;
        }
        return *this;
    }

    RootWithDetailsDTO &mergeWith(const RootWithDetailsDTO &other)
    {
        if (this != &other) {
            if (other.m_metaData.idSet) {
                m_id = other.m_id;
                m_metaData.idSet = true;
            }
            if (other.m_metaData.uuidSet) {
                m_uuid = other.m_uuid;
                m_metaData.uuidSet = true;
            }
            if (other.m_metaData.creationDateSet) {
                m_creationDate = other.m_creationDate;
                m_metaData.creationDateSet = true;
            }
            if (other.m_metaData.updateDateSet) {
                m_updateDate = other.m_updateDate;
                m_metaData.updateDateSet = true;
            }
            if (other.m_metaData.contentSet) {
                m_content = other.m_content;
                m_metaData.contentSet = true;
            }
            if (other.m_metaData.rootPathSet) {
                m_rootPath = other.m_rootPath;
                m_metaData.rootPathSet = true;
            }
            if (other.m_metaData.recentProjectsSet) {
                m_recentProjects = other.m_recentProjects;
                m_metaData.recentProjectsSet = true;
            }
            if (other.m_metaData.projectSet) {
                m_project = other.m_project;
                m_metaData.projectSet = true;
            }
        }
        return *this;
    }

    // import operator
    RootWithDetailsDTO &operator<<(const RootWithDetailsDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const RootWithDetailsDTO &lhs, const RootWithDetailsDTO &rhs);

    friend uint qHash(const RootWithDetailsDTO &dto, uint seed) noexcept;

    // ------ id : -----

    int id() const
    {
        return m_id;
    }

    void setId(int id)
    {
        m_id = id;
        m_metaData.idSet = true;
    }

    // ------ uuid : -----

    QUuid uuid() const
    {
        return m_uuid;
    }

    void setUuid(const QUuid &uuid)
    {
        m_uuid = uuid;
        m_metaData.uuidSet = true;
    }

    // ------ creationDate : -----

    QDateTime creationDate() const
    {
        return m_creationDate;
    }

    void setCreationDate(const QDateTime &creationDate)
    {
        m_creationDate = creationDate;
        m_metaData.creationDateSet = true;
    }

    // ------ updateDate : -----

    QDateTime updateDate() const
    {
        return m_updateDate;
    }

    void setUpdateDate(const QDateTime &updateDate)
    {
        m_updateDate = updateDate;
        m_metaData.updateDateSet = true;
    }

    // ------ content : -----

    QString content() const
    {
        return m_content;
    }

    void setContent(const QString &content)
    {
        m_content = content;
        m_metaData.contentSet = true;
    }

    // ------ rootPath : -----

    QString rootPath() const
    {
        return m_rootPath;
    }

    void setRootPath(const QString &rootPath)
    {
        m_rootPath = rootPath;
        m_metaData.rootPathSet = true;
    }

    // ------ recentProjects : -----

    QList<RecentProjectDTO> recentProjects() const
    {
        return m_recentProjects;
    }

    void setRecentProjects(const QList<RecentProjectDTO> &recentProjects)
    {
        m_recentProjects = recentProjects;
        m_metaData.recentProjectsSet = true;
    }

    // ------ project : -----

    ProjectDTO project() const
    {
        return m_project;
    }

    void setProject(const ProjectDTO &project)
    {
        m_project = project;
        m_metaData.projectSet = true;
    }

    MetaData metaData() const
    {
        return m_metaData;
    }

private:
    MetaData m_metaData;

    int m_id;
    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
    QString m_content;
    QString m_rootPath;
    QList<RecentProjectDTO> m_recentProjects;
    ProjectDTO m_project;
};

inline bool operator==(const RootWithDetailsDTO &lhs, const RootWithDetailsDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_content == rhs.m_content && lhs.m_rootPath == rhs.m_rootPath && lhs.m_recentProjects == rhs.m_recentProjects && lhs.m_project == rhs.m_project;
}

inline uint qHash(const RootWithDetailsDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_content, seed);
    hash ^= ::qHash(dto.m_rootPath, seed);
    hash ^= ::qHash(dto.m_recentProjects, seed);
    hash ^= ::qHash(dto.m_project, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Root
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Root::RootWithDetailsDTO)