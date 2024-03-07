// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_project_query_handler.h"
#include "repository/interface_project_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::Project::Queries;

GetProjectQueryHandler::GetProjectQueryHandler(InterfaceProjectRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ProjectDTO> GetProjectQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetProjectQuery &query)
{
    Result<ProjectDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<ProjectDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetProjectQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ProjectDTO> GetProjectQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetProjectQuery &query)
{
    qDebug() << "GetProjectQueryHandler::handleImpl called with id" << query.id;

    // do
    auto projectResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(ProjectDTO, projectResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Project, ProjectDTO>(projectResult.value());

    qDebug() << "GetProjectQueryHandler::handleImpl done";

    return Result<ProjectDTO>(dto);
}

bool GetProjectQueryHandler::s_mappingRegistered = false;

void GetProjectQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Project, Contracts::DTO::Project::ProjectDTO>(true, true);
}