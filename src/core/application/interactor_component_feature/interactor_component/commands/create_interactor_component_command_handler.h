// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "interactor_component/commands/create_interactor_component_command.h"
#include "interactor_component/interactor_component_dto.h"
#include "qleany_editor_application_interactor_component_export.h"
#include "repository/interface_interactor_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::InteractorComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Commands;

namespace QleanyEditor::Application::Features::InteractorComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_INTERACTOR_COMPONENT_EXPORT CreateInteractorComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateInteractorComponentCommandHandler(InterfaceInteractorComponentRepository *repository);

    Result<InteractorComponentDTO> handle(QPromise<Result<void>> &progressPromise, const CreateInteractorComponentCommand &request);
    Result<InteractorComponentDTO> restore();

Q_SIGNALS:
    void interactorComponentCreated(QleanyEditor::Contracts::DTO::InteractorComponent::InteractorComponentDTO interactorComponentDto);
    void interactorComponentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceInteractorComponentRepository *m_repository;
    Result<InteractorComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateInteractorComponentCommand &request);
    Result<InteractorComponentDTO> restoreImpl();
    Result<QleanyEditor::Entities::InteractorComponent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::InteractorComponent m_oldOwnerInteractorComponent;
    QleanyEditor::Entities::InteractorComponent m_ownerInteractorComponentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::InteractorComponent::Commands