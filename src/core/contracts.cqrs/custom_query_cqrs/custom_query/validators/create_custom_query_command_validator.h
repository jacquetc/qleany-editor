// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_query/create_custom_query_dto.h"

#include "repository/interface_custom_query_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::CustomQuery;

namespace QleanyEditor::Contracts::CQRS::CustomQuery::Validators
{
class CreateCustomQueryCommandValidator
{
public:
    CreateCustomQueryCommandValidator(InterfaceCustomQueryRepository *customQueryRepository)
        : m_customQueryRepository(customQueryRepository)
    {
    }

    Result<void> validate(const CreateCustomQueryDTO &dto) const

    {
        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceCustomQueryRepository *m_customQueryRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomQuery::Validators