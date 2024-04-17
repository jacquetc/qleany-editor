// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature/application_feature_dto.h"
#include "application_feature/commands/create_application_feature_command.h"
#include "qleany_editor_application_application_feature_export.h"
#include "repository/interface_application_feature_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Commands;

namespace QleanyEditor::Application::Features::ApplicationFeature::Commands
{
class QLEANY_EDITOR_APPLICATION_APPLICATION_FEATURE_EXPORT CreateApplicationFeatureCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateApplicationFeatureCommandHandler(InterfaceApplicationFeatureRepository *repository);

    Result<ApplicationFeatureDTO> handle(QPromise<Result<void>> &progressPromise, const CreateApplicationFeatureCommand &request);
    Result<ApplicationFeatureDTO> restore();

Q_SIGNALS:
    void applicationFeatureCreated(QleanyEditor::Contracts::DTO::ApplicationFeature::ApplicationFeatureDTO applicationFeatureDto);
    void applicationFeatureRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceApplicationFeatureRepository *m_repository;
    Result<ApplicationFeatureDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateApplicationFeatureCommand &request);
    Result<ApplicationFeatureDTO> restoreImpl();
    Result<QleanyEditor::Entities::ApplicationFeature> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::ApplicationFeature> m_oldOwnerFeatures;
    QList<QleanyEditor::Entities::ApplicationFeature> m_ownerFeaturesNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::ApplicationFeature::Commands