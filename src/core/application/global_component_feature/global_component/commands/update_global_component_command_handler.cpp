// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_global_component_command_handler.h"
#include "global_component/validators/update_global_component_command_validator.h"
#include "repository/interface_global_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::GlobalComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::GlobalComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::GlobalComponent::Validators;
using namespace QleanyEditor::Application::Features::GlobalComponent::Commands;

UpdateGlobalComponentCommandHandler::UpdateGlobalComponentCommandHandler(InterfaceGlobalComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<GlobalComponentDTO> UpdateGlobalComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateGlobalComponentCommand &request)
{
    Result<GlobalComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<GlobalComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateGlobalComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<GlobalComponentDTO> UpdateGlobalComponentCommandHandler::restore()
{
    Result<GlobalComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<GlobalComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateGlobalComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<GlobalComponentDTO> UpdateGlobalComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateGlobalComponentCommand &request)
{
    qDebug() << "UpdateGlobalComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateGlobalComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(GlobalComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::GlobalComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(GlobalComponentDTO, currentResult)

        // map
        m_undoState = Result<GlobalComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::GlobalComponent, GlobalComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<GlobalComponentDTO, UpdateGlobalComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto globalComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateGlobalComponentDTO, QleanyEditor::Entities::GlobalComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        globalComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto globalComponentResult = m_repository->update(std::move(globalComponent));

    if (globalComponentResult.hasError()) {
        return Result<GlobalComponentDTO>(globalComponentResult.error());
    }

    // map
    auto globalComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::GlobalComponent, GlobalComponentDTO>(globalComponentResult.value());

    Q_EMIT globalComponentUpdated(globalComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT globalComponentDetailsUpdated(globalComponentDto.id());
    }

    qDebug() << "UpdateGlobalComponentCommandHandler::handleImpl done";

    return Result<GlobalComponentDTO>(globalComponentDto);
}

Result<GlobalComponentDTO> UpdateGlobalComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateGlobalComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto globalComponent = Qleany::Tools::AutoMapper::AutoMapper::map<GlobalComponentDTO, QleanyEditor::Entities::GlobalComponent>(m_undoState.value());

    // do
    auto globalComponentResult = m_repository->update(std::move(globalComponent));

    QLN_RETURN_IF_ERROR(GlobalComponentDTO, globalComponentResult)

    // map
    auto globalComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::GlobalComponent, GlobalComponentDTO>(globalComponentResult.value());

    Q_EMIT globalComponentUpdated(globalComponentDto);

    qDebug() << "UpdateGlobalComponentCommandHandler::restoreImpl done";

    return Result<GlobalComponentDTO>(globalComponentDto);
}

bool UpdateGlobalComponentCommandHandler::s_mappingRegistered = false;

void UpdateGlobalComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::GlobalComponent, Contracts::DTO::GlobalComponent::GlobalComponentDTO>(true,
                                                                                                                                                         true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::GlobalComponent::UpdateGlobalComponentDTO,
                                                           Contracts::DTO::GlobalComponent::GlobalComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::GlobalComponent::UpdateGlobalComponentDTO,
                                                           QleanyEditor::Entities::GlobalComponent>();
}