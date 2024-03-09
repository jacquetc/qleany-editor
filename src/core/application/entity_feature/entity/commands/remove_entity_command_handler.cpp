// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_entity_command_handler.h"
#include "entity/validators/remove_entity_command_validator.h"
#include "repository/interface_entity_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Entity::Commands;
using namespace QleanyEditor::Application::Features::Entity::Commands;
using namespace QleanyEditor::Contracts::CQRS::Entity::Validators;

RemoveEntityCommandHandler::RemoveEntityCommandHandler(InterfaceEntityRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveEntityCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveEntityCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveEntityCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveEntityCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveEntityCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveEntityCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveEntityCommand &request)
{
    int entityId = request.id;

    // Validate the command using the validator
    auto validator = RemoveEntityCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(entityId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::Entity> entityResult = m_repository->get(entityId);

    QLN_RETURN_IF_ERROR(int, entityResult)

    // save old entity
    m_oldState = entityResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << entityId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT entityRemoved(deleteResult.value());

    qDebug() << "Entity removed:" << entityId;

    return Result<int>(entityId);
}

Result<int> RemoveEntityCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveEntityCommandHandler::s_mappingRegistered = false;

void RemoveEntityCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Entity, Contracts::DTO::Entity::EntityDTO>(true, true);
}