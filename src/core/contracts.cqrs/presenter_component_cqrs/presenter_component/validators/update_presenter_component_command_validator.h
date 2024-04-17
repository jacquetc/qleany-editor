// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component/update_presenter_component_dto.h"

#include "repository/interface_presenter_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::PresenterComponent;

namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Validators
{
class UpdatePresenterComponentCommandValidator
{
public:
    UpdatePresenterComponentCommandValidator(InterfacePresenterComponentRepository *presenterComponentRepository)
        : m_presenterComponentRepository(presenterComponentRepository)
    {
    }

    Result<void> validate(const UpdatePresenterComponentDTO &dto) const

    {
        Result<bool> existsResult = m_presenterComponentRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfacePresenterComponentRepository *m_presenterComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Validators