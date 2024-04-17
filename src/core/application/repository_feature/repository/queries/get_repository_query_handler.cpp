// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_repository_query_handler.h"
#include "repository/interface_repository_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::Repository::Queries;

GetRepositoryQueryHandler::GetRepositoryQueryHandler(InterfaceRepositoryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RepositoryDTO> GetRepositoryQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetRepositoryQuery &query)
{
    Result<RepositoryDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<RepositoryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetRepositoryQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RepositoryDTO> GetRepositoryQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetRepositoryQuery &query)
{
    qDebug() << "GetRepositoryQueryHandler::handleImpl called with id" << query.id;

    // do
    auto repositoryResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(RepositoryDTO, repositoryResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Repository, RepositoryDTO>(repositoryResult.value());

    qDebug() << "GetRepositoryQueryHandler::handleImpl done";

    return Result<RepositoryDTO>(dto);
}

bool GetRepositoryQueryHandler::s_mappingRegistered = false;

void GetRepositoryQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Repository, Contracts::DTO::Repository::RepositoryDTO>(true, true);
}