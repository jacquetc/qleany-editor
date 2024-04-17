// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_front_end_component_query_handler.h"
#include "repository/interface_front_end_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::FrontEndComponent::Queries;

GetFrontEndComponentQueryHandler::GetFrontEndComponentQueryHandler(InterfaceFrontEndComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<FrontEndComponentDTO> GetFrontEndComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetFrontEndComponentQuery &query)
{
    Result<FrontEndComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<FrontEndComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetFrontEndComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<FrontEndComponentDTO> GetFrontEndComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetFrontEndComponentQuery &query)
{
    qDebug() << "GetFrontEndComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto frontEndComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(FrontEndComponentDTO, frontEndComponentResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::FrontEndComponent, FrontEndComponentDTO>(frontEndComponentResult.value());

    qDebug() << "GetFrontEndComponentQueryHandler::handleImpl done";

    return Result<FrontEndComponentDTO>(dto);
}

bool GetFrontEndComponentQueryHandler::s_mappingRegistered = false;

void GetFrontEndComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::FrontEndComponent, Contracts::DTO::FrontEndComponent::FrontEndComponentDTO>(
        true,
        true);
}