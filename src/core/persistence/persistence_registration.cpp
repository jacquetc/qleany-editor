// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "persistence_registration.h"
#include <qleany/database/database_context.h>
#include <qleany/database/database_table_group.h>

#include "repository/application_component_repository.h"
#include "repository/application_feature_repository.h"
#include "repository/c_q_r_s_component_repository.h"
#include "repository/c_r_u_d_repository.h"
#include "repository/contracts_component_repository.h"
#include "repository/custom_command_repository.h"
#include "repository/custom_d_t_o_field_repository.h"
#include "repository/custom_d_t_o_repository.h"
#include "repository/custom_query_repository.h"
#include "repository/d_t_o_component_repository.h"
#include "repository/entity_component_repository.h"
#include "repository/entity_field_repository.h"
#include "repository/entity_parent_repository.h"
#include "repository/entity_repository.h"
#include "repository/front_end_component_repository.h"
#include "repository/global_component_repository.h"
#include "repository/interactor_component_repository.h"
#include "repository/presenter_component_repository.h"
#include "repository/presenter_list_model_repository.h"
#include "repository/presenter_single_repository.h"
#include "repository/project_repository.h"
#include "repository/recent_project_repository.h"
#include "repository/repository_component_repository.h"
#include "repository/repository_repository.h"
#include "repository/root_repository.h"

using namespace Qleany;
using namespace Qleany::Database;
using namespace Qleany::Repository;
using namespace QleanyEditor::Persistence;
using namespace QleanyEditor::Persistence::Repository;

PersistenceRegistration::PersistenceRegistration(QObject *parent)
    : QObject{parent}
{
    QSharedPointer<DatabaseContext> context(new DatabaseContext());

    // database tables:

    auto *applicationComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::ApplicationComponent>(context);
    auto *applicationFeatureDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::ApplicationFeature>(context);
    auto *cQRSComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::CQRSComponent>(context);
    auto *cRUDDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::CRUD>(context);
    auto *contractsComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::ContractsComponent>(context);
    auto *customCommandDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::CustomCommand>(context);
    auto *customDTODatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::CustomDTO>(context);
    auto *customDTOFieldDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::CustomDTOField>(context);
    auto *customQueryDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::CustomQuery>(context);
    auto *dTOComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::DTOComponent>(context);
    auto *entityDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::Entity>(context);
    auto *entityComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::EntityComponent>(context);
    auto *entityFieldDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::EntityField>(context);
    auto *entityParentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::EntityParent>(context);
    auto *frontEndComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::FrontEndComponent>(context);
    auto *globalComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::GlobalComponent>(context);
    auto *interactorComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::InteractorComponent>(context);
    auto *presenterComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::PresenterComponent>(context);
    auto *presenterListModelDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::PresenterListModel>(context);
    auto *presenterSingleDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::PresenterSingle>(context);
    auto *projectDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::Project>(context);
    auto *recentProjectDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::RecentProject>(context);
    auto *repositoryDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::Repository>(context);
    auto *repositoryComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::RepositoryComponent>(context);
    auto *rootDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::Root>(context);

    Result<void> initResult = context->init();

    if (initResult.hasError()) {
        Error error = initResult.error();
        qCritical() << error.className() + "\n"_L1 + error.code() + "\n"_L1 + error.message() + "\n"_L1 + error.data();
    }

    // repositories:

    CQRSComponentRepository *cQRSComponentRepository = new CQRSComponentRepository(cQRSComponentDatabaseTableGroup);
    ContractsComponentRepository *contractsComponentRepository = new ContractsComponentRepository(contractsComponentDatabaseTableGroup);
    CustomDTOFieldRepository *customDTOFieldRepository = new CustomDTOFieldRepository(customDTOFieldDatabaseTableGroup);
    CustomDTORepository *customDTORepository = new CustomDTORepository(customDTODatabaseTableGroup, customDTOFieldRepository);
    DTOComponentRepository *dTOComponentRepository = new DTOComponentRepository(dTOComponentDatabaseTableGroup);
    EntityFieldRepository *entityFieldRepository = new EntityFieldRepository(entityFieldDatabaseTableGroup);
    EntityParentRepository *entityParentRepository = new EntityParentRepository(entityParentDatabaseTableGroup);
    EntityRepository *entityRepository = new EntityRepository(entityDatabaseTableGroup, entityFieldRepository, entityParentRepository);
    CustomCommandRepository *customCommandRepository = new CustomCommandRepository(customCommandDatabaseTableGroup, customDTORepository, entityRepository);
    CustomQueryRepository *customQueryRepository = new CustomQueryRepository(customQueryDatabaseTableGroup, customDTORepository, entityRepository);
    EntityComponentRepository *entityComponentRepository = new EntityComponentRepository(entityComponentDatabaseTableGroup, entityRepository);
    FrontEndComponentRepository *frontEndComponentRepository = new FrontEndComponentRepository(frontEndComponentDatabaseTableGroup);
    GlobalComponentRepository *globalComponentRepository = new GlobalComponentRepository(globalComponentDatabaseTableGroup);
    InteractorComponentRepository *interactorComponentRepository = new InteractorComponentRepository(interactorComponentDatabaseTableGroup);
    PresenterListModelRepository *presenterListModelRepository =
        new PresenterListModelRepository(presenterListModelDatabaseTableGroup, entityFieldRepository, entityRepository);
    PresenterSingleRepository *presenterSingleRepository = new PresenterSingleRepository(presenterSingleDatabaseTableGroup, entityRepository);
    RecentProjectRepository *recentProjectRepository = new RecentProjectRepository(recentProjectDatabaseTableGroup);
    RepositoryRepository *repositoryRepository = new RepositoryRepository(repositoryDatabaseTableGroup, entityRepository);
    RepositoryComponentRepository *repositoryComponentRepository =
        new RepositoryComponentRepository(repositoryComponentDatabaseTableGroup, repositoryRepository);
    CRUDRepository *cRUDRepository = new CRUDRepository(cRUDDatabaseTableGroup, entityRepository);

    ApplicationFeatureRepository *applicationFeatureRepository = new ApplicationFeatureRepository(applicationFeatureDatabaseTableGroup,
                                                                                                  cRUDRepository,
                                                                                                  customCommandRepository,
                                                                                                  customQueryRepository,
                                                                                                  entityRepository);
    ApplicationComponentRepository *applicationComponentRepository =
        new ApplicationComponentRepository(applicationComponentDatabaseTableGroup, applicationFeatureRepository);
    PresenterComponentRepository *presenterComponentRepository =
        new PresenterComponentRepository(presenterComponentDatabaseTableGroup, presenterListModelRepository, presenterSingleRepository);
    ProjectRepository *projectRepository = new ProjectRepository(projectDatabaseTableGroup,
                                                                 applicationComponentRepository,
                                                                 cQRSComponentRepository,
                                                                 contractsComponentRepository,
                                                                 dTOComponentRepository,
                                                                 entityComponentRepository,
                                                                 frontEndComponentRepository,
                                                                 globalComponentRepository,
                                                                 interactorComponentRepository,
                                                                 presenterComponentRepository,
                                                                 repositoryComponentRepository);
    RootRepository *rootRepository = new RootRepository(rootDatabaseTableGroup, projectRepository, recentProjectRepository);

    // register repositories:

    RepositoryProvider::instance()->registerRepository("applicationComponent", applicationComponentRepository);
    RepositoryProvider::instance()->registerRepository("applicationFeature", applicationFeatureRepository);
    RepositoryProvider::instance()->registerRepository("cQRSComponent", cQRSComponentRepository);
    RepositoryProvider::instance()->registerRepository("cRUD", cRUDRepository);
    RepositoryProvider::instance()->registerRepository("contractsComponent", contractsComponentRepository);
    RepositoryProvider::instance()->registerRepository("customCommand", customCommandRepository);
    RepositoryProvider::instance()->registerRepository("customDTO", customDTORepository);
    RepositoryProvider::instance()->registerRepository("customDTOField", customDTOFieldRepository);
    RepositoryProvider::instance()->registerRepository("customQuery", customQueryRepository);
    RepositoryProvider::instance()->registerRepository("dTOComponent", dTOComponentRepository);
    RepositoryProvider::instance()->registerRepository("entity", entityRepository);
    RepositoryProvider::instance()->registerRepository("entityComponent", entityComponentRepository);
    RepositoryProvider::instance()->registerRepository("entityField", entityFieldRepository);
    RepositoryProvider::instance()->registerRepository("entityParent", entityParentRepository);
    RepositoryProvider::instance()->registerRepository("frontEndComponent", frontEndComponentRepository);
    RepositoryProvider::instance()->registerRepository("globalComponent", globalComponentRepository);
    RepositoryProvider::instance()->registerRepository("interactorComponent", interactorComponentRepository);
    RepositoryProvider::instance()->registerRepository("presenterComponent", presenterComponentRepository);
    RepositoryProvider::instance()->registerRepository("presenterListModel", presenterListModelRepository);
    RepositoryProvider::instance()->registerRepository("presenterSingle", presenterSingleRepository);
    RepositoryProvider::instance()->registerRepository("project", projectRepository);
    RepositoryProvider::instance()->registerRepository("recentProject", recentProjectRepository);
    RepositoryProvider::instance()->registerRepository("repository", repositoryRepository);
    RepositoryProvider::instance()->registerRepository("repositoryComponent", repositoryComponentRepository);
    RepositoryProvider::instance()->registerRepository("root", rootRepository);
}

RepositoryProvider *PersistenceRegistration::repositoryProvider()
{
    return RepositoryProvider::instance();
}
