// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component/update_presenter_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Commands
{
class UpdatePresenterComponentCommand
{
public:
    UpdatePresenterComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::PresenterComponent::UpdatePresenterComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Commands