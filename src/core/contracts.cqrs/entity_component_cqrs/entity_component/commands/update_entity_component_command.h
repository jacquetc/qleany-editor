// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_component/update_entity_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::EntityComponent::Commands
{
class UpdateEntityComponentCommand
{
public:
    UpdateEntityComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::EntityComponent::UpdateEntityComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::EntityComponent::Commands