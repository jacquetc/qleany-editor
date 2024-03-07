// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project/save_project_dto.h"

namespace QleanyEditor::Contracts::CQRS::Project::Commands
{
class SaveProjectCommand
{
public:
    SaveProjectCommand()
    {
    }

    QleanyEditor::Contracts::DTO::Project::SaveProjectDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::Project::Commands