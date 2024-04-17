// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single/update_presenter_single_dto.h"

#include "repository/interface_presenter_single_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::PresenterSingle;

namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Validators
{
class UpdatePresenterSingleCommandValidator
{
public:
    UpdatePresenterSingleCommandValidator(InterfacePresenterSingleRepository *presenterSingleRepository)
        : m_presenterSingleRepository(presenterSingleRepository)
    {
    }

    Result<void> validate(const UpdatePresenterSingleDTO &dto) const

    {
        Result<bool> existsResult = m_presenterSingleRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfacePresenterSingleRepository *m_presenterSingleRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Validators