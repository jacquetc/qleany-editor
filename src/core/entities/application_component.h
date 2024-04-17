// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature.h"
#include <QString>

#include "common_parent.h"
#include "entities.h"
#include <qleany/entities/entity_schema.h>

using namespace Qleany::Entities;

namespace QleanyEditor::Entities
{

class ApplicationComponent : public CommonParent
{
    Q_GADGET

    Q_PROPERTY(QString commonCMakeFolderPath READ commonCMakeFolderPath WRITE setCommonCMakeFolderPath)

    Q_PROPERTY(QList<ApplicationFeature> features READ features WRITE setFeatures)

public:
    struct MetaData {
        MetaData(ApplicationComponent *entity)
            : m_entity(entity)
        {
        }
        MetaData(ApplicationComponent *entity, const MetaData &other)
            : m_entity(entity)
        {
            this->featuresSet = other.featuresSet;
            this->featuresLoaded = other.featuresLoaded;
        }

        bool featuresSet = false;
        bool featuresLoaded = false;

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "commonCMakeFolderPath"_L1) {
                return true;
            }
            if (fieldName == "features"_L1) {
                return featuresSet;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getSet(fieldName);
        }

        // Getters for the fields' metadata. Normal fields are always set, but lazy-loaded fields may not be
        bool getLoaded(const QString &fieldName) const
        {
            if (fieldName == "commonCMakeFolderPath"_L1) {
                return true;
            }
            if (fieldName == "features"_L1) {
                return featuresLoaded;
            }
            // If the field is not found, we delegate to the parent class
            return m_entity->CommonParent::metaData().getLoaded(fieldName);
        }

    private:
        ApplicationComponent *m_entity = nullptr;
    };

    ApplicationComponent()
        : CommonParent()
        , m_metaData(this)
        , m_commonCMakeFolderPath(QString())
    {
    }

    ~ApplicationComponent()
    {
    }

    ApplicationComponent(const int &id,
                         const QUuid &uuid,
                         const QDateTime &creationDate,
                         const QDateTime &updateDate,
                         const QString &commonCMakeFolderPath,
                         const QList<ApplicationFeature> &features)
        : CommonParent(id, uuid, creationDate, updateDate)
        , m_metaData(this)
        , m_commonCMakeFolderPath(commonCMakeFolderPath)
        , m_features(features)
    {
    }

    ApplicationComponent(const ApplicationComponent &other)
        : CommonParent(other)
        , m_metaData(other.m_metaData)
        , m_commonCMakeFolderPath(other.m_commonCMakeFolderPath)
        , m_features(other.m_features)
    {
        m_metaData = MetaData(this, other.metaData());
    }

    static QleanyEditor::Entities::Entities::EntityEnum enumValue()
    {
        return QleanyEditor::Entities::Entities::EntityEnum::ApplicationComponent;
    }

    ApplicationComponent &operator=(const ApplicationComponent &other)
    {
        if (this != &other) {
            CommonParent::operator=(other);
            m_commonCMakeFolderPath = other.m_commonCMakeFolderPath;
            m_features = other.m_features;

            m_metaData = MetaData(this, other.metaData());
        }
        return *this;
    }

    friend bool operator==(const ApplicationComponent &lhs, const ApplicationComponent &rhs);

    friend uint qHash(const ApplicationComponent &entity, uint seed) noexcept;

    // ------ commonCMakeFolderPath : -----

    QString commonCMakeFolderPath() const
    {
        return m_commonCMakeFolderPath;
    }

    void setCommonCMakeFolderPath(const QString &commonCMakeFolderPath)
    {
        m_commonCMakeFolderPath = commonCMakeFolderPath;
    }

    // ------ features : -----

    QList<ApplicationFeature> features()
    {
        if (!m_metaData.featuresLoaded && m_featuresLoader) {
            m_features = m_featuresLoader(this->id());
            m_metaData.featuresLoaded = true;
        }
        return m_features;
    }

    void setFeatures(const QList<ApplicationFeature> &features)
    {
        m_features = features;

        m_metaData.featuresSet = true;
    }

    using FeaturesLoader = std::function<QList<ApplicationFeature>(int entityId)>;

    void setFeaturesLoader(const FeaturesLoader &loader)
    {
        m_featuresLoader = loader;
    }

    static Qleany::Entities::EntitySchema schema;

    MetaData metaData() const
    {
        return m_metaData;
    }

protected:
    MetaData m_metaData;

private:
    QString m_commonCMakeFolderPath;
    QList<ApplicationFeature> m_features;
    FeaturesLoader m_featuresLoader;
};

inline bool operator==(const ApplicationComponent &lhs, const ApplicationComponent &rhs)
{
    return static_cast<const CommonParent &>(lhs) == static_cast<const CommonParent &>(rhs) &&

        lhs.m_commonCMakeFolderPath == rhs.m_commonCMakeFolderPath && lhs.m_features == rhs.m_features;
}

inline uint qHash(const ApplicationComponent &entity, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;
    hash ^= qHash(static_cast<const CommonParent &>(entity), seed);

    // Combine with this class's properties
    hash ^= ::qHash(entity.m_commonCMakeFolderPath, seed);
    hash ^= ::qHash(entity.m_features, seed);

    return hash;
}

/// Schema for ApplicationComponent entity
inline Qleany::Entities::EntitySchema ApplicationComponent::schema = {QleanyEditor::Entities::Entities::EntityEnum::ApplicationComponent,
                                                                      "ApplicationComponent"_L1,

                                                                      // relationships:
                                                                      {{QleanyEditor::Entities::Entities::EntityEnum::Project,
                                                                        "Project"_L1,
                                                                        QleanyEditor::Entities::Entities::EntityEnum::ApplicationComponent,
                                                                        "ApplicationComponent"_L1,
                                                                        "applicationComponent"_L1,
                                                                        RelationshipType::OneToOne,
                                                                        RelationshipStrength::Strong,
                                                                        RelationshipCardinality::One,
                                                                        RelationshipDirection::Backward},
                                                                       {QleanyEditor::Entities::Entities::EntityEnum::ApplicationComponent,
                                                                        "ApplicationComponent"_L1,
                                                                        QleanyEditor::Entities::Entities::EntityEnum::ApplicationFeature,
                                                                        "ApplicationFeature"_L1,
                                                                        "features"_L1,
                                                                        RelationshipType::OneToMany,
                                                                        RelationshipStrength::Strong,
                                                                        RelationshipCardinality::ManyOrdered,
                                                                        RelationshipDirection::Forward}},

                                                                      // fields:
                                                                      {{"id"_L1, FieldType::Integer, true, false},
                                                                       {"uuid"_L1, FieldType::Uuid, false, false},
                                                                       {"creationDate"_L1, FieldType::DateTime, false, false},
                                                                       {"updateDate"_L1, FieldType::DateTime, false, false},
                                                                       {"commonCMakeFolderPath"_L1, FieldType::String, false, false},
                                                                       {"features"_L1, FieldType::Entity, false, true}}};

} // namespace QleanyEditor::Entities
Q_DECLARE_METATYPE(QleanyEditor::Entities::ApplicationComponent)