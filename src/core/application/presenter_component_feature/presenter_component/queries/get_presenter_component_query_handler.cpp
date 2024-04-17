// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_presenter_component_query_handler.h"
#include "repository/interface_presenter_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::PresenterComponent::Queries;

GetPresenterComponentQueryHandler::GetPresenterComponentQueryHandler(InterfacePresenterComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterComponentDTO> GetPresenterComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetPresenterComponentQuery &query)
{
    Result<PresenterComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<PresenterComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetPresenterComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterComponentDTO> GetPresenterComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetPresenterComponentQuery &query)
{
    qDebug() << "GetPresenterComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto presenterComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(PresenterComponentDTO, presenterComponentResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterComponent, PresenterComponentDTO>(presenterComponentResult.value());

    qDebug() << "GetPresenterComponentQueryHandler::handleImpl done";

    return Result<PresenterComponentDTO>(dto);
}

bool GetPresenterComponentQueryHandler::s_mappingRegistered = false;

void GetPresenterComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterComponent,
                                                           Contracts::DTO::PresenterComponent::PresenterComponentDTO>(true, true);
}