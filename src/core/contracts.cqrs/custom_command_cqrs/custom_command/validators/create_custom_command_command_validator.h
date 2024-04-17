// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/create_custom_command_dto.h"

#include "repository/interface_custom_command_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::CustomCommand;

namespace QleanyEditor::Contracts::CQRS::CustomCommand::Validators
{
class CreateCustomCommandCommandValidator
{
public:
    CreateCustomCommandCommandValidator(InterfaceCustomCommandRepository *customCommandRepository)
        : m_customCommandRepository(customCommandRepository)
    {
    }

    Result<void> validate(const CreateCustomCommandDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceCustomCommandRepository *m_customCommandRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomCommand::Validators