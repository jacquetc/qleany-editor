// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_recent_project_export.h"
#include "recent_project/queries/get_recent_project_query.h"
#include "recent_project/recent_project_dto.h"

#include "repository/interface_recent_project_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::RecentProject;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RecentProject::Queries;

namespace QleanyEditor::Application::Features::RecentProject::Queries
{
class QLEANY_EDITOR_APPLICATION_RECENT_PROJECT_EXPORT GetRecentProjectQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetRecentProjectQueryHandler(InterfaceRecentProjectRepository *repository);
    Result<RecentProjectDTO> handle(QPromise<Result<void>> &progressPromise, const GetRecentProjectQuery &query);

private:
    InterfaceRecentProjectRepository *m_repository;
    Result<RecentProjectDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetRecentProjectQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::RecentProject::Queries