// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_entity_field_query_handler.h"
#include "repository/interface_entity_field_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::EntityField::Queries;

GetEntityFieldQueryHandler::GetEntityFieldQueryHandler(InterfaceEntityFieldRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityFieldDTO> GetEntityFieldQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetEntityFieldQuery &query)
{
    Result<EntityFieldDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<EntityFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetEntityFieldQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityFieldDTO> GetEntityFieldQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityFieldQuery &query)
{
    qDebug() << "GetEntityFieldQueryHandler::handleImpl called with id" << query.id;

    // do
    auto entityFieldResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(EntityFieldDTO, entityFieldResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityField, EntityFieldDTO>(entityFieldResult.value());

    qDebug() << "GetEntityFieldQueryHandler::handleImpl done";

    return Result<EntityFieldDTO>(dto);
}

bool GetEntityFieldQueryHandler::s_mappingRegistered = false;

void GetEntityFieldQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityField, Contracts::DTO::EntityField::EntityFieldDTO>(true, true);
}