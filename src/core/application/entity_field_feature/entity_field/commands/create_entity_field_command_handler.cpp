// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_entity_field_command_handler.h"
#include "entity_field/validators/create_entity_field_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "entity.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::EntityField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityField::Validators;
using namespace QleanyEditor::Application::Features::EntityField::Commands;

CreateEntityFieldCommandHandler::CreateEntityFieldCommandHandler(InterfaceEntityFieldRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityFieldDTO> CreateEntityFieldCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateEntityFieldCommand &request)
{
    Result<EntityFieldDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<EntityFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateEntityFieldCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityFieldDTO> CreateEntityFieldCommandHandler::restore()
{
    Result<EntityFieldDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<EntityFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateEntityFieldCommand restore:" << ex.what();
    }
    return result;
}

Result<EntityFieldDTO> CreateEntityFieldCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateEntityFieldCommand &request)
{
    qDebug() << "CreateEntityFieldCommandHandler::handleImpl called";
    QleanyEditor::Entities::EntityField entityField;
    CreateEntityFieldDTO createDTO = request.req;

    QList<QleanyEditor::Entities::EntityField> ownerEntityFields;

    // Get the entities from owner
    int ownerId = createDTO.entityId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create EntityField command using the validator
        auto validator = CreateEntityFieldCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(EntityFieldDTO, validatorResult);

        // Map the create EntityField command to a domain EntityField object and
        // generate a UUID
        entityField = Qleany::Tools::AutoMapper::AutoMapper::map<CreateEntityFieldDTO, QleanyEditor::Entities::EntityField>(createDTO);

        // allow for forcing the uuid
        if (entityField.uuid().isNull()) {
            entityField.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        entityField.setCreationDate(QDateTime::currentDateTime());
        entityField.setUpdateDate(QDateTime::currentDateTime());

    } else {
        entityField = m_newEntity.value();
    }

    // Add the entityField to the repository

    m_repository->beginChanges();
    auto entityFieldResult = m_repository->add(std::move(entityField));

    QLN_RETURN_IF_ERROR_WITH_ACTION(EntityFieldDTO, entityFieldResult, m_repository->cancelChanges();)

    // Get the newly created EntityField entity
    entityField = entityFieldResult.value();
    // Save the newly created entity
    m_newEntity = entityFieldResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerFieldsResult = m_repository->getEntitiesInRelationOf(Entity::schema, ownerId, "fields"_L1);
        if (Q_UNLIKELY(originalOwnerFieldsResult.hasError())) {
            return Result<EntityFieldDTO>(originalOwnerFieldsResult.error());
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

        originalOwnerFields.insert(position, entityField);

        m_ownerFieldsNewState = originalOwnerFields;
        ownerEntityFields = originalOwnerFields;
    } else {
        ownerEntityFields = m_ownerFieldsNewState;
        position = m_position;
    }

    // Add the entityField to the owner entity
    Result<QList<QleanyEditor::Entities::EntityField>> updateResult =
        m_repository->updateEntitiesInRelationOf(Entity::schema, ownerId, "fields"_L1, ownerEntityFields);

    QLN_RETURN_IF_ERROR_WITH_ACTION(EntityFieldDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = entityFieldResult;

    auto entityFieldDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityField, EntityFieldDTO>(entityFieldResult.value());
    Q_EMIT entityFieldCreated(entityFieldDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(entityField.id(), ownerId, position);

    qDebug() << "EntityField added:" << entityFieldDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created EntityField as a Result object
    return Result<EntityFieldDTO>(entityFieldDTO);
}

Result<EntityFieldDTO> CreateEntityFieldCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(EntityFieldDTO, deleteResult)

    Q_EMIT entityFieldRemoved(deleteResult.value());

    qDebug() << "EntityField removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<EntityFieldDTO>(EntityFieldDTO());
}

bool CreateEntityFieldCommandHandler::s_mappingRegistered = false;

void CreateEntityFieldCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityField, Contracts::DTO::EntityField::EntityFieldDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::EntityField::CreateEntityFieldDTO, QleanyEditor::Entities::EntityField>();
}