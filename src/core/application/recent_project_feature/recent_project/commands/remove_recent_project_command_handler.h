// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_recent_project_export.h"
#include "recent_project/commands/remove_recent_project_command.h"
#include "recent_project/recent_project_dto.h"

#include "repository/interface_recent_project_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::RecentProject;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RecentProject::Commands;

namespace QleanyEditor::Application::Features::RecentProject::Commands
{
class QLEANY_EDITOR_APPLICATION_RECENT_PROJECT_EXPORT RemoveRecentProjectCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveRecentProjectCommandHandler(InterfaceRecentProjectRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveRecentProjectCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void recentProjectRemoved(int id);

private:
    InterfaceRecentProjectRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveRecentProjectCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::RecentProject m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::RecentProject::Commands