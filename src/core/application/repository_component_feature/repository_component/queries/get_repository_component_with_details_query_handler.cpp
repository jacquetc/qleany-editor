// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_repository_component_with_details_query_handler.h"
#include "repository/interface_repository_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::RepositoryComponent::Queries;

GetRepositoryComponentWithDetailsQueryHandler::GetRepositoryComponentWithDetailsQueryHandler(InterfaceRepositoryComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RepositoryComponentWithDetailsDTO> GetRepositoryComponentWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                                const GetRepositoryComponentQuery &query)
{
    Result<RepositoryComponentWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<RepositoryComponentWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetRepositoryComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RepositoryComponentWithDetailsDTO> GetRepositoryComponentWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                                    const GetRepositoryComponentQuery &query)
{
    qDebug() << "GetRepositoryComponentWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto repositoryComponentResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(RepositoryComponentWithDetailsDTO, repositoryComponentResult)

    QleanyEditor::Entities::RepositoryComponent repositoryComponent = repositoryComponentResult.value();

    // map
    auto repositoryComponentWithDetailsDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::RepositoryComponent, RepositoryComponentWithDetailsDTO>(repositoryComponent);

    qDebug() << "GetRepositoryComponentWithDetailsQueryHandler::handleImpl done";

    return Result<RepositoryComponentWithDetailsDTO>(repositoryComponentWithDetailsDTO);
}

bool GetRepositoryComponentWithDetailsQueryHandler::s_mappingRegistered = false;

void GetRepositoryComponentWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::RepositoryComponent,
                                                           Contracts::DTO::RepositoryComponent::RepositoryComponentWithDetailsDTO>();
}