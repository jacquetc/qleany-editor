// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "global_component/global_component_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::GlobalComponent;

namespace QleanyEditor::Contracts::DTO::Project
{
using namespace Qt::Literals::StringLiterals;

class ProjectWithDetailsDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    Q_PROPERTY(GlobalComponentDTO globalComponent READ globalComponent WRITE setGlobalComponent)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool fileNameSet = false;
        bool globalComponentSet = false;
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
            if (fieldName == "fileName"_L1) {
                return fileNameSet;
            }
            if (fieldName == "globalComponent"_L1) {
                return globalComponentSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (globalComponentSet)
                return true;

            return false;
        }
    };

    ProjectWithDetailsDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_fileName(QString())
    {
    }

    ~ProjectWithDetailsDTO()
    {
    }

    ProjectWithDetailsDTO(int id,
                          const QUuid &uuid,
                          const QDateTime &creationDate,
                          const QDateTime &updateDate,
                          const QString &fileName,
                          const GlobalComponentDTO &globalComponent)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_fileName(fileName)
        , m_globalComponent(globalComponent)
    {
    }

    ProjectWithDetailsDTO(const ProjectWithDetailsDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_fileName(other.m_fileName)
        , m_globalComponent(other.m_globalComponent)
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

    ProjectWithDetailsDTO &operator=(const ProjectWithDetailsDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_fileName = other.m_fileName;
            m_globalComponent = other.m_globalComponent;
        }
        return *this;
    }

    ProjectWithDetailsDTO &operator=(const ProjectWithDetailsDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_fileName = other.m_fileName;
            m_globalComponent = other.m_globalComponent;
        }
        return *this;
    }

    ProjectWithDetailsDTO &mergeWith(const ProjectWithDetailsDTO &other)
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
            if (other.m_metaData.fileNameSet) {
                m_fileName = other.m_fileName;
                m_metaData.fileNameSet = true;
            }
            if (other.m_metaData.globalComponentSet) {
                m_globalComponent = other.m_globalComponent;
                m_metaData.globalComponentSet = true;
            }
        }
        return *this;
    }

    // import operator
    ProjectWithDetailsDTO &operator<<(const ProjectWithDetailsDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const ProjectWithDetailsDTO &lhs, const ProjectWithDetailsDTO &rhs);

    friend uint qHash(const ProjectWithDetailsDTO &dto, uint seed) noexcept;

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

    // ------ fileName : -----

    QString fileName() const
    {
        return m_fileName;
    }

    void setFileName(const QString &fileName)
    {
        m_fileName = fileName;
        m_metaData.fileNameSet = true;
    }

    // ------ globalComponent : -----

    GlobalComponentDTO globalComponent() const
    {
        return m_globalComponent;
    }

    void setGlobalComponent(const GlobalComponentDTO &globalComponent)
    {
        m_globalComponent = globalComponent;
        m_metaData.globalComponentSet = true;
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
    QString m_fileName;
    GlobalComponentDTO m_globalComponent;
};

inline bool operator==(const ProjectWithDetailsDTO &lhs, const ProjectWithDetailsDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_fileName == rhs.m_fileName && lhs.m_globalComponent == rhs.m_globalComponent;
}

inline uint qHash(const ProjectWithDetailsDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_fileName, seed);
    hash ^= ::qHash(dto.m_globalComponent, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Project
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Project::ProjectWithDetailsDTO)