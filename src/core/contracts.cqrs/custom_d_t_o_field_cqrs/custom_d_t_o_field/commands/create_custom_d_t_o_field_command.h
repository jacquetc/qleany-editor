// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field/create_custom_d_t_o_field_dto.h"

namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Commands
{
class CreateCustomDTOFieldCommand
{
public:
    CreateCustomDTOFieldCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CustomDTOField::CreateCustomDTOFieldDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Commands