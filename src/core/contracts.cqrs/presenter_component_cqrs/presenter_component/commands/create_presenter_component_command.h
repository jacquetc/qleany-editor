// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component/create_presenter_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Commands
{
class CreatePresenterComponentCommand
{
public:
    CreatePresenterComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::PresenterComponent::CreatePresenterComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Commands