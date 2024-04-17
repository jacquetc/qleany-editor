// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_interactor_component_query_handler.h"
#include "repository/interface_interactor_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::InteractorComponent::Queries;

GetInteractorComponentQueryHandler::GetInteractorComponentQueryHandler(InterfaceInteractorComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<InteractorComponentDTO> GetInteractorComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetInteractorComponentQuery &query)
{
    Result<InteractorComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<InteractorComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetInteractorComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<InteractorComponentDTO> GetInteractorComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetInteractorComponentQuery &query)
{
    qDebug() << "GetInteractorComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto interactorComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(InteractorComponentDTO, interactorComponentResult)

    // map
    auto dto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::InteractorComponent, InteractorComponentDTO>(interactorComponentResult.value());

    qDebug() << "GetInteractorComponentQueryHandler::handleImpl done";

    return Result<InteractorComponentDTO>(dto);
}

bool GetInteractorComponentQueryHandler::s_mappingRegistered = false;

void GetInteractorComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::InteractorComponent,
                                                           Contracts::DTO::InteractorComponent::InteractorComponentDTO>(true, true);
}