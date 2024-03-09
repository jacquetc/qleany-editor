// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_project_export.h"

#include "project/commands/close_project_command.h"

#include "repository/interface_project_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::CQRS::Project::Commands;

namespace QleanyEditor::Application::Features::Project::Commands
{
class QLEANY_EDITOR_APPLICATION_PROJECT_EXPORT CloseProjectCommandHandler : public QObject
{
    Q_OBJECT
public:
    CloseProjectCommandHandler(InterfaceProjectRepository *projectRepository);

    Result<void> handle(QPromise<Result<void>> &progressPromise, const CloseProjectCommand &request);

    Result<void> restore();

Q_SIGNALS:

    void closeProjectChanged();

private:
    InterfaceProjectRepository *m_projectRepository;
    Result<void> handleImpl(QPromise<Result<void>> &progressPromise, const CloseProjectCommand &request);

    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Project::Commands