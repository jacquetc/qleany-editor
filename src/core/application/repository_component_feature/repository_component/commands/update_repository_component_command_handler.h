// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_component_export.h"
#include "repository_component/commands/update_repository_component_command.h"
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
class QLEANY_EDITOR_APPLICATION_REPOSITORY_COMPONENT_EXPORT UpdateRepositoryComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateRepositoryComponentCommandHandler(InterfaceRepositoryComponentRepository *repository);
    Result<RepositoryComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateRepositoryComponentCommand &request);
    Result<RepositoryComponentDTO> restore();

Q_SIGNALS:
    void repositoryComponentUpdated(QleanyEditor::Contracts::DTO::RepositoryComponent::RepositoryComponentDTO repositoryComponentDto);
    void repositoryComponentDetailsUpdated(int id);

private:
    InterfaceRepositoryComponentRepository *m_repository;
    Result<RepositoryComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateRepositoryComponentCommand &request);
    Result<RepositoryComponentDTO> restoreImpl();
    Result<RepositoryComponentDTO> saveOldState();
    Result<RepositoryComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::RepositoryComponent::Commands