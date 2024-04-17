// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_d_t_o_component_query_handler.h"
#include "repository/interface_d_t_o_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::DTOComponent::Queries;

GetDTOComponentQueryHandler::GetDTOComponentQueryHandler(InterfaceDTOComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<DTOComponentDTO> GetDTOComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetDTOComponentQuery &query)
{
    Result<DTOComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<DTOComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetDTOComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<DTOComponentDTO> GetDTOComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetDTOComponentQuery &query)
{
    qDebug() << "GetDTOComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto dTOComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(DTOComponentDTO, dTOComponentResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::DTOComponent, DTOComponentDTO>(dTOComponentResult.value());

    qDebug() << "GetDTOComponentQueryHandler::handleImpl done";

    return Result<DTOComponentDTO>(dto);
}

bool GetDTOComponentQueryHandler::s_mappingRegistered = false;

void GetDTOComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::DTOComponent, Contracts::DTO::DTOComponent::DTOComponentDTO>(true, true);
}