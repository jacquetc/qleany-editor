// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project.h"
#include "qleany_editor_contracts_export.h"
#include <QObject>
#include <qleany/common/result.h>
#include <qleany/contracts/repository/interface_generic_repository.h>
#include <qleany/contracts/repository/interface_repository.h>

using namespace Qleany;

namespace QleanyEditor::Contracts::Repository
{

class QLEANY_EDITOR_CONTRACTS_EXPORT InterfaceProjectRepository
    : public virtual Qleany::Contracts::Repository::InterfaceGenericRepository<QleanyEditor::Entities::Project>,
      public Qleany::Contracts::Repository::InterfaceRepository
{
public:
    virtual ~InterfaceProjectRepository()
    {
    }

    virtual Result<QleanyEditor::Entities::Project> update(QleanyEditor::Entities::Project &&entity) override = 0;
    virtual Result<QleanyEditor::Entities::Project> getWithDetails(int entityId) = 0;

    virtual QleanyEditor::Entities::Project::ApplicationComponentLoader fetchApplicationComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::CqrsComponentLoader fetchCqrsComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::ContractsComponentLoader fetchContractsComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::DtoComponentLoader fetchDtoComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::EntityComponentLoader fetchEntityComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::GlobalComponentLoader fetchGlobalComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::InteractorComponentLoader fetchInteractorComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::PresenterComponentLoader fetchPresenterComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::FrontEndComponentLoader fetchFrontEndComponentLoader() = 0;

    virtual QleanyEditor::Entities::Project::RepositoryComponentLoader fetchRepositoryComponentLoader() = 0;

    virtual Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) = 0;
    virtual Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) = 0;
};
} // namespace QleanyEditor::Contracts::Repository