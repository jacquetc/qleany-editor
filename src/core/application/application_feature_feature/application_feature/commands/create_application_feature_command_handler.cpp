// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_application_feature_command_handler.h"
#include "application_feature/validators/create_application_feature_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "application_component.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationFeature::Validators;
using namespace QleanyEditor::Application::Features::ApplicationFeature::Commands;

CreateApplicationFeatureCommandHandler::CreateApplicationFeatureCommandHandler(InterfaceApplicationFeatureRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ApplicationFeatureDTO> CreateApplicationFeatureCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                             const CreateApplicationFeatureCommand &request)
{
    Result<ApplicationFeatureDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<ApplicationFeatureDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateApplicationFeatureCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ApplicationFeatureDTO> CreateApplicationFeatureCommandHandler::restore()
{
    Result<ApplicationFeatureDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<ApplicationFeatureDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateApplicationFeatureCommand restore:" << ex.what();
    }
    return result;
}

Result<ApplicationFeatureDTO> CreateApplicationFeatureCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                 const CreateApplicationFeatureCommand &request)
{
    qDebug() << "CreateApplicationFeatureCommandHandler::handleImpl called";
    QleanyEditor::Entities::ApplicationFeature applicationFeature;
    CreateApplicationFeatureDTO createDTO = request.req;

    QList<QleanyEditor::Entities::ApplicationFeature> ownerEntityFeatures;

    // Get the entities from owner
    int ownerId = createDTO.applicationComponentId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create ApplicationFeature command using the validator
        auto validator = CreateApplicationFeatureCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(ApplicationFeatureDTO, validatorResult);

        // Map the create ApplicationFeature command to a domain ApplicationFeature object and
        // generate a UUID
        applicationFeature = Qleany::Tools::AutoMapper::AutoMapper::map<CreateApplicationFeatureDTO, QleanyEditor::Entities::ApplicationFeature>(createDTO);

        // allow for forcing the uuid
        if (applicationFeature.uuid().isNull()) {
            applicationFeature.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        applicationFeature.setCreationDate(QDateTime::currentDateTime());
        applicationFeature.setUpdateDate(QDateTime::currentDateTime());

    } else {
        applicationFeature = m_newEntity.value();
    }

    // Add the applicationFeature to the repository

    m_repository->beginChanges();
    auto applicationFeatureResult = m_repository->add(std::move(applicationFeature));

    QLN_RETURN_IF_ERROR_WITH_ACTION(ApplicationFeatureDTO, applicationFeatureResult, m_repository->cancelChanges();)

    // Get the newly created ApplicationFeature entity
    applicationFeature = applicationFeatureResult.value();
    // Save the newly created entity
    m_newEntity = applicationFeatureResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerFeaturesResult = m_repository->getEntitiesInRelationOf(ApplicationComponent::schema, ownerId, "features"_L1);
        if (Q_UNLIKELY(originalOwnerFeaturesResult.hasError())) {
            return Result<ApplicationFeatureDTO>(originalOwnerFeaturesResult.error());
        }
        auto originalOwnerFeatures = originalOwnerFeaturesResult.value();

        // save
        m_oldOwnerFeatures = originalOwnerFeatures;

        // Insert to the right position

        position = createDTO.position();
        if (position == -1) {
            position = originalOwnerFeatures.count();
        }
        if (position > originalOwnerFeatures.count()) {
            position = originalOwnerFeatures.count();
        } else if (position < 0) {
            position = 0;
        }

        m_position = position;

        originalOwnerFeatures.insert(position, applicationFeature);

        m_ownerFeaturesNewState = originalOwnerFeatures;
        ownerEntityFeatures = originalOwnerFeatures;
    } else {
        ownerEntityFeatures = m_ownerFeaturesNewState;
        position = m_position;
    }

    // Add the applicationFeature to the owner entity
    Result<QList<QleanyEditor::Entities::ApplicationFeature>> updateResult =
        m_repository->updateEntitiesInRelationOf(ApplicationComponent::schema, ownerId, "features"_L1, ownerEntityFeatures);

    QLN_RETURN_IF_ERROR_WITH_ACTION(ApplicationFeatureDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = applicationFeatureResult;

    auto applicationFeatureDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationFeature, ApplicationFeatureDTO>(applicationFeatureResult.value());
    Q_EMIT applicationFeatureCreated(applicationFeatureDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(applicationFeature.id(), ownerId, position);

    qDebug() << "ApplicationFeature added:" << applicationFeatureDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created ApplicationFeature as a Result object
    return Result<ApplicationFeatureDTO>(applicationFeatureDTO);
}

Result<ApplicationFeatureDTO> CreateApplicationFeatureCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(ApplicationFeatureDTO, deleteResult)

    Q_EMIT applicationFeatureRemoved(deleteResult.value());

    qDebug() << "ApplicationFeature removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<ApplicationFeatureDTO>(ApplicationFeatureDTO());
}

bool CreateApplicationFeatureCommandHandler::s_mappingRegistered = false;

void CreateApplicationFeatureCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationFeature,
                                                           Contracts::DTO::ApplicationFeature::ApplicationFeatureDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ApplicationFeature::CreateApplicationFeatureDTO,
                                                           QleanyEditor::Entities::ApplicationFeature>();
}