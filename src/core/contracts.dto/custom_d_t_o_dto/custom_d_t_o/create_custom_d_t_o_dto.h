// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field/custom_d_t_o_field_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::CustomDTOField;

namespace QleanyEditor::Contracts::DTO::CustomDTO
{
using namespace Qt::Literals::StringLiterals;

class CreateCustomDTODTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString typePrefix READ typePrefix WRITE setTypePrefix)
    Q_PROPERTY(QList<CustomDTOFieldDTO> fields READ fields WRITE setFields)
    Q_PROPERTY(int customCommandId READ customCommandId WRITE setCustomCommandId)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool typePrefixSet = false;
        bool fieldsSet = false;
        bool customCommandIdSet = false;
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
            if (fieldName == "typePrefix"_L1) {
                return typePrefixSet;
            }
            if (fieldName == "fields"_L1) {
                return fieldsSet;
            }
            if (fieldName == "customCommandId"_L1) {
                return customCommandIdSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (fieldsSet)
                return true;

            return false;
        }
    };

    CreateCustomDTODTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_typePrefix(QString())
        , m_customCommandId(0)
    {
    }

    ~CreateCustomDTODTO()
    {
    }

    CreateCustomDTODTO(const QUuid &uuid,
                       const QDateTime &creationDate,
                       const QDateTime &updateDate,
                       const QString &typePrefix,
                       const QList<CustomDTOFieldDTO> &fields,
                       int customCommandId)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_typePrefix(typePrefix)
        , m_fields(fields)
        , m_customCommandId(customCommandId)
    {
    }

    CreateCustomDTODTO(const CreateCustomDTODTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_typePrefix(other.m_typePrefix)
        , m_fields(other.m_fields)
        , m_customCommandId(other.m_customCommandId)
    {
    }

    CreateCustomDTODTO &operator=(const CreateCustomDTODTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_typePrefix = other.m_typePrefix;
            m_fields = other.m_fields;
            m_customCommandId = other.m_customCommandId;
        }
        return *this;
    }

    CreateCustomDTODTO &operator=(const CreateCustomDTODTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_typePrefix = other.m_typePrefix;
            m_fields = other.m_fields;
            m_customCommandId = other.m_customCommandId;
        }
        return *this;
    }

    CreateCustomDTODTO &mergeWith(const CreateCustomDTODTO &other)
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
            if (other.m_metaData.typePrefixSet) {
                m_typePrefix = other.m_typePrefix;
                m_metaData.typePrefixSet = true;
            }
            if (other.m_metaData.fieldsSet) {
                m_fields = other.m_fields;
                m_metaData.fieldsSet = true;
            }
            if (other.m_metaData.customCommandIdSet) {
                m_customCommandId = other.m_customCommandId;
                m_metaData.customCommandIdSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateCustomDTODTO &operator<<(const CreateCustomDTODTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateCustomDTODTO &lhs, const CreateCustomDTODTO &rhs);

    friend uint qHash(const CreateCustomDTODTO &dto, uint seed) noexcept;

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

    // ------ typePrefix : -----

    QString typePrefix() const
    {
        return m_typePrefix;
    }

    void setTypePrefix(const QString &typePrefix)
    {
        m_typePrefix = typePrefix;
        m_metaData.typePrefixSet = true;
    }

    // ------ fields : -----

    QList<CustomDTOFieldDTO> fields() const
    {
        return m_fields;
    }

    void setFields(const QList<CustomDTOFieldDTO> &fields)
    {
        m_fields = fields;
        m_metaData.fieldsSet = true;
    }

    // ------ customCommandId : -----

    int customCommandId() const
    {
        return m_customCommandId;
    }

    void setCustomCommandId(int customCommandId)
    {
        m_customCommandId = customCommandId;
        m_metaData.customCommandIdSet = true;
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
    QString m_typePrefix;
    QList<CustomDTOFieldDTO> m_fields;
    int m_customCommandId;
};

inline bool operator==(const CreateCustomDTODTO &lhs, const CreateCustomDTODTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_typePrefix == rhs.m_typePrefix
        && lhs.m_fields == rhs.m_fields && lhs.m_customCommandId == rhs.m_customCommandId;
}

inline uint qHash(const CreateCustomDTODTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_typePrefix, seed);
    hash ^= ::qHash(dto.m_fields, seed);
    hash ^= ::qHash(dto.m_customCommandId, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::CustomDTO
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::CustomDTO::CreateCustomDTODTO)
