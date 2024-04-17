// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_custom_d_t_o_field_command_handler.h"
#include "custom_d_t_o_field/validators/update_custom_d_t_o_field_command_validator.h"
#include "repository/interface_custom_d_t_o_field_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomDTOField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Commands;
using namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Validators;
using namespace QleanyEditor::Application::Features::CustomDTOField::Commands;

UpdateCustomDTOFieldCommandHandler::UpdateCustomDTOFieldCommandHandler(InterfaceCustomDTOFieldRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomDTOFieldDTO> UpdateCustomDTOFieldCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateCustomDTOFieldCommand &request)
{
    Result<CustomDTOFieldDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CustomDTOFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCustomDTOFieldCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomDTOFieldDTO> UpdateCustomDTOFieldCommandHandler::restore()
{
    Result<CustomDTOFieldDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CustomDTOFieldDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCustomDTOFieldCommand restore:" << ex.what();
    }
    return result;
}

Result<CustomDTOFieldDTO> UpdateCustomDTOFieldCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCustomDTOFieldCommand &request)
{
    qDebug() << "UpdateCustomDTOFieldCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateCustomDTOFieldCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(CustomDTOFieldDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::CustomDTOField> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(CustomDTOFieldDTO, currentResult)

        // map
        m_undoState = Result<CustomDTOFieldDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTOField, CustomDTOFieldDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<CustomDTOFieldDTO, UpdateCustomDTOFieldDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto customDTOField = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateCustomDTOFieldDTO, QleanyEditor::Entities::CustomDTOField>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        customDTOField.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto customDTOFieldResult = m_repository->update(std::move(customDTOField));

    if (customDTOFieldResult.hasError()) {
        return Result<CustomDTOFieldDTO>(customDTOFieldResult.error());
    }

    // map
    auto customDTOFieldDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTOField, CustomDTOFieldDTO>(customDTOFieldResult.value());

    Q_EMIT customDTOFieldUpdated(customDTOFieldDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT customDTOFieldDetailsUpdated(customDTOFieldDto.id());
    }

    qDebug() << "UpdateCustomDTOFieldCommandHandler::handleImpl done";

    return Result<CustomDTOFieldDTO>(customDTOFieldDto);
}

Result<CustomDTOFieldDTO> UpdateCustomDTOFieldCommandHandler::restoreImpl()
{
    qDebug() << "UpdateCustomDTOFieldCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto customDTOField = Qleany::Tools::AutoMapper::AutoMapper::map<CustomDTOFieldDTO, QleanyEditor::Entities::CustomDTOField>(m_undoState.value());

    // do
    auto customDTOFieldResult = m_repository->update(std::move(customDTOField));

    QLN_RETURN_IF_ERROR(CustomDTOFieldDTO, customDTOFieldResult)

    // map
    auto customDTOFieldDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomDTOField, CustomDTOFieldDTO>(customDTOFieldResult.value());

    Q_EMIT customDTOFieldUpdated(customDTOFieldDto);

    qDebug() << "UpdateCustomDTOFieldCommandHandler::restoreImpl done";

    return Result<CustomDTOFieldDTO>(customDTOFieldDto);
}

bool UpdateCustomDTOFieldCommandHandler::s_mappingRegistered = false;

void UpdateCustomDTOFieldCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTOField, Contracts::DTO::CustomDTOField::CustomDTOFieldDTO>(true,
                                                                                                                                                      true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomDTOField::UpdateCustomDTOFieldDTO,
                                                           Contracts::DTO::CustomDTOField::CustomDTOFieldDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomDTOField::UpdateCustomDTOFieldDTO, QleanyEditor::Entities::CustomDTOField>();
}