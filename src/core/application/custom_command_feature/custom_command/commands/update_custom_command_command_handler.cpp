// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_custom_command_command_handler.h"
#include "custom_command/validators/update_custom_command_command_validator.h"
#include "repository/interface_custom_command_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomCommand;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomCommand::Commands;
using namespace QleanyEditor::Contracts::CQRS::CustomCommand::Validators;
using namespace QleanyEditor::Application::Features::CustomCommand::Commands;

UpdateCustomCommandCommandHandler::UpdateCustomCommandCommandHandler(InterfaceCustomCommandRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomCommandDTO> UpdateCustomCommandCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateCustomCommandCommand &request)
{
    Result<CustomCommandDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CustomCommandDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCustomCommandCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomCommandDTO> UpdateCustomCommandCommandHandler::restore()
{
    Result<CustomCommandDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CustomCommandDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCustomCommandCommand restore:" << ex.what();
    }
    return result;
}

Result<CustomCommandDTO> UpdateCustomCommandCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCustomCommandCommand &request)
{
    qDebug() << "UpdateCustomCommandCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateCustomCommandCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(CustomCommandDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::CustomCommand> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(CustomCommandDTO, currentResult)

        // map
        m_undoState = Result<CustomCommandDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomCommand, CustomCommandDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<CustomCommandDTO, UpdateCustomCommandDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto customCommand = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateCustomCommandDTO, QleanyEditor::Entities::CustomCommand>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        customCommand.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto customCommandResult = m_repository->update(std::move(customCommand));

    if (customCommandResult.hasError()) {
        return Result<CustomCommandDTO>(customCommandResult.error());
    }

    // map
    auto customCommandDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomCommand, CustomCommandDTO>(customCommandResult.value());

    Q_EMIT customCommandUpdated(customCommandDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT customCommandDetailsUpdated(customCommandDto.id());
    }

    qDebug() << "UpdateCustomCommandCommandHandler::handleImpl done";

    return Result<CustomCommandDTO>(customCommandDto);
}

Result<CustomCommandDTO> UpdateCustomCommandCommandHandler::restoreImpl()
{
    qDebug() << "UpdateCustomCommandCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto customCommand = Qleany::Tools::AutoMapper::AutoMapper::map<CustomCommandDTO, QleanyEditor::Entities::CustomCommand>(m_undoState.value());

    // do
    auto customCommandResult = m_repository->update(std::move(customCommand));

    QLN_RETURN_IF_ERROR(CustomCommandDTO, customCommandResult)

    // map
    auto customCommandDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomCommand, CustomCommandDTO>(customCommandResult.value());

    Q_EMIT customCommandUpdated(customCommandDto);

    qDebug() << "UpdateCustomCommandCommandHandler::restoreImpl done";

    return Result<CustomCommandDTO>(customCommandDto);
}

bool UpdateCustomCommandCommandHandler::s_mappingRegistered = false;

void UpdateCustomCommandCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomCommand, Contracts::DTO::CustomCommand::CustomCommandDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomCommand::UpdateCustomCommandDTO,
                                                           Contracts::DTO::CustomCommand::CustomCommandDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomCommand::UpdateCustomCommandDTO, QleanyEditor::Entities::CustomCommand>();
}