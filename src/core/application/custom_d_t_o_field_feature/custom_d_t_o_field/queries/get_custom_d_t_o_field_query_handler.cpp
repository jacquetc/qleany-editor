// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_custom_d_t_o_field_query_handler.h"
#include "repository/interface_custom_d_t_o_field_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CustomDTOField::Queries;

GetCustomDTOFieldQueryHandler::GetCustomDTOFieldQueryHandler(InterfaceCustomDTOFieldRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomDTOFieldDTO> GetCustomDTOFieldQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCustomDTOFieldQuery &query)
{
    Result<CustomDTOFieldDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CustomDTOFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCustomDTOFieldQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomDTOFieldDTO> GetCustomDTOFieldQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomDTOFieldQuery &query)
{
    qDebug() << "GetCustomDTOFieldQueryHandler::handleImpl called with id" << query.id;

    // do
    auto customDTOFieldResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(CustomDTOFieldDTO, customDTOFieldResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTOField, CustomDTOFieldDTO>(customDTOFieldResult.value());

    qDebug() << "GetCustomDTOFieldQueryHandler::handleImpl done";

    return Result<CustomDTOFieldDTO>(dto);
}

bool GetCustomDTOFieldQueryHandler::s_mappingRegistered = false;

void GetCustomDTOFieldQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTOField, Contracts::DTO::CustomDTOField::CustomDTOFieldDTO>(true,
                                                                                                                                                      true);
}