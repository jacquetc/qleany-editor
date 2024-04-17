// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_export.h"
#include "repository/queries/get_repository_query.h"
#include "repository/repository_dto.h"

#include "repository/interface_repository_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Repository::Queries;

namespace QleanyEditor::Application::Features::Repository::Queries
{
class QLEANY_EDITOR_APPLICATION_REPOSITORY_EXPORT GetRepositoryQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetRepositoryQueryHandler(InterfaceRepositoryRepository *repository);
    Result<RepositoryDTO> handle(QPromise<Result<void>> &progressPromise, const GetRepositoryQuery &query);

private:
    InterfaceRepositoryRepository *m_repository;
    Result<RepositoryDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetRepositoryQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Repository::Queries