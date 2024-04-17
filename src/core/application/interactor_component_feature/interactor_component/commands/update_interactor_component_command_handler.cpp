// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_interactor_component_command_handler.h"
#include "interactor_component/validators/update_interactor_component_command_validator.h"
#include "repository/interface_interactor_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::InteractorComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Validators;
using namespace QleanyEditor::Application::Features::InteractorComponent::Commands;

UpdateInteractorComponentCommandHandler::UpdateInteractorComponentCommandHandler(InterfaceInteractorComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<InteractorComponentDTO> UpdateInteractorComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                               const UpdateInteractorComponentCommand &request)
{
    Result<InteractorComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<InteractorComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateInteractorComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<InteractorComponentDTO> UpdateInteractorComponentCommandHandler::restore()
{
    Result<InteractorComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<InteractorComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateInteractorComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<InteractorComponentDTO> UpdateInteractorComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                   const UpdateInteractorComponentCommand &request)
{
    qDebug() << "UpdateInteractorComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateInteractorComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(InteractorComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::InteractorComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(InteractorComponentDTO, currentResult)

        // map
        m_undoState = Result<InteractorComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::InteractorComponent, InteractorComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<InteractorComponentDTO, UpdateInteractorComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto interactorComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateInteractorComponentDTO, QleanyEditor::Entities::InteractorComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        interactorComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto interactorComponentResult = m_repository->update(std::move(interactorComponent));

    if (interactorComponentResult.hasError()) {
        return Result<InteractorComponentDTO>(interactorComponentResult.error());
    }

    // map
    auto interactorComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::InteractorComponent, InteractorComponentDTO>(interactorComponentResult.value());

    Q_EMIT interactorComponentUpdated(interactorComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT interactorComponentDetailsUpdated(interactorComponentDto.id());
    }

    qDebug() << "UpdateInteractorComponentCommandHandler::handleImpl done";

    return Result<InteractorComponentDTO>(interactorComponentDto);
}

Result<InteractorComponentDTO> UpdateInteractorComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateInteractorComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto interactorComponent =
        Qleany::Tools::AutoMapper::AutoMapper::map<InteractorComponentDTO, QleanyEditor::Entities::InteractorComponent>(m_undoState.value());

    // do
    auto interactorComponentResult = m_repository->update(std::move(interactorComponent));

    QLN_RETURN_IF_ERROR(InteractorComponentDTO, interactorComponentResult)

    // map
    auto interactorComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::InteractorComponent, InteractorComponentDTO>(interactorComponentResult.value());

    Q_EMIT interactorComponentUpdated(interactorComponentDto);

    qDebug() << "UpdateInteractorComponentCommandHandler::restoreImpl done";

    return Result<InteractorComponentDTO>(interactorComponentDto);
}

bool UpdateInteractorComponentCommandHandler::s_mappingRegistered = false;

void UpdateInteractorComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::InteractorComponent,
                                                           Contracts::DTO::InteractorComponent::InteractorComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::InteractorComponent::UpdateInteractorComponentDTO,
                                                           Contracts::DTO::InteractorComponent::InteractorComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::InteractorComponent::UpdateInteractorComponentDTO,
                                                           QleanyEditor::Entities::InteractorComponent>();
}