// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_entity_with_details_query_handler.h"
#include "repository/interface_entity_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::Entity::Queries;

GetEntityWithDetailsQueryHandler::GetEntityWithDetailsQueryHandler(InterfaceEntityRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityWithDetailsDTO> GetEntityWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetEntityQuery &query)
{
    Result<EntityWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<EntityWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetEntityQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityWithDetailsDTO> GetEntityWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityQuery &query)
{
    qDebug() << "GetEntityWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto entityResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(EntityWithDetailsDTO, entityResult)

    QleanyEditor::Entities::Entity entity = entityResult.value();

    // map
    auto entityWithDetailsDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Entity, EntityWithDetailsDTO>(entity);

    qDebug() << "GetEntityWithDetailsQueryHandler::handleImpl done";

    return Result<EntityWithDetailsDTO>(entityWithDetailsDTO);
}

bool GetEntityWithDetailsQueryHandler::s_mappingRegistered = false;

void GetEntityWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Entity, Contracts::DTO::Entity::EntityWithDetailsDTO>();
}