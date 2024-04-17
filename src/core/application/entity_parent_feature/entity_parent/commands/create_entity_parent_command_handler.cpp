// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_entity_parent_command_handler.h"
#include "entity_parent/validators/create_entity_parent_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "entity.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::EntityParent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityParent::Validators;
using namespace QleanyEditor::Application::Features::EntityParent::Commands;

CreateEntityParentCommandHandler::CreateEntityParentCommandHandler(InterfaceEntityParentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityParentDTO> CreateEntityParentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateEntityParentCommand &request)
{
    Result<EntityParentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<EntityParentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateEntityParentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityParentDTO> CreateEntityParentCommandHandler::restore()
{
    Result<EntityParentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<EntityParentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateEntityParentCommand restore:" << ex.what();
    }
    return result;
}

Result<EntityParentDTO> CreateEntityParentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateEntityParentCommand &request)
{
    qDebug() << "CreateEntityParentCommandHandler::handleImpl called";
    QleanyEditor::Entities::EntityParent entityParent;
    CreateEntityParentDTO createDTO = request.req;

    QleanyEditor::Entities::EntityParent ownerEntityParent;

    // Get the entities from owner
    int ownerId = createDTO.entityId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create EntityParent command using the validator
        auto validator = CreateEntityParentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(EntityParentDTO, validatorResult);

        // Map the create EntityParent command to a domain EntityParent object and
        // generate a UUID
        entityParent = Qleany::Tools::AutoMapper::AutoMapper::map<CreateEntityParentDTO, QleanyEditor::Entities::EntityParent>(createDTO);

        // allow for forcing the uuid
        if (entityParent.uuid().isNull()) {
            entityParent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        entityParent.setCreationDate(QDateTime::currentDateTime());
        entityParent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        entityParent = m_newEntity.value();
    }

    // Add the entityParent to the repository

    m_repository->beginChanges();
    auto entityParentResult = m_repository->add(std::move(entityParent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(EntityParentDTO, entityParentResult, m_repository->cancelChanges();)

    // Get the newly created EntityParent entity
    entityParent = entityParentResult.value();
    // Save the newly created entity
    m_newEntity = entityParentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerParentResult = m_repository->getEntityInRelationOf(Entity::schema, ownerId, "parent"_L1);
        if (Q_UNLIKELY(originalOwnerParentResult.hasError())) {
            return Result<EntityParentDTO>(originalOwnerParentResult.error());
        }
        auto originalOwnerParent = originalOwnerParentResult.value();

        // save
        m_oldOwnerParent = originalOwnerParent;
        originalOwnerParent = entityParent;

        m_ownerParentNewState = originalOwnerParent;
        ownerEntityParent = originalOwnerParent;
    } else {
        ownerEntityParent = m_ownerParentNewState;
        position = m_position;
    }

    // Add the entityParent to the owner entity
    Result<QleanyEditor::Entities::EntityParent> updateResult = m_repository->updateEntityInRelationOf(Entity::schema, ownerId, "parent"_L1, ownerEntityParent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(EntityParentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = entityParentResult;

    auto entityParentDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityParent, EntityParentDTO>(entityParentResult.value());
    Q_EMIT entityParentCreated(entityParentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(entityParent.id(), ownerId, position);

    qDebug() << "EntityParent added:" << entityParentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created EntityParent as a Result object
    return Result<EntityParentDTO>(entityParentDTO);
}

Result<EntityParentDTO> CreateEntityParentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(EntityParentDTO, deleteResult)

    Q_EMIT entityParentRemoved(deleteResult.value());

    qDebug() << "EntityParent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<EntityParentDTO>(EntityParentDTO());
}

bool CreateEntityParentCommandHandler::s_mappingRegistered = false;

void CreateEntityParentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityParent, Contracts::DTO::EntityParent::EntityParentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::EntityParent::CreateEntityParentDTO, QleanyEditor::Entities::EntityParent>();
}