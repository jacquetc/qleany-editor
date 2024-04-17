// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/application_component_dto.h"
#include "application_component/commands/create_application_component_command.h"
#include "qleany_editor_application_application_component_export.h"
#include "repository/interface_application_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Commands;

namespace QleanyEditor::Application::Features::ApplicationComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_APPLICATION_COMPONENT_EXPORT CreateApplicationComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateApplicationComponentCommandHandler(InterfaceApplicationComponentRepository *repository);

    Result<ApplicationComponentDTO> handle(QPromise<Result<void>> &progressPromise, const CreateApplicationComponentCommand &request);
    Result<ApplicationComponentDTO> restore();

Q_SIGNALS:
    void applicationComponentCreated(QleanyEditor::Contracts::DTO::ApplicationComponent::ApplicationComponentDTO applicationComponentDto);
    void applicationComponentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceApplicationComponentRepository *m_repository;
    Result<ApplicationComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateApplicationComponentCommand &request);
    Result<ApplicationComponentDTO> restoreImpl();
    Result<QleanyEditor::Entities::ApplicationComponent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::ApplicationComponent m_oldOwnerApplicationComponent;
    QleanyEditor::Entities::ApplicationComponent m_ownerApplicationComponentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::ApplicationComponent::Commands