// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/create_custom_command_dto.h"

namespace QleanyEditor::Contracts::CQRS::CustomCommand::Commands
{
class CreateCustomCommandCommand
{
public:
    CreateCustomCommandCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CustomCommand::CreateCustomCommandDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomCommand::Commands