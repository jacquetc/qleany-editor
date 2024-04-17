// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_entity_field_command_handler.h"
#include "entity_field/validators/update_entity_field_command_validator.h"
#include "repository/interface_entity_field_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityField::Commands;
using namespace QleanyEditor::Contracts::CQRS::EntityField::Validators;
using namespace QleanyEditor::Application::Features::EntityField::Commands;

UpdateEntityFieldCommandHandler::UpdateEntityFieldCommandHandler(InterfaceEntityFieldRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityFieldDTO> UpdateEntityFieldCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateEntityFieldCommand &request)
{
    Result<EntityFieldDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<EntityFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateEntityFieldCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityFieldDTO> UpdateEntityFieldCommandHandler::restore()
{
    Result<EntityFieldDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<EntityFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateEntityFieldCommand restore:" << ex.what();
    }
    return result;
}

Result<EntityFieldDTO> UpdateEntityFieldCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateEntityFieldCommand &request)
{
    qDebug() << "UpdateEntityFieldCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateEntityFieldCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(EntityFieldDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::EntityField> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(EntityFieldDTO, currentResult)

        // map
        m_undoState =
            Result<EntityFieldDTO>(Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityField, EntityFieldDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<EntityFieldDTO, UpdateEntityFieldDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto entityField = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateEntityFieldDTO, QleanyEditor::Entities::EntityField>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        entityField.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto entityFieldResult = m_repository->update(std::move(entityField));

    if (entityFieldResult.hasError()) {
        return Result<EntityFieldDTO>(entityFieldResult.error());
    }

    // map
    auto entityFieldDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityField, EntityFieldDTO>(entityFieldResult.value());

    Q_EMIT entityFieldUpdated(entityFieldDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT entityFieldDetailsUpdated(entityFieldDto.id());
    }

    qDebug() << "UpdateEntityFieldCommandHandler::handleImpl done";

    return Result<EntityFieldDTO>(entityFieldDto);
}

Result<EntityFieldDTO> UpdateEntityFieldCommandHandler::restoreImpl()
{
    qDebug() << "UpdateEntityFieldCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto entityField = Qleany::Tools::AutoMapper::AutoMapper::map<EntityFieldDTO, QleanyEditor::Entities::EntityField>(m_undoState.value());

    // do
    auto entityFieldResult = m_repository->update(std::move(entityField));

    QLN_RETURN_IF_ERROR(EntityFieldDTO, entityFieldResult)

    // map
    auto entityFieldDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityField, EntityFieldDTO>(entityFieldResult.value());

    Q_EMIT entityFieldUpdated(entityFieldDto);

    qDebug() << "UpdateEntityFieldCommandHandler::restoreImpl done";

    return Result<EntityFieldDTO>(entityFieldDto);
}

bool UpdateEntityFieldCommandHandler::s_mappingRegistered = false;

void UpdateEntityFieldCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityField, Contracts::DTO::EntityField::EntityFieldDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::EntityField::UpdateEntityFieldDTO, Contracts::DTO::EntityField::EntityFieldDTO>(
        true,
        true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::EntityField::UpdateEntityFieldDTO, QleanyEditor::Entities::EntityField>();
}