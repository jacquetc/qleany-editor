// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_entity_parent_query_handler.h"
#include "repository/interface_entity_parent_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::EntityParent::Queries;

GetEntityParentQueryHandler::GetEntityParentQueryHandler(InterfaceEntityParentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityParentDTO> GetEntityParentQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetEntityParentQuery &query)
{
    Result<EntityParentDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<EntityParentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetEntityParentQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityParentDTO> GetEntityParentQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityParentQuery &query)
{
    qDebug() << "GetEntityParentQueryHandler::handleImpl called with id" << query.id;

    // do
    auto entityParentResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(EntityParentDTO, entityParentResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityParent, EntityParentDTO>(entityParentResult.value());

    qDebug() << "GetEntityParentQueryHandler::handleImpl done";

    return Result<EntityParentDTO>(dto);
}

bool GetEntityParentQueryHandler::s_mappingRegistered = false;

void GetEntityParentQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityParent, Contracts::DTO::EntityParent::EntityParentDTO>(true, true);
}