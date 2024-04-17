// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_repository_component_query_handler.h"
#include "repository/interface_repository_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::RepositoryComponent::Queries;

GetRepositoryComponentQueryHandler::GetRepositoryComponentQueryHandler(InterfaceRepositoryComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RepositoryComponentDTO> GetRepositoryComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetRepositoryComponentQuery &query)
{
    Result<RepositoryComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<RepositoryComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetRepositoryComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RepositoryComponentDTO> GetRepositoryComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetRepositoryComponentQuery &query)
{
    qDebug() << "GetRepositoryComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto repositoryComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(RepositoryComponentDTO, repositoryComponentResult)

    // map
    auto dto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::RepositoryComponent, RepositoryComponentDTO>(repositoryComponentResult.value());

    qDebug() << "GetRepositoryComponentQueryHandler::handleImpl done";

    return Result<RepositoryComponentDTO>(dto);
}

bool GetRepositoryComponentQueryHandler::s_mappingRegistered = false;

void GetRepositoryComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::RepositoryComponent,
                                                           Contracts::DTO::RepositoryComponent::RepositoryComponentDTO>(true, true);
}