// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature.h"
#include "qleany_editor_contracts_export.h"
#include <QObject>
#include <qleany/common/result.h>
#include <qleany/contracts/repository/interface_generic_repository.h>
#include <qleany/contracts/repository/interface_repository.h>

using namespace Qleany;

namespace QleanyEditor::Contracts::Repository
{

class QLEANY_EDITOR_CONTRACTS_EXPORT InterfaceApplicationFeatureRepository
    : public virtual Qleany::Contracts::Repository::InterfaceGenericRepository<QleanyEditor::Entities::ApplicationFeature>,
      public Qleany::Contracts::Repository::InterfaceRepository
{
public:
    virtual ~InterfaceApplicationFeatureRepository()
    {
    }

    virtual Result<QleanyEditor::Entities::ApplicationFeature> update(QleanyEditor::Entities::ApplicationFeature &&entity) override = 0;
    virtual Result<QleanyEditor::Entities::ApplicationFeature> getWithDetails(int entityId) = 0;

    virtual QleanyEditor::Entities::ApplicationFeature::CrudLoader fetchCrudLoader() = 0;

    virtual QleanyEditor::Entities::ApplicationFeature::DtoIdenticalToEntityLoader fetchDtoIdenticalToEntityLoader() = 0;

    virtual QleanyEditor::Entities::ApplicationFeature::CustomCommandsLoader fetchCustomCommandsLoader() = 0;

    virtual QleanyEditor::Entities::ApplicationFeature::CustomQueriesLoader fetchCustomQueriesLoader() = 0;

    virtual Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) = 0;
    virtual Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) = 0;
};
} // namespace QleanyEditor::Contracts::Repository