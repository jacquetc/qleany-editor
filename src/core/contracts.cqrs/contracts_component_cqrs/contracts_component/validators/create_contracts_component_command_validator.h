// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "contracts_component/create_contracts_component_dto.h"

#include "repository/interface_contracts_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::ContractsComponent;

namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Validators
{
class CreateContractsComponentCommandValidator
{
public:
    CreateContractsComponentCommandValidator(InterfaceContractsComponentRepository *contractsComponentRepository)
        : m_contractsComponentRepository(contractsComponentRepository)
    {
    }

    Result<void> validate(const CreateContractsComponentDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceContractsComponentRepository *m_contractsComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Validators