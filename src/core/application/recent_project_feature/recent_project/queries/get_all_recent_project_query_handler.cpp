// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_all_recent_project_query_handler.h"
#include "repository/interface_recent_project_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::RecentProject::Queries;

GetAllRecentProjectQueryHandler::GetAllRecentProjectQueryHandler(InterfaceRecentProjectRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<QList<RecentProjectDTO>> GetAllRecentProjectQueryHandler::handle(QPromise<Result<void>> &progressPromise)
{
    qDebug() << "GetAllRecentProjectQueryHandler::handle called";

    Result<QList<RecentProjectDTO>> result;

    try {
        result = handleImpl(progressPromise);
    } catch (const std::exception &ex) {
        result = Result<QList<RecentProjectDTO>>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetAllRecentProjectQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<QList<RecentProjectDTO>> GetAllRecentProjectQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise)
{
    qDebug() << "GetAllRecentProjectQueryHandler::handleImpl called";

    // do
    auto recentProjectResult = m_repository->getAll();

    QLN_RETURN_IF_ERROR(QList<RecentProjectDTO>, recentProjectResult)

    // map
    QList<RecentProjectDTO> dtoList;

    for (const QleanyEditor::Entities::RecentProject &recentProject : recentProjectResult.value()) {
        auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::RecentProject, RecentProjectDTO>(recentProject);
        dtoList.append(dto);
    }

    qDebug() << "GetAllRecentProjectQueryHandler::handleImpl done";

    return Result<QList<RecentProjectDTO>>(dtoList);
}

bool GetAllRecentProjectQueryHandler::s_mappingRegistered = false;

void GetAllRecentProjectQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::RecentProject, Contracts::DTO::RecentProject::RecentProjectDTO>(true, true);
}