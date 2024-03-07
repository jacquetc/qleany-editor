// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_component/entity_component_with_details_dto.h"
#include "entity_component/queries/get_entity_component_query.h"
#include "qleany_editor_application_entity_component_export.h"

#include "repository/interface_entity_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityComponent::Queries;

namespace QleanyEditor::Application::Features::EntityComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_ENTITY_COMPONENT_EXPORT GetEntityComponentWithDetailsQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetEntityComponentWithDetailsQueryHandler(InterfaceEntityComponentRepository *repository);
    Result<EntityComponentWithDetailsDTO> handle(QPromise<Result<void>> &progressPromise, const GetEntityComponentQuery &query);

private:
    InterfaceEntityComponentRepository *m_repository;
    Result<EntityComponentWithDetailsDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::EntityComponent::Queries