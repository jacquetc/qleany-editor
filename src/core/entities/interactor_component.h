// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class InteractorComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString folderPath READ folderPath WRITE setFolderPath)

    Q_PROPERTY(bool createUndoRedoInteractor READ createUndoRedoInteractor WRITE setCreateUndoRedoInteractor)

public:
    struct MetaData {
        MetaData(InteractorComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(InteractorComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            Q_UNUSED(other);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "folderPath"_L1) {
                return true;
            }
            if (fieldName == "createUndoRedoInteractor"_L1) {
                return true;
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
            if (fieldName == "createUndoRedoInteractor"_L1) {
                return true;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        InteractorComponent *m_entity = nullptr;
    };

    InteractorComponent()
        : CommonParent()
        , m_metaData(this)
        , m_folderPath(QString())
        , m_createUndoRedoInteractor(false)
    {
    }

    ~InteractorComponent()
    {
    }

    InteractorComponent(const int &id,
                        const QUuid &uuid,
                        const QDateTime &creationDate,
                        const QDateTime &updateDate,
                        const QString &folderPath,
                        bool createUndoRedoInteractor)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_folderPath(folderPath)
        , m_createUndoRedoInteractor(createUndoRedoInteractor)
    {
    }

    InteractorComponent(const InteractorComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_folderPath(other.m_folderPath)
        , m_createUndoRedoInteractor(other.m_createUndoRedoInteractor)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::InteractorComponent;
    }

    InteractorComponent &operator=(const InteractorComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_folderPath = other.m_folderPath;
            m_createUndoRedoInteractor = other.m_createUndoRedoInteractor;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const InteractorComponent &lhs, const InteractorComponent &rhs);

    friend uint qHash(const InteractorComponent &entity, uint seed) noexcept;

    // ------ folderPath : -----

    QString folderPath() const
    {
        return m_folderPath;
    }

    void setFolderPath(const QString &folderPath)
    {
        m_folderPath = folderPath;
    }

    // ------ createUndoRedoInteractor : -----

    bool createUndoRedoInteractor() const
    {
        return m_createUndoRedoInteractor;
    }

    void setCreateUndoRedoInteractor(bool createUndoRedoInteractor)
    {
        m_createUndoRedoInteractor = createUndoRedoInteractor;
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
    bool m_createUndoRedoInteractor;
};

inline bool operator==(const InteractorComponent &lhs, const InteractorComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_folderPath == rhs.m_folderPath && lhs.m_createUndoRedoInteractor == rhs.m_createUndoRedoInteractor;
}

inline uint qHash(const InteractorComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_folderPath, seed);
    hash ^= ::qHash(entity.m_createUndoRedoInteractor, seed);

    return hash;
}

/// Schema for InteractorComponent entity
inline Qleany::Entities::EntitySchema InteractorComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::InteractorComponent,
                                                                     "InteractorComponent"_L1,

                                                                     // relationships:
                                                                     {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                       "Project"_L1,
                                                                       QleanyEditor::Entities::Entities::EntityEnum::InteractorComponent,
                                                                       "InteractorComponent"_L1,
                                                                       "interactorComponent"_L1,
                                                                       RelationshipType::OneToOne,
                                                                       RelationshipStrength::Strong,
                                                                       RelationshipCardinality::One,
                                                                       RelationshipDirection::Backward}},

                                                                     // fields:
                                                                     {{"id"_L1, FieldType::Integer, true, false},
                                                                      {"uuid"_L1, FieldType::Uuid, false, false},
                                                                      {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                      {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                      {"folderPath"_L1, FieldType::String, false, false},
                                                                      {"createUndoRedoInteractor"_L1, FieldType::Bool, false, false}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::InteractorComponent)