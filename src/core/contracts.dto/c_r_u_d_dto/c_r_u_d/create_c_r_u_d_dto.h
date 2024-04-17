// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/entity_dto.h"
#include <QDateTime>
#include <QObject>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::Entity;

namespace QleanyEditor::Contracts::DTO::CRUD
{
using namespace Qt::Literals::StringLiterals;

class CreateCRUDDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled)
    Q_PROPERTY(EntityDTO entityMappableWith READ entityMappableWith WRITE setEntityMappableWith)
    Q_PROPERTY(bool getEnabled READ getEnabled WRITE setGetEnabled)
    Q_PROPERTY(bool getAllEnabled READ getAllEnabled WRITE setGetAllEnabled)
    Q_PROPERTY(bool getWithDetailsEnabled READ getWithDetailsEnabled WRITE setGetWithDetailsEnabled)
    Q_PROPERTY(bool createEnabled READ createEnabled WRITE setCreateEnabled)
    Q_PROPERTY(bool updateEnabled READ updateEnabled WRITE setUpdateEnabled)
    Q_PROPERTY(bool removeEnabled READ removeEnabled WRITE setRemoveEnabled)
    Q_PROPERTY(int applicationFeatureId READ applicationFeatureId WRITE setApplicationFeatureId)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool enabledSet = false;
        bool entityMappableWithSet = false;
        bool getEnabledSet = false;
        bool getAllEnabledSet = false;
        bool getWithDetailsEnabledSet = false;
        bool createEnabledSet = false;
        bool updateEnabledSet = false;
        bool removeEnabledSet = false;
        bool applicationFeatureIdSet = false;
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
            if (fieldName == "enabled"_L1) {
                return enabledSet;
            }
            if (fieldName == "entityMappableWith"_L1) {
                return entityMappableWithSet;
            }
            if (fieldName == "getEnabled"_L1) {
                return getEnabledSet;
            }
            if (fieldName == "getAllEnabled"_L1) {
                return getAllEnabledSet;
            }
            if (fieldName == "getWithDetailsEnabled"_L1) {
                return getWithDetailsEnabledSet;
            }
            if (fieldName == "createEnabled"_L1) {
                return createEnabledSet;
            }
            if (fieldName == "updateEnabled"_L1) {
                return updateEnabledSet;
            }
            if (fieldName == "removeEnabled"_L1) {
                return removeEnabledSet;
            }
            if (fieldName == "applicationFeatureId"_L1) {
                return applicationFeatureIdSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (entityMappableWithSet)
                return true;

            return false;
        }
    };

    CreateCRUDDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_enabled(false)
        , m_getEnabled(false)
        , m_getAllEnabled(false)
        , m_getWithDetailsEnabled(false)
        , m_createEnabled(false)
        , m_updateEnabled(false)
        , m_removeEnabled(false)
        , m_applicationFeatureId(0)
    {
    }

    ~CreateCRUDDTO()
    {
    }

    CreateCRUDDTO(const QUuid &uuid,
                  const QDateTime &creationDate,
                  const QDateTime &updateDate,
                  bool enabled,
                  const EntityDTO &entityMappableWith,
                  bool getEnabled,
                  bool getAllEnabled,
                  bool getWithDetailsEnabled,
                  bool createEnabled,
                  bool updateEnabled,
                  bool removeEnabled,
                  int applicationFeatureId)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_enabled(enabled)
        , m_entityMappableWith(entityMappableWith)
        , m_getEnabled(getEnabled)
        , m_getAllEnabled(getAllEnabled)
        , m_getWithDetailsEnabled(getWithDetailsEnabled)
        , m_createEnabled(createEnabled)
        , m_updateEnabled(updateEnabled)
        , m_removeEnabled(removeEnabled)
        , m_applicationFeatureId(applicationFeatureId)
    {
    }

    CreateCRUDDTO(const CreateCRUDDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_enabled(other.m_enabled)
        , m_entityMappableWith(other.m_entityMappableWith)
        , m_getEnabled(other.m_getEnabled)
        , m_getAllEnabled(other.m_getAllEnabled)
        , m_getWithDetailsEnabled(other.m_getWithDetailsEnabled)
        , m_createEnabled(other.m_createEnabled)
        , m_updateEnabled(other.m_updateEnabled)
        , m_removeEnabled(other.m_removeEnabled)
        , m_applicationFeatureId(other.m_applicationFeatureId)
    {
    }

    CreateCRUDDTO &operator=(const CreateCRUDDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_enabled = other.m_enabled;
            m_entityMappableWith = other.m_entityMappableWith;
            m_getEnabled = other.m_getEnabled;
            m_getAllEnabled = other.m_getAllEnabled;
            m_getWithDetailsEnabled = other.m_getWithDetailsEnabled;
            m_createEnabled = other.m_createEnabled;
            m_updateEnabled = other.m_updateEnabled;
            m_removeEnabled = other.m_removeEnabled;
            m_applicationFeatureId = other.m_applicationFeatureId;
        }
        return *this;
    }

    CreateCRUDDTO &operator=(const CreateCRUDDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_enabled = other.m_enabled;
            m_entityMappableWith = other.m_entityMappableWith;
            m_getEnabled = other.m_getEnabled;
            m_getAllEnabled = other.m_getAllEnabled;
            m_getWithDetailsEnabled = other.m_getWithDetailsEnabled;
            m_createEnabled = other.m_createEnabled;
            m_updateEnabled = other.m_updateEnabled;
            m_removeEnabled = other.m_removeEnabled;
            m_applicationFeatureId = other.m_applicationFeatureId;
        }
        return *this;
    }

    CreateCRUDDTO &mergeWith(const CreateCRUDDTO &other)
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
            if (other.m_metaData.enabledSet) {
                m_enabled = other.m_enabled;
                m_metaData.enabledSet = true;
            }
            if (other.m_metaData.entityMappableWithSet) {
                m_entityMappableWith = other.m_entityMappableWith;
                m_metaData.entityMappableWithSet = true;
            }
            if (other.m_metaData.getEnabledSet) {
                m_getEnabled = other.m_getEnabled;
                m_metaData.getEnabledSet = true;
            }
            if (other.m_metaData.getAllEnabledSet) {
                m_getAllEnabled = other.m_getAllEnabled;
                m_metaData.getAllEnabledSet = true;
            }
            if (other.m_metaData.getWithDetailsEnabledSet) {
                m_getWithDetailsEnabled = other.m_getWithDetailsEnabled;
                m_metaData.getWithDetailsEnabledSet = true;
            }
            if (other.m_metaData.createEnabledSet) {
                m_createEnabled = other.m_createEnabled;
                m_metaData.createEnabledSet = true;
            }
            if (other.m_metaData.updateEnabledSet) {
                m_updateEnabled = other.m_updateEnabled;
                m_metaData.updateEnabledSet = true;
            }
            if (other.m_metaData.removeEnabledSet) {
                m_removeEnabled = other.m_removeEnabled;
                m_metaData.removeEnabledSet = true;
            }
            if (other.m_metaData.applicationFeatureIdSet) {
                m_applicationFeatureId = other.m_applicationFeatureId;
                m_metaData.applicationFeatureIdSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateCRUDDTO &operator<<(const CreateCRUDDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateCRUDDTO &lhs, const CreateCRUDDTO &rhs);

    friend uint qHash(const CreateCRUDDTO &dto, uint seed) noexcept;

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

    // ------ enabled : -----

    bool enabled() const
    {
        return m_enabled;
    }

    void setEnabled(bool enabled)
    {
        m_enabled = enabled;
        m_metaData.enabledSet = true;
    }

    // ------ entityMappableWith : -----

    EntityDTO entityMappableWith() const
    {
        return m_entityMappableWith;
    }

    void setEntityMappableWith(const EntityDTO &entityMappableWith)
    {
        m_entityMappableWith = entityMappableWith;
        m_metaData.entityMappableWithSet = true;
    }

    // ------ getEnabled : -----

    bool getEnabled() const
    {
        return m_getEnabled;
    }

    void setGetEnabled(bool getEnabled)
    {
        m_getEnabled = getEnabled;
        m_metaData.getEnabledSet = true;
    }

    // ------ getAllEnabled : -----

    bool getAllEnabled() const
    {
        return m_getAllEnabled;
    }

    void setGetAllEnabled(bool getAllEnabled)
    {
        m_getAllEnabled = getAllEnabled;
        m_metaData.getAllEnabledSet = true;
    }

    // ------ getWithDetailsEnabled : -----

    bool getWithDetailsEnabled() const
    {
        return m_getWithDetailsEnabled;
    }

    void setGetWithDetailsEnabled(bool getWithDetailsEnabled)
    {
        m_getWithDetailsEnabled = getWithDetailsEnabled;
        m_metaData.getWithDetailsEnabledSet = true;
    }

    // ------ createEnabled : -----

    bool createEnabled() const
    {
        return m_createEnabled;
    }

    void setCreateEnabled(bool createEnabled)
    {
        m_createEnabled = createEnabled;
        m_metaData.createEnabledSet = true;
    }

    // ------ updateEnabled : -----

    bool updateEnabled() const
    {
        return m_updateEnabled;
    }

    void setUpdateEnabled(bool updateEnabled)
    {
        m_updateEnabled = updateEnabled;
        m_metaData.updateEnabledSet = true;
    }

    // ------ removeEnabled : -----

    bool removeEnabled() const
    {
        return m_removeEnabled;
    }

    void setRemoveEnabled(bool removeEnabled)
    {
        m_removeEnabled = removeEnabled;
        m_metaData.removeEnabledSet = true;
    }

    // ------ applicationFeatureId : -----

    int applicationFeatureId() const
    {
        return m_applicationFeatureId;
    }

    void setApplicationFeatureId(int applicationFeatureId)
    {
        m_applicationFeatureId = applicationFeatureId;
        m_metaData.applicationFeatureIdSet = true;
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
    bool m_enabled;
    EntityDTO m_entityMappableWith;
    bool m_getEnabled;
    bool m_getAllEnabled;
    bool m_getWithDetailsEnabled;
    bool m_createEnabled;
    bool m_updateEnabled;
    bool m_removeEnabled;
    int m_applicationFeatureId;
};

inline bool operator==(const CreateCRUDDTO &lhs, const CreateCRUDDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate && lhs.m_enabled == rhs.m_enabled
        && lhs.m_entityMappableWith == rhs.m_entityMappableWith && lhs.m_getEnabled == rhs.m_getEnabled && lhs.m_getAllEnabled == rhs.m_getAllEnabled
        && lhs.m_getWithDetailsEnabled == rhs.m_getWithDetailsEnabled && lhs.m_createEnabled == rhs.m_createEnabled
        && lhs.m_updateEnabled == rhs.m_updateEnabled && lhs.m_removeEnabled == rhs.m_removeEnabled && lhs.m_applicationFeatureId == rhs.m_applicationFeatureId;
}

inline uint qHash(const CreateCRUDDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_enabled, seed);
    hash ^= ::qHash(dto.m_entityMappableWith, seed);
    hash ^= ::qHash(dto.m_getEnabled, seed);
    hash ^= ::qHash(dto.m_getAllEnabled, seed);
    hash ^= ::qHash(dto.m_getWithDetailsEnabled, seed);
    hash ^= ::qHash(dto.m_createEnabled, seed);
    hash ^= ::qHash(dto.m_updateEnabled, seed);
    hash ^= ::qHash(dto.m_removeEnabled, seed);
    hash ^= ::qHash(dto.m_applicationFeatureId, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::CRUD
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::CRUD::CreateCRUDDTO)