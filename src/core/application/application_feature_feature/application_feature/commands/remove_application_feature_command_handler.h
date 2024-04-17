// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature/application_feature_dto.h"
#include "application_feature/commands/remove_application_feature_command.h"
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
class QLEANY_EDITOR_APPLICATION_APPLICATION_FEATURE_EXPORT RemoveApplicationFeatureCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveApplicationFeatureCommandHandler(InterfaceApplicationFeatureRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveApplicationFeatureCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void applicationFeatureRemoved(int id);

private:
    InterfaceApplicationFeatureRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveApplicationFeatureCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::ApplicationFeature m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ApplicationFeature::Commands