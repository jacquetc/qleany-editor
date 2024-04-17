// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_q_r_s_component/update_c_q_r_s_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Commands
{
class UpdateCQRSComponentCommand
{
public:
    UpdateCQRSComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CQRSComponent::UpdateCQRSComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Commands