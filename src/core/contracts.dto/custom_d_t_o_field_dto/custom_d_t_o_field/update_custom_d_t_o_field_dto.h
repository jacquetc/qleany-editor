// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

namespace QleanyEditor::Contracts::DTO::CustomDTOField
{
using namespace Qt::Literals::StringLiterals;

class UpdateCustomDTOFieldDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString type READ type WRITE setType)
    Q_PROPERTY(QString name READ name WRITE setName)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool typeSet = false;
        bool nameSet = false;
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
            if (fieldName == "type"_L1) {
                return typeSet;
            }
            if (fieldName == "name"_L1) {
                return nameSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    UpdateCustomDTOFieldDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_type(QString())
        , m_name(QString())
    {
    }

    ~UpdateCustomDTOFieldDTO()
    {
    }

    UpdateCustomDTOFieldDTO(int id, const QUuid &uuid, const QDateTime &creationDate, const QDateTime &updateDate, const QString &type, const QString &name)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_type(type)
        , m_name(name)
    {
    }

    UpdateCustomDTOFieldDTO(const UpdateCustomDTOFieldDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_type(other.m_type)
        , m_name(other.m_name)
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

    UpdateCustomDTOFieldDTO &operator=(const UpdateCustomDTOFieldDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_type = other.m_type;
            m_name = other.m_name;
        }
        return *this;
    }

    UpdateCustomDTOFieldDTO &operator=(const UpdateCustomDTOFieldDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_type = other.m_type;
            m_name = other.m_name;
        }
        return *this;
    }

    UpdateCustomDTOFieldDTO &mergeWith(const UpdateCustomDTOFieldDTO &other)
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
            if (other.m_metaData.typeSet) {
                m_type = other.m_type;
                m_metaData.typeSet = true;
            }
            if (other.m_metaData.nameSet) {
                m_name = other.m_name;
                m_metaData.nameSet = true;
            }
        }
        return *this;
    }

    // import operator
    UpdateCustomDTOFieldDTO &operator<<(const UpdateCustomDTOFieldDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const UpdateCustomDTOFieldDTO &lhs, const UpdateCustomDTOFieldDTO &rhs);

    friend uint qHash(const UpdateCustomDTOFieldDTO &dto, uint seed) noexcept;

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

    // ------ type : -----

    QString type() const
    {
        return m_type;
    }

    void setType(const QString &type)
    {
        m_type = type;
        m_metaData.typeSet = true;
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
    QString m_type;
    QString m_name;
};

inline bool operator==(const UpdateCustomDTOFieldDTO &lhs, const UpdateCustomDTOFieldDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_type == rhs.m_type && lhs.m_name == rhs.m_name;
}

inline uint qHash(const UpdateCustomDTOFieldDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_type, seed);
    hash ^= ::qHash(dto.m_name, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::CustomDTOField
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::CustomDTOField::UpdateCustomDTOFieldDTO)