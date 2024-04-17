// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_repository_command_handler.h"
#include "repository/interface_repository_repository.h"
#include "repository/validators/remove_repository_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Repository::Commands;
using namespace QleanyEditor::Application::Features::Repository::Commands;
using namespace QleanyEditor::Contracts::CQRS::Repository::Validators;

RemoveRepositoryCommandHandler::RemoveRepositoryCommandHandler(InterfaceRepositoryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveRepositoryCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveRepositoryCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveRepositoryCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveRepositoryCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveRepositoryCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveRepositoryCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveRepositoryCommand &request)
{
    int repositoryId = request.id;

    // Validate the command using the validator
    auto validator = RemoveRepositoryCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(repositoryId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::Repository> repositoryResult = m_repository->get(repositoryId);

    QLN_RETURN_IF_ERROR(int, repositoryResult)

    // save old entity
    m_oldState = repositoryResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << repositoryId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT repositoryRemoved(deleteResult.value());

    qDebug() << "Repository removed:" << repositoryId;

    return Result<int>(repositoryId);
}

Result<int> RemoveRepositoryCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveRepositoryCommandHandler::s_mappingRegistered = false;

void RemoveRepositoryCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Repository, Contracts::DTO::Repository::RepositoryDTO>(true, true);
}