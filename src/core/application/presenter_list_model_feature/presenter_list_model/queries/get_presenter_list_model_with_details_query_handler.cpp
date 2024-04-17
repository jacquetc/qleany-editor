// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_presenter_list_model_with_details_query_handler.h"
#include "repository/interface_presenter_list_model_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::PresenterListModel::Queries;

GetPresenterListModelWithDetailsQueryHandler::GetPresenterListModelWithDetailsQueryHandler(InterfacePresenterListModelRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterListModelWithDetailsDTO> GetPresenterListModelWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                              const GetPresenterListModelQuery &query)
{
    Result<PresenterListModelWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<PresenterListModelWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetPresenterListModelQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterListModelWithDetailsDTO> GetPresenterListModelWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                                  const GetPresenterListModelQuery &query)
{
    qDebug() << "GetPresenterListModelWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto presenterListModelResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(PresenterListModelWithDetailsDTO, presenterListModelResult)

    QleanyEditor::Entities::PresenterListModel presenterListModel = presenterListModelResult.value();

    // map
    auto presenterListModelWithDetailsDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterListModel, PresenterListModelWithDetailsDTO>(presenterListModel);

    qDebug() << "GetPresenterListModelWithDetailsQueryHandler::handleImpl done";

    return Result<PresenterListModelWithDetailsDTO>(presenterListModelWithDetailsDTO);
}

bool GetPresenterListModelWithDetailsQueryHandler::s_mappingRegistered = false;

void GetPresenterListModelWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterListModel,
                                                           Contracts::DTO::PresenterListModel::PresenterListModelWithDetailsDTO>();
}