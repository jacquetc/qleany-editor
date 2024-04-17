// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class RepositoryComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QList<Repository> repositories READ repositories WRITE setRepositories)

    Q_PROPERTY(QString repositoryFolderPath READ repositoryFolderPath WRITE setRepositoryFolderPath)

    Q_PROPERTY(QString baseFolderPath READ baseFolderPath WRITE setBaseFolderPath)

public:
    struct MetaData {
        MetaData(RepositoryComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(RepositoryComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->repositoriesSet = other.repositoriesSet;
            this->repositoriesLoaded = other.repositoriesLoaded;
        }

        bool repositoriesSet = false;
        bool repositoriesLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "repositories"_L1) {
                return repositoriesSet;
            }
            if (fieldName == "repositoryFolderPath"_L1) {
                return true;
            }
            if (fieldName == "baseFolderPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "repositories"_L1) {
                return repositoriesLoaded;
            }
            if (fieldName == "repositoryFolderPath"_L1) {
                return true;
            }
            if (fieldName == "baseFolderPath"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        RepositoryComponent *m_entity = nullptr;
    };

    RepositoryComponent()
        : CommonParent()
        , m_metaData(this)
        , m_repositoryFolderPath(QString())
        , m_baseFolderPath(QString())
    {
    }

    ~RepositoryComponent()
    {
    }

    RepositoryComponent(const int &id,
                        const QUuid &uuid,
                        const QDateTime &creationDate,
                        const QDateTime &updateDate,
                        const QList<Repository> &repositories,
                        const QString &repositoryFolderPath,
                        const QString &baseFolderPath)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_repositories(repositories)
        , m_repositoryFolderPath(repositoryFolderPath)
        , m_baseFolderPath(baseFolderPath)
    {
    }

    RepositoryComponent(const RepositoryComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_repositories(other.m_repositories)
        , m_repositoryFolderPath(other.m_repositoryFolderPath)
        , m_baseFolderPath(other.m_baseFolderPath)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::RepositoryComponent;
    }

    RepositoryComponent &operator=(const RepositoryComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_repositories = other.m_repositories;
            m_repositoryFolderPath = other.m_repositoryFolderPath;
            m_baseFolderPath = other.m_baseFolderPath;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const RepositoryComponent &lhs, const RepositoryComponent &rhs);

    friend uint qHash(const RepositoryComponent &entity, uint seed) noexcept;

    // ------ repositories : -----

    QList<Repository> repositories()
    {
        if (!m_metaData.repositoriesLoaded && m_repositoriesLoader) {
            m_repositories = m_repositoriesLoader(this->id());
            m_metaData.repositoriesLoaded = true;
        }
        return m_repositories;
    }

    void setRepositories(const QList<Repository> &repositories)
    {
        m_repositories = repositories;

        m_metaData.repositoriesSet = true;
    }

    using RepositoriesLoader = std::function<QList<Repository>(int entityId)>;

    void setRepositoriesLoader(const RepositoriesLoader &loader)
    {
        m_repositoriesLoader = loader;
    }

    // ------ repositoryFolderPath : -----

    QString repositoryFolderPath() const
    {
        return m_repositoryFolderPath;
    }

    void setRepositoryFolderPath(const QString &repositoryFolderPath)
    {
        m_repositoryFolderPath = repositoryFolderPath;
    }

    // ------ baseFolderPath : -----

    QString baseFolderPath() const
    {
        return m_baseFolderPath;
    }

    void setBaseFolderPath(const QString &baseFolderPath)
    {
        m_baseFolderPath = baseFolderPath;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QList<Repository> m_repositories;
    RepositoriesLoader m_repositoriesLoader;
    QString m_repositoryFolderPath;
    QString m_baseFolderPath;
};

inline bool operator==(const RepositoryComponent &lhs, const RepositoryComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_repositories == rhs.m_repositories && lhs.m_repositoryFolderPath == rhs.m_repositoryFolderPath && lhs.m_baseFolderPath == rhs.m_baseFolderPath;
}

inline uint qHash(const RepositoryComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_repositories, seed);
    hash ^= ::qHash(entity.m_repositoryFolderPath, seed);
    hash ^= ::qHash(entity.m_baseFolderPath, seed);

    return hash;
}

/// Schema for RepositoryComponent entity
inline Qleany::Entities::EntitySchema RepositoryComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::RepositoryComponent,
                                                                     "RepositoryComponent"_L1,

                                                                     // relationships:
                                                                     {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                       "Project"_L1,
                                                                       QleanyEditor::Entities::Entities::EntityEnum::RepositoryComponent,
                                                                       "RepositoryComponent"_L1,
                                                                       "repositoryComponent"_L1,
                                                                       RelationshipType::OneToOne,
                                                                       RelationshipStrength::Strong,
                                                                       RelationshipCardinality::One,
                                                                       RelationshipDirection::Backward},
                                                                      {QleanyEditor::Entities::Entities::EntityEnum::RepositoryComponent,
                                                                       "RepositoryComponent"_L1,
                                                                       QleanyEditor::Entities::Entities::EntityEnum::Repository,
                                                                       "Repository"_L1,
                                                                       "repositories"_L1,
                                                                       RelationshipType::OneToMany,
                                                                       RelationshipStrength::Strong,
                                                                       RelationshipCardinality::ManyOrdered,
                                                                       RelationshipDirection::Forward}},

                                                                     // fields:
                                                                     {{"id"_L1, FieldType::Integer, true, false},
                                                                      {"uuid"_L1, FieldType::Uuid, false, false},
                                                                      {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                      {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                      {"repositories"_L1, FieldType::Entity, false, true},
                                                                      {"repositoryFolderPath"_L1, FieldType::String, false, false},
                                                                      {"baseFolderPath"_L1, FieldType::String, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::RepositoryComponent)