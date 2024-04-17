// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field/create_custom_d_t_o_field_dto.h"

#include "repository/interface_custom_d_t_o_field_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::CustomDTOField;

namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Validators
{
class CreateCustomDTOFieldCommandValidator
{
public:
    CreateCustomDTOFieldCommandValidator(InterfaceCustomDTOFieldRepository *customDTOFieldRepository)
        : m_customDTOFieldRepository(customDTOFieldRepository)
    {
    }

    Result<void> validate(const CreateCustomDTOFieldDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceCustomDTOFieldRepository *m_customDTOFieldRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Validators