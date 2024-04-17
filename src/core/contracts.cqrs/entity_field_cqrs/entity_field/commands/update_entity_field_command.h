// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field/update_entity_field_dto.h"

namespace QleanyEditor::Contracts::CQRS::EntityField::Commands
{
class UpdateEntityFieldCommand
{
public:
    UpdateEntityFieldCommand()
    {
    }

    QleanyEditor::Contracts::DTO::EntityField::UpdateEntityFieldDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::EntityField::Commands