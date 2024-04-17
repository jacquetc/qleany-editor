// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_front_end_component_command_handler.h"
#include "front_end_component/validators/create_front_end_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "project.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Validators;
using namespace QleanyEditor::Application::Features::FrontEndComponent::Commands;

CreateFrontEndComponentCommandHandler::CreateFrontEndComponentCommandHandler(InterfaceFrontEndComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<FrontEndComponentDTO> CreateFrontEndComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                           const CreateFrontEndComponentCommand &request)
{
    Result<FrontEndComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<FrontEndComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateFrontEndComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<FrontEndComponentDTO> CreateFrontEndComponentCommandHandler::restore()
{
    Result<FrontEndComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<FrontEndComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateFrontEndComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<FrontEndComponentDTO> CreateFrontEndComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                               const CreateFrontEndComponentCommand &request)
{
    qDebug() << "CreateFrontEndComponentCommandHandler::handleImpl called";
    QleanyEditor::Entities::FrontEndComponent frontEndComponent;
    CreateFrontEndComponentDTO createDTO = request.req;

    QList<QleanyEditor::Entities::FrontEndComponent> ownerEntityFrontEndComponent;

    // Get the entities from owner
    int ownerId = createDTO.projectId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create FrontEndComponent command using the validator
        auto validator = CreateFrontEndComponentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(FrontEndComponentDTO, validatorResult);

        // Map the create FrontEndComponent command to a domain FrontEndComponent object and
        // generate a UUID
        frontEndComponent = Qleany::Tools::AutoMapper::AutoMapper::map<CreateFrontEndComponentDTO, QleanyEditor::Entities::FrontEndComponent>(createDTO);

        // allow for forcing the uuid
        if (frontEndComponent.uuid().isNull()) {
            frontEndComponent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        frontEndComponent.setCreationDate(QDateTime::currentDateTime());
        frontEndComponent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        frontEndComponent = m_newEntity.value();
    }

    // Add the frontEndComponent to the repository

    m_repository->beginChanges();
    auto frontEndComponentResult = m_repository->add(std::move(frontEndComponent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(FrontEndComponentDTO, frontEndComponentResult, m_repository->cancelChanges();)

    // Get the newly created FrontEndComponent entity
    frontEndComponent = frontEndComponentResult.value();
    // Save the newly created entity
    m_newEntity = frontEndComponentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerFrontEndComponentResult = m_repository->getEntitiesInRelationOf(Project::schema, ownerId, "frontEndComponent"_L1);
        if (Q_UNLIKELY(originalOwnerFrontEndComponentResult.hasError())) {
            return Result<FrontEndComponentDTO>(originalOwnerFrontEndComponentResult.error());
        }
        auto originalOwnerFrontEndComponent = originalOwnerFrontEndComponentResult.value();

        // save
        m_oldOwnerFrontEndComponent = originalOwnerFrontEndComponent;

        originalOwnerFrontEndComponent.append(frontEndComponent);

        m_ownerFrontEndComponentNewState = originalOwnerFrontEndComponent;
        ownerEntityFrontEndComponent = originalOwnerFrontEndComponent;
    } else {
        ownerEntityFrontEndComponent = m_ownerFrontEndComponentNewState;
        position = m_position;
    }

    // Add the frontEndComponent to the owner entity
    Result<QList<QleanyEditor::Entities::FrontEndComponent>> updateResult =
        m_repository->updateEntitiesInRelationOf(Project::schema, ownerId, "frontEndComponent"_L1, ownerEntityFrontEndComponent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(FrontEndComponentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = frontEndComponentResult;

    auto frontEndComponentDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::FrontEndComponent, FrontEndComponentDTO>(frontEndComponentResult.value());
    Q_EMIT frontEndComponentCreated(frontEndComponentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(frontEndComponent.id(), ownerId, position);

    qDebug() << "FrontEndComponent added:" << frontEndComponentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created FrontEndComponent as a Result object
    return Result<FrontEndComponentDTO>(frontEndComponentDTO);
}

Result<FrontEndComponentDTO> CreateFrontEndComponentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(FrontEndComponentDTO, deleteResult)

    Q_EMIT frontEndComponentRemoved(deleteResult.value());

    qDebug() << "FrontEndComponent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<FrontEndComponentDTO>(FrontEndComponentDTO());
}

bool CreateFrontEndComponentCommandHandler::s_mappingRegistered = false;

void CreateFrontEndComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::FrontEndComponent, Contracts::DTO::FrontEndComponent::FrontEndComponentDTO>(
        true,
        true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::FrontEndComponent::CreateFrontEndComponentDTO,
                                                           QleanyEditor::Entities::FrontEndComponent>();
}