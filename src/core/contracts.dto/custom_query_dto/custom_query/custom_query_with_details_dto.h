// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/custom_d_t_o_dto.h"
#include "entity/entity_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::DTO::CustomDTO;
using namespace QleanyEditor::Contracts::DTO::CustomDTO;

namespace QleanyEditor::Contracts::DTO::CustomQuery
{
using namespace Qt::Literals::StringLiterals;

class CustomQueryWithDetailsDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QList<EntityDTO> entities READ entities WRITE setEntities)
    Q_PROPERTY(bool validator READ validator WRITE setValidator)
    Q_PROPERTY(bool undo READ undo WRITE setUndo)
    Q_PROPERTY(CustomDTODTO dtoIn READ dtoIn WRITE setDtoIn)
    Q_PROPERTY(CustomDTODTO dtoOut READ dtoOut WRITE setDtoOut)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool nameSet = false;
        bool entitiesSet = false;
        bool validatorSet = false;
        bool undoSet = false;
        bool dtoInSet = false;
        bool dtoOutSet = false;
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
            if (fieldName == "name"_L1) {
                return nameSet;
            }
            if (fieldName == "entities"_L1) {
                return entitiesSet;
            }
            if (fieldName == "validator"_L1) {
                return validatorSet;
            }
            if (fieldName == "undo"_L1) {
                return undoSet;
            }
            if (fieldName == "dtoIn"_L1) {
                return dtoInSet;
            }
            if (fieldName == "dtoOut"_L1) {
                return dtoOutSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (entitiesSet)
                return true;

            if (dtoInSet)
                return true;

            if (dtoOutSet)
                return true;

            return false;
        }
    };

    CustomQueryWithDetailsDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_name(QString())
        , m_validator(false)
        , m_undo(false)
    {
    }

    ~CustomQueryWithDetailsDTO()
    {
    }

    CustomQueryWithDetailsDTO(int id,
                              const QUuid &uuid,
                              const QDateTime &creationDate,
                              const QDateTime &updateDate,
                              const QString &name,
                              const QList<EntityDTO> &entities,
                              bool validator,
                              bool undo,
                              const CustomDTODTO &dtoIn,
                              const CustomDTODTO &dtoOut)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_name(name)
        , m_entities(entities)
        , m_validator(validator)
        , m_undo(undo)
        , m_dtoIn(dtoIn)
        , m_dtoOut(dtoOut)
    {
    }

    CustomQueryWithDetailsDTO(const CustomQueryWithDetailsDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_name(other.m_name)
        , m_entities(other.m_entities)
        , m_validator(other.m_validator)
        , m_undo(other.m_undo)
        , m_dtoIn(other.m_dtoIn)
        , m_dtoOut(other.m_dtoOut)
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

    CustomQueryWithDetailsDTO &operator=(const CustomQueryWithDetailsDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_entities = other.m_entities;
            m_validator = other.m_validator;
            m_undo = other.m_undo;
            m_dtoIn = other.m_dtoIn;
            m_dtoOut = other.m_dtoOut;
        }
        return *this;
    }

    CustomQueryWithDetailsDTO &operator=(const CustomQueryWithDetailsDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_name = other.m_name;
            m_entities = other.m_entities;
            m_validator = other.m_validator;
            m_undo = other.m_undo;
            m_dtoIn = other.m_dtoIn;
            m_dtoOut = other.m_dtoOut;
        }
        return *this;
    }

    CustomQueryWithDetailsDTO &mergeWith(const CustomQueryWithDetailsDTO &other)
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
            if (other.m_metaData.nameSet) {
                m_name = other.m_name;
                m_metaData.nameSet = true;
            }
            if (other.m_metaData.entitiesSet) {
                m_entities = other.m_entities;
                m_metaData.entitiesSet = true;
            }
            if (other.m_metaData.validatorSet) {
                m_validator = other.m_validator;
                m_metaData.validatorSet = true;
            }
            if (other.m_metaData.undoSet) {
                m_undo = other.m_undo;
                m_metaData.undoSet = true;
            }
            if (other.m_metaData.dtoInSet) {
                m_dtoIn = other.m_dtoIn;
                m_metaData.dtoInSet = true;
            }
            if (other.m_metaData.dtoOutSet) {
                m_dtoOut = other.m_dtoOut;
                m_metaData.dtoOutSet = true;
            }
        }
        return *this;
    }

    // import operator
    CustomQueryWithDetailsDTO &operator<<(const CustomQueryWithDetailsDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CustomQueryWithDetailsDTO &lhs, const CustomQueryWithDetailsDTO &rhs);

    friend uint qHash(const CustomQueryWithDetailsDTO &dto, uint seed) noexcept;

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

    // ------ validator : -----

    bool validator() const
    {
        return m_validator;
    }

    void setValidator(bool validator)
    {
        m_validator = validator;
        m_metaData.validatorSet = true;
    }

    // ------ undo : -----

    bool undo() const
    {
        return m_undo;
    }

    void setUndo(bool undo)
    {
        m_undo = undo;
        m_metaData.undoSet = true;
    }

    // ------ dtoIn : -----

    CustomDTODTO dtoIn() const
    {
        return m_dtoIn;
    }

    void setDtoIn(const CustomDTODTO &dtoIn)
    {
        m_dtoIn = dtoIn;
        m_metaData.dtoInSet = true;
    }

    // ------ dtoOut : -----

    CustomDTODTO dtoOut() const
    {
        return m_dtoOut;
    }

    void setDtoOut(const CustomDTODTO &dtoOut)
    {
        m_dtoOut = dtoOut;
        m_metaData.dtoOutSet = true;
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
    QString m_name;
    QList<EntityDTO> m_entities;
    bool m_validator;
    bool m_undo;
    CustomDTODTO m_dtoIn;
    CustomDTODTO m_dtoOut;
};

inline bool operator==(const CustomQueryWithDetailsDTO &lhs, const CustomQueryWithDetailsDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_name == rhs.m_name && lhs.m_entities == rhs.m_entities && lhs.m_validator == rhs.m_validator && lhs.m_undo == rhs.m_undo
        && lhs.m_dtoIn == rhs.m_dtoIn && lhs.m_dtoOut == rhs.m_dtoOut;
}

inline uint qHash(const CustomQueryWithDetailsDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_name, seed);
    hash ^= ::qHash(dto.m_entities, seed);
    hash ^= ::qHash(dto.m_validator, seed);
    hash ^= ::qHash(dto.m_undo, seed);
    hash ^= ::qHash(dto.m_dtoIn, seed);
    hash ^= ::qHash(dto.m_dtoOut, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::CustomQuery
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::CustomQuery::CustomQueryWithDetailsDTO)
