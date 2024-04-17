// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature/application_feature_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;

namespace QleanyEditor::Contracts::DTO::ApplicationComponent
{
using namespace Qt::Literals::StringLiterals;

class CreateApplicationComponentDTO
{
    Q_GADGET

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString commonCMakeFolderPath READ commonCMakeFolderPath WRITE setCommonCMakeFolderPath)
    Q_PROPERTY(QList<ApplicationFeatureDTO> features READ features WRITE setFeatures)
    Q_PROPERTY(int projectId READ projectId WRITE setProjectId)

public:
    struct MetaData {
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool commonCMakeFolderPathSet = false;
        bool featuresSet = false;
        bool projectIdSet = false;
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
            if (fieldName == "commonCMakeFolderPath"_L1) {
                return commonCMakeFolderPathSet;
            }
            if (fieldName == "features"_L1) {
                return featuresSet;
            }
            if (fieldName == "projectId"_L1) {
                return projectIdSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (featuresSet)
                return true;

            return false;
        }
    };

    CreateApplicationComponentDTO()
        : m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_commonCMakeFolderPath(QString())
        , m_projectId(0)
    {
    }

    ~CreateApplicationComponentDTO()
    {
    }

    CreateApplicationComponentDTO(const QUuid &uuid,
                                  const QDateTime &creationDate,
                                  const QDateTime &updateDate,
                                  const QString &commonCMakeFolderPath,
                                  const QList<ApplicationFeatureDTO> &features,
                                  int projectId)
        : m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_commonCMakeFolderPath(commonCMakeFolderPath)
        , m_features(features)
        , m_projectId(projectId)
    {
    }

    CreateApplicationComponentDTO(const CreateApplicationComponentDTO &other)
        : m_metaData(other.m_metaData)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_commonCMakeFolderPath(other.m_commonCMakeFolderPath)
        , m_features(other.m_features)
        , m_projectId(other.m_projectId)
    {
    }

    CreateApplicationComponentDTO &operator=(const CreateApplicationComponentDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_commonCMakeFolderPath = other.m_commonCMakeFolderPath;
            m_features = other.m_features;
            m_projectId = other.m_projectId;
        }
        return *this;
    }

    CreateApplicationComponentDTO &operator=(const CreateApplicationComponentDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_commonCMakeFolderPath = other.m_commonCMakeFolderPath;
            m_features = other.m_features;
            m_projectId = other.m_projectId;
        }
        return *this;
    }

    CreateApplicationComponentDTO &mergeWith(const CreateApplicationComponentDTO &other)
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
            if (other.m_metaData.commonCMakeFolderPathSet) {
                m_commonCMakeFolderPath = other.m_commonCMakeFolderPath;
                m_metaData.commonCMakeFolderPathSet = true;
            }
            if (other.m_metaData.featuresSet) {
                m_features = other.m_features;
                m_metaData.featuresSet = true;
            }
            if (other.m_metaData.projectIdSet) {
                m_projectId = other.m_projectId;
                m_metaData.projectIdSet = true;
            }
        }
        return *this;
    }

    // import operator
    CreateApplicationComponentDTO &operator<<(const CreateApplicationComponentDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CreateApplicationComponentDTO &lhs, const CreateApplicationComponentDTO &rhs);

    friend uint qHash(const CreateApplicationComponentDTO &dto, uint seed) noexcept;

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

    // ------ commonCMakeFolderPath : -----

    QString commonCMakeFolderPath() const
    {
        return m_commonCMakeFolderPath;
    }

    void setCommonCMakeFolderPath(const QString &commonCMakeFolderPath)
    {
        m_commonCMakeFolderPath = commonCMakeFolderPath;
        m_metaData.commonCMakeFolderPathSet = true;
    }

    // ------ features : -----

    QList<ApplicationFeatureDTO> features() const
    {
        return m_features;
    }

    void setFeatures(const QList<ApplicationFeatureDTO> &features)
    {
        m_features = features;
        m_metaData.featuresSet = true;
    }

    // ------ projectId : -----

    int projectId() const
    {
        return m_projectId;
    }

    void setProjectId(int projectId)
    {
        m_projectId = projectId;
        m_metaData.projectIdSet = true;
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
    QString m_commonCMakeFolderPath;
    QList<ApplicationFeatureDTO> m_features;
    int m_projectId;
};

inline bool operator==(const CreateApplicationComponentDTO &lhs, const CreateApplicationComponentDTO &rhs)
{
    return lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_commonCMakeFolderPath == rhs.m_commonCMakeFolderPath && lhs.m_features == rhs.m_features && lhs.m_projectId == rhs.m_projectId;
}

inline uint qHash(const CreateApplicationComponentDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_commonCMakeFolderPath, seed);
    hash ^= ::qHash(dto.m_features, seed);
    hash ^= ::qHash(dto.m_projectId, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::ApplicationComponent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::ApplicationComponent::CreateApplicationComponentDTO)