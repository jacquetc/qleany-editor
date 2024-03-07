// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "global_component/update_global_component_dto.h"

#include "repository/interface_global_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::GlobalComponent;

namespace QleanyEditor::Contracts::CQRS::GlobalComponent::Validators
{
class UpdateGlobalComponentCommandValidator
{
public:
    UpdateGlobalComponentCommandValidator(InterfaceGlobalComponentRepository *globalComponentRepository)
        : m_globalComponentRepository(globalComponentRepository)
    {
    }

    Result<void> validate(const UpdateGlobalComponentDTO &dto) const

    {
        Result<bool> existsResult = m_globalComponentRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceGlobalComponentRepository *m_globalComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::GlobalComponent::Validators