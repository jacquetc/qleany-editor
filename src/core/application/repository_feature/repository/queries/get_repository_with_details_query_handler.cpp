// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_repository_with_details_query_handler.h"
#include "repository/interface_repository_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::Repository::Queries;

GetRepositoryWithDetailsQueryHandler::GetRepositoryWithDetailsQueryHandler(InterfaceRepositoryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RepositoryWithDetailsDTO> GetRepositoryWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetRepositoryQuery &query)
{
    Result<RepositoryWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<RepositoryWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetRepositoryQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RepositoryWithDetailsDTO> GetRepositoryWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetRepositoryQuery &query)
{
    qDebug() << "GetRepositoryWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto repositoryResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(RepositoryWithDetailsDTO, repositoryResult)

    QleanyEditor::Entities::Repository repository = repositoryResult.value();

    // map
    auto repositoryWithDetailsDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Repository, RepositoryWithDetailsDTO>(repository);

    qDebug() << "GetRepositoryWithDetailsQueryHandler::handleImpl done";

    return Result<RepositoryWithDetailsDTO>(repositoryWithDetailsDTO);
}

bool GetRepositoryWithDetailsQueryHandler::s_mappingRegistered = false;

void GetRepositoryWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Repository, Contracts::DTO::Repository::RepositoryWithDetailsDTO>();
}