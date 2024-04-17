// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/create_c_r_u_d_dto.h"

namespace QleanyEditor::Contracts::CQRS::CRUD::Commands
{
class CreateCRUDCommand
{
public:
    CreateCRUDCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CRUD::CreateCRUDDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CRUD::Commands