// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "global_component/update_global_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::GlobalComponent::Commands
{
class UpdateGlobalComponentCommand
{
public:
    UpdateGlobalComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::GlobalComponent::UpdateGlobalComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::GlobalComponent::Commands