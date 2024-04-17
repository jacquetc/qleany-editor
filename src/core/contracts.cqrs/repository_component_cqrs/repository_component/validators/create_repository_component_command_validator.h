// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository_component/create_repository_component_dto.h"

#include "repository/interface_repository_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;

namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Validators
{
class CreateRepositoryComponentCommandValidator
{
public:
    CreateRepositoryComponentCommandValidator(InterfaceRepositoryComponentRepository *repositoryComponentRepository)
        : m_repositoryComponentRepository(repositoryComponentRepository)
    {
    }

    Result<void> validate(const CreateRepositoryComponentDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceRepositoryComponentRepository *m_repositoryComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Validators