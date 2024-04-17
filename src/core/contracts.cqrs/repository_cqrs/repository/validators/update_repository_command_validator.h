// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository/update_repository_dto.h"

#include "repository/interface_repository_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::Repository;

namespace QleanyEditor::Contracts::CQRS::Repository::Validators
{
class UpdateRepositoryCommandValidator
{
public:
    UpdateRepositoryCommandValidator(InterfaceRepositoryRepository *repositoryRepository)
        : m_repositoryRepository(repositoryRepository)
    {
    }

    Result<void> validate(const UpdateRepositoryDTO &dto) const

    {
        Result<bool> existsResult = m_repositoryRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceRepositoryRepository *m_repositoryRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::Repository::Validators