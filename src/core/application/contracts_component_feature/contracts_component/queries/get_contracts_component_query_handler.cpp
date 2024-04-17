// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_contracts_component_query_handler.h"
#include "repository/interface_contracts_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::ContractsComponent::Queries;

GetContractsComponentQueryHandler::GetContractsComponentQueryHandler(InterfaceContractsComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ContractsComponentDTO> GetContractsComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetContractsComponentQuery &query)
{
    Result<ContractsComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<ContractsComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetContractsComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ContractsComponentDTO> GetContractsComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetContractsComponentQuery &query)
{
    qDebug() << "GetContractsComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto contractsComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(ContractsComponentDTO, contractsComponentResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ContractsComponent, ContractsComponentDTO>(contractsComponentResult.value());

    qDebug() << "GetContractsComponentQueryHandler::handleImpl done";

    return Result<ContractsComponentDTO>(dto);
}

bool GetContractsComponentQueryHandler::s_mappingRegistered = false;

void GetContractsComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ContractsComponent,
                                                           Contracts::DTO::ContractsComponent::ContractsComponentDTO>(true, true);
}