// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_front_end_component_command_handler.h"
#include "front_end_component/validators/update_front_end_component_command_validator.h"
#include "repository/interface_front_end_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Validators;
using namespace QleanyEditor::Application::Features::FrontEndComponent::Commands;

UpdateFrontEndComponentCommandHandler::UpdateFrontEndComponentCommandHandler(InterfaceFrontEndComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<FrontEndComponentDTO> UpdateFrontEndComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                           const UpdateFrontEndComponentCommand &request)
{
    Result<FrontEndComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<FrontEndComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateFrontEndComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<FrontEndComponentDTO> UpdateFrontEndComponentCommandHandler::restore()
{
    Result<FrontEndComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<FrontEndComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateFrontEndComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<FrontEndComponentDTO> UpdateFrontEndComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                               const UpdateFrontEndComponentCommand &request)
{
    qDebug() << "UpdateFrontEndComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateFrontEndComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(FrontEndComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::FrontEndComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(FrontEndComponentDTO, currentResult)

        // map
        m_undoState = Result<FrontEndComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::FrontEndComponent, FrontEndComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<FrontEndComponentDTO, UpdateFrontEndComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto frontEndComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateFrontEndComponentDTO, QleanyEditor::Entities::FrontEndComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        frontEndComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto frontEndComponentResult = m_repository->update(std::move(frontEndComponent));

    if (frontEndComponentResult.hasError()) {
        return Result<FrontEndComponentDTO>(frontEndComponentResult.error());
    }

    // map
    auto frontEndComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::FrontEndComponent, FrontEndComponentDTO>(frontEndComponentResult.value());

    Q_EMIT frontEndComponentUpdated(frontEndComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT frontEndComponentDetailsUpdated(frontEndComponentDto.id());
    }

    qDebug() << "UpdateFrontEndComponentCommandHandler::handleImpl done";

    return Result<FrontEndComponentDTO>(frontEndComponentDto);
}

Result<FrontEndComponentDTO> UpdateFrontEndComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateFrontEndComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto frontEndComponent = Qleany::Tools::AutoMapper::AutoMapper::map<FrontEndComponentDTO, QleanyEditor::Entities::FrontEndComponent>(m_undoState.value());

    // do
    auto frontEndComponentResult = m_repository->update(std::move(frontEndComponent));

    QLN_RETURN_IF_ERROR(FrontEndComponentDTO, frontEndComponentResult)

    // map
    auto frontEndComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::FrontEndComponent, FrontEndComponentDTO>(frontEndComponentResult.value());

    Q_EMIT frontEndComponentUpdated(frontEndComponentDto);

    qDebug() << "UpdateFrontEndComponentCommandHandler::restoreImpl done";

    return Result<FrontEndComponentDTO>(frontEndComponentDto);
}

bool UpdateFrontEndComponentCommandHandler::s_mappingRegistered = false;

void UpdateFrontEndComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::FrontEndComponent, Contracts::DTO::FrontEndComponent::FrontEndComponentDTO>(
        true,
        true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::FrontEndComponent::UpdateFrontEndComponentDTO,
                                                           Contracts::DTO::FrontEndComponent::FrontEndComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::FrontEndComponent::UpdateFrontEndComponentDTO,
                                                           QleanyEditor::Entities::FrontEndComponent>();
}