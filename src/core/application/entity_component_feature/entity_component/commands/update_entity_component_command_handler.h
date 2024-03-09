// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_component/commands/update_entity_component_command.h"
#include "entity_component/entity_component_dto.h"
#include "qleany_editor_application_entity_component_export.h"

#include "repository/interface_entity_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityComponent::Commands;

namespace QleanyEditor::Application::Features::EntityComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_ENTITY_COMPONENT_EXPORT UpdateEntityComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateEntityComponentCommandHandler(InterfaceEntityComponentRepository *repository);
    Result<EntityComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateEntityComponentCommand &request);
    Result<EntityComponentDTO> restore();

Q_SIGNALS:
    void entityComponentUpdated(QleanyEditor::Contracts::DTO::EntityComponent::EntityComponentDTO entityComponentDto);
    void entityComponentDetailsUpdated(int id);

private:
    InterfaceEntityComponentRepository *m_repository;
    Result<EntityComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateEntityComponentCommand &request);
    Result<EntityComponentDTO> restoreImpl();
    Result<EntityComponentDTO> saveOldState();
    Result<EntityComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::EntityComponent::Commands