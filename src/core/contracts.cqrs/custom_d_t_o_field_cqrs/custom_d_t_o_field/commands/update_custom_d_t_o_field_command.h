// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field/update_custom_d_t_o_field_dto.h"

namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Commands
{
class UpdateCustomDTOFieldCommand
{
public:
    UpdateCustomDTOFieldCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CustomDTOField::UpdateCustomDTOFieldDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Commands