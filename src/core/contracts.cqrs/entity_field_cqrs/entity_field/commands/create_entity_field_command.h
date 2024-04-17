// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field/create_entity_field_dto.h"

namespace QleanyEditor::Contracts::CQRS::EntityField::Commands
{
class CreateEntityFieldCommand
{
public:
    CreateEntityFieldCommand()
    {
    }

    QleanyEditor::Contracts::DTO::EntityField::CreateEntityFieldDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::EntityField::Commands