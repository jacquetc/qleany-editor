// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project/load_project_dto.h"

#include "repository/interface_project_repository.h"

#include "repository/interface_global_component_repository.h"

#include "repository/interface_recent_project_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::Project;

namespace QleanyEditor::Contracts::CQRS::Project::Validators
{
class LoadProjectCommandValidator
{
public:
    LoadProjectCommandValidator(InterfaceProjectRepository *projectRepository,
                                InterfaceGlobalComponentRepository *globalComponentRepository,
                                InterfaceRecentProjectRepository *recentProjectRepository)
        : m_projectRepository(projectRepository)
        , m_globalComponentRepository(globalComponentRepository)
        , m_recentProjectRepository(recentProjectRepository)
    {
    }

    Result<void> validate(const LoadProjectDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceProjectRepository *m_projectRepository;

    InterfaceGlobalComponentRepository *m_globalComponentRepository;

    InterfaceRecentProjectRepository *m_recentProjectRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::Project::Validators