// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_entity_query_handler.h"
#include "repository/interface_entity_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::Entity::Queries;

GetEntityQueryHandler::GetEntityQueryHandler(InterfaceEntityRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityDTO> GetEntityQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetEntityQuery &query)
{
    Result<EntityDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<EntityDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetEntityQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityDTO> GetEntityQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityQuery &query)
{
    qDebug() << "GetEntityQueryHandler::handleImpl called with id" << query.id;

    // do
    auto entityResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(EntityDTO, entityResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Entity, EntityDTO>(entityResult.value());

    qDebug() << "GetEntityQueryHandler::handleImpl done";

    return Result<EntityDTO>(dto);
}

bool GetEntityQueryHandler::s_mappingRegistered = false;

void GetEntityQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Entity, Contracts::DTO::Entity::EntityDTO>(true, true);
}