// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_custom_query_query_handler.h"
#include "repository/interface_custom_query_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CustomQuery::Queries;

GetCustomQueryQueryHandler::GetCustomQueryQueryHandler(InterfaceCustomQueryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomQueryDTO> GetCustomQueryQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCustomQueryQuery &query)
{
    Result<CustomQueryDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CustomQueryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCustomQueryQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomQueryDTO> GetCustomQueryQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomQueryQuery &query)
{
    qDebug() << "GetCustomQueryQueryHandler::handleImpl called with id" << query.id;

    // do
    auto customQueryResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(CustomQueryDTO, customQueryResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomQuery, CustomQueryDTO>(customQueryResult.value());

    qDebug() << "GetCustomQueryQueryHandler::handleImpl done";

    return Result<CustomQueryDTO>(dto);
}

bool GetCustomQueryQueryHandler::s_mappingRegistered = false;

void GetCustomQueryQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomQuery, Contracts::DTO::CustomQuery::CustomQueryDTO>(true, true);
}