// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field/entity_field_dto.h"
#include "entity_field/queries/get_entity_field_query.h"
#include "qleany_editor_application_entity_field_export.h"

#include "repository/interface_entity_field_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityField::Queries;

namespace QleanyEditor::Application::Features::EntityField::Queries
{
class QLEANY_EDITOR_APPLICATION_ENTITY_FIELD_EXPORT GetEntityFieldQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetEntityFieldQueryHandler(InterfaceEntityFieldRepository *repository);
    Result<EntityFieldDTO> handle(QPromise<Result<void>> &progressPromise, const GetEntityFieldQuery &query);

private:
    InterfaceEntityFieldRepository *m_repository;
    Result<EntityFieldDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityFieldQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::EntityField::Queries