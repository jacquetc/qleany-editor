// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_presenter_single_with_details_query_handler.h"
#include "repository/interface_presenter_single_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::PresenterSingle::Queries;

GetPresenterSingleWithDetailsQueryHandler::GetPresenterSingleWithDetailsQueryHandler(InterfacePresenterSingleRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterSingleWithDetailsDTO> GetPresenterSingleWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                        const GetPresenterSingleQuery &query)
{
    Result<PresenterSingleWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<PresenterSingleWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetPresenterSingleQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterSingleWithDetailsDTO> GetPresenterSingleWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                            const GetPresenterSingleQuery &query)
{
    qDebug() << "GetPresenterSingleWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto presenterSingleResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(PresenterSingleWithDetailsDTO, presenterSingleResult)

    QleanyEditor::Entities::PresenterSingle presenterSingle = presenterSingleResult.value();

    // map
    auto presenterSingleWithDetailsDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterSingle, PresenterSingleWithDetailsDTO>(presenterSingle);

    qDebug() << "GetPresenterSingleWithDetailsQueryHandler::handleImpl done";

    return Result<PresenterSingleWithDetailsDTO>(presenterSingleWithDetailsDTO);
}

bool GetPresenterSingleWithDetailsQueryHandler::s_mappingRegistered = false;

void GetPresenterSingleWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterSingle,
                                                           Contracts::DTO::PresenterSingle::PresenterSingleWithDetailsDTO>();
}