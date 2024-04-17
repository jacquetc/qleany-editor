// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_application_feature_command_handler.h"
#include "application_feature/validators/update_application_feature_command_validator.h"
#include "repository/interface_application_feature_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Commands;
using namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Validators;
using namespace QleanyEditor::Application::Features::ApplicationFeature::Commands;

UpdateApplicationFeatureCommandHandler::UpdateApplicationFeatureCommandHandler(InterfaceApplicationFeatureRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ApplicationFeatureDTO> UpdateApplicationFeatureCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                             const UpdateApplicationFeatureCommand &request)
{
    Result<ApplicationFeatureDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<ApplicationFeatureDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateApplicationFeatureCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ApplicationFeatureDTO> UpdateApplicationFeatureCommandHandler::restore()
{
    Result<ApplicationFeatureDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<ApplicationFeatureDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateApplicationFeatureCommand restore:" << ex.what();
    }
    return result;
}

Result<ApplicationFeatureDTO> UpdateApplicationFeatureCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                 const UpdateApplicationFeatureCommand &request)
{
    qDebug() << "UpdateApplicationFeatureCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateApplicationFeatureCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(ApplicationFeatureDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::ApplicationFeature> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(ApplicationFeatureDTO, currentResult)

        // map
        m_undoState = Result<ApplicationFeatureDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationFeature, ApplicationFeatureDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<ApplicationFeatureDTO, UpdateApplicationFeatureDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto applicationFeature = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateApplicationFeatureDTO, QleanyEditor::Entities::ApplicationFeature>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        applicationFeature.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto applicationFeatureResult = m_repository->update(std::move(applicationFeature));

    if (applicationFeatureResult.hasError()) {
        return Result<ApplicationFeatureDTO>(applicationFeatureResult.error());
    }

    // map
    auto applicationFeatureDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationFeature, ApplicationFeatureDTO>(applicationFeatureResult.value());

    Q_EMIT applicationFeatureUpdated(applicationFeatureDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT applicationFeatureDetailsUpdated(applicationFeatureDto.id());
    }

    qDebug() << "UpdateApplicationFeatureCommandHandler::handleImpl done";

    return Result<ApplicationFeatureDTO>(applicationFeatureDto);
}

Result<ApplicationFeatureDTO> UpdateApplicationFeatureCommandHandler::restoreImpl()
{
    qDebug() << "UpdateApplicationFeatureCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto applicationFeature =
        Qleany::Tools::AutoMapper::AutoMapper::map<ApplicationFeatureDTO, QleanyEditor::Entities::ApplicationFeature>(m_undoState.value());

    // do
    auto applicationFeatureResult = m_repository->update(std::move(applicationFeature));

    QLN_RETURN_IF_ERROR(ApplicationFeatureDTO, applicationFeatureResult)

    // map
    auto applicationFeatureDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationFeature, ApplicationFeatureDTO>(applicationFeatureResult.value());

    Q_EMIT applicationFeatureUpdated(applicationFeatureDto);

    qDebug() << "UpdateApplicationFeatureCommandHandler::restoreImpl done";

    return Result<ApplicationFeatureDTO>(applicationFeatureDto);
}

bool UpdateApplicationFeatureCommandHandler::s_mappingRegistered = false;

void UpdateApplicationFeatureCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationFeature,
                                                           Contracts::DTO::ApplicationFeature::ApplicationFeatureDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ApplicationFeature::UpdateApplicationFeatureDTO,
                                                           Contracts::DTO::ApplicationFeature::ApplicationFeatureDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ApplicationFeature::UpdateApplicationFeatureDTO,
                                                           QleanyEditor::Entities::ApplicationFeature>();
}