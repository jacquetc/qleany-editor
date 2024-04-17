// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "repository_component/create_repository_component_dto.h"

namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Commands
{
class CreateRepositoryComponentCommand
{
public:
    CreateRepositoryComponentCommand()
    {
    }

    QleanyEditor::Contracts::DTO::RepositoryComponent::CreateRepositoryComponentDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Commands