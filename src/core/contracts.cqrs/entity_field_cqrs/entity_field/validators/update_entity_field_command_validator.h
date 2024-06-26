// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field/update_entity_field_dto.h"

#include "repository/interface_entity_field_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::EntityField;

namespace QleanyEditor::Contracts::CQRS::EntityField::Validators
{
class UpdateEntityFieldCommandValidator
{
public:
    UpdateEntityFieldCommandValidator(InterfaceEntityFieldRepository *entityFieldRepository)
        : m_entityFieldRepository(entityFieldRepository)
    {
    }

    Result<void> validate(const UpdateEntityFieldDTO &dto) const

    {
        Result<bool> existsResult = m_entityFieldRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceEntityFieldRepository *m_entityFieldRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::EntityField::Validators