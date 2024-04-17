// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model.h"
#include "presenter_single.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class PresenterComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString folderPath READ folderPath WRITE setFolderPath)

    Q_PROPERTY(bool createUndoAndRedoSingles READ createUndoAndRedoSingles WRITE setCreateUndoAndRedoSingles)

    Q_PROPERTY(QList<PresenterSingle> singles READ singles WRITE setSingles)

    Q_PROPERTY(QList<PresenterListModel> listModels READ listModels WRITE setListModels)

public:
    struct MetaData {
        MetaData(PresenterComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(PresenterComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->singlesSet = other.singlesSet;
            this->singlesLoaded = other.singlesLoaded;
            this->listModelsSet = other.listModelsSet;
            this->listModelsLoaded = other.listModelsLoaded;
        }

        bool singlesSet = false;
        bool singlesLoaded = false;

        bool listModelsSet = false;
        bool listModelsLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "folderPath"_L1) {
                return true;
            }
            if (fieldName == "createUndoAndRedoSingles"_L1) {
                return true;
            }
            if (fieldName == "singles"_L1) {
                return singlesSet;
            }
            if (fieldName == "listModels"_L1) {
                return listModelsSet;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "folderPath"_L1) {
                return true;
            }
            if (fieldName == "createUndoAndRedoSingles"_L1) {
                return true;
            }
            if (fieldName == "singles"_L1) {
                return singlesLoaded;
            }
            if (fieldName == "listModels"_L1) {
                return listModelsLoaded;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        PresenterComponent *m_entity = nullptr;
    };

    PresenterComponent()
        : CommonParent()
        , m_metaData(this)
        , m_folderPath(QString())
        , m_createUndoAndRedoSingles(false)
    {
    }

    ~PresenterComponent()
    {
    }

    PresenterComponent(const int &id,
                       const QUuid &uuid,
                       const QDateTime &creationDate,
                       const QDateTime &updateDate,
                       const QString &folderPath,
                       bool createUndoAndRedoSingles,
                       const QList<PresenterSingle> &singles,
                       const QList<PresenterListModel> &listModels)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_folderPath(folderPath)
        , m_createUndoAndRedoSingles(createUndoAndRedoSingles)
        , m_singles(singles)
        , m_listModels(listModels)
    {
    }

    PresenterComponent(const PresenterComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_folderPath(other.m_folderPath)
        , m_createUndoAndRedoSingles(other.m_createUndoAndRedoSingles)
        , m_singles(other.m_singles)
        , m_listModels(other.m_listModels)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::PresenterComponent;
    }

    PresenterComponent &operator=(const PresenterComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_folderPath = other.m_folderPath;
            m_createUndoAndRedoSingles = other.m_createUndoAndRedoSingles;
            m_singles = other.m_singles;
            m_listModels = other.m_listModels;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const PresenterComponent &lhs, const PresenterComponent &rhs);

    friend uint qHash(const PresenterComponent &entity, uint seed) noexcept;

    // ------ folderPath : -----

    QString folderPath() const
    {
        return m_folderPath;
    }

    void setFolderPath(const QString &folderPath)
    {
        m_folderPath = folderPath;
    }

    // ------ createUndoAndRedoSingles : -----

    bool createUndoAndRedoSingles() const
    {
        return m_createUndoAndRedoSingles;
    }

    void setCreateUndoAndRedoSingles(bool createUndoAndRedoSingles)
    {
        m_createUndoAndRedoSingles = createUndoAndRedoSingles;
    }

    // ------ singles : -----

    QList<PresenterSingle> singles()
    {
        if (!m_metaData.singlesLoaded && m_singlesLoader) {
            m_singles = m_singlesLoader(this->id());
            m_metaData.singlesLoaded = true;
        }
        return m_singles;
    }

    void setSingles(const QList<PresenterSingle> &singles)
    {
        m_singles = singles;

        m_metaData.singlesSet = true;
    }

    using SinglesLoader = std::function<QList<PresenterSingle>(int entityId)>;

    void setSinglesLoader(const SinglesLoader &loader)
    {
        m_singlesLoader = loader;
    }

    // ------ listModels : -----

    QList<PresenterListModel> listModels()
    {
        if (!m_metaData.listModelsLoaded && m_listModelsLoader) {
            m_listModels = m_listModelsLoader(this->id());
            m_metaData.listModelsLoaded = true;
        }
        return m_listModels;
    }

    void setListModels(const QList<PresenterListModel> &listModels)
    {
        m_listModels = listModels;

        m_metaData.listModelsSet = true;
    }

    using ListModelsLoader = std::function<QList<PresenterListModel>(int entityId)>;

    void setListModelsLoader(const ListModelsLoader &loader)
    {
        m_listModelsLoader = loader;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_folderPath;
    bool m_createUndoAndRedoSingles;
    QList<PresenterSingle> m_singles;
    SinglesLoader m_singlesLoader;
    QList<PresenterListModel> m_listModels;
    ListModelsLoader m_listModelsLoader;
};

inline bool operator==(const PresenterComponent &lhs, const PresenterComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_folderPath == rhs.m_folderPath && lhs.m_createUndoAndRedoSingles == rhs.m_createUndoAndRedoSingles && lhs.m_singles == rhs.m_singles
        && lhs.m_listModels == rhs.m_listModels;
}

inline uint qHash(const PresenterComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_folderPath, seed);
    hash ^= ::qHash(entity.m_createUndoAndRedoSingles, seed);
    hash ^= ::qHash(entity.m_singles, seed);
    hash ^= ::qHash(entity.m_listModels, seed);

    return hash;
}

/// Schema for PresenterComponent entity
inline Qleany::Entities::EntitySchema PresenterComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::PresenterComponent,
                                                                    "PresenterComponent"_L1,

                                                                    // relationships:
                                                                    {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                      "Project"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::PresenterComponent,
                                                                      "PresenterComponent"_L1,
                                                                      "presenterComponent"_L1,
                                                                      RelationshipType::OneToOne,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::One,
                                                                      RelationshipDirection::Backward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::PresenterComponent,
                                                                      "PresenterComponent"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::PresenterSingle,
                                                                      "PresenterSingle"_L1,
                                                                      "singles"_L1,
                                                                      RelationshipType::OneToMany,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::ManyOrdered,
                                                                      RelationshipDirection::Forward},
                                                                     {QleanyEditor::Entities::Entities::EntityEnum::PresenterComponent,
                                                                      "PresenterComponent"_L1,
                                                                      QleanyEditor::Entities::Entities::EntityEnum::PresenterListModel,
                                                                      "PresenterListModel"_L1,
                                                                      "listModels"_L1,
                                                                      RelationshipType::OneToMany,
                                                                      RelationshipStrength::Strong,
                                                                      RelationshipCardinality::ManyOrdered,
                                                                      RelationshipDirection::Forward}},

                                                                    // fields:
                                                                    {{"id"_L1, FieldType::Integer, true, false},
                                                                     {"uuid"_L1, FieldType::Uuid, false, false},
                                                                     {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                     {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                     {"folderPath"_L1, FieldType::String, false, false},
                                                                     {"createUndoAndRedoSingles"_L1, FieldType::Bool, false, false},
                                                                     {"singles"_L1, FieldType::Entity, false, true},
                                                                     {"listModels"_L1, FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::PresenterComponent)