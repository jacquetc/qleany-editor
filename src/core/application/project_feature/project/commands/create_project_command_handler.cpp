// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_project_command_handler.h"
#include "project/create_project_dto.h"
#include "project/validators/create_project_command_validator.h"
#include <QDebug>
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Project;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Project::Validators;
using namespace QleanyEditor::Application::Features::Project::Commands;

CreateProjectCommandHandler::CreateProjectCommandHandler(InterfaceProjectRepository *projectRepository,
                                                         InterfaceGlobalComponentRepository *globalComponentRepository)
    : m_projectRepository(projectRepository)
    , m_globalComponentRepository(globalComponentRepository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<void> CreateProjectCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateProjectCommand &request)
{
    Result<void> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<void>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateProjectCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<void> CreateProjectCommandHandler::restore()
{
    Q_UNREACHABLE();
    return Result<void>();
}

Result<void> CreateProjectCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateProjectCommand &request)
{
    qDebug() << "CreateProjectCommandHandler::handleImpl called";

    // Validate the create project command using the validator
    auto validator = CreateProjectCommandValidator(m_projectRepository, m_globalComponentRepository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(void, validatorResult);

    // implement logic here which will not be repeated on restore
    // project = Qleany::Tools::AutoMapper::AutoMapper::map<CreateProjectDTO, QleanyEditor::Entities::Project>(request.req);

    m_projectRepository->beginChanges();

    // play here with the repositories
    Q_UNIMPLEMENTED();

    m_projectRepository->saveChanges();

    // emit signal
    // emit createProjectChanged();

    // Return
    return Result<void>();
}

bool CreateProjectCommandHandler::s_mappingRegistered = false;

void CreateProjectCommandHandler::registerMappings()
{
}