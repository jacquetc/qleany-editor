// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_parent/create_entity_parent_dto.h"

namespace QleanyEditor::Contracts::CQRS::EntityParent::Commands
{
class CreateEntityParentCommand
{
public:
    CreateEntityParentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::EntityParent::CreateEntityParentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::EntityParent::Commands