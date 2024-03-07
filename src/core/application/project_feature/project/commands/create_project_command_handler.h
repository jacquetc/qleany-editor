// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_project_export.h"

#include "project/commands/create_project_command.h"

#include "repository/interface_global_component_repository.h"
#include "repository/interface_project_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::CQRS::Project::Commands;

namespace QleanyEditor::Application::Features::Project::Commands
{
class QLEANY_EDITOR_APPLICATION_PROJECT_EXPORT CreateProjectCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateProjectCommandHandler(InterfaceProjectRepository *projectRepository, InterfaceGlobalComponentRepository *globalComponentRepository);

    Result<void> handle(QPromise<Result<void>> &progressPromise, const CreateProjectCommand &request);

    Result<void> restore();

signals:

    void createProjectChanged();

private:
    InterfaceProjectRepository *m_projectRepository;
    InterfaceGlobalComponentRepository *m_globalComponentRepository;
    Result<void> handleImpl(QPromise<Result<void>> &progressPromise, const CreateProjectCommand &request);

    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Project::Commands