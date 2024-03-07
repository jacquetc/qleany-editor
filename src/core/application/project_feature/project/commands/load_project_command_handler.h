// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_project_export.h"

#include "project/commands/load_project_command.h"

#include "repository/interface_global_component_repository.h"
#include "repository/interface_project_repository.h"
#include "repository/interface_recent_project_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;

using namespace QleanyEditor::Contracts::Repository;

using namespace QleanyEditor::Contracts::CQRS::Project::Commands;

namespace QleanyEditor::Application::Features::Project::Commands
{
class QLEANY_EDITOR_APPLICATION_PROJECT_EXPORT LoadProjectCommandHandler : public QObject
{
    Q_OBJECT
public:
    LoadProjectCommandHandler(InterfaceProjectRepository *projectRepository,
                              InterfaceGlobalComponentRepository *globalComponentRepository,
                              InterfaceRecentProjectRepository *recentProjectRepository);

    Result<void> handle(QPromise<Result<void>> &progressPromise, const LoadProjectCommand &request);

    Result<void> restore();

signals:

    void loadProjectChanged();

private:
    InterfaceProjectRepository *m_projectRepository;
    InterfaceGlobalComponentRepository *m_globalComponentRepository;
    InterfaceRecentProjectRepository *m_recentProjectRepository;
    Result<void> handleImpl(QPromise<Result<void>> &progressPromise, const LoadProjectCommand &request);

    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Project::Commands