// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_c_r_u_d_query_handler.h"
#include "repository/interface_c_r_u_d_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CRUD::Queries;

GetCRUDQueryHandler::GetCRUDQueryHandler(InterfaceCRUDRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CRUDDTO> GetCRUDQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCRUDQuery &query)
{
    Result<CRUDDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CRUDDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCRUDQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CRUDDTO> GetCRUDQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCRUDQuery &query)
{
    qDebug() << "GetCRUDQueryHandler::handleImpl called with id" << query.id;

    // do
    auto cRUDResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(CRUDDTO, cRUDResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CRUD, CRUDDTO>(cRUDResult.value());

    qDebug() << "GetCRUDQueryHandler::handleImpl done";

    return Result<CRUDDTO>(dto);
}

bool GetCRUDQueryHandler::s_mappingRegistered = false;

void GetCRUDQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CRUD, Contracts::DTO::CRUD::CRUDDTO>(true, true);
}