// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/create_application_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Commands
{
class CreateApplicationComponentCommand
{
public:
    CreateApplicationComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::ApplicationComponent::CreateApplicationComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Commands