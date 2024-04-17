// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/create_custom_d_t_o_dto.h"

namespace QleanyEditor::Contracts::CQRS::CustomDTO::Commands
{
class CreateCustomDTOCommand
{
public:
    CreateCustomDTOCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CustomDTO::CreateCustomDTODTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomDTO::Commands