// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/update_application_component_dto.h"

#include "repository/interface_application_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;

namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Validators
{
class UpdateApplicationComponentCommandValidator
{
public:
    UpdateApplicationComponentCommandValidator(InterfaceApplicationComponentRepository *applicationComponentRepository)
        : m_applicationComponentRepository(applicationComponentRepository)
    {
    }

    Result<void> validate(const UpdateApplicationComponentDTO &dto) const

    {
        Result<bool> existsResult = m_applicationComponentRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceApplicationComponentRepository *m_applicationComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Validators