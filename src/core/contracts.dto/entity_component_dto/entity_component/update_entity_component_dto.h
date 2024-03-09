// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/entity_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::Entity;

namespace QleanyEditor::Contracts::DTO::EntityComponent
{
using namespace Qt::Literals::StringLiterals;

class UpdateEntityComponentDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString relativeFolderPath READ relativeFolderPath WRITE setRelativeFolderPath)
    Q_PROPERTY(QList<EntityDTO> entities READ entities WRITE setEntities)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool relativeFolderPathSet = false;
        bool entitiesSet = false;
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "id"_L1) {
                return idSet;
            }
            if (fieldName == "uuid"_L1) {
                return uuidSet;
            }
            if (fieldName == "creationDate"_L1) {
                return creationDateSet;
            }
            if (fieldName == "updateDate"_L1) {
                return updateDateSet;
            }
            if (fieldName == "relativeFolderPath"_L1) {
                return relativeFolderPathSet;
            }
            if (fieldName == "entities"_L1) {
                return entitiesSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (entitiesSet)
                return true;

            return false;
        }
    };

    UpdateEntityComponentDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_relativeFolderPath(QString())
    {
    }

    ~UpdateEntityComponentDTO()
    {
    }

    UpdateEntityComponentDTO(int id,
                             const QUuid &uuid,
                             const QDateTime &creationDate,
                             const QDateTime &updateDate,
                             const QString &relativeFolderPath,
                             const QList<EntityDTO> &entities)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_relativeFolderPath(relativeFolderPath)
        , m_entities(entities)
    {
    }

    UpdateEntityComponentDTO(const UpdateEntityComponentDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_relativeFolderPath(other.m_relativeFolderPath)
        , m_entities(other.m_entities)
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

    UpdateEntityComponentDTO &operator=(const UpdateEntityComponentDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_relativeFolderPath = other.m_relativeFolderPath;
            m_entities = other.m_entities;
        }
        return *this;
    }

    UpdateEntityComponentDTO &operator=(const UpdateEntityComponentDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_relativeFolderPath = other.m_relativeFolderPath;
            m_entities = other.m_entities;
        }
        return *this;
    }

    UpdateEntityComponentDTO &mergeWith(const UpdateEntityComponentDTO &other)
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
            if (other.m_metaData.relativeFolderPathSet) {
                m_relativeFolderPath = other.m_relativeFolderPath;
                m_metaData.relativeFolderPathSet = true;
            }
            if (other.m_metaData.entitiesSet) {
                m_entities = other.m_entities;
                m_metaData.entitiesSet = true;
            }
        }
        return *this;
    }

    // import operator
    UpdateEntityComponentDTO &operator<<(const UpdateEntityComponentDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const UpdateEntityComponentDTO &lhs, const UpdateEntityComponentDTO &rhs);

    friend uint qHash(const UpdateEntityComponentDTO &dto, uint seed) noexcept;

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

    // ------ relativeFolderPath : -----

    QString relativeFolderPath() const
    {
        return m_relativeFolderPath;
    }

    void setRelativeFolderPath(const QString &relativeFolderPath)
    {
        m_relativeFolderPath = relativeFolderPath;
        m_metaData.relativeFolderPathSet = true;
    }

    // ------ entities : -----

    QList<EntityDTO> entities() const
    {
        return m_entities;
    }

    void setEntities(const QList<EntityDTO> &entities)
    {
        m_entities = entities;
        m_metaData.entitiesSet = true;
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
    QString m_relativeFolderPath;
    QList<EntityDTO> m_entities;
};

inline bool operator==(const UpdateEntityComponentDTO &lhs, const UpdateEntityComponentDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_relativeFolderPath == rhs.m_relativeFolderPath && lhs.m_entities == rhs.m_entities;
}

inline uint qHash(const UpdateEntityComponentDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_relativeFolderPath, seed);
    hash ^= ::qHash(dto.m_entities, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::EntityComponent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::EntityComponent::UpdateEntityComponentDTO)