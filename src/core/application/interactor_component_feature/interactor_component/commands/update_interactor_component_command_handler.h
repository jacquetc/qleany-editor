// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "interactor_component/commands/update_interactor_component_command.h"
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
class QLEANY_EDITOR_APPLICATION_INTERACTOR_COMPONENT_EXPORT UpdateInteractorComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateInteractorComponentCommandHandler(InterfaceInteractorComponentRepository *repository);
    Result<InteractorComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateInteractorComponentCommand &request);
    Result<InteractorComponentDTO> restore();

Q_SIGNALS:
    void interactorComponentUpdated(QleanyEditor::Contracts::DTO::InteractorComponent::InteractorComponentDTO interactorComponentDto);
    void interactorComponentDetailsUpdated(int id);

private:
    InterfaceInteractorComponentRepository *m_repository;
    Result<InteractorComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateInteractorComponentCommand &request);
    Result<InteractorComponentDTO> restoreImpl();
    Result<InteractorComponentDTO> saveOldState();
    Result<InteractorComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::InteractorComponent::Commands