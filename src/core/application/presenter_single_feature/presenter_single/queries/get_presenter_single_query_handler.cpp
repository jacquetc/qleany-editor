// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_presenter_single_query_handler.h"
#include "repository/interface_presenter_single_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::PresenterSingle::Queries;

GetPresenterSingleQueryHandler::GetPresenterSingleQueryHandler(InterfacePresenterSingleRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterSingleDTO> GetPresenterSingleQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetPresenterSingleQuery &query)
{
    Result<PresenterSingleDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<PresenterSingleDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetPresenterSingleQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterSingleDTO> GetPresenterSingleQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetPresenterSingleQuery &query)
{
    qDebug() << "GetPresenterSingleQueryHandler::handleImpl called with id" << query.id;

    // do
    auto presenterSingleResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(PresenterSingleDTO, presenterSingleResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterSingle, PresenterSingleDTO>(presenterSingleResult.value());

    qDebug() << "GetPresenterSingleQueryHandler::handleImpl done";

    return Result<PresenterSingleDTO>(dto);
}

bool GetPresenterSingleQueryHandler::s_mappingRegistered = false;

void GetPresenterSingleQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterSingle, Contracts::DTO::PresenterSingle::PresenterSingleDTO>(true,
                                                                                                                                                         true);
}