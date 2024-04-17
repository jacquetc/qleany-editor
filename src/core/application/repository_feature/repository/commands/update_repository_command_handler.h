// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_export.h"
#include "repository/commands/update_repository_command.h"
#include "repository/repository_dto.h"

#include "repository/interface_repository_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Repository::Commands;

namespace QleanyEditor::Application::Features::Repository::Commands
{
class QLEANY_EDITOR_APPLICATION_REPOSITORY_EXPORT UpdateRepositoryCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateRepositoryCommandHandler(InterfaceRepositoryRepository *repository);
    Result<RepositoryDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateRepositoryCommand &request);
    Result<RepositoryDTO> restore();

Q_SIGNALS:
    void repositoryUpdated(QleanyEditor::Contracts::DTO::Repository::RepositoryDTO repositoryDto);
    void repositoryDetailsUpdated(int id);

private:
    InterfaceRepositoryRepository *m_repository;
    Result<RepositoryDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateRepositoryCommand &request);
    Result<RepositoryDTO> restoreImpl();
    Result<RepositoryDTO> saveOldState();
    Result<RepositoryDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Repository::Commands