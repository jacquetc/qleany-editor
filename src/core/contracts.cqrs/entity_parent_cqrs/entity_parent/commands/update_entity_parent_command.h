// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_parent/update_entity_parent_dto.h"

namespace QleanyEditor::Contracts::CQRS::EntityParent::Commands
{
class UpdateEntityParentCommand
{
public:
    UpdateEntityParentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::EntityParent::UpdateEntityParentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::EntityParent::Commands