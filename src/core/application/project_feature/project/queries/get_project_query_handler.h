// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "project/project_dto.h"
#include "project/queries/get_project_query.h"
#include "qleany_editor_application_project_export.h"

#include "repository/interface_project_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Project;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Project::Queries;

namespace QleanyEditor::Application::Features::Project::Queries
{
class QLEANY_EDITOR_APPLICATION_PROJECT_EXPORT GetProjectQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetProjectQueryHandler(InterfaceProjectRepository *repository);
    Result<ProjectDTO> handle(QPromise<Result<void>> &progressPromise, const GetProjectQuery &query);

private:
    InterfaceProjectRepository *m_repository;
    Result<ProjectDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetProjectQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Project::Queries