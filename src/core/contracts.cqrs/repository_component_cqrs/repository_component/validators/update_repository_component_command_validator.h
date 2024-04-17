// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository_component/update_repository_component_dto.h"

#include "repository/interface_repository_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;

namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Validators
{
class UpdateRepositoryComponentCommandValidator
{
public:
    UpdateRepositoryComponentCommandValidator(InterfaceRepositoryComponentRepository *repositoryComponentRepository)
        : m_repositoryComponentRepository(repositoryComponentRepository)
    {
    }

    Result<void> validate(const UpdateRepositoryComponentDTO &dto) const

    {
        Result<bool> existsResult = m_repositoryComponentRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceRepositoryComponentRepository *m_repositoryComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Validators