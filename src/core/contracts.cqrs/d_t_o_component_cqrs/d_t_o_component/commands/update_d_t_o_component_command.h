// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "d_t_o_component/update_d_t_o_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::DTOComponent::Commands
{
class UpdateDTOComponentCommand
{
public:
    UpdateDTOComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::DTOComponent::UpdateDTOComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::DTOComponent::Commands