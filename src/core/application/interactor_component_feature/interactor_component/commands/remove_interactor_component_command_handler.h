// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "interactor_component/commands/remove_interactor_component_command.h"
#include "interactor_component/interactor_component_dto.h"
#include "qleany_editor_application_interactor_component_export.h"

#include "repository/interface_interactor_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::InteractorComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Commands;

namespace QleanyEditor::Application::Features::InteractorComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_INTERACTOR_COMPONENT_EXPORT RemoveInteractorComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveInteractorComponentCommandHandler(InterfaceInteractorComponentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveInteractorComponentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void interactorComponentRemoved(int id);

private:
    InterfaceInteractorComponentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveInteractorComponentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::InteractorComponent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::InteractorComponent::Commands