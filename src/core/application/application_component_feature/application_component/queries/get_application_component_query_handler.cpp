// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_application_component_query_handler.h"
#include "repository/interface_application_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::ApplicationComponent::Queries;

GetApplicationComponentQueryHandler::GetApplicationComponentQueryHandler(InterfaceApplicationComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ApplicationComponentDTO> GetApplicationComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetApplicationComponentQuery &query)
{
    Result<ApplicationComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<ApplicationComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetApplicationComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ApplicationComponentDTO> GetApplicationComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                const GetApplicationComponentQuery &query)
{
    qDebug() << "GetApplicationComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto applicationComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(ApplicationComponentDTO, applicationComponentResult)

    // map
    auto dto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationComponent, ApplicationComponentDTO>(applicationComponentResult.value());

    qDebug() << "GetApplicationComponentQueryHandler::handleImpl done";

    return Result<ApplicationComponentDTO>(dto);
}

bool GetApplicationComponentQueryHandler::s_mappingRegistered = false;

void GetApplicationComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationComponent,
                                                           Contracts::DTO::ApplicationComponent::ApplicationComponentDTO>(true, true);
}