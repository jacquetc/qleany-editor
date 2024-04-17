// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/create_application_component_dto.h"

#include "repository/interface_application_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;

namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Validators
{
class CreateApplicationComponentCommandValidator
{
public:
    CreateApplicationComponentCommandValidator(InterfaceApplicationComponentRepository *applicationComponentRepository)
        : m_applicationComponentRepository(applicationComponentRepository)
    {
    }

    Result<void> validate(const CreateApplicationComponentDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceApplicationComponentRepository *m_applicationComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Validators