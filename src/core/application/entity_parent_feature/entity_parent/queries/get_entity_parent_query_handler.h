// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_parent/entity_parent_dto.h"
#include "entity_parent/queries/get_entity_parent_query.h"
#include "qleany_editor_application_entity_parent_export.h"

#include "repository/interface_entity_parent_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityParent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityParent::Queries;

namespace QleanyEditor::Application::Features::EntityParent::Queries
{
class QLEANY_EDITOR_APPLICATION_ENTITY_PARENT_EXPORT GetEntityParentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetEntityParentQueryHandler(InterfaceEntityParentRepository *repository);
    Result<EntityParentDTO> handle(QPromise<Result<void>> &progressPromise, const GetEntityParentQuery &query);

private:
    InterfaceEntityParentRepository *m_repository;
    Result<EntityParentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityParentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::EntityParent::Queries