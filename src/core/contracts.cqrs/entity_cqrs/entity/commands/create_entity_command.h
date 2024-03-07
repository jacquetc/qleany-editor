// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/create_entity_dto.h"

namespace QleanyEditor::Contracts::CQRS::Entity::Commands
{
class CreateEntityCommand
{
public:
    CreateEntityCommand()
    {
    }

    QleanyEditor::Contracts::DTO::Entity::CreateEntityDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::Entity::Commands