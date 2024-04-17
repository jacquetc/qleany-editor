// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository/create_repository_dto.h"

namespace QleanyEditor::Contracts::CQRS::Repository::Commands
{
class CreateRepositoryCommand
{
public:
    CreateRepositoryCommand()
    {
    }

    QleanyEditor::Contracts::DTO::Repository::CreateRepositoryDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::Repository::Commands