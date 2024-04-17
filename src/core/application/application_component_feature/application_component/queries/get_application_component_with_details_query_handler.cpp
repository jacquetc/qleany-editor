// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_application_component_with_details_query_handler.h"
#include "repository/interface_application_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::ApplicationComponent::Queries;

GetApplicationComponentWithDetailsQueryHandler::GetApplicationComponentWithDetailsQueryHandler(InterfaceApplicationComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ApplicationComponentWithDetailsDTO> GetApplicationComponentWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                                  const GetApplicationComponentQuery &query)
{
    Result<ApplicationComponentWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<ApplicationComponentWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetApplicationComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ApplicationComponentWithDetailsDTO> GetApplicationComponentWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                                      const GetApplicationComponentQuery &query)
{
    qDebug() << "GetApplicationComponentWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto applicationComponentResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(ApplicationComponentWithDetailsDTO, applicationComponentResult)

    QleanyEditor::Entities::ApplicationComponent applicationComponent = applicationComponentResult.value();

    // map
    auto applicationComponentWithDetailsDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationComponent, ApplicationComponentWithDetailsDTO>(applicationComponent);

    qDebug() << "GetApplicationComponentWithDetailsQueryHandler::handleImpl done";

    return Result<ApplicationComponentWithDetailsDTO>(applicationComponentWithDetailsDTO);
}

bool GetApplicationComponentWithDetailsQueryHandler::s_mappingRegistered = false;

void GetApplicationComponentWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationComponent,
                                                           Contracts::DTO::ApplicationComponent::ApplicationComponentWithDetailsDTO>();
}