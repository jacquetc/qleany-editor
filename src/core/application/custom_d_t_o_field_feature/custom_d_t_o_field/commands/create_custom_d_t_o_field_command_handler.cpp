// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_custom_d_t_o_field_command_handler.h"
#include "custom_d_t_o_field/validators/create_custom_d_t_o_field_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "custom_d_t_o.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CustomDTOField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Validators;
using namespace QleanyEditor::Application::Features::CustomDTOField::Commands;

CreateCustomDTOFieldCommandHandler::CreateCustomDTOFieldCommandHandler(InterfaceCustomDTOFieldRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomDTOFieldDTO> CreateCustomDTOFieldCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateCustomDTOFieldCommand &request)
{
    Result<CustomDTOFieldDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CustomDTOFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCustomDTOFieldCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomDTOFieldDTO> CreateCustomDTOFieldCommandHandler::restore()
{
    Result<CustomDTOFieldDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CustomDTOFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCustomDTOFieldCommand restore:" << ex.what();
    }
    return result;
}

Result<CustomDTOFieldDTO> CreateCustomDTOFieldCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateCustomDTOFieldCommand &request)
{
    qDebug() << "CreateCustomDTOFieldCommandHandler::handleImpl called";
    QleanyEditor::Entities::CustomDTOField customDTOField;
    CreateCustomDTOFieldDTO createDTO = request.req;

    QList<QleanyEditor::Entities::CustomDTOField> ownerEntityFields;

    // Get the entities from owner
    int ownerId = createDTO.customDTOId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create CustomDTOField command using the validator
        auto validator = CreateCustomDTOFieldCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(CustomDTOFieldDTO, validatorResult);

        // Map the create CustomDTOField command to a domain CustomDTOField object and
        // generate a UUID
        customDTOField = Qleany::Tools::AutoMapper::AutoMapper::map<CreateCustomDTOFieldDTO, QleanyEditor::Entities::CustomDTOField>(createDTO);

        // allow for forcing the uuid
        if (customDTOField.uuid().isNull()) {
            customDTOField.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        customDTOField.setCreationDate(QDateTime::currentDateTime());
        customDTOField.setUpdateDate(QDateTime::currentDateTime());

    } else {
        customDTOField = m_newEntity.value();
    }

    // Add the customDTOField to the repository

    m_repository->beginChanges();
    auto customDTOFieldResult = m_repository->add(std::move(customDTOField));

    QLN_RETURN_IF_ERROR_WITH_ACTION(CustomDTOFieldDTO, customDTOFieldResult, m_repository->cancelChanges();)

    // Get the newly created CustomDTOField entity
    customDTOField = customDTOFieldResult.value();
    // Save the newly created entity
    m_newEntity = customDTOFieldResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerFieldsResult = m_repository->getEntitiesInRelationOf(CustomDTO::schema, ownerId, "fields"_L1);
        if (Q_UNLIKELY(originalOwnerFieldsResult.hasError())) {
            return Result<CustomDTOFieldDTO>(originalOwnerFieldsResult.error());
        }
        auto originalOwnerFields = originalOwnerFieldsResult.value();

        // save
        m_oldOwnerFields = originalOwnerFields;

        // Insert to the right position

        position = createDTO.position();
        if (position == -1) {
            position = originalOwnerFields.count();
        }
        if (position > originalOwnerFields.count()) {
            position = originalOwnerFields.count();
        } else if (position < 0) {
            position = 0;
        }

        m_position = position;

        originalOwnerFields.insert(position, customDTOField);

        m_ownerFieldsNewState = originalOwnerFields;
        ownerEntityFields = originalOwnerFields;
    } else {
        ownerEntityFields = m_ownerFieldsNewState;
        position = m_position;
    }

    // Add the customDTOField to the owner entity
    Result<QList<QleanyEditor::Entities::CustomDTOField>> updateResult =
        m_repository->updateEntitiesInRelationOf(CustomDTO::schema, ownerId, "fields"_L1, ownerEntityFields);

    QLN_RETURN_IF_ERROR_WITH_ACTION(CustomDTOFieldDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = customDTOFieldResult;

    auto customDTOFieldDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTOField, CustomDTOFieldDTO>(customDTOFieldResult.value());
    Q_EMIT customDTOFieldCreated(customDTOFieldDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(customDTOField.id(), ownerId, position);

    qDebug() << "CustomDTOField added:" << customDTOFieldDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created CustomDTOField as a Result object
    return Result<CustomDTOFieldDTO>(customDTOFieldDTO);
}

Result<CustomDTOFieldDTO> CreateCustomDTOFieldCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(CustomDTOFieldDTO, deleteResult)

    Q_EMIT customDTOFieldRemoved(deleteResult.value());

    qDebug() << "CustomDTOField removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<CustomDTOFieldDTO>(CustomDTOFieldDTO());
}

bool CreateCustomDTOFieldCommandHandler::s_mappingRegistered = false;

void CreateCustomDTOFieldCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTOField, Contracts::DTO::CustomDTOField::CustomDTOFieldDTO>(true,
                                                                                                                                                      true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomDTOField::CreateCustomDTOFieldDTO, QleanyEditor::Entities::CustomDTOField>();
}