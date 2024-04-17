// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/create_c_r_u_d_dto.h"

#include "repository/interface_c_r_u_d_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::CRUD;

namespace QleanyEditor::Contracts::CQRS::CRUD::Validators
{
class CreateCRUDCommandValidator
{
public:
    CreateCRUDCommandValidator(InterfaceCRUDRepository *cRUDRepository)
        : m_cRUDRepository(cRUDRepository)
    {
    }

    Result<void> validate(const CreateCRUDDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceCRUDRepository *m_cRUDRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::CRUD::Validators