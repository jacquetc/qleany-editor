// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component/create_presenter_component_dto.h"

#include "repository/interface_presenter_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::PresenterComponent;

namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Validators
{
class CreatePresenterComponentCommandValidator
{
public:
    CreatePresenterComponentCommandValidator(InterfacePresenterComponentRepository *presenterComponentRepository)
        : m_presenterComponentRepository(presenterComponentRepository)
    {
    }

    Result<void> validate(const CreatePresenterComponentDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfacePresenterComponentRepository *m_presenterComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Validators