// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "d_t_o_component/update_d_t_o_component_dto.h"

#include "repository/interface_d_t_o_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::DTOComponent;

namespace QleanyEditor::Contracts::CQRS::DTOComponent::Validators
{
class UpdateDTOComponentCommandValidator
{
public:
    UpdateDTOComponentCommandValidator(InterfaceDTOComponentRepository *dTOComponentRepository)
        : m_dTOComponentRepository(dTOComponentRepository)
    {
    }

    Result<void> validate(const UpdateDTOComponentDTO &dto) const

    {
        Result<bool> existsResult = m_dTOComponentRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceDTOComponentRepository *m_dTOComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::DTOComponent::Validators