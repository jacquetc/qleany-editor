// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_entity_parent_command_handler.h"
#include "entity_parent/validators/remove_entity_parent_command_validator.h"
#include "repository/interface_entity_parent_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityParent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityParent::Commands;
using namespace QleanyEditor::Application::Features::EntityParent::Commands;
using namespace QleanyEditor::Contracts::CQRS::EntityParent::Validators;

RemoveEntityParentCommandHandler::RemoveEntityParentCommandHandler(InterfaceEntityParentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveEntityParentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveEntityParentCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveEntityParentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveEntityParentCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveEntityParentCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveEntityParentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveEntityParentCommand &request)
{
    int entityParentId = request.id;

    // Validate the command using the validator
    auto validator = RemoveEntityParentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(entityParentId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::EntityParent> entityParentResult = m_repository->get(entityParentId);

    QLN_RETURN_IF_ERROR(int, entityParentResult)

    // save old entity
    m_oldState = entityParentResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << entityParentId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT entityParentRemoved(deleteResult.value());

    qDebug() << "EntityParent removed:" << entityParentId;

    return Result<int>(entityParentId);
}

Result<int> RemoveEntityParentCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveEntityParentCommandHandler::s_mappingRegistered = false;

void RemoveEntityParentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::EntityParent, Contracts::DTO::EntityParent::EntityParentDTO>(true, true);
}