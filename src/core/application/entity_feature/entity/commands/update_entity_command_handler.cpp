// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_entity_command_handler.h"
#include "entity/validators/update_entity_command_validator.h"
#include "repository/interface_entity_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Entity::Commands;
using namespace QleanyEditor::Contracts::CQRS::Entity::Validators;
using namespace QleanyEditor::Application::Features::Entity::Commands;

UpdateEntityCommandHandler::UpdateEntityCommandHandler(InterfaceEntityRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityDTO> UpdateEntityCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateEntityCommand &request)
{
    Result<EntityDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<EntityDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateEntityCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityDTO> UpdateEntityCommandHandler::restore()
{
    Result<EntityDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<EntityDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateEntityCommand restore:" << ex.what();
    }
    return result;
}

Result<EntityDTO> UpdateEntityCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateEntityCommand &request)
{
    qDebug() << "UpdateEntityCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateEntityCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(EntityDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::Entity> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(EntityDTO, currentResult)

        // map
        m_undoState = Result<EntityDTO>(Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Entity, EntityDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<EntityDTO, UpdateEntityDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto entity = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateEntityDTO, QleanyEditor::Entities::Entity>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        entity.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto entityResult = m_repository->update(std::move(entity));

    if (entityResult.hasError()) {
        return Result<EntityDTO>(entityResult.error());
    }

    // map
    auto entityDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Entity, EntityDTO>(entityResult.value());

    Q_EMIT entityUpdated(entityDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT entityDetailsUpdated(entityDto.id());
    }

    qDebug() << "UpdateEntityCommandHandler::handleImpl done";

    return Result<EntityDTO>(entityDto);
}

Result<EntityDTO> UpdateEntityCommandHandler::restoreImpl()
{
    qDebug() << "UpdateEntityCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto entity = Qleany::Tools::AutoMapper::AutoMapper::map<EntityDTO, QleanyEditor::Entities::Entity>(m_undoState.value());

    // do
    auto entityResult = m_repository->update(std::move(entity));

    QLN_RETURN_IF_ERROR(EntityDTO, entityResult)

    // map
    auto entityDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Entity, EntityDTO>(entityResult.value());

    Q_EMIT entityUpdated(entityDto);

    qDebug() << "UpdateEntityCommandHandler::restoreImpl done";

    return Result<EntityDTO>(entityDto);
}

bool UpdateEntityCommandHandler::s_mappingRegistered = false;

void UpdateEntityCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Entity, Contracts::DTO::Entity::EntityDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::Entity::UpdateEntityDTO, Contracts::DTO::Entity::EntityDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::Entity::UpdateEntityDTO, QleanyEditor::Entities::Entity>();
}