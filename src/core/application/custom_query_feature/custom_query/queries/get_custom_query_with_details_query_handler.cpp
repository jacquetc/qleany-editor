// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_custom_query_with_details_query_handler.h"
#include "repository/interface_custom_query_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CustomQuery::Queries;

GetCustomQueryWithDetailsQueryHandler::GetCustomQueryWithDetailsQueryHandler(InterfaceCustomQueryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomQueryWithDetailsDTO> GetCustomQueryWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCustomQueryQuery &query)
{
    Result<CustomQueryWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CustomQueryWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCustomQueryQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomQueryWithDetailsDTO> GetCustomQueryWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomQueryQuery &query)
{
    qDebug() << "GetCustomQueryWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto customQueryResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(CustomQueryWithDetailsDTO, customQueryResult)

    QleanyEditor::Entities::CustomQuery customQuery = customQueryResult.value();

    // map
    auto customQueryWithDetailsDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomQuery, CustomQueryWithDetailsDTO>(customQuery);

    qDebug() << "GetCustomQueryWithDetailsQueryHandler::handleImpl done";

    return Result<CustomQueryWithDetailsDTO>(customQueryWithDetailsDTO);
}

bool GetCustomQueryWithDetailsQueryHandler::s_mappingRegistered = false;

void GetCustomQueryWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomQuery, Contracts::DTO::CustomQuery::CustomQueryWithDetailsDTO>();
}