// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project/create_project_dto.h"

#include "repository/interface_project_repository.h"

#include "repository/interface_global_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::Project;

namespace QleanyEditor::Contracts::CQRS::Project::Validators
{
class CreateProjectCommandValidator
{
public:
    CreateProjectCommandValidator(InterfaceProjectRepository *projectRepository, InterfaceGlobalComponentRepository *globalComponentRepository)
        : m_projectRepository(projectRepository)
        , m_globalComponentRepository(globalComponentRepository)
    {
    }

    Result<void> validate(const CreateProjectDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceProjectRepository *m_projectRepository;

    InterfaceGlobalComponentRepository *m_globalComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::Project::Validators