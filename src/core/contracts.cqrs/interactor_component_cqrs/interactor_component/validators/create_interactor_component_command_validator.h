// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "interactor_component/create_interactor_component_dto.h"

#include "repository/interface_interactor_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::InteractorComponent;

namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Validators
{
class CreateInteractorComponentCommandValidator
{
public:
    CreateInteractorComponentCommandValidator(InterfaceInteractorComponentRepository *interactorComponentRepository)
        : m_interactorComponentRepository(interactorComponentRepository)
    {
    }

    Result<void> validate(const CreateInteractorComponentDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceInteractorComponentRepository *m_interactorComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Validators