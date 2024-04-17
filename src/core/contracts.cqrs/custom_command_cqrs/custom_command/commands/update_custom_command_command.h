// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/update_custom_command_dto.h"

namespace QleanyEditor::Contracts::CQRS::CustomCommand::Commands
{
class UpdateCustomCommandCommand
{
public:
    UpdateCustomCommandCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CustomCommand::UpdateCustomCommandDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomCommand::Commands