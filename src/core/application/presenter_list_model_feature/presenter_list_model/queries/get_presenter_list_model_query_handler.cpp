// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_presenter_list_model_query_handler.h"
#include "repository/interface_presenter_list_model_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::PresenterListModel::Queries;

GetPresenterListModelQueryHandler::GetPresenterListModelQueryHandler(InterfacePresenterListModelRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterListModelDTO> GetPresenterListModelQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetPresenterListModelQuery &query)
{
    Result<PresenterListModelDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<PresenterListModelDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetPresenterListModelQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterListModelDTO> GetPresenterListModelQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetPresenterListModelQuery &query)
{
    qDebug() << "GetPresenterListModelQueryHandler::handleImpl called with id" << query.id;

    // do
    auto presenterListModelResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(PresenterListModelDTO, presenterListModelResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterListModel, PresenterListModelDTO>(presenterListModelResult.value());

    qDebug() << "GetPresenterListModelQueryHandler::handleImpl done";

    return Result<PresenterListModelDTO>(dto);
}

bool GetPresenterListModelQueryHandler::s_mappingRegistered = false;

void GetPresenterListModelQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterListModel,
                                                           Contracts::DTO::PresenterListModel::PresenterListModelDTO>(true, true);
}