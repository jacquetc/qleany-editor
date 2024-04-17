// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature/application_feature_dto.h"
#include "application_feature/commands/update_application_feature_command.h"
#include "qleany_editor_application_application_feature_export.h"

#include "repository/interface_application_feature_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Commands;

namespace QleanyEditor::Application::Features::ApplicationFeature::Commands
{
class QLEANY_EDITOR_APPLICATION_APPLICATION_FEATURE_EXPORT UpdateApplicationFeatureCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateApplicationFeatureCommandHandler(InterfaceApplicationFeatureRepository *repository);
    Result<ApplicationFeatureDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateApplicationFeatureCommand &request);
    Result<ApplicationFeatureDTO> restore();

Q_SIGNALS:
    void applicationFeatureUpdated(QleanyEditor::Contracts::DTO::ApplicationFeature::ApplicationFeatureDTO applicationFeatureDto);
    void applicationFeatureDetailsUpdated(int id);

private:
    InterfaceApplicationFeatureRepository *m_repository;
    Result<ApplicationFeatureDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateApplicationFeatureCommand &request);
    Result<ApplicationFeatureDTO> restoreImpl();
    Result<ApplicationFeatureDTO> saveOldState();
    Result<ApplicationFeatureDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ApplicationFeature::Commands