// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/update_entity_dto.h"

#include "repository/interface_entity_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::Entity;

namespace QleanyEditor::Contracts::CQRS::Entity::Validators
{
class UpdateEntityCommandValidator
{
public:
    UpdateEntityCommandValidator(InterfaceEntityRepository *entityRepository)
        : m_entityRepository(entityRepository)
    {
    }

    Result<void> validate(const UpdateEntityDTO &dto) const

    {
        Result<bool> existsResult = m_entityRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceEntityRepository *m_entityRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::Entity::Validators