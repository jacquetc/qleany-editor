// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/entity_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::Entity;

namespace QleanyEditor::Contracts::DTO::Repository
{
using namespace Qt::Literals::StringLiterals;

class CreateRepositoryDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString entityName READ entityName WRITE setEntityName)
    Q_PROPERTY(bool lazyLoaders READ lazyLoaders WRITE setLazyLoaders)
    Q_PROPERTY(EntityDTO entity READ entity WRITE setEntity)
    Q_PROPERTY(int repositoryComponentId READ repositoryComponentId WRITE setRepositoryComponentId)
    Q_PROPERTY(int position READ position WRITE setPosition)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool entityNameSet = false;
        bool lazyLoadersSet = false;
        bool entitySet = false;
        bool repositoryComponentIdSet = false;
        bool positionSet = false;
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "uuid"_L1) {
                return uuidSet;
            }
            if (fieldName == "creationDate"_L1) {
                return creationDateSet;
            }
            if (fieldName == "updateDate"_L1) {
                return updateDateSet;
            }
            if (fieldName == "entityName"_L1) {
                return entityNameSet;
            }
            if (fieldName == "lazyLoaders"_L1) {
                return lazyLoadersSet;
            }
            if (fieldName == "entity"_L1) {
                return entitySet;
            }
            if (fieldName == "repositoryComponentId"_L1) {
                return repositoryComponentIdSet;
            }
            if (fieldName == "position"_L1) {
                return positionSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (entitySet)
                return true;

            return false;
        }
    };

    CreateRepositoryDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_entityName(QString())
        , m_lazyLoaders(false)
        , m_repositoryComponentId(0)
        , m_position(0)
    {
    }

    ~CreateRepositoryDTO()
    {
    }

    CreateRepositoryDTO(const QUuid &uuid,
                        const QDateTime &creationDate,
                        const QDateTime &updateDate,
                        const QString &entityName,
                        bool lazyLoaders,
                        const EntityDTO &entity,
                        int repositoryComponentId,
                        int position)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_entityName(entityName)
        , m_lazyLoaders(lazyLoaders)
        , m_entity(entity)
        , m_repositoryComponentId(repositoryComponentId)
        , m_position(position)
    {
    }

    CreateRepositoryDTO(const CreateRepositoryDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_entityName(other.m_entityName)
        , m_lazyLoaders(other.m_lazyLoaders)
        , m_entity(other.m_entity)
        , m_repositoryComponentId(other.m_repositoryComponentId)
        , m_position(other.m_position)
    {
    }

    CreateRepositoryDTO &operator=(const CreateRepositoryDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_entityName = other.m_entityName;
            m_lazyLoaders = other.m_lazyLoaders;
            m_entity = other.m_entity;
            m_repositoryComponentId = other.m_repositoryComponentId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreateRepositoryDTO &operator=(const CreateRepositoryDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_entityName = other.m_entityName;
            m_lazyLoaders = other.m_lazyLoaders;
            m_entity = other.m_entity;
            m_repositoryComponentId = other.m_repositoryComponentId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreateRepositoryDTO &mergeWith(const CreateRepositoryDTO &other)
    {
        if (this != &other) {
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
            if (other.m_metaData.entityNameSet) {
                m_entityName = other.m_entityName;
                m_metaData.entityNameSet = true;
            }
            if (other.m_metaData.lazyLoadersSet) {
                m_lazyLoaders = other.m_lazyLoaders;
                m_metaData.lazyLoadersSet = true;
            }
            if (other.m_metaData.entitySet) {
                m_entity = other.m_entity;
                m_metaData.entitySet = true;
            }
            if (other.m_metaData.repositoryComponentIdSet) {
                m_repositoryComponentId = other.m_repositoryComponentId;
                m_metaData.repositoryComponentIdSet = true;
            }
            if (other.m_metaData.positionSet) {
                m_position = other.m_position;
                m_metaData.positionSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateRepositoryDTO &operator<<(const CreateRepositoryDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateRepositoryDTO &lhs, const CreateRepositoryDTO &rhs);

    friend uint qHash(const CreateRepositoryDTO &dto, uint seed) noexcept;

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

    // ------ entityName : -----

    QString entityName() const
    {
        return m_entityName;
    }

    void setEntityName(const QString &entityName)
    {
        m_entityName = entityName;
        m_metaData.entityNameSet = true;
    }

    // ------ lazyLoaders : -----

    bool lazyLoaders() const
    {
        return m_lazyLoaders;
    }

    void setLazyLoaders(bool lazyLoaders)
    {
        m_lazyLoaders = lazyLoaders;
        m_metaData.lazyLoadersSet = true;
    }

    // ------ entity : -----

    EntityDTO entity() const
    {
        return m_entity;
    }

    void setEntity(const EntityDTO &entity)
    {
        m_entity = entity;
        m_metaData.entitySet = true;
    }

    // ------ repositoryComponentId : -----

    int repositoryComponentId() const
    {
        return m_repositoryComponentId;
    }

    void setRepositoryComponentId(int repositoryComponentId)
    {
        m_repositoryComponentId = repositoryComponentId;
        m_metaData.repositoryComponentIdSet = true;
    }

    // ------ position : -----

    int position() const
    {
        return m_position;
    }

    void setPosition(int position)
    {
        m_position = position;
        m_metaData.positionSet = true;
    }

    MetaData metaData() const
    {
        return m_metaData;
    }

private:
    MetaData m_metaData;

    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
    QString m_entityName;
    bool m_lazyLoaders;
    EntityDTO m_entity;
    int m_repositoryComponentId;
    int m_position;
};

inline bool operator==(const CreateRepositoryDTO &lhs, const CreateRepositoryDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_entityName == rhs.m_entityName
        && lhs.m_lazyLoaders == rhs.m_lazyLoaders && lhs.m_entity == rhs.m_entity && lhs.m_repositoryComponentId == rhs.m_repositoryComponentId
        && lhs.m_position == rhs.m_position;
}

inline uint qHash(const CreateRepositoryDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_entityName, seed);
    hash ^= ::qHash(dto.m_lazyLoaders, seed);
    hash ^= ::qHash(dto.m_entity, seed);
    hash ^= ::qHash(dto.m_repositoryComponentId, seed);
    hash ^= ::qHash(dto.m_position, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Repository
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Repository::CreateRepositoryDTO)