// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_entity_component_command_handler.h"
#include "entity_component/validators/update_entity_component_command_validator.h"
#include "repository/interface_entity_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::EntityComponent::Validators;
using namespace QleanyEditor::Application::Features::EntityComponent::Commands;

UpdateEntityComponentCommandHandler::UpdateEntityComponentCommandHandler(InterfaceEntityComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<EntityComponentDTO> UpdateEntityComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateEntityComponentCommand &request)
{
    Result<EntityComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<EntityComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateEntityComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<EntityComponentDTO> UpdateEntityComponentCommandHandler::restore()
{
    Result<EntityComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<EntityComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateEntityComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<EntityComponentDTO> UpdateEntityComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateEntityComponentCommand &request)
{
    qDebug() << "UpdateEntityComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateEntityComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(EntityComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::EntityComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(EntityComponentDTO, currentResult)

        // map
        m_undoState = Result<EntityComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityComponent, EntityComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<EntityComponentDTO, UpdateEntityComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto entityComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateEntityComponentDTO, QleanyEditor::Entities::EntityComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        entityComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto entityComponentResult = m_repository->update(std::move(entityComponent));

    if (entityComponentResult.hasError()) {
        return Result<EntityComponentDTO>(entityComponentResult.error());
    }

    // map
    auto entityComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityComponent, EntityComponentDTO>(entityComponentResult.value());

    Q_EMIT entityComponentUpdated(entityComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT entityComponentDetailsUpdated(entityComponentDto.id());
    }

    qDebug() << "UpdateEntityComponentCommandHandler::handleImpl done";

    return Result<EntityComponentDTO>(entityComponentDto);
}

Result<EntityComponentDTO> UpdateEntityComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateEntityComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto entityComponent = Qleany::Tools::AutoMapper::AutoMapper::map<EntityComponentDTO, QleanyEditor::Entities::EntityComponent>(m_undoState.value());

    // do
    auto entityComponentResult = m_repository->update(std::move(entityComponent));

    QLN_RETURN_IF_ERROR(EntityComponentDTO, entityComponentResult)

    // map
    auto entityComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::EntityComponent, EntityComponentDTO>(entityComponentResult.value());

    Q_EMIT entityComponentUpdated(entityComponentDto);

    qDebug() << "UpdateEntityComponentCommandHandler::restoreImpl done";

    return Result<EntityComponentDTO>(entityComponentDto);
}

bool UpdateEntityComponentCommandHandler::s_mappingRegistered = false;

void UpdateEntityComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityComponent, Contracts::DTO::EntityComponent::EntityComponentDTO>(true,
                                                                                                                                                         true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::EntityComponent::UpdateEntityComponentDTO,
                                                           Contracts::DTO::EntityComponent::EntityComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::EntityComponent::UpdateEntityComponentDTO,
                                                           QleanyEditor::Entities::EntityComponent>();
}