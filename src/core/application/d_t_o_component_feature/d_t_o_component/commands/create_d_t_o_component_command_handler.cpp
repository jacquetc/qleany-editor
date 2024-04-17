// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_d_t_o_component_command_handler.h"
#include "d_t_o_component/validators/create_d_t_o_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "project.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::DTOComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::DTOComponent::Validators;
using namespace QleanyEditor::Application::Features::DTOComponent::Commands;

CreateDTOComponentCommandHandler::CreateDTOComponentCommandHandler(InterfaceDTOComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<DTOComponentDTO> CreateDTOComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateDTOComponentCommand &request)
{
    Result<DTOComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<DTOComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateDTOComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<DTOComponentDTO> CreateDTOComponentCommandHandler::restore()
{
    Result<DTOComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<DTOComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateDTOComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<DTOComponentDTO> CreateDTOComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateDTOComponentCommand &request)
{
    qDebug() << "CreateDTOComponentCommandHandler::handleImpl called";
    QleanyEditor::Entities::DTOComponent dTOComponent;
    CreateDTOComponentDTO createDTO = request.req;

    QleanyEditor::Entities::DTOComponent ownerEntityDtoComponent;

    // Get the entities from owner
    int ownerId = createDTO.projectId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create DTOComponent command using the validator
        auto validator = CreateDTOComponentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(DTOComponentDTO, validatorResult);

        // Map the create DTOComponent command to a domain DTOComponent object and
        // generate a UUID
        dTOComponent = Qleany::Tools::AutoMapper::AutoMapper::map<CreateDTOComponentDTO, QleanyEditor::Entities::DTOComponent>(createDTO);

        // allow for forcing the uuid
        if (dTOComponent.uuid().isNull()) {
            dTOComponent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        dTOComponent.setCreationDate(QDateTime::currentDateTime());
        dTOComponent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        dTOComponent = m_newEntity.value();
    }

    // Add the dTOComponent to the repository

    m_repository->beginChanges();
    auto dTOComponentResult = m_repository->add(std::move(dTOComponent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(DTOComponentDTO, dTOComponentResult, m_repository->cancelChanges();)

    // Get the newly created DTOComponent entity
    dTOComponent = dTOComponentResult.value();
    // Save the newly created entity
    m_newEntity = dTOComponentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerDtoComponentResult = m_repository->getEntityInRelationOf(Project::schema, ownerId, "dtoComponent"_L1);
        if (Q_UNLIKELY(originalOwnerDtoComponentResult.hasError())) {
            return Result<DTOComponentDTO>(originalOwnerDtoComponentResult.error());
        }
        auto originalOwnerDtoComponent = originalOwnerDtoComponentResult.value();

        // save
        m_oldOwnerDtoComponent = originalOwnerDtoComponent;
        originalOwnerDtoComponent = dTOComponent;

        m_ownerDtoComponentNewState = originalOwnerDtoComponent;
        ownerEntityDtoComponent = originalOwnerDtoComponent;
    } else {
        ownerEntityDtoComponent = m_ownerDtoComponentNewState;
        position = m_position;
    }

    // Add the dTOComponent to the owner entity
    Result<QleanyEditor::Entities::DTOComponent> updateResult =
        m_repository->updateEntityInRelationOf(Project::schema, ownerId, "dtoComponent"_L1, ownerEntityDtoComponent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(DTOComponentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = dTOComponentResult;

    auto dTOComponentDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::DTOComponent, DTOComponentDTO>(dTOComponentResult.value());
    Q_EMIT dTOComponentCreated(dTOComponentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(dTOComponent.id(), ownerId, position);

    qDebug() << "DTOComponent added:" << dTOComponentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created DTOComponent as a Result object
    return Result<DTOComponentDTO>(dTOComponentDTO);
}

Result<DTOComponentDTO> CreateDTOComponentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(DTOComponentDTO, deleteResult)

    Q_EMIT dTOComponentRemoved(deleteResult.value());

    qDebug() << "DTOComponent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<DTOComponentDTO>(DTOComponentDTO());
}

bool CreateDTOComponentCommandHandler::s_mappingRegistered = false;

void CreateDTOComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::DTOComponent, Contracts::DTO::DTOComponent::DTOComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::DTOComponent::CreateDTOComponentDTO, QleanyEditor::Entities::DTOComponent>();
}