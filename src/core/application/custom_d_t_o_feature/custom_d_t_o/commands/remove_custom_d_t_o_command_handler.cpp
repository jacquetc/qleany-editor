// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_custom_d_t_o_command_handler.h"
#include "custom_d_t_o/validators/remove_custom_d_t_o_command_validator.h"
#include "repository/interface_custom_d_t_o_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomDTO;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTO::Commands;
using namespace QleanyEditor::Application::Features::CustomDTO::Commands;
using namespace QleanyEditor::Contracts::CQRS::CustomDTO::Validators;

RemoveCustomDTOCommandHandler::RemoveCustomDTOCommandHandler(InterfaceCustomDTORepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveCustomDTOCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveCustomDTOCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCustomDTOCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveCustomDTOCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCustomDTOCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveCustomDTOCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCustomDTOCommand &request)
{
    int customDTOId = request.id;

    // Validate the command using the validator
    auto validator = RemoveCustomDTOCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(customDTOId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::CustomDTO> customDTOResult = m_repository->get(customDTOId);

    QLN_RETURN_IF_ERROR(int, customDTOResult)

    // save old entity
    m_oldState = customDTOResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << customDTOId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT customDTORemoved(deleteResult.value());

    qDebug() << "CustomDTO removed:" << customDTOId;

    return Result<int>(customDTOId);
}

Result<int> RemoveCustomDTOCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveCustomDTOCommandHandler::s_mappingRegistered = false;

void RemoveCustomDTOCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTO, Contracts::DTO::CustomDTO::CustomDTODTO>(true, true);
}