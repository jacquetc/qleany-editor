// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model/create_presenter_list_model_dto.h"

namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Commands
{
class CreatePresenterListModelCommand
{
public:
    CreatePresenterListModelCommand()
    {
    }

    QleanyEditor::Contracts::DTO::PresenterListModel::CreatePresenterListModelDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Commands