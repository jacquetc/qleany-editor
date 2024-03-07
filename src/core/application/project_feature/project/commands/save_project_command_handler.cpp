// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "save_project_command_handler.h"
#include "project/save_project_dto.h"
#include "project/validators/save_project_command_validator.h"
#include <QDebug>
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Project;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Project::Validators;
using namespace QleanyEditor::Application::Features::Project::Commands;

SaveProjectCommandHandler::SaveProjectCommandHandler(InterfaceProjectRepository *projectRepository,
                                                     InterfaceGlobalComponentRepository *globalComponentRepository)
    : m_projectRepository(projectRepository)
    , m_globalComponentRepository(globalComponentRepository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<void> SaveProjectCommandHandler::handle(QPromise<Result<void>> &progressPromise, const SaveProjectCommand &request)
{
    Result<void> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<void>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling SaveProjectCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<void> SaveProjectCommandHandler::restore()
{
    Q_UNREACHABLE();
    return Result<void>();
}

Result<void> SaveProjectCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const SaveProjectCommand &request)
{
    qDebug() << "SaveProjectCommandHandler::handleImpl called";

    // Validate the create project command using the validator
    auto validator = SaveProjectCommandValidator(m_projectRepository, m_globalComponentRepository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(void, validatorResult);

    // implement logic here which will not be repeated on restore
    // project = Qleany::Tools::AutoMapper::AutoMapper::map<SaveProjectDTO, QleanyEditor::Entities::Project>(request.req);

    m_projectRepository->beginChanges();

    // play here with the repositories
    Q_UNIMPLEMENTED();

    m_projectRepository->saveChanges();

    // emit signal
    // emit saveProjectChanged();

    // Return
    return Result<void>();
}

bool SaveProjectCommandHandler::s_mappingRegistered = false;

void SaveProjectCommandHandler::registerMappings()
{
}