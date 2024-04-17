// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_query/update_custom_query_dto.h"

namespace QleanyEditor::Contracts::CQRS::CustomQuery::Commands
{
class UpdateCustomQueryCommand
{
public:
    UpdateCustomQueryCommand()
    {
    }

    QleanyEditor::Contracts::DTO::CustomQuery::UpdateCustomQueryDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::CustomQuery::Commands