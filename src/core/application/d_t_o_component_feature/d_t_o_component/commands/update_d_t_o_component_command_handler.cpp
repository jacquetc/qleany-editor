// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_d_t_o_component_command_handler.h"
#include "d_t_o_component/validators/update_d_t_o_component_command_validator.h"
#include "repository/interface_d_t_o_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::DTOComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::DTOComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::DTOComponent::Validators;
using namespace QleanyEditor::Application::Features::DTOComponent::Commands;

UpdateDTOComponentCommandHandler::UpdateDTOComponentCommandHandler(InterfaceDTOComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<DTOComponentDTO> UpdateDTOComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateDTOComponentCommand &request)
{
    Result<DTOComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<DTOComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateDTOComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<DTOComponentDTO> UpdateDTOComponentCommandHandler::restore()
{
    Result<DTOComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<DTOComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateDTOComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<DTOComponentDTO> UpdateDTOComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateDTOComponentCommand &request)
{
    qDebug() << "UpdateDTOComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateDTOComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(DTOComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::DTOComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(DTOComponentDTO, currentResult)

        // map
        m_undoState =
            Result<DTOComponentDTO>(Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::DTOComponent, DTOComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<DTOComponentDTO, UpdateDTOComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto dTOComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateDTOComponentDTO, QleanyEditor::Entities::DTOComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        dTOComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto dTOComponentResult = m_repository->update(std::move(dTOComponent));

    if (dTOComponentResult.hasError()) {
        return Result<DTOComponentDTO>(dTOComponentResult.error());
    }

    // map
    auto dTOComponentDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::DTOComponent, DTOComponentDTO>(dTOComponentResult.value());

    Q_EMIT dTOComponentUpdated(dTOComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT dTOComponentDetailsUpdated(dTOComponentDto.id());
    }

    qDebug() << "UpdateDTOComponentCommandHandler::handleImpl done";

    return Result<DTOComponentDTO>(dTOComponentDto);
}

Result<DTOComponentDTO> UpdateDTOComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateDTOComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto dTOComponent = Qleany::Tools::AutoMapper::AutoMapper::map<DTOComponentDTO, QleanyEditor::Entities::DTOComponent>(m_undoState.value());

    // do
    auto dTOComponentResult = m_repository->update(std::move(dTOComponent));

    QLN_RETURN_IF_ERROR(DTOComponentDTO, dTOComponentResult)

    // map
    auto dTOComponentDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::DTOComponent, DTOComponentDTO>(dTOComponentResult.value());

    Q_EMIT dTOComponentUpdated(dTOComponentDto);

    qDebug() << "UpdateDTOComponentCommandHandler::restoreImpl done";

    return Result<DTOComponentDTO>(dTOComponentDto);
}

bool UpdateDTOComponentCommandHandler::s_mappingRegistered = false;

void UpdateDTOComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::DTOComponent, Contracts::DTO::DTOComponent::DTOComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::DTOComponent::UpdateDTOComponentDTO, Contracts::DTO::DTOComponent::DTOComponentDTO>(
        true,
        true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::DTOComponent::UpdateDTOComponentDTO, QleanyEditor::Entities::DTOComponent>();
}