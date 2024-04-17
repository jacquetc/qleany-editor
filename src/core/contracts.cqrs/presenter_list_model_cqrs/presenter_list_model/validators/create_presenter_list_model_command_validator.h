// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model/create_presenter_list_model_dto.h"

#include "repository/interface_presenter_list_model_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::PresenterListModel;

namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Validators
{
class CreatePresenterListModelCommandValidator
{
public:
    CreatePresenterListModelCommandValidator(InterfacePresenterListModelRepository *presenterListModelRepository)
        : m_presenterListModelRepository(presenterListModelRepository)
    {
    }

    Result<void> validate(const CreatePresenterListModelDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfacePresenterListModelRepository *m_presenterListModelRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Validators