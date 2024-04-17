// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/update_application_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Commands
{
class UpdateApplicationComponentCommand
{
public:
    UpdateApplicationComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::ApplicationComponent::UpdateApplicationComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Commands