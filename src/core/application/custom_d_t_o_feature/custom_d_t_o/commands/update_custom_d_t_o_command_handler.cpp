// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_custom_d_t_o_command_handler.h"
#include "custom_d_t_o/validators/update_custom_d_t_o_command_validator.h"
#include "repository/interface_custom_d_t_o_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomDTO;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTO::Commands;
using namespace QleanyEditor::Contracts::CQRS::CustomDTO::Validators;
using namespace QleanyEditor::Application::Features::CustomDTO::Commands;

UpdateCustomDTOCommandHandler::UpdateCustomDTOCommandHandler(InterfaceCustomDTORepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomDTODTO> UpdateCustomDTOCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateCustomDTOCommand &request)
{
    Result<CustomDTODTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CustomDTODTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCustomDTOCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomDTODTO> UpdateCustomDTOCommandHandler::restore()
{
    Result<CustomDTODTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CustomDTODTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCustomDTOCommand restore:" << ex.what();
    }
    return result;
}

Result<CustomDTODTO> UpdateCustomDTOCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCustomDTOCommand &request)
{
    qDebug() << "UpdateCustomDTOCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateCustomDTOCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(CustomDTODTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::CustomDTO> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(CustomDTODTO, currentResult)

        // map
        m_undoState = Result<CustomDTODTO>(Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTO, CustomDTODTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<CustomDTODTO, UpdateCustomDTODTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto customDTO = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateCustomDTODTO, QleanyEditor::Entities::CustomDTO>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        customDTO.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto customDTOResult = m_repository->update(std::move(customDTO));

    if (customDTOResult.hasError()) {
        return Result<CustomDTODTO>(customDTOResult.error());
    }

    // map
    auto customDTODto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTO, CustomDTODTO>(customDTOResult.value());

    Q_EMIT customDTOUpdated(customDTODto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT customDTODetailsUpdated(customDTODto.id());
    }

    qDebug() << "UpdateCustomDTOCommandHandler::handleImpl done";

    return Result<CustomDTODTO>(customDTODto);
}

Result<CustomDTODTO> UpdateCustomDTOCommandHandler::restoreImpl()
{
    qDebug() << "UpdateCustomDTOCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto customDTO = Qleany::Tools::AutoMapper::AutoMapper::map<CustomDTODTO, QleanyEditor::Entities::CustomDTO>(m_undoState.value());

    // do
    auto customDTOResult = m_repository->update(std::move(customDTO));

    QLN_RETURN_IF_ERROR(CustomDTODTO, customDTOResult)

    // map
    auto customDTODto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTO, CustomDTODTO>(customDTOResult.value());

    Q_EMIT customDTOUpdated(customDTODto);

    qDebug() << "UpdateCustomDTOCommandHandler::restoreImpl done";

    return Result<CustomDTODTO>(customDTODto);
}

bool UpdateCustomDTOCommandHandler::s_mappingRegistered = false;

void UpdateCustomDTOCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTO, Contracts::DTO::CustomDTO::CustomDTODTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomDTO::UpdateCustomDTODTO, Contracts::DTO::CustomDTO::CustomDTODTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomDTO::UpdateCustomDTODTO, QleanyEditor::Entities::CustomDTO>();
}