// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_application_feature_command_handler.h"
#include "application_feature/validators/remove_application_feature_command_validator.h"
#include "repository/interface_application_feature_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Commands;
using namespace QleanyEditor::Application::Features::ApplicationFeature::Commands;
using namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Validators;

RemoveApplicationFeatureCommandHandler::RemoveApplicationFeatureCommandHandler(InterfaceApplicationFeatureRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveApplicationFeatureCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveApplicationFeatureCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveApplicationFeatureCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveApplicationFeatureCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveApplicationFeatureCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveApplicationFeatureCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveApplicationFeatureCommand &request)
{
    int applicationFeatureId = request.id;

    // Validate the command using the validator
    auto validator = RemoveApplicationFeatureCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(applicationFeatureId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::ApplicationFeature> applicationFeatureResult = m_repository->get(applicationFeatureId);

    QLN_RETURN_IF_ERROR(int, applicationFeatureResult)

    // save old entity
    m_oldState = applicationFeatureResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << applicationFeatureId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT applicationFeatureRemoved(deleteResult.value());

    qDebug() << "ApplicationFeature removed:" << applicationFeatureId;

    return Result<int>(applicationFeatureId);
}

Result<int> RemoveApplicationFeatureCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveApplicationFeatureCommandHandler::s_mappingRegistered = false;

void RemoveApplicationFeatureCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationFeature,
                                                           Contracts::DTO::ApplicationFeature::ApplicationFeatureDTO>(true, true);
}