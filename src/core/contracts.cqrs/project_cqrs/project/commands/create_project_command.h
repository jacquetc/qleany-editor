// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project/create_project_dto.h"

namespace QleanyEditor::Contracts::CQRS::Project::Commands
{
class CreateProjectCommand
{
public:
    CreateProjectCommand()
    {
    }

    QleanyEditor::Contracts::DTO::Project::CreateProjectDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::Project::Commands