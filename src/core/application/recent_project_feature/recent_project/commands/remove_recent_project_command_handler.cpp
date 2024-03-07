// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_recent_project_command_handler.h"
#include "recent_project/validators/remove_recent_project_command_validator.h"
#include "repository/interface_recent_project_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::RecentProject;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RecentProject::Commands;
using namespace QleanyEditor::Application::Features::RecentProject::Commands;
using namespace QleanyEditor::Contracts::CQRS::RecentProject::Validators;

RemoveRecentProjectCommandHandler::RemoveRecentProjectCommandHandler(InterfaceRecentProjectRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveRecentProjectCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveRecentProjectCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveRecentProjectCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveRecentProjectCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveRecentProjectCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveRecentProjectCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveRecentProjectCommand &request)
{
    int recentProjectId = request.id;

    // Validate the command using the validator
    auto validator = RemoveRecentProjectCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(recentProjectId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::RecentProject> recentProjectResult = m_repository->get(recentProjectId);

    QLN_RETURN_IF_ERROR(int, recentProjectResult)

    // save old entity
    m_oldState = recentProjectResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << recentProjectId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove signals
    // emit recentProjectRemoved(deleteResult.value());

    qDebug() << "RecentProject removed:" << recentProjectId;

    return Result<int>(recentProjectId);
}

Result<int> RemoveRecentProjectCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveRecentProjectCommandHandler::s_mappingRegistered = false;

void RemoveRecentProjectCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::RecentProject, Contracts::DTO::RecentProject::RecentProjectDTO>(true, true);
}