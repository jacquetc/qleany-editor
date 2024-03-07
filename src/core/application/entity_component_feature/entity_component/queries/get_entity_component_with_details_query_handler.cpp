// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_entity_component_with_details_query_handler.h"
#include "repository/interface_entity_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::EntityComponent::Queries;

GetEntityComponentWithDetailsQueryHandler::GetEntityComponentWithDetailsQueryHandler(InterfaceEntityComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityComponentWithDetailsDTO> GetEntityComponentWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                        const GetEntityComponentQuery &query)
{
    Result<EntityComponentWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<EntityComponentWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetEntityComponentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityComponentWithDetailsDTO> GetEntityComponentWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                            const GetEntityComponentQuery &query)
{
    qDebug() << "GetEntityComponentWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto entityComponentResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(EntityComponentWithDetailsDTO, entityComponentResult)

    QleanyEditor::Entities::EntityComponent entityComponent = entityComponentResult.value();

    // map
    auto entityComponentWithDetailsDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityComponent, EntityComponentWithDetailsDTO>(entityComponent);

    qDebug() << "GetEntityComponentWithDetailsQueryHandler::handleImpl done";

    return Result<EntityComponentWithDetailsDTO>(entityComponentWithDetailsDTO);
}

bool GetEntityComponentWithDetailsQueryHandler::s_mappingRegistered = false;

void GetEntityComponentWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityComponent,
                                                           Contracts::DTO::EntityComponent::EntityComponentWithDetailsDTO>();
}