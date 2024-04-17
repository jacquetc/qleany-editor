// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_custom_d_t_o_with_details_query_handler.h"
#include "repository/interface_custom_d_t_o_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CustomDTO::Queries;

GetCustomDTOWithDetailsQueryHandler::GetCustomDTOWithDetailsQueryHandler(InterfaceCustomDTORepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomDTOWithDetailsDTO> GetCustomDTOWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCustomDTOQuery &query)
{
    Result<CustomDTOWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CustomDTOWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCustomDTOQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomDTOWithDetailsDTO> GetCustomDTOWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomDTOQuery &query)
{
    qDebug() << "GetCustomDTOWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto customDTOResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(CustomDTOWithDetailsDTO, customDTOResult)

    QleanyEditor::Entities::CustomDTO customDTO = customDTOResult.value();

    // map
    auto customDTOWithDetailsDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTO, CustomDTOWithDetailsDTO>(customDTO);

    qDebug() << "GetCustomDTOWithDetailsQueryHandler::handleImpl done";

    return Result<CustomDTOWithDetailsDTO>(customDTOWithDetailsDTO);
}

bool GetCustomDTOWithDetailsQueryHandler::s_mappingRegistered = false;

void GetCustomDTOWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTO, Contracts::DTO::CustomDTO::CustomDTOWithDetailsDTO>();
}