// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_export.h"
#include "repository/commands/remove_repository_command.h"
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
class QLEANY_EDITOR_APPLICATION_REPOSITORY_EXPORT RemoveRepositoryCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveRepositoryCommandHandler(InterfaceRepositoryRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveRepositoryCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void repositoryRemoved(int id);

private:
    InterfaceRepositoryRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveRepositoryCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::Repository m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Repository::Commands