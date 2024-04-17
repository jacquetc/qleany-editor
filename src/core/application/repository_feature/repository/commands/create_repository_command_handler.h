// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_export.h"
#include "repository/commands/create_repository_command.h"
#include "repository/interface_repository_repository.h"
#include "repository/repository_dto.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Repository::Commands;

namespace QleanyEditor::Application::Features::Repository::Commands
{
class QLEANY_EDITOR_APPLICATION_REPOSITORY_EXPORT CreateRepositoryCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateRepositoryCommandHandler(InterfaceRepositoryRepository *repository);

    Result<RepositoryDTO> handle(QPromise<Result<void>> &progressPromise, const CreateRepositoryCommand &request);
    Result<RepositoryDTO> restore();

Q_SIGNALS:
    void repositoryCreated(QleanyEditor::Contracts::DTO::Repository::RepositoryDTO repositoryDto);
    void repositoryRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceRepositoryRepository *m_repository;
    Result<RepositoryDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateRepositoryCommand &request);
    Result<RepositoryDTO> restoreImpl();
    Result<QleanyEditor::Entities::Repository> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::Repository> m_oldOwnerRepositories;
    QList<QleanyEditor::Entities::Repository> m_ownerRepositoriesNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::Repository::Commands