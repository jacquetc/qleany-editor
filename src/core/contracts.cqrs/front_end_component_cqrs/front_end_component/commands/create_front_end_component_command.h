// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "front_end_component/create_front_end_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Commands
{
class CreateFrontEndComponentCommand
{
public:
    CreateFrontEndComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::FrontEndComponent::CreateFrontEndComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Commands