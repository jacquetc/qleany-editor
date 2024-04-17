// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_custom_d_t_o_query_handler.h"
#include "repository/interface_custom_d_t_o_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CustomDTO::Queries;

GetCustomDTOQueryHandler::GetCustomDTOQueryHandler(InterfaceCustomDTORepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomDTODTO> GetCustomDTOQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCustomDTOQuery &query)
{
    Result<CustomDTODTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CustomDTODTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCustomDTOQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomDTODTO> GetCustomDTOQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomDTOQuery &query)
{
    qDebug() << "GetCustomDTOQueryHandler::handleImpl called with id" << query.id;

    // do
    auto customDTOResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(CustomDTODTO, customDTOResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTO, CustomDTODTO>(customDTOResult.value());

    qDebug() << "GetCustomDTOQueryHandler::handleImpl done";

    return Result<CustomDTODTO>(dto);
}

bool GetCustomDTOQueryHandler::s_mappingRegistered = false;

void GetCustomDTOQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTO, Contracts::DTO::CustomDTO::CustomDTODTO>(true, true);
}