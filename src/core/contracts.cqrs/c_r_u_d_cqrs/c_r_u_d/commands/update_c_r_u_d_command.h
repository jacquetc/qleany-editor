// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/update_c_r_u_d_dto.h"

namespace QleanyEditor::Contracts::CQRS::CRUD::Commands
{
class UpdateCRUDCommand
{
public:
    UpdateCRUDCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CRUD::UpdateCRUDDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CRUD::Commands