// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_entity_field_command_handler.h"
#include "entity_field/validators/remove_entity_field_command_validator.h"
#include "repository/interface_entity_field_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityField::Commands;
using namespace QleanyEditor::Application::Features::EntityField::Commands;
using namespace QleanyEditor::Contracts::CQRS::EntityField::Validators;

RemoveEntityFieldCommandHandler::RemoveEntityFieldCommandHandler(InterfaceEntityFieldRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveEntityFieldCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveEntityFieldCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveEntityFieldCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveEntityFieldCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveEntityFieldCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveEntityFieldCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveEntityFieldCommand &request)
{
    int entityFieldId = request.id;

    // Validate the command using the validator
    auto validator = RemoveEntityFieldCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(entityFieldId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::EntityField> entityFieldResult = m_repository->get(entityFieldId);

    QLN_RETURN_IF_ERROR(int, entityFieldResult)

    // save old entity
    m_oldState = entityFieldResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << entityFieldId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT entityFieldRemoved(deleteResult.value());

    qDebug() << "EntityField removed:" << entityFieldId;

    return Result<int>(entityFieldId);
}

Result<int> RemoveEntityFieldCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveEntityFieldCommandHandler::s_mappingRegistered = false;

void RemoveEntityFieldCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityField, Contracts::DTO::EntityField::EntityFieldDTO>(true, true);
}