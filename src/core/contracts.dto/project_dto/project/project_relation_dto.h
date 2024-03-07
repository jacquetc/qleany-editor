// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QObject>

namespace QleanyEditor::Contracts::DTO::Project
{

class ProjectRelationDTO
{
    Q_GADGET

    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(RelationField relationField READ relationField WRITE setRelationshipField)
    Q_PROPERTY(QList<int> relatedIds READ relatedIds WRITE setRelatedIds)
    Q_PROPERTY(int position READ position WRITE setPosition)

public:
    struct MetaData {
        bool idSet = false;
        bool relationFieldSet = false;
        bool relatedIdsSet = false;
        bool positionSet = false;
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == QString::fromUtf8("id")) {
                return idSet;
            }
            if (fieldName == QString::fromUtf8("relationField")) {
                return relationFieldSet;
            }
            if (fieldName == QString::fromUtf8("relatedIds")) {
                return relatedIdsSet;
            }
            if (fieldName == QString::fromUtf8("position")) {
                return positionSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    enum RelationField { Undefined, GlobalComponent };
    Q_ENUM(RelationField);

    ProjectRelationDTO()
        : m_id(0)
        , m_relationField(RelationField::Undefined)
        , m_relatedIds({})
        , m_position(0)
    {
    }

    ~ProjectRelationDTO()
    {
    }

    ProjectRelationDTO(int id, const RelationField &relationField, const QList<int> &relatedIds, int position)
        : m_id(id)
        , m_relationField(relationField)
        , m_relatedIds(relatedIds)
        , m_position(position)
    {
    }

    ProjectRelationDTO(const ProjectRelationDTO &other)
        : m_metaData(other.m_metaData)
        , m_id(other.m_id)
        , m_relationField(other.m_relationField)
        , m_relatedIds(other.m_relatedIds)
        , m_position(other.m_position)
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

    ProjectRelationDTO &operator=(const ProjectRelationDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_relationField = other.m_relationField;
            m_relatedIds = other.m_relatedIds;
            m_position = other.m_position;
        }
        return *this;
    }

    ProjectRelationDTO &operator=(const ProjectRelationDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_id = other.m_id;
            m_relationField = other.m_relationField;
            m_relatedIds = other.m_relatedIds;
            m_position = other.m_position;
        }
        return *this;
    }

    ProjectRelationDTO &mergeWith(const ProjectRelationDTO &other)
    {
        if (this != &other) {
            if (other.m_metaData.idSet) {
                m_id = other.m_id;
                m_metaData.idSet = true;
            }
            if (other.m_metaData.relationFieldSet) {
                m_relationField = other.m_relationField;
                m_metaData.relationFieldSet = true;
            }
            if (other.m_metaData.relatedIdsSet) {
                m_relatedIds = other.m_relatedIds;
                m_metaData.relatedIdsSet = true;
            }
            if (other.m_metaData.positionSet) {
                m_position = other.m_position;
                m_metaData.positionSet = true;
            }
        }
        return *this;
    }

    // import operator
    ProjectRelationDTO &operator<<(const ProjectRelationDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const ProjectRelationDTO &lhs, const ProjectRelationDTO &rhs);

    friend uint qHash(const ProjectRelationDTO &dto, uint seed) noexcept;

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

    // ------ relationField : -----

    RelationField relationField() const
    {
        return m_relationField;
    }

    void setRelationshipField(const RelationField &relationField)
    {
        m_relationField = relationField;
        m_metaData.relationFieldSet = true;
    }

    // ------ relatedIds : -----

    QList<int> relatedIds() const
    {
        return m_relatedIds;
    }

    void setRelatedIds(const QList<int> &relatedIds)
    {
        m_relatedIds = relatedIds;
        m_metaData.relatedIdsSet = true;
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

    int m_id;
    RelationField m_relationField;
    QList<int> m_relatedIds;
    int m_position;
};

inline bool operator==(const ProjectRelationDTO &lhs, const ProjectRelationDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_relationField == rhs.m_relationField && lhs.m_relatedIds == rhs.m_relatedIds && lhs.m_position == rhs.m_position;
}

inline uint qHash(const ProjectRelationDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_relationField, seed);
    hash ^= ::qHash(dto.m_relatedIds, seed);
    hash ^= ::qHash(dto.m_position, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Project
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Project::ProjectRelationDTO)