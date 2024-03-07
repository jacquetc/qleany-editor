// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_component/update_entity_component_dto.h"

#include "repository/interface_entity_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::EntityComponent;

namespace QleanyEditor::Contracts::CQRS::EntityComponent::Validators
{
class UpdateEntityComponentCommandValidator
{
public:
    UpdateEntityComponentCommandValidator(InterfaceEntityComponentRepository *entityComponentRepository)
        : m_entityComponentRepository(entityComponentRepository)
    {
    }

    Result<void> validate(const UpdateEntityComponentDTO &dto) const

    {
        Result<bool> existsResult = m_entityComponentRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceEntityComponentRepository *m_entityComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::EntityComponent::Validators