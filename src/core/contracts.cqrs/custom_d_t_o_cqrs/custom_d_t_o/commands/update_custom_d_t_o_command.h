// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/update_custom_d_t_o_dto.h"

namespace QleanyEditor::Contracts::CQRS::CustomDTO::Commands
{
class UpdateCustomDTOCommand
{
public:
    UpdateCustomDTOCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CustomDTO::UpdateCustomDTODTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomDTO::Commands