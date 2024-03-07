// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "persistence_registration.h"
#include <qleany/database/database_context.h>
#include <qleany/database/database_table_group.h>

#include "repository/entity_component_repository.h"
#include "repository/entity_repository.h"
#include "repository/global_component_repository.h"
#include "repository/project_repository.h"
#include "repository/recent_project_repository.h"
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

    auto *entityDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::Entity>(context);
    auto *entityComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::EntityComponent>(context);
    auto *globalComponentDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::GlobalComponent>(context);
    auto *projectDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::Project>(context);
    auto *recentProjectDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::RecentProject>(context);
    auto *rootDatabaseTableGroup = new DatabaseTableGroup<QleanyEditor::Entities::Root>(context);

    Result<void> initResult = context->init();

    if (initResult.hasError()) {
        Error error = initResult.error();
        qCritical() << error.className() + "\n" + error.code() + "\n" + error.message() + "\n" + error.data();
    }

    // repositories:

    EntityRepository *entityRepository = new EntityRepository(entityDatabaseTableGroup);
    EntityComponentRepository *entityComponentRepository = new EntityComponentRepository(entityComponentDatabaseTableGroup, entityRepository);
    GlobalComponentRepository *globalComponentRepository = new GlobalComponentRepository(globalComponentDatabaseTableGroup);
    ProjectRepository *projectRepository = new ProjectRepository(projectDatabaseTableGroup, globalComponentRepository);
    RecentProjectRepository *recentProjectRepository = new RecentProjectRepository(recentProjectDatabaseTableGroup);
    RootRepository *rootRepository = new RootRepository(rootDatabaseTableGroup, projectRepository, recentProjectRepository);

    // register repositories:

    RepositoryProvider::instance()->registerRepository("entity", entityRepository);
    RepositoryProvider::instance()->registerRepository("entityComponent", entityComponentRepository);
    RepositoryProvider::instance()->registerRepository("globalComponent", globalComponentRepository);
    RepositoryProvider::instance()->registerRepository("project", projectRepository);
    RepositoryProvider::instance()->registerRepository("recentProject", recentProjectRepository);
    RepositoryProvider::instance()->registerRepository("root", rootRepository);
}

RepositoryProvider *PersistenceRegistration::repositoryProvider()
{
    return RepositoryProvider::instance();
}