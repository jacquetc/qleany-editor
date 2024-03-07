// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_entity_component_query_handler.h"
#include "repository/interface_entity_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::EntityComponent::Queries;

GetEntityComponentQueryHandler::GetEntityComponentQueryHandler(InterfaceEntityComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityComponentDTO> GetEntityComponentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetEntityComponentQuery &query)
{
    Result<EntityComponentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<EntityComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetEntityComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityComponentDTO> GetEntityComponentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityComponentQuery &query)
{
    qDebug() << "GetEntityComponentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto entityComponentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(EntityComponentDTO, entityComponentResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityComponent, EntityComponentDTO>(entityComponentResult.value());

    qDebug() << "GetEntityComponentQueryHandler::handleImpl done";

    return Result<EntityComponentDTO>(dto);
}

bool GetEntityComponentQueryHandler::s_mappingRegistered = false;

void GetEntityComponentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityComponent, Contracts::DTO::EntityComponent::EntityComponentDTO>(true,
                                                                                                                                                         true);
}