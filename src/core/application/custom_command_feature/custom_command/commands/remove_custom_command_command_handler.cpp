// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_custom_command_command_handler.h"
#include "custom_command/validators/remove_custom_command_command_validator.h"
#include "repository/interface_custom_command_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomCommand;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomCommand::Commands;
using namespace QleanyEditor::Application::Features::CustomCommand::Commands;
using namespace QleanyEditor::Contracts::CQRS::CustomCommand::Validators;

RemoveCustomCommandCommandHandler::RemoveCustomCommandCommandHandler(InterfaceCustomCommandRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveCustomCommandCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveCustomCommandCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCustomCommandCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveCustomCommandCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCustomCommandCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveCustomCommandCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCustomCommandCommand &request)
{
    int customCommandId = request.id;

    // Validate the command using the validator
    auto validator = RemoveCustomCommandCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(customCommandId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::CustomCommand> customCommandResult = m_repository->get(customCommandId);

    QLN_RETURN_IF_ERROR(int, customCommandResult)

    // save old entity
    m_oldState = customCommandResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << customCommandId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT customCommandRemoved(deleteResult.value());

    qDebug() << "CustomCommand removed:" << customCommandId;

    return Result<int>(customCommandId);
}

Result<int> RemoveCustomCommandCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveCustomCommandCommandHandler::s_mappingRegistered = false;

void RemoveCustomCommandCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomCommand, Contracts::DTO::CustomCommand::CustomCommandDTO>(true, true);
}