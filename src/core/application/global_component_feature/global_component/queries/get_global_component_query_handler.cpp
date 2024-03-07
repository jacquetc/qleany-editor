// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_global_component_query_handler.h"
#include "repository/interface_global_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::GlobalComponent::Queries;

GetGlobalComponentQueryHandler::GetGlobalComponentQueryHandler(InterfaceGlobalComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<GlobalComponentDTO> GetGlobalComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetGlobalComponentQuery &query)
{
    Result<GlobalComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<GlobalComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetGlobalComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<GlobalComponentDTO> GetGlobalComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetGlobalComponentQuery &query)
{
    qDebug() << "GetGlobalComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto globalComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(GlobalComponentDTO, globalComponentResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::GlobalComponent, GlobalComponentDTO>(globalComponentResult.value());

    qDebug() << "GetGlobalComponentQueryHandler::handleImpl done";

    return Result<GlobalComponentDTO>(dto);
}

bool GetGlobalComponentQueryHandler::s_mappingRegistered = false;

void GetGlobalComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::GlobalComponent, Contracts::DTO::GlobalComponent::GlobalComponentDTO>(true,
                                                                                                                                                         true);
}