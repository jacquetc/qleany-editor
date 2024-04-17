// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository/create_repository_dto.h"

#include "repository/interface_repository_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::Repository;

namespace QleanyEditor::Contracts::CQRS::Repository::Validators
{
class CreateRepositoryCommandValidator
{
public:
    CreateRepositoryCommandValidator(InterfaceRepositoryRepository *repositoryRepository)
        : m_repositoryRepository(repositoryRepository)
    {
    }

    Result<void> validate(const CreateRepositoryDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceRepositoryRepository *m_repositoryRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::Repository::Validators