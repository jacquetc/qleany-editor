// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_all_front_end_component_query_handler.h"
#include "repository/interface_front_end_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::FrontEndComponent::Queries;

GetAllFrontEndComponentQueryHandler::GetAllFrontEndComponentQueryHandler(InterfaceFrontEndComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<QList<FrontEndComponentDTO>> GetAllFrontEndComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise)
{
    qDebug() << "GetAllFrontEndComponentQueryHandler::handle called";

    Result<QList<FrontEndComponentDTO>> result;

    try {
        result = handleImpl(progressPromise);
    } catch (const std::exception &ex) {
        result = Result<QList<FrontEndComponentDTO>>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetAllFrontEndComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<QList<FrontEndComponentDTO>> GetAllFrontEndComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise)
{
    qDebug() << "GetAllFrontEndComponentQueryHandler::handleImpl called";

    // do
    auto frontEndComponentResult = m_repository->getAll();

    QLN_RETURN_IF_ERROR(QList<FrontEndComponentDTO>, frontEndComponentResult)

    // map
    QList<FrontEndComponentDTO> dtoList;

    for (const QleanyEditor::Entities::FrontEndComponent &frontEndComponent : frontEndComponentResult.value()) {
        auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::FrontEndComponent, FrontEndComponentDTO>(frontEndComponent);
        dtoList.append(dto);
    }

    qDebug() << "GetAllFrontEndComponentQueryHandler::handleImpl done";

    return Result<QList<FrontEndComponentDTO>>(dtoList);
}

bool GetAllFrontEndComponentQueryHandler::s_mappingRegistered = false;

void GetAllFrontEndComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::FrontEndComponent, Contracts::DTO::FrontEndComponent::FrontEndComponentDTO>(
        true,
        true);
}