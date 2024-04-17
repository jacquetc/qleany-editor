// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QObject>

namespace QleanyEditor::Contracts::DTO::CustomDTO
{
using namespace Qt::Literals::StringLiterals;

class CustomDTORelationDTO
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
            if (fieldName == "id"_L1) {
                return idSet;
            }
            if (fieldName == "relationField"_L1) {
                return relationFieldSet;
            }
            if (fieldName == "relatedIds"_L1) {
                return relatedIdsSet;
            }
            if (fieldName == "position"_L1) {
                return positionSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    enum RelationField { Undefined, Fields };
    Q_ENUM(RelationField);

    CustomDTORelationDTO()
        : m_id(0)
        , m_relationField(RelationField::Undefined)
        , m_relatedIds({})
        , m_position(0)
    {
    }

    ~CustomDTORelationDTO()
    {
    }

    CustomDTORelationDTO(int id, const RelationField &relationField, const QList<int> &relatedIds, int position)
        : m_id(id)
        , m_relationField(relationField)
        , m_relatedIds(relatedIds)
        , m_position(position)
    {
    }

    CustomDTORelationDTO(const CustomDTORelationDTO &other)
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

    CustomDTORelationDTO &operator=(const CustomDTORelationDTO &other)
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

    CustomDTORelationDTO &operator=(const CustomDTORelationDTO &&other)
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

    CustomDTORelationDTO &mergeWith(const CustomDTORelationDTO &other)
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
    CustomDTORelationDTO &operator<<(const CustomDTORelationDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const CustomDTORelationDTO &lhs, const CustomDTORelationDTO &rhs);

    friend uint qHash(const CustomDTORelationDTO &dto, uint seed) noexcept;

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

inline bool operator==(const CustomDTORelationDTO &lhs, const CustomDTORelationDTO &rhs)
{
    return lhs.m_id == rhs.m_id && lhs.m_relationField == rhs.m_relationField && lhs.m_relatedIds == rhs.m_relatedIds && lhs.m_position == rhs.m_position;
}

inline uint qHash(const CustomDTORelationDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_id, seed);
    hash ^= ::qHash(dto.m_relationField, seed);
    hash ^= ::qHash(dto.m_relatedIds, seed);
    hash ^= ::qHash(dto.m_position, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::CustomDTO
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::CustomDTO::CustomDTORelationDTO)