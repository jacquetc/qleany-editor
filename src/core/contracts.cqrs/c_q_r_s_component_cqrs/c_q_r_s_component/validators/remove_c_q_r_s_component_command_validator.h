// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository/interface_c_q_r_s_component_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Validators
{
class RemoveCQRSComponentCommandValidator
{
public:
    RemoveCQRSComponentCommandValidator(InterfaceCQRSComponentRepository *cQRSComponentRepository)
        : m_cQRSComponentRepository(cQRSComponentRepository)
    {
    }

    Result<void> validate(int id) const

    {
        Result<bool> existsResult = m_cQRSComponentRepository->exists(id);

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceCQRSComponentRepository *m_cQRSComponentRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Validators