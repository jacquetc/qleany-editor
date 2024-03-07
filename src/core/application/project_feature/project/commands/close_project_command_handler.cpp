// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "close_project_command_handler.h"
#include <qleany/tools/automapper/automapper.h>

#include <QDebug>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Application::Features::Project::Commands;

CloseProjectCommandHandler::CloseProjectCommandHandler(InterfaceProjectRepository *projectRepository)
    : m_projectRepository(projectRepository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<void> CloseProjectCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CloseProjectCommand &request)
{
    Result<void> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<void>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CloseProjectCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<void> CloseProjectCommandHandler::restore()
{
    Q_UNREACHABLE();
    return Result<void>();
}

Result<void> CloseProjectCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CloseProjectCommand &request)
{
    qDebug() << "CloseProjectCommandHandler::handleImpl called";

    // implement logic here which will not be repeated on restore
    // project = Qleany::Tools::AutoMapper::AutoMapper::map<void, QleanyEditor::Entities::Project>(request.req);

    m_projectRepository->beginChanges();

    // play here with the repositories
    Q_UNIMPLEMENTED();

    m_projectRepository->saveChanges();

    // emit signal
    // emit closeProjectChanged();

    // Return
    return Result<void>();
}

bool CloseProjectCommandHandler::s_mappingRegistered = false;

void CloseProjectCommandHandler::registerMappings()
{
}