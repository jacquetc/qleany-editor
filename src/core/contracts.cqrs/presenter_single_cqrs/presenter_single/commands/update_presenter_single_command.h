// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single/update_presenter_single_dto.h"

namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Commands
{
class UpdatePresenterSingleCommand
{
public:
    UpdatePresenterSingleCommand()
    {
    }

    QleanyEditor::Contracts::DTO::PresenterSingle::UpdatePresenterSingleDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Commands