// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository_component/update_repository_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Commands
{
class UpdateRepositoryComponentCommand
{
public:
    UpdateRepositoryComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::RepositoryComponent::UpdateRepositoryComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Commands