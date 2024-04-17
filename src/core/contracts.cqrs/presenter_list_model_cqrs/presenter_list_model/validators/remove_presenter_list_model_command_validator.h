// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository/interface_presenter_list_model_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Validators
{
class RemovePresenterListModelCommandValidator
{
public:
    RemovePresenterListModelCommandValidator(InterfacePresenterListModelRepository *presenterListModelRepository)
        : m_presenterListModelRepository(presenterListModelRepository)
    {
    }

    Result<void> validate(int id) const

    {
        Result<bool> existsResult = m_presenterListModelRepository->exists(id);

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfacePresenterListModelRepository *m_presenterListModelRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Validators