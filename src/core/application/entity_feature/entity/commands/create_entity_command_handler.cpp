// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_entity_command_handler.h"
#include "entity/validators/create_entity_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "entity_component.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Entity::Validators;
using namespace QleanyEditor::Application::Features::Entity::Commands;

CreateEntityCommandHandler::CreateEntityCommandHandler(InterfaceEntityRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityDTO> CreateEntityCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateEntityCommand &request)
{
    Result<EntityDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<EntityDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateEntityCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityDTO> CreateEntityCommandHandler::restore()
{
    Result<EntityDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<EntityDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateEntityCommand restore:" << ex.what();
    }
    return result;
}

Result<EntityDTO> CreateEntityCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateEntityCommand &request)
{
    qDebug() << "CreateEntityCommandHandler::handleImpl called";
    QleanyEditor::Entities::Entity entity;
    CreateEntityDTO createDTO = request.req;

    QList<QleanyEditor::Entities::Entity> ownerEntityEntities;

    // Get the entities from owner
    int ownerId = createDTO.entityComponentId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create Entity command using the validator
        auto validator = CreateEntityCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(EntityDTO, validatorResult);

        // Map the create Entity command to a domain Entity object and
        // generate a UUID
        entity = Qleany::Tools::AutoMapper::AutoMapper::map<CreateEntityDTO, QleanyEditor::Entities::Entity>(createDTO);

        // allow for forcing the uuid
        if (entity.uuid().isNull()) {
            entity.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        entity.setCreationDate(QDateTime::currentDateTime());
        entity.setUpdateDate(QDateTime::currentDateTime());

    } else {
        entity = m_newEntity.value();
    }

    // Add the entity to the repository

    m_repository->beginChanges();
    auto entityResult = m_repository->add(std::move(entity));

    QLN_RETURN_IF_ERROR_WITH_ACTION(EntityDTO, entityResult, m_repository->cancelChanges();)

    // Get the newly created Entity entity
    entity = entityResult.value();
    // Save the newly created entity
    m_newEntity = entityResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerEntitiesResult = m_repository->getEntitiesInRelationOf(EntityComponent::schema, ownerId, "entities"_L1);
        if (Q_UNLIKELY(originalOwnerEntitiesResult.hasError())) {
            return Result<EntityDTO>(originalOwnerEntitiesResult.error());
        }
        auto originalOwnerEntities = originalOwnerEntitiesResult.value();

        // save
        m_oldOwnerEntities = originalOwnerEntities;

        // Insert to the right position

        position = createDTO.position();
        if (position == -1) {
            position = originalOwnerEntities.count();
        }
        if (position > originalOwnerEntities.count()) {
            position = originalOwnerEntities.count();
        } else if (position < 0) {
            position = 0;
        }

        m_position = position;

        originalOwnerEntities.insert(position, entity);

        m_ownerEntitiesNewState = originalOwnerEntities;
        ownerEntityEntities = originalOwnerEntities;
    } else {
        ownerEntityEntities = m_ownerEntitiesNewState;
        position = m_position;
    }

    // Add the entity to the owner entity
    Result<QList<QleanyEditor::Entities::Entity>> updateResult =
        m_repository->updateEntitiesInRelationOf(EntityComponent::schema, ownerId, "entities"_L1, ownerEntityEntities);

    QLN_RETURN_IF_ERROR_WITH_ACTION(EntityDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = entityResult;

    auto entityDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Entity, EntityDTO>(entityResult.value());
    Q_EMIT entityCreated(entityDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(entity.id(), ownerId, position);

    qDebug() << "Entity added:" << entityDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created Entity as a Result object
    return Result<EntityDTO>(entityDTO);
}

Result<EntityDTO> CreateEntityCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(EntityDTO, deleteResult)

    Q_EMIT entityRemoved(deleteResult.value());

    qDebug() << "Entity removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<EntityDTO>(EntityDTO());
}

bool CreateEntityCommandHandler::s_mappingRegistered = false;

void CreateEntityCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Entity, Contracts::DTO::Entity::EntityDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::Entity::CreateEntityDTO, QleanyEditor::Entities::Entity>();
}