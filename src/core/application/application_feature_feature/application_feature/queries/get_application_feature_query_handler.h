// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature/application_feature_dto.h"
#include "application_feature/queries/get_application_feature_query.h"
#include "qleany_editor_application_application_feature_export.h"

#include "repository/interface_application_feature_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Queries;

namespace QleanyEditor::Application::Features::ApplicationFeature::Queries
{
class QLEANY_EDITOR_APPLICATION_APPLICATION_FEATURE_EXPORT GetApplicationFeatureQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetApplicationFeatureQueryHandler(InterfaceApplicationFeatureRepository *repository);
    Result<ApplicationFeatureDTO> handle(QPromise<Result<void>> &progressPromise, const GetApplicationFeatureQuery &query);

private:
    InterfaceApplicationFeatureRepository *m_repository;
    Result<ApplicationFeatureDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetApplicationFeatureQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ApplicationFeature::Queries