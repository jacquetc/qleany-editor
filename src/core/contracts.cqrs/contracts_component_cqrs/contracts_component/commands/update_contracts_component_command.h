// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "contracts_component/update_contracts_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Commands
{
class UpdateContractsComponentCommand
{
public:
    UpdateContractsComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::ContractsComponent::UpdateContractsComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Commands