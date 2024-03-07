// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/create_entity_dto.h"

#include "repository/interface_entity_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::Entity;

namespace QleanyEditor::Contracts::CQRS::Entity::Validators
{
class CreateEntityCommandValidator
{
public:
    CreateEntityCommandValidator(InterfaceEntityRepository *entityRepository)
        : m_entityRepository(entityRepository)
    {
    }

    Result<void> validate(const CreateEntityDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceEntityRepository *m_entityRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::Entity::Validators