// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_repository_component_export.h"
#include "repository/interface_repository_component_repository.h"
#include "repository_component/commands/create_repository_component_command.h"
#include "repository_component/repository_component_dto.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Commands;

namespace QleanyEditor::Application::Features::RepositoryComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_REPOSITORY_COMPONENT_EXPORT CreateRepositoryComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateRepositoryComponentCommandHandler(InterfaceRepositoryComponentRepository *repository);

    Result<RepositoryComponentDTO> handle(QPromise<Result<void>> &progressPromise, const CreateRepositoryComponentCommand &request);
    Result<RepositoryComponentDTO> restore();

Q_SIGNALS:
    void repositoryComponentCreated(QleanyEditor::Contracts::DTO::RepositoryComponent::RepositoryComponentDTO repositoryComponentDto);
    void repositoryComponentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceRepositoryComponentRepository *m_repository;
    Result<RepositoryComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateRepositoryComponentCommand &request);
    Result<RepositoryComponentDTO> restoreImpl();
    Result<QleanyEditor::Entities::RepositoryComponent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::RepositoryComponent m_oldOwnerRepositoryComponent;
    QleanyEditor::Entities::RepositoryComponent m_ownerRepositoryComponentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::RepositoryComponent::Commands