// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature/update_application_feature_dto.h"

#include "repository/interface_application_feature_repository.h"

#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;

namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Validators
{
class UpdateApplicationFeatureCommandValidator
{
public:
    UpdateApplicationFeatureCommandValidator(InterfaceApplicationFeatureRepository *applicationFeatureRepository)
        : m_applicationFeatureRepository(applicationFeatureRepository)
    {
    }

    Result<void> validate(const UpdateApplicationFeatureDTO &dto) const

    {
        Result<bool> existsResult = m_applicationFeatureRepository->exists(dto.id());

        if (!existsResult.value()) {
            return Result<void>(QLN_ERROR_1(Q_FUNC_INFO, Error::Critical, "id_not_found"));
        }

        // Return that is Ok :
        return Result<void>();
    }

private:
    InterfaceApplicationFeatureRepository *m_applicationFeatureRepository;
};
} // namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Validators