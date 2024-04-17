// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single/create_presenter_single_dto.h"

namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Commands
{
class CreatePresenterSingleCommand
{
public:
    CreatePresenterSingleCommand()
    {
    }

    QleanyEditor::Contracts::DTO::PresenterSingle::CreatePresenterSingleDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Commands