// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_presenter_component_command_handler.h"
#include "presenter_component/validators/update_presenter_component_command_validator.h"
#include "repository/interface_presenter_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Validators;
using namespace QleanyEditor::Application::Features::PresenterComponent::Commands;

UpdatePresenterComponentCommandHandler::UpdatePresenterComponentCommandHandler(InterfacePresenterComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterComponentDTO> UpdatePresenterComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                             const UpdatePresenterComponentCommand &request)
{
    Result<PresenterComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<PresenterComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdatePresenterComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterComponentDTO> UpdatePresenterComponentCommandHandler::restore()
{
    Result<PresenterComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<PresenterComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdatePresenterComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<PresenterComponentDTO> UpdatePresenterComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                 const UpdatePresenterComponentCommand &request)
{
    qDebug() << "UpdatePresenterComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdatePresenterComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(PresenterComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::PresenterComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(PresenterComponentDTO, currentResult)

        // map
        m_undoState = Result<PresenterComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterComponent, PresenterComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<PresenterComponentDTO, UpdatePresenterComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto presenterComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdatePresenterComponentDTO, QleanyEditor::Entities::PresenterComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        presenterComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto presenterComponentResult = m_repository->update(std::move(presenterComponent));

    if (presenterComponentResult.hasError()) {
        return Result<PresenterComponentDTO>(presenterComponentResult.error());
    }

    // map
    auto presenterComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterComponent, PresenterComponentDTO>(presenterComponentResult.value());

    Q_EMIT presenterComponentUpdated(presenterComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT presenterComponentDetailsUpdated(presenterComponentDto.id());
    }

    qDebug() << "UpdatePresenterComponentCommandHandler::handleImpl done";

    return Result<PresenterComponentDTO>(presenterComponentDto);
}

Result<PresenterComponentDTO> UpdatePresenterComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdatePresenterComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto presenterComponent =
        Qleany::Tools::AutoMapper::AutoMapper::map<PresenterComponentDTO, QleanyEditor::Entities::PresenterComponent>(m_undoState.value());

    // do
    auto presenterComponentResult = m_repository->update(std::move(presenterComponent));

    QLN_RETURN_IF_ERROR(PresenterComponentDTO, presenterComponentResult)

    // map
    auto presenterComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterComponent, PresenterComponentDTO>(presenterComponentResult.value());

    Q_EMIT presenterComponentUpdated(presenterComponentDto);

    qDebug() << "UpdatePresenterComponentCommandHandler::restoreImpl done";

    return Result<PresenterComponentDTO>(presenterComponentDto);
}

bool UpdatePresenterComponentCommandHandler::s_mappingRegistered = false;

void UpdatePresenterComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterComponent,
                                                           Contracts::DTO::PresenterComponent::PresenterComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterComponent::UpdatePresenterComponentDTO,
                                                           Contracts::DTO::PresenterComponent::PresenterComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterComponent::UpdatePresenterComponentDTO,
                                                           QleanyEditor::Entities::PresenterComponent>();
}