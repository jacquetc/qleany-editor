// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_query/create_custom_query_dto.h"

namespace QleanyEditor::Contracts::CQRS::CustomQuery::Commands
{
class CreateCustomQueryCommand
{
public:
    CreateCustomQueryCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CustomQuery::CreateCustomQueryDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomQuery::Commands