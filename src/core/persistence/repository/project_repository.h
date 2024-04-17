// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_application_component_repository.h"
#include "repository/interface_c_q_r_s_component_repository.h"
#include "repository/interface_contracts_component_repository.h"
#include "repository/interface_d_t_o_component_repository.h"
#include "repository/interface_entity_component_repository.h"
#include "repository/interface_front_end_component_repository.h"
#include "repository/interface_global_component_repository.h"
#include "repository/interface_interactor_component_repository.h"
#include "repository/interface_presenter_component_repository.h"
#include "repository/interface_project_repository.h"
#include "repository/interface_repository_component_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT ProjectRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::Project>,
                                                                 public QleanyEditor::Contracts::Repository::InterfaceProjectRepository
{
public:
    explicit ProjectRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::Project> *projectDatabase,
                               InterfaceApplicationComponentRepository *applicationComponentRepository,
                               InterfaceCQRSComponentRepository *cQRSComponentRepository,
                               InterfaceContractsComponentRepository *contractsComponentRepository,
                               InterfaceDTOComponentRepository *dTOComponentRepository,
                               InterfaceEntityComponentRepository *entityComponentRepository,
                               InterfaceFrontEndComponentRepository *frontEndComponentRepository,
                               InterfaceGlobalComponentRepository *globalComponentRepository,
                               InterfaceInteractorComponentRepository *interactorComponentRepository,
                               InterfacePresenterComponentRepository *presenterComponentRepository,
                               InterfaceRepositoryComponentRepository *repositoryComponentRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::Project> update(QleanyEditor::Entities::Project &&entity) override;
    Result<QleanyEditor::Entities::Project> getWithDetails(int entityId) override;

    QleanyEditor::Entities::Project::ApplicationComponentLoader fetchApplicationComponentLoader() override;

    QleanyEditor::Entities::Project::CqrsComponentLoader fetchCqrsComponentLoader() override;

    QleanyEditor::Entities::Project::ContractsComponentLoader fetchContractsComponentLoader() override;

    QleanyEditor::Entities::Project::DtoComponentLoader fetchDtoComponentLoader() override;

    QleanyEditor::Entities::Project::EntityComponentLoader fetchEntityComponentLoader() override;

    QleanyEditor::Entities::Project::GlobalComponentLoader fetchGlobalComponentLoader() override;

    QleanyEditor::Entities::Project::InteractorComponentLoader fetchInteractorComponentLoader() override;

    QleanyEditor::Entities::Project::PresenterComponentLoader fetchPresenterComponentLoader() override;

    QleanyEditor::Entities::Project::FrontEndComponentLoader fetchFrontEndComponentLoader() override;

    QleanyEditor::Entities::Project::RepositoryComponentLoader fetchRepositoryComponentLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceApplicationComponentRepository *m_applicationComponentRepository;
    InterfaceCQRSComponentRepository *m_cQRSComponentRepository;
    InterfaceContractsComponentRepository *m_contractsComponentRepository;
    InterfaceDTOComponentRepository *m_dTOComponentRepository;
    InterfaceEntityComponentRepository *m_entityComponentRepository;
    InterfaceGlobalComponentRepository *m_globalComponentRepository;
    InterfaceInteractorComponentRepository *m_interactorComponentRepository;
    InterfacePresenterComponentRepository *m_presenterComponentRepository;
    InterfaceFrontEndComponentRepository *m_frontEndComponentRepository;
    InterfaceRepositoryComponentRepository *m_repositoryComponentRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository