// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "contracts_component/create_contracts_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Commands
{
class CreateContractsComponentCommand
{
public:
    CreateContractsComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::ContractsComponent::CreateContractsComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Commands