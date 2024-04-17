// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_c_q_r_s_component_command_handler.h"
#include "c_q_r_s_component/validators/update_c_q_r_s_component_command_validator.h"
#include "repository/interface_c_q_r_s_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CQRSComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Validators;
using namespace QleanyEditor::Application::Features::CQRSComponent::Commands;

UpdateCQRSComponentCommandHandler::UpdateCQRSComponentCommandHandler(InterfaceCQRSComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CQRSComponentDTO> UpdateCQRSComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateCQRSComponentCommand &request)
{
    Result<CQRSComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CQRSComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCQRSComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CQRSComponentDTO> UpdateCQRSComponentCommandHandler::restore()
{
    Result<CQRSComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CQRSComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCQRSComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<CQRSComponentDTO> UpdateCQRSComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCQRSComponentCommand &request)
{
    qDebug() << "UpdateCQRSComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateCQRSComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(CQRSComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::CQRSComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(CQRSComponentDTO, currentResult)

        // map
        m_undoState = Result<CQRSComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CQRSComponent, CQRSComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<CQRSComponentDTO, UpdateCQRSComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto cQRSComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateCQRSComponentDTO, QleanyEditor::Entities::CQRSComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        cQRSComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto cQRSComponentResult = m_repository->update(std::move(cQRSComponent));

    if (cQRSComponentResult.hasError()) {
        return Result<CQRSComponentDTO>(cQRSComponentResult.error());
    }

    // map
    auto cQRSComponentDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CQRSComponent, CQRSComponentDTO>(cQRSComponentResult.value());

    Q_EMIT cQRSComponentUpdated(cQRSComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT cQRSComponentDetailsUpdated(cQRSComponentDto.id());
    }

    qDebug() << "UpdateCQRSComponentCommandHandler::handleImpl done";

    return Result<CQRSComponentDTO>(cQRSComponentDto);
}

Result<CQRSComponentDTO> UpdateCQRSComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateCQRSComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto cQRSComponent = Qleany::Tools::AutoMapper::AutoMapper::map<CQRSComponentDTO, QleanyEditor::Entities::CQRSComponent>(m_undoState.value());

    // do
    auto cQRSComponentResult = m_repository->update(std::move(cQRSComponent));

    QLN_RETURN_IF_ERROR(CQRSComponentDTO, cQRSComponentResult)

    // map
    auto cQRSComponentDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CQRSComponent, CQRSComponentDTO>(cQRSComponentResult.value());

    Q_EMIT cQRSComponentUpdated(cQRSComponentDto);

    qDebug() << "UpdateCQRSComponentCommandHandler::restoreImpl done";

    return Result<CQRSComponentDTO>(cQRSComponentDto);
}

bool UpdateCQRSComponentCommandHandler::s_mappingRegistered = false;

void UpdateCQRSComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CQRSComponent, Contracts::DTO::CQRSComponent::CQRSComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CQRSComponent::UpdateCQRSComponentDTO,
                                                           Contracts::DTO::CQRSComponent::CQRSComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CQRSComponent::UpdateCQRSComponentDTO, QleanyEditor::Entities::CQRSComponent>();
}