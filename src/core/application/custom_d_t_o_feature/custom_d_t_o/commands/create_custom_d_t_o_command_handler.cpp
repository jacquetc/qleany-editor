// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_custom_d_t_o_command_handler.h"
#include "custom_d_t_o/validators/create_custom_d_t_o_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "custom_command.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CustomDTO;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTO::Validators;
using namespace QleanyEditor::Application::Features::CustomDTO::Commands;

CreateCustomDTOCommandHandler::CreateCustomDTOCommandHandler(InterfaceCustomDTORepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomDTODTO> CreateCustomDTOCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateCustomDTOCommand &request)
{
    Result<CustomDTODTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CustomDTODTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCustomDTOCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomDTODTO> CreateCustomDTOCommandHandler::restore()
{
    Result<CustomDTODTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CustomDTODTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCustomDTOCommand restore:" << ex.what();
    }
    return result;
}

Result<CustomDTODTO> CreateCustomDTOCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateCustomDTOCommand &request)
{
    qDebug() << "CreateCustomDTOCommandHandler::handleImpl called";
    QleanyEditor::Entities::CustomDTO customDTO;
    CreateCustomDTODTO createDTO = request.req;

    QleanyEditor::Entities::CustomDTO ownerEntityDtoIn;

    // Get the entities from owner
    int ownerId = createDTO.customCommandId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create CustomDTO command using the validator
        auto validator = CreateCustomDTOCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(CustomDTODTO, validatorResult);

        // Map the create CustomDTO command to a domain CustomDTO object and
        // generate a UUID
        customDTO = Qleany::Tools::AutoMapper::AutoMapper::map<CreateCustomDTODTO, QleanyEditor::Entities::CustomDTO>(createDTO);

        // allow for forcing the uuid
        if (customDTO.uuid().isNull()) {
            customDTO.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        customDTO.setCreationDate(QDateTime::currentDateTime());
        customDTO.setUpdateDate(QDateTime::currentDateTime());

    } else {
        customDTO = m_newEntity.value();
    }

    // Add the customDTO to the repository

    m_repository->beginChanges();
    auto customDTOResult = m_repository->add(std::move(customDTO));

    QLN_RETURN_IF_ERROR_WITH_ACTION(CustomDTODTO, customDTOResult, m_repository->cancelChanges();)

    // Get the newly created CustomDTO entity
    customDTO = customDTOResult.value();
    // Save the newly created entity
    m_newEntity = customDTOResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerDtoInResult = m_repository->getEntityInRelationOf(CustomCommand::schema, ownerId, "dtoIn"_L1);
        if (Q_UNLIKELY(originalOwnerDtoInResult.hasError())) {
            return Result<CustomDTODTO>(originalOwnerDtoInResult.error());
        }
        auto originalOwnerDtoIn = originalOwnerDtoInResult.value();

        // save
        m_oldOwnerDtoIn = originalOwnerDtoIn;
        originalOwnerDtoIn = customDTO;

        m_ownerDtoInNewState = originalOwnerDtoIn;
        ownerEntityDtoIn = originalOwnerDtoIn;
    } else {
        ownerEntityDtoIn = m_ownerDtoInNewState;
        position = m_position;
    }

    // Add the customDTO to the owner entity
    Result<QleanyEditor::Entities::CustomDTO> updateResult =
        m_repository->updateEntityInRelationOf(CustomCommand::schema, ownerId, "dtoIn"_L1, ownerEntityDtoIn);

    QLN_RETURN_IF_ERROR_WITH_ACTION(CustomDTODTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = customDTOResult;

    auto customDTODTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTO, CustomDTODTO>(customDTOResult.value());
    Q_EMIT customDTOCreated(customDTODTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(customDTO.id(), ownerId, position);

    qDebug() << "CustomDTO added:" << customDTODTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created CustomDTO as a Result object
    return Result<CustomDTODTO>(customDTODTO);
}

Result<CustomDTODTO> CreateCustomDTOCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(CustomDTODTO, deleteResult)

    Q_EMIT customDTORemoved(deleteResult.value());

    qDebug() << "CustomDTO removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<CustomDTODTO>(CustomDTODTO());
}

bool CreateCustomDTOCommandHandler::s_mappingRegistered = false;

void CreateCustomDTOCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTO, Contracts::DTO::CustomDTO::CustomDTODTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomDTO::CreateCustomDTODTO, QleanyEditor::Entities::CustomDTO>();
}