// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_recent_project_query_handler.h"
#include "repository/interface_recent_project_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::RecentProject::Queries;

GetRecentProjectQueryHandler::GetRecentProjectQueryHandler(InterfaceRecentProjectRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RecentProjectDTO> GetRecentProjectQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetRecentProjectQuery &query)
{
    Result<RecentProjectDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<RecentProjectDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetRecentProjectQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RecentProjectDTO> GetRecentProjectQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetRecentProjectQuery &query)
{
    qDebug() << "GetRecentProjectQueryHandler::handleImpl called with id" << query.id;

    // do
    auto recentProjectResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(RecentProjectDTO, recentProjectResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::RecentProject, RecentProjectDTO>(recentProjectResult.value());

    qDebug() << "GetRecentProjectQueryHandler::handleImpl done";

    return Result<RecentProjectDTO>(dto);
}

bool GetRecentProjectQueryHandler::s_mappingRegistered = false;

void GetRecentProjectQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::RecentProject, Contracts::DTO::RecentProject::RecentProjectDTO>(true, true);
}