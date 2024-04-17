// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_component_export.h"
#include "repository_component/commands/remove_repository_component_command.h"
#include "repository_component/repository_component_dto.h"

#include "repository/interface_repository_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Commands;

namespace QleanyEditor::Application::Features::RepositoryComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_REPOSITORY_COMPONENT_EXPORT RemoveRepositoryComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveRepositoryComponentCommandHandler(InterfaceRepositoryComponentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveRepositoryComponentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void repositoryComponentRemoved(int id);

private:
    InterfaceRepositoryComponentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveRepositoryComponentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::RepositoryComponent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::RepositoryComponent::Commands