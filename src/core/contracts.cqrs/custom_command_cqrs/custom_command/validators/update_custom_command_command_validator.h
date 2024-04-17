// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/update_custom_command_dto.h"

#include "repository/interface_custom_command_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::CustomCommand;

namespace QleanyEditor::Contracts::CQRS::CustomCommand::Validators
{
class UpdateCustomCommandCommandValidator
{
public:
    UpdateCustomCommandCommandValidator(InterfaceCustomCommandRepository *customCommandRepository)
        : m_customCommandRepository(customCommandRepository)
    {
    }

    Result<void> validate(const UpdateCustomCommandDTO &dto) const

    {
        Result<bool> existsResult = m_customCommandRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceCustomCommandRepository *m_customCommandRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomCommand::Validators