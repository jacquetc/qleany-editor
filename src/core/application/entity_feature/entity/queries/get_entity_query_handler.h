// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/entity_dto.h"
#include "entity/queries/get_entity_query.h"
#include "qleany_editor_application_entity_export.h"

#include "repository/interface_entity_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Entity::Queries;

namespace QleanyEditor::Application::Features::Entity::Queries
{
class QLEANY_EDITOR_APPLICATION_ENTITY_EXPORT GetEntityQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetEntityQueryHandler(InterfaceEntityRepository *repository);
    Result<EntityDTO> handle(QPromise<Result<void>> &progressPromise, const GetEntityQuery &query);

private:
    InterfaceEntityRepository *m_repository;
    Result<EntityDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetEntityQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Entity::Queries