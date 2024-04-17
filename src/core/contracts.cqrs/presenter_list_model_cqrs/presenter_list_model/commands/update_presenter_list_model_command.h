// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model/update_presenter_list_model_dto.h"

namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Commands
{
class UpdatePresenterListModelCommand
{
public:
    UpdatePresenterListModelCommand()
    {
    }

    QleanyEditor::Contracts::DTO::PresenterListModel::UpdatePresenterListModelDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Commands