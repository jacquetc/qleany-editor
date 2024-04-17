// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_application_component_command_handler.h"
#include "application_component/validators/create_application_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "project.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Validators;
using namespace QleanyEditor::Application::Features::ApplicationComponent::Commands;

CreateApplicationComponentCommandHandler::CreateApplicationComponentCommandHandler(InterfaceApplicationComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ApplicationComponentDTO> CreateApplicationComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                 const CreateApplicationComponentCommand &request)
{
    Result<ApplicationComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<ApplicationComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateApplicationComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ApplicationComponentDTO> CreateApplicationComponentCommandHandler::restore()
{
    Result<ApplicationComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<ApplicationComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateApplicationComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<ApplicationComponentDTO> CreateApplicationComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                     const CreateApplicationComponentCommand &request)
{
    qDebug() << "CreateApplicationComponentCommandHandler::handleImpl called";
    QleanyEditor::Entities::ApplicationComponent applicationComponent;
    CreateApplicationComponentDTO createDTO = request.req;

    QleanyEditor::Entities::ApplicationComponent ownerEntityApplicationComponent;

    // Get the entities from owner
    int ownerId = createDTO.projectId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create ApplicationComponent command using the validator
        auto validator = CreateApplicationComponentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(ApplicationComponentDTO, validatorResult);

        // Map the create ApplicationComponent command to a domain ApplicationComponent object and
        // generate a UUID
        applicationComponent =
            Qleany::Tools::AutoMapper::AutoMapper::map<CreateApplicationComponentDTO, QleanyEditor::Entities::ApplicationComponent>(createDTO);

        // allow for forcing the uuid
        if (applicationComponent.uuid().isNull()) {
            applicationComponent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        applicationComponent.setCreationDate(QDateTime::currentDateTime());
        applicationComponent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        applicationComponent = m_newEntity.value();
    }

    // Add the applicationComponent to the repository

    m_repository->beginChanges();
    auto applicationComponentResult = m_repository->add(std::move(applicationComponent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(ApplicationComponentDTO, applicationComponentResult, m_repository->cancelChanges();)

    // Get the newly created ApplicationComponent entity
    applicationComponent = applicationComponentResult.value();
    // Save the newly created entity
    m_newEntity = applicationComponentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerApplicationComponentResult = m_repository->getEntityInRelationOf(Project::schema, ownerId, "applicationComponent"_L1);
        if (Q_UNLIKELY(originalOwnerApplicationComponentResult.hasError())) {
            return Result<ApplicationComponentDTO>(originalOwnerApplicationComponentResult.error());
        }
        auto originalOwnerApplicationComponent = originalOwnerApplicationComponentResult.value();

        // save
        m_oldOwnerApplicationComponent = originalOwnerApplicationComponent;
        originalOwnerApplicationComponent = applicationComponent;

        m_ownerApplicationComponentNewState = originalOwnerApplicationComponent;
        ownerEntityApplicationComponent = originalOwnerApplicationComponent;
    } else {
        ownerEntityApplicationComponent = m_ownerApplicationComponentNewState;
        position = m_position;
    }

    // Add the applicationComponent to the owner entity
    Result<QleanyEditor::Entities::ApplicationComponent> updateResult =
        m_repository->updateEntityInRelationOf(Project::schema, ownerId, "applicationComponent"_L1, ownerEntityApplicationComponent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(ApplicationComponentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = applicationComponentResult;

    auto applicationComponentDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationComponent, ApplicationComponentDTO>(applicationComponentResult.value());
    Q_EMIT applicationComponentCreated(applicationComponentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(applicationComponent.id(), ownerId, position);

    qDebug() << "ApplicationComponent added:" << applicationComponentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created ApplicationComponent as a Result object
    return Result<ApplicationComponentDTO>(applicationComponentDTO);
}

Result<ApplicationComponentDTO> CreateApplicationComponentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(ApplicationComponentDTO, deleteResult)

    Q_EMIT applicationComponentRemoved(deleteResult.value());

    qDebug() << "ApplicationComponent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<ApplicationComponentDTO>(ApplicationComponentDTO());
}

bool CreateApplicationComponentCommandHandler::s_mappingRegistered = false;

void CreateApplicationComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationComponent,
                                                           Contracts::DTO::ApplicationComponent::ApplicationComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ApplicationComponent::CreateApplicationComponentDTO,
                                                           QleanyEditor::Entities::ApplicationComponent>();
}