// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model/presenter_list_model_dto.h"
#include "presenter_single/presenter_single_dto.h"
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

using namespace QleanyEditor::Contracts::DTO::PresenterSingle;
using namespace QleanyEditor::Contracts::DTO::PresenterListModel;

namespace QleanyEditor::Contracts::DTO::PresenterComponent
{
using namespace Qt::Literals::StringLiterals;

class PresenterComponentWithDetailsDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate)
    Q_PROPERTY(QString folderPath READ folderPath WRITE setFolderPath)
    Q_PROPERTY(bool createUndoAndRedoSingles READ createUndoAndRedoSingles WRITE setCreateUndoAndRedoSingles)
    Q_PROPERTY(QList<PresenterSingleDTO> singles READ singles WRITE setSingles)
    Q_PROPERTY(QList<PresenterListModelDTO> listModels READ listModels WRITE setListModels)

public:
    struct MetaData {
        bool idSet = false;
        bool uuidSet = false;
        bool creationDateSet = false;
        bool updateDateSet = false;
        bool folderPathSet = false;
        bool createUndoAndRedoSinglesSet = false;
        bool singlesSet = false;
        bool listModelsSet = false;
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
            if (fieldName == "folderPath"_L1) {
                return folderPathSet;
            }
            if (fieldName == "createUndoAndRedoSingles"_L1) {
                return createUndoAndRedoSinglesSet;
            }
            if (fieldName == "singles"_L1) {
                return singlesSet;
            }
            if (fieldName == "listModels"_L1) {
                return listModelsSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            if (singlesSet)
                return true;

            if (listModelsSet)
                return true;

            return false;
        }
    };

    PresenterComponentWithDetailsDTO()
        : m_id(0)
        , m_uuid(QUuid())
        , m_creationDate(QDateTime())
        , m_updateDate(QDateTime())
        , m_folderPath(QString())
        , m_createUndoAndRedoSingles(false)
    {
    }

    ~PresenterComponentWithDetailsDTO()
    {
    }

    PresenterComponentWithDetailsDTO(int id,
                                     const QUuid &uuid,
                                     const QDateTime &creationDate,
                                     const QDateTime &updateDate,
                                     const QString &folderPath,
                                     bool createUndoAndRedoSingles,
                                     const QList<PresenterSingleDTO> &singles,
                                     const QList<PresenterListModelDTO> &listModels)
        : m_id(id)
        , m_uuid(uuid)
        , m_creationDate(creationDate)
        , m_updateDate(updateDate)
        , m_folderPath(folderPath)
        , m_createUndoAndRedoSingles(createUndoAndRedoSingles)
        , m_singles(singles)
        , m_listModels(listModels)
    {
    }

    PresenterComponentWithDetailsDTO(const PresenterComponentWithDetailsDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_uuid(other.m_uuid)
        , m_creationDate(other.m_creationDate)
        , m_updateDate(other.m_updateDate)
        , m_folderPath(other.m_folderPath)
        , m_createUndoAndRedoSingles(other.m_createUndoAndRedoSingles)
        , m_singles(other.m_singles)
        , m_listModels(other.m_listModels)
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

    PresenterComponentWithDetailsDTO &operator=(const PresenterComponentWithDetailsDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_folderPath = other.m_folderPath;
            m_createUndoAndRedoSingles = other.m_createUndoAndRedoSingles;
            m_singles = other.m_singles;
            m_listModels = other.m_listModels;
        }
        return *this;
    }

    PresenterComponentWithDetailsDTO &operator=(const PresenterComponentWithDetailsDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_uuid = other.m_uuid;
            m_creationDate = other.m_creationDate;
            m_updateDate = other.m_updateDate;
            m_folderPath = other.m_folderPath;
            m_createUndoAndRedoSingles = other.m_createUndoAndRedoSingles;
            m_singles = other.m_singles;
            m_listModels = other.m_listModels;
        }
        return *this;
    }

    PresenterComponentWithDetailsDTO &mergeWith(const PresenterComponentWithDetailsDTO &other)
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
            if (other.m_metaData.folderPathSet) {
                m_folderPath = other.m_folderPath;
                m_metaData.folderPathSet = true;
            }
            if (other.m_metaData.createUndoAndRedoSinglesSet) {
                m_createUndoAndRedoSingles = other.m_createUndoAndRedoSingles;
                m_metaData.createUndoAndRedoSinglesSet = true;
            }
            if (other.m_metaData.singlesSet) {
                m_singles = other.m_singles;
                m_metaData.singlesSet = true;
            }
            if (other.m_metaData.listModelsSet) {
                m_listModels = other.m_listModels;
                m_metaData.listModelsSet = true;
            }
        }
        return *this;
    }

    // import operator
    PresenterComponentWithDetailsDTO &operator<<(const PresenterComponentWithDetailsDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const PresenterComponentWithDetailsDTO &lhs, const PresenterComponentWithDetailsDTO &rhs);

    friend uint qHash(const PresenterComponentWithDetailsDTO &dto, uint seed) noexcept;

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

    // ------ folderPath : -----

    QString folderPath() const
    {
        return m_folderPath;
    }

    void setFolderPath(const QString &folderPath)
    {
        m_folderPath = folderPath;
        m_metaData.folderPathSet = true;
    }

    // ------ createUndoAndRedoSingles : -----

    bool createUndoAndRedoSingles() const
    {
        return m_createUndoAndRedoSingles;
    }

    void setCreateUndoAndRedoSingles(bool createUndoAndRedoSingles)
    {
        m_createUndoAndRedoSingles = createUndoAndRedoSingles;
        m_metaData.createUndoAndRedoSinglesSet = true;
    }

    // ------ singles : -----

    QList<PresenterSingleDTO> singles() const
    {
        return m_singles;
    }

    void setSingles(const QList<PresenterSingleDTO> &singles)
    {
        m_singles = singles;
        m_metaData.singlesSet = true;
    }

    // ------ listModels : -----

    QList<PresenterListModelDTO> listModels() const
    {
        return m_listModels;
    }

    void setListModels(const QList<PresenterListModelDTO> &listModels)
    {
        m_listModels = listModels;
        m_metaData.listModelsSet = true;
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
    QString m_folderPath;
    bool m_createUndoAndRedoSingles;
    QList<PresenterSingleDTO> m_singles;
    QList<PresenterListModelDTO> m_listModels;
};

inline bool operator==(const PresenterComponentWithDetailsDTO &lhs, const PresenterComponentWithDetailsDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_uuid == rhs.m_uuid && lhs.m_creationDate == rhs.m_creationDate && lhs.m_updateDate == rhs.m_updateDate
        && lhs.m_folderPath == rhs.m_folderPath && lhs.m_createUndoAndRedoSingles == rhs.m_createUndoAndRedoSingles && lhs.m_singles == rhs.m_singles
        && lhs.m_listModels == rhs.m_listModels;
}

inline uint qHash(const PresenterComponentWithDetailsDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_uuid, seed);
    hash ^= ::qHash(dto.m_creationDate, seed);
    hash ^= ::qHash(dto.m_updateDate, seed);
    hash ^= ::qHash(dto.m_folderPath, seed);
    hash ^= ::qHash(dto.m_createUndoAndRedoSingles, seed);
    hash ^= ::qHash(dto.m_singles, seed);
    hash ^= ::qHash(dto.m_listModels, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::PresenterComponent
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::PresenterComponent::PresenterComponentWithDetailsDTO)