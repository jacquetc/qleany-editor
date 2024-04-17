// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_entity_parent_command_handler.h"
#include "entity_parent/validators/update_entity_parent_command_validator.h"
#include "repository/interface_entity_parent_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityParent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityParent::Commands;
using namespace QleanyEditor::Contracts::CQRS::EntityParent::Validators;
using namespace QleanyEditor::Application::Features::EntityParent::Commands;

UpdateEntityParentCommandHandler::UpdateEntityParentCommandHandler(InterfaceEntityParentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityParentDTO> UpdateEntityParentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateEntityParentCommand &request)
{
    Result<EntityParentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<EntityParentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateEntityParentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityParentDTO> UpdateEntityParentCommandHandler::restore()
{
    Result<EntityParentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<EntityParentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateEntityParentCommand restore:" << ex.what();
    }
    return result;
}

Result<EntityParentDTO> UpdateEntityParentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateEntityParentCommand &request)
{
    qDebug() << "UpdateEntityParentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateEntityParentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(EntityParentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::EntityParent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(EntityParentDTO, currentResult)

        // map
        m_undoState =
            Result<EntityParentDTO>(Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityParent, EntityParentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<EntityParentDTO, UpdateEntityParentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto entityParent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateEntityParentDTO, QleanyEditor::Entities::EntityParent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        entityParent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto entityParentResult = m_repository->update(std::move(entityParent));

    if (entityParentResult.hasError()) {
        return Result<EntityParentDTO>(entityParentResult.error());
    }

    // map
    auto entityParentDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityParent, EntityParentDTO>(entityParentResult.value());

    Q_EMIT entityParentUpdated(entityParentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT entityParentDetailsUpdated(entityParentDto.id());
    }

    qDebug() << "UpdateEntityParentCommandHandler::handleImpl done";

    return Result<EntityParentDTO>(entityParentDto);
}

Result<EntityParentDTO> UpdateEntityParentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateEntityParentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto entityParent = Qleany::Tools::AutoMapper::AutoMapper::map<EntityParentDTO, QleanyEditor::Entities::EntityParent>(m_undoState.value());

    // do
    auto entityParentResult = m_repository->update(std::move(entityParent));

    QLN_RETURN_IF_ERROR(EntityParentDTO, entityParentResult)

    // map
    auto entityParentDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityParent, EntityParentDTO>(entityParentResult.value());

    Q_EMIT entityParentUpdated(entityParentDto);

    qDebug() << "UpdateEntityParentCommandHandler::restoreImpl done";

    return Result<EntityParentDTO>(entityParentDto);
}

bool UpdateEntityParentCommandHandler::s_mappingRegistered = false;

void UpdateEntityParentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityParent, Contracts::DTO::EntityParent::EntityParentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::EntityParent::UpdateEntityParentDTO, Contracts::DTO::EntityParent::EntityParentDTO>(
        true,
        true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::EntityParent::UpdateEntityParentDTO, QleanyEditor::Entities::EntityParent>();
}