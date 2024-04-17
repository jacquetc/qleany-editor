// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_custom_d_t_o_field_command_handler.h"
#include "custom_d_t_o_field/validators/remove_custom_d_t_o_field_command_validator.h"
#include "repository/interface_custom_d_t_o_field_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomDTOField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Commands;
using namespace QleanyEditor::Application::Features::CustomDTOField::Commands;
using namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Validators;

RemoveCustomDTOFieldCommandHandler::RemoveCustomDTOFieldCommandHandler(InterfaceCustomDTOFieldRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveCustomDTOFieldCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveCustomDTOFieldCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCustomDTOFieldCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveCustomDTOFieldCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCustomDTOFieldCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveCustomDTOFieldCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCustomDTOFieldCommand &request)
{
    int customDTOFieldId = request.id;

    // Validate the command using the validator
    auto validator = RemoveCustomDTOFieldCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(customDTOFieldId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::CustomDTOField> customDTOFieldResult = m_repository->get(customDTOFieldId);

    QLN_RETURN_IF_ERROR(int, customDTOFieldResult)

    // save old entity
    m_oldState = customDTOFieldResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << customDTOFieldId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT customDTOFieldRemoved(deleteResult.value());

    qDebug() << "CustomDTOField removed:" << customDTOFieldId;

    return Result<int>(customDTOFieldId);
}

Result<int> RemoveCustomDTOFieldCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveCustomDTOFieldCommandHandler::s_mappingRegistered = false;

void RemoveCustomDTOFieldCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomDTOField, Contracts::DTO::CustomDTOField::CustomDTOFieldDTO>(true,
                                                                                                                                                      true);
}