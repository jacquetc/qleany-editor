// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_parent/create_entity_parent_dto.h"

#include "repository/interface_entity_parent_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::EntityParent;

namespace QleanyEditor::Contracts::CQRS::EntityParent::Validators
{
class CreateEntityParentCommandValidator
{
public:
    CreateEntityParentCommandValidator(InterfaceEntityParentRepository *entityParentRepository)
        : m_entityParentRepository(entityParentRepository)
    {
    }

    Result<void> validate(const CreateEntityParentDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceEntityParentRepository *m_entityParentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::EntityParent::Validators