// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_export.h"
#include "repository/repository_dto.h"

#include "repository/interface_repository_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Repository;
using namespace QleanyEditor::Contracts::Repository;

namespace QleanyEditor::Application::Features::Repository::Queries
{
class QLEANY_EDITOR_APPLICATION_REPOSITORY_EXPORT GetAllRepositoryQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetAllRepositoryQueryHandler(InterfaceRepositoryRepository *repository);
    Result<QList<RepositoryDTO>> handle(QPromise<Result<void>> &progressPromise);

private:
    InterfaceRepositoryRepository *m_repository;
    Result<QList<RepositoryDTO>> handleImpl(QPromise<Result<void>> &progressPromise);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Repository::Queries