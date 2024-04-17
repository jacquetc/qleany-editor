// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/c_r_u_d_dto.h"
#include "custom_command/custom_command_dto.h"
#include "custom_query/custom_query_dto.h"
#include "entity/entity_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::DTO::CRUD;
using namespace QleanyEditor::Contracts::DTO::CustomCommand;
using namespace QleanyEditor::Contracts::DTO::CustomQuery;

namespace QleanyEditor::Contracts::DTO::ApplicationFeature
{
using namespace Qt::Literals::StringLiterals;

class CreateApplicationFeatureDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(EntityDTO dtoIdenticalToEntity READ dtoIdenticalToEntity WRITE setDtoIdenticalToEntity)
    Q_PROPERTY(CRUDDTO crud READ crud WRITE setCrud)
    Q_PROPERTY(QList<CustomCommandDTO> customCommands READ customCommands WRITE setCustomCommands)
    Q_PROPERTY(QList<CustomQueryDTO> customQueries READ customQueries WRITE setCustomQueries)
    Q_PROPERTY(int applicationComponentId READ applicationComponentId WRITE setApplicationComponentId)
    Q_PROPERTY(int position READ position WRITE setPosition)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool nameSet = false;
        bool dtoIdenticalToEntitySet = false;
        bool crudSet = false;
        bool customCommandsSet = false;
        bool customQueriesSet = false;
        bool applicationComponentIdSet = false;
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
            if (fieldName == "name"_L1) {
                return nameSet;
            }
            if (fieldName == "dtoIdenticalToEntity"_L1) {
                return dtoIdenticalToEntitySet;
            }
            if (fieldName == "crud"_L1) {
                return crudSet;
            }
            if (fieldName == "customCommands"_L1) {
                return customCommandsSet;
            }
            if (fieldName == "customQueries"_L1) {
                return customQueriesSet;
            }
            if (fieldName == "applicationComponentId"_L1) {
                return applicationComponentIdSet;
            }
            if (fieldName == "position"_L1) {
                return positionSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (dtoIdenticalToEntitySet)
                return true;

            if (crudSet)
                return true;

            if (customCommandsSet)
                return true;

            if (customQueriesSet)
                return true;

            return false;
        }
    };

    CreateApplicationFeatureDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_name(QString())
        , m_applicationComponentId(0)
        , m_position(0)
    {
    }

    ~CreateApplicationFeatureDTO()
    {
    }

    CreateApplicationFeatureDTO(const QUuid &uuid,
                                const QDateTime &creationDate,
                                const QDateTime &updateDate,
                                const QString &name,
                                const EntityDTO &dtoIdenticalToEntity,
                                const CRUDDTO &crud,
                                const QList<CustomCommandDTO> &customCommands,
                                const QList<CustomQueryDTO> &customQueries,
                                int applicationComponentId,
                                int position)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_name(name)
        , m_dtoIdenticalToEntity(dtoIdenticalToEntity)
        , m_crud(crud)
        , m_customCommands(customCommands)
        , m_customQueries(customQueries)
        , m_applicationComponentId(applicationComponentId)
        , m_position(position)
    {
    }

    CreateApplicationFeatureDTO(const CreateApplicationFeatureDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_name(other.m_name)
        , m_dtoIdenticalToEntity(other.m_dtoIdenticalToEntity)
        , m_crud(other.m_crud)
        , m_customCommands(other.m_customCommands)
        , m_customQueries(other.m_customQueries)
        , m_applicationComponentId(other.m_applicationComponentId)
        , m_position(other.m_position)
    {
    }

    CreateApplicationFeatureDTO &operator=(const CreateApplicationFeatureDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_dtoIdenticalToEntity = other.m_dtoIdenticalToEntity;
            m_crud = other.m_crud;
            m_customCommands = other.m_customCommands;
            m_customQueries = other.m_customQueries;
            m_applicationComponentId = other.m_applicationComponentId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreateApplicationFeatureDTO &operator=(const CreateApplicationFeatureDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_dtoIdenticalToEntity = other.m_dtoIdenticalToEntity;
            m_crud = other.m_crud;
            m_customCommands = other.m_customCommands;
            m_customQueries = other.m_customQueries;
            m_applicationComponentId = other.m_applicationComponentId;
            m_position = other.m_position;
        }
        return *this;
    }

    CreateApplicationFeatureDTO &mergeWith(const CreateApplicationFeatureDTO &other)
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
            if (other.m_metaData.nameSet) {
                m_name = other.m_name;
                m_metaData.nameSet = true;
            }
            if (other.m_metaData.dtoIdenticalToEntitySet) {
                m_dtoIdenticalToEntity = other.m_dtoIdenticalToEntity;
                m_metaData.dtoIdenticalToEntitySet = true;
            }
            if (other.m_metaData.crudSet) {
                m_crud = other.m_crud;
                m_metaData.crudSet = true;
            }
            if (other.m_metaData.customCommandsSet) {
                m_customCommands = other.m_customCommands;
                m_metaData.customCommandsSet = true;
            }
            if (other.m_metaData.customQueriesSet) {
                m_customQueries = other.m_customQueries;
                m_metaData.customQueriesSet = true;
            }
            if (other.m_metaData.applicationComponentIdSet) {
                m_applicationComponentId = other.m_applicationComponentId;
                m_metaData.applicationComponentIdSet = true;
            }
            if (other.m_metaData.positionSet) {
                m_position = other.m_position;
                m_metaData.positionSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateApplicationFeatureDTO &operator<<(const CreateApplicationFeatureDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateApplicationFeatureDTO &lhs, const CreateApplicationFeatureDTO &rhs);

    friend uint qHash(const CreateApplicationFeatureDTO &dto, uint seed) noexcept;

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

    // ------ name : -----

    QString name() const
    {
        return m_name;
    }

    void setName(const QString &name)
    {
        m_name = name;
        m_metaData.nameSet = true;
    }

    // ------ dtoIdenticalToEntity : -----

    EntityDTO dtoIdenticalToEntity() const
    {
        return m_dtoIdenticalToEntity;
    }

    void setDtoIdenticalToEntity(const EntityDTO &dtoIdenticalToEntity)
    {
        m_dtoIdenticalToEntity = dtoIdenticalToEntity;
        m_metaData.dtoIdenticalToEntitySet = true;
    }

    // ------ crud : -----

    CRUDDTO crud() const
    {
        return m_crud;
    }

    void setCrud(const CRUDDTO &crud)
    {
        m_crud = crud;
        m_metaData.crudSet = true;
    }

    // ------ customCommands : -----

    QList<CustomCommandDTO> customCommands() const
    {
        return m_customCommands;
    }

    void setCustomCommands(const QList<CustomCommandDTO> &customCommands)
    {
        m_customCommands = customCommands;
        m_metaData.customCommandsSet = true;
    }

    // ------ customQueries : -----

    QList<CustomQueryDTO> customQueries() const
    {
        return m_customQueries;
    }

    void setCustomQueries(const QList<CustomQueryDTO> &customQueries)
    {
        m_customQueries = customQueries;
        m_metaData.customQueriesSet = true;
    }

    // ------ applicationComponentId : -----

    int applicationComponentId() const
    {
        return m_applicationComponentId;
    }

    void setApplicationComponentId(int applicationComponentId)
    {
        m_applicationComponentId = applicationComponentId;
        m_metaData.applicationComponentIdSet = true;
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
    QString m_name;
    EntityDTO m_dtoIdenticalToEntity;
    CRUDDTO m_crud;
    QList<CustomCommandDTO> m_customCommands;
    QList<CustomQueryDTO> m_customQueries;
    int m_applicationComponentId;
    int m_position;
};

inline bool operator==(const CreateApplicationFeatureDTO &lhs, const CreateApplicationFeatureDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_name == rhs.m_name
        && lhs.m_dtoIdenticalToEntity == rhs.m_dtoIdenticalToEntity && lhs.m_crud == rhs.m_crud && lhs.m_customCommands == rhs.m_customCommands
        && lhs.m_customQueries == rhs.m_customQueries && lhs.m_applicationComponentId == rhs.m_applicationComponentId && lhs.m_position == rhs.m_position;
}

inline uint qHash(const CreateApplicationFeatureDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_dtoIdenticalToEntity, seed);
    hash ^= ::qHash(dto.m_crud, seed);
    hash ^= ::qHash(dto.m_customCommands, seed);
    hash ^= ::qHash(dto.m_customQueries, seed);
    hash ^= ::qHash(dto.m_applicationComponentId, seed);
    hash ^= ::qHash(dto.m_position, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::ApplicationFeature
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::ApplicationFeature::CreateApplicationFeatureDTO)