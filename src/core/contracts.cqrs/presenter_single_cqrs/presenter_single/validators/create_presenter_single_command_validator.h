// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single/create_presenter_single_dto.h"

#include "repository/interface_presenter_single_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::PresenterSingle;

namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Validators
{
class CreatePresenterSingleCommandValidator
{
public:
    CreatePresenterSingleCommandValidator(InterfacePresenterSingleRepository *presenterSingleRepository)
        : m_presenterSingleRepository(presenterSingleRepository)
    {
    }

    Result<void> validate(const CreatePresenterSingleDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfacePresenterSingleRepository *m_presenterSingleRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Validators