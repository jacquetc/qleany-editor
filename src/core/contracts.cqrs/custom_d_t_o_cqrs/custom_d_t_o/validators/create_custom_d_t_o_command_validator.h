// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/create_custom_d_t_o_dto.h"

#include "repository/interface_custom_d_t_o_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::CustomDTO;

namespace QleanyEditor::Contracts::CQRS::CustomDTO::Validators
{
class CreateCustomDTOCommandValidator
{
public:
    CreateCustomDTOCommandValidator(InterfaceCustomDTORepository *customDTORepository)
        : m_customDTORepository(customDTORepository)
    {
    }

    Result<void> validate(const CreateCustomDTODTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceCustomDTORepository *m_customDTORepository;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomDTO::Validators