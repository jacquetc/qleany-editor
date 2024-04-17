// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/update_custom_d_t_o_dto.h"

#include "repository/interface_custom_d_t_o_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::CustomDTO;

namespace QleanyEditor::Contracts::CQRS::CustomDTO::Validators
{
class UpdateCustomDTOCommandValidator
{
public:
    UpdateCustomDTOCommandValidator(InterfaceCustomDTORepository *customDTORepository)
        : m_customDTORepository(customDTORepository)
    {
    }

    Result<void> validate(const UpdateCustomDTODTO &dto) const

    {
        Result<bool> existsResult = m_customDTORepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceCustomDTORepository *m_customDTORepository;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomDTO::Validators