// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_c_q_r_s_component_query_handler.h"
#include "repository/interface_c_q_r_s_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CQRSComponent::Queries;

GetCQRSComponentQueryHandler::GetCQRSComponentQueryHandler(InterfaceCQRSComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CQRSComponentDTO> GetCQRSComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCQRSComponentQuery &query)
{
    Result<CQRSComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CQRSComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCQRSComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CQRSComponentDTO> GetCQRSComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCQRSComponentQuery &query)
{
    qDebug() << "GetCQRSComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto cQRSComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(CQRSComponentDTO, cQRSComponentResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CQRSComponent, CQRSComponentDTO>(cQRSComponentResult.value());

    qDebug() << "GetCQRSComponentQueryHandler::handleImpl done";

    return Result<CQRSComponentDTO>(dto);
}

bool GetCQRSComponentQueryHandler::s_mappingRegistered = false;

void GetCQRSComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CQRSComponent, Contracts::DTO::CQRSComponent::CQRSComponentDTO>(true, true);
}