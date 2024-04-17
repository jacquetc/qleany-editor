// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "d_t_o_component/create_d_t_o_component_dto.h"

#include "repository/interface_d_t_o_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::DTOComponent;

namespace QleanyEditor::Contracts::CQRS::DTOComponent::Validators
{
class CreateDTOComponentCommandValidator
{
public:
    CreateDTOComponentCommandValidator(InterfaceDTOComponentRepository *dTOComponentRepository)
        : m_dTOComponentRepository(dTOComponentRepository)
    {
    }

    Result<void> validate(const CreateDTOComponentDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceDTOComponentRepository *m_dTOComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::DTOComponent::Validators