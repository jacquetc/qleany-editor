// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "interactor_component/create_interactor_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Commands
{
class CreateInteractorComponentCommand
{
public:
    CreateInteractorComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::InteractorComponent::CreateInteractorComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Commands