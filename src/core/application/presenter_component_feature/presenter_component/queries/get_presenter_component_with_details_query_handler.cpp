// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_presenter_component_with_details_query_handler.h"
#include "repository/interface_presenter_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::PresenterComponent::Queries;

GetPresenterComponentWithDetailsQueryHandler::GetPresenterComponentWithDetailsQueryHandler(InterfacePresenterComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterComponentWithDetailsDTO> GetPresenterComponentWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                              const GetPresenterComponentQuery &query)
{
    Result<PresenterComponentWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<PresenterComponentWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetPresenterComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterComponentWithDetailsDTO> GetPresenterComponentWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                                  const GetPresenterComponentQuery &query)
{
    qDebug() << "GetPresenterComponentWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto presenterComponentResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(PresenterComponentWithDetailsDTO, presenterComponentResult)

    QleanyEditor::Entities::PresenterComponent presenterComponent = presenterComponentResult.value();

    // map
    auto presenterComponentWithDetailsDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterComponent, PresenterComponentWithDetailsDTO>(presenterComponent);

    qDebug() << "GetPresenterComponentWithDetailsQueryHandler::handleImpl done";

    return Result<PresenterComponentWithDetailsDTO>(presenterComponentWithDetailsDTO);
}

bool GetPresenterComponentWithDetailsQueryHandler::s_mappingRegistered = false;

void GetPresenterComponentWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterComponent,
                                                           Contracts::DTO::PresenterComponent::PresenterComponentWithDetailsDTO>();
}