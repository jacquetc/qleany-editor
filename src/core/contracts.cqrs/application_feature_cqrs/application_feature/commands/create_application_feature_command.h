// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature/create_application_feature_dto.h"

namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Commands
{
class CreateApplicationFeatureCommand
{
public:
    CreateApplicationFeatureCommand()
    {
    }

    QleanyEditor::Contracts::DTO::ApplicationFeature::CreateApplicationFeatureDTO req;
};
} // namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Commands