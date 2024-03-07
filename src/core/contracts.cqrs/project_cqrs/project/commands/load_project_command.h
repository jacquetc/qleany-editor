// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project/load_project_dto.h"

namespace QleanyEditor::Contracts::CQRS::Project::Commands
{
class LoadProjectCommand
{
public:
    LoadProjectCommand()
    {
    }

    QleanyEditor::Contracts::DTO::Project::LoadProjectDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::Project::Commands