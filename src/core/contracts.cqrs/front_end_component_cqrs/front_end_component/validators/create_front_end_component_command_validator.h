// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "front_end_component/create_front_end_component_dto.h"

#include "repository/interface_front_end_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;

namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Validators
{
class CreateFrontEndComponentCommandValidator
{
public:
    CreateFrontEndComponentCommandValidator(InterfaceFrontEndComponentRepository *frontEndComponentRepository)
        : m_frontEndComponentRepository(frontEndComponentRepository)
    {
    }

    Result<void> validate(const CreateFrontEndComponentDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceFrontEndComponentRepository *m_frontEndComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Validators