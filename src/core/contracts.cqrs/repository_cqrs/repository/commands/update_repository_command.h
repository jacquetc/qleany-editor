// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository/update_repository_dto.h"

namespace QleanyEditor::Contracts::CQRS::Repository::Commands
{
class UpdateRepositoryCommand
{
public:
    UpdateRepositoryCommand()
    {
    }

    QleanyEditor::Contracts::DTO::Repository::UpdateRepositoryDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::Repository::Commands