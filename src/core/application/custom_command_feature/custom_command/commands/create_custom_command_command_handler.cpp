// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_custom_command_command_handler.h"
#include "custom_command/validators/create_custom_command_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "application_feature.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CustomCommand;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomCommand::Validators;
using namespace QleanyEditor::Application::Features::CustomCommand::Commands;

CreateCustomCommandCommandHandler::CreateCustomCommandCommandHandler(InterfaceCustomCommandRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomCommandDTO> CreateCustomCommandCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateCustomCommandCommand &request)
{
    Result<CustomCommandDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CustomCommandDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCustomCommandCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomCommandDTO> CreateCustomCommandCommandHandler::restore()
{
    Result<CustomCommandDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CustomCommandDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCustomCommandCommand restore:" << ex.what();
    }
    return result;
}

Result<CustomCommandDTO> CreateCustomCommandCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateCustomCommandCommand &request)
{
    qDebug() << "CreateCustomCommandCommandHandler::handleImpl called";
    QleanyEditor::Entities::CustomCommand customCommand;
    CreateCustomCommandDTO createDTO = request.req;

    QList<QleanyEditor::Entities::CustomCommand> ownerEntityCustomCommands;

    // Get the entities from owner
    int ownerId = createDTO.applicationFeatureId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create CustomCommand command using the validator
        auto validator = CreateCustomCommandCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(CustomCommandDTO, validatorResult);

        // Map the create CustomCommand command to a domain CustomCommand object and
        // generate a UUID
        customCommand = Qleany::Tools::AutoMapper::AutoMapper::map<CreateCustomCommandDTO, QleanyEditor::Entities::CustomCommand>(createDTO);

        // allow for forcing the uuid
        if (customCommand.uuid().isNull()) {
            customCommand.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        customCommand.setCreationDate(QDateTime::currentDateTime());
        customCommand.setUpdateDate(QDateTime::currentDateTime());

    } else {
        customCommand = m_newEntity.value();
    }

    // Add the customCommand to the repository

    m_repository->beginChanges();
    auto customCommandResult = m_repository->add(std::move(customCommand));

    QLN_RETURN_IF_ERROR_WITH_ACTION(CustomCommandDTO, customCommandResult, m_repository->cancelChanges();)

    // Get the newly created CustomCommand entity
    customCommand = customCommandResult.value();
    // Save the newly created entity
    m_newEntity = customCommandResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerCustomCommandsResult = m_repository->getEntitiesInRelationOf(ApplicationFeature::schema, ownerId, "customCommands"_L1);
        if (Q_UNLIKELY(originalOwnerCustomCommandsResult.hasError())) {
            return Result<CustomCommandDTO>(originalOwnerCustomCommandsResult.error());
        }
        auto originalOwnerCustomCommands = originalOwnerCustomCommandsResult.value();

        // save
        m_oldOwnerCustomCommands = originalOwnerCustomCommands;

        // Insert to the right position

        position = createDTO.position();
        if (position == -1) {
            position = originalOwnerCustomCommands.count();
        }
        if (position > originalOwnerCustomCommands.count()) {
            position = originalOwnerCustomCommands.count();
        } else if (position < 0) {
            position = 0;
        }

        m_position = position;

        originalOwnerCustomCommands.insert(position, customCommand);

        m_ownerCustomCommandsNewState = originalOwnerCustomCommands;
        ownerEntityCustomCommands = originalOwnerCustomCommands;
    } else {
        ownerEntityCustomCommands = m_ownerCustomCommandsNewState;
        position = m_position;
    }

    // Add the customCommand to the owner entity
    Result<QList<QleanyEditor::Entities::CustomCommand>> updateResult =
        m_repository->updateEntitiesInRelationOf(ApplicationFeature::schema, ownerId, "customCommands"_L1, ownerEntityCustomCommands);

    QLN_RETURN_IF_ERROR_WITH_ACTION(CustomCommandDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = customCommandResult;

    auto customCommandDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomCommand, CustomCommandDTO>(customCommandResult.value());
    Q_EMIT customCommandCreated(customCommandDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(customCommand.id(), ownerId, position);

    qDebug() << "CustomCommand added:" << customCommandDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created CustomCommand as a Result object
    return Result<CustomCommandDTO>(customCommandDTO);
}

Result<CustomCommandDTO> CreateCustomCommandCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(CustomCommandDTO, deleteResult)

    Q_EMIT customCommandRemoved(deleteResult.value());

    qDebug() << "CustomCommand removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<CustomCommandDTO>(CustomCommandDTO());
}

bool CreateCustomCommandCommandHandler::s_mappingRegistered = false;

void CreateCustomCommandCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomCommand, Contracts::DTO::CustomCommand::CustomCommandDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomCommand::CreateCustomCommandDTO, QleanyEditor::Entities::CustomCommand>();
}