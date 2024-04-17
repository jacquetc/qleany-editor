// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_repository_component_command_handler.h"
#include "repository/interface_repository_component_repository.h"
#include "repository_component/validators/remove_repository_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Commands;
using namespace QleanyEditor::Application::Features::RepositoryComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Validators;

RemoveRepositoryComponentCommandHandler::RemoveRepositoryComponentCommandHandler(InterfaceRepositoryComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveRepositoryComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveRepositoryComponentCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveRepositoryComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveRepositoryComponentCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveRepositoryComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveRepositoryComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveRepositoryComponentCommand &request)
{
    int repositoryComponentId = request.id;

    // Validate the command using the validator
    auto validator = RemoveRepositoryComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(repositoryComponentId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::RepositoryComponent> repositoryComponentResult = m_repository->get(repositoryComponentId);

    QLN_RETURN_IF_ERROR(int, repositoryComponentResult)

    // save old entity
    m_oldState = repositoryComponentResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << repositoryComponentId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT repositoryComponentRemoved(deleteResult.value());

    qDebug() << "RepositoryComponent removed:" << repositoryComponentId;

    return Result<int>(repositoryComponentId);
}

Result<int> RemoveRepositoryComponentCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveRepositoryComponentCommandHandler::s_mappingRegistered = false;

void RemoveRepositoryComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::RepositoryComponent,
                                                           Contracts::DTO::RepositoryComponent::RepositoryComponentDTO>(true, true);
}