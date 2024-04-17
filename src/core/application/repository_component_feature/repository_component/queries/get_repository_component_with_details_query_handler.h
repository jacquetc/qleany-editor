// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_component_export.h"
#include "repository_component/queries/get_repository_component_query.h"
#include "repository_component/repository_component_with_details_dto.h"

#include "repository/interface_repository_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Queries;

namespace QleanyEditor::Application::Features::RepositoryComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_REPOSITORY_COMPONENT_EXPORT GetRepositoryComponentWithDetailsQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetRepositoryComponentWithDetailsQueryHandler(InterfaceRepositoryComponentRepository *repository);
    Result<RepositoryComponentWithDetailsDTO> handle(QPromise<Result<void>> &progressPromise, const GetRepositoryComponentQuery &query);

private:
    InterfaceRepositoryComponentRepository *m_repository;
    Result<RepositoryComponentWithDetailsDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetRepositoryComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::RepositoryComponent::Queries