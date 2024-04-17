// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_c_r_u_d_with_details_query_handler.h"
#include "repository/interface_c_r_u_d_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CRUD::Queries;

GetCRUDWithDetailsQueryHandler::GetCRUDWithDetailsQueryHandler(InterfaceCRUDRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CRUDWithDetailsDTO> GetCRUDWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCRUDQuery &query)
{
    Result<CRUDWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CRUDWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCRUDQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CRUDWithDetailsDTO> GetCRUDWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCRUDQuery &query)
{
    qDebug() << "GetCRUDWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto cRUDResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(CRUDWithDetailsDTO, cRUDResult)

    QleanyEditor::Entities::CRUD cRUD = cRUDResult.value();

    // map
    auto cRUDWithDetailsDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CRUD, CRUDWithDetailsDTO>(cRUD);

    qDebug() << "GetCRUDWithDetailsQueryHandler::handleImpl done";

    return Result<CRUDWithDetailsDTO>(cRUDWithDetailsDTO);
}

bool GetCRUDWithDetailsQueryHandler::s_mappingRegistered = false;

void GetCRUDWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CRUD, Contracts::DTO::CRUD::CRUDWithDetailsDTO>();
}