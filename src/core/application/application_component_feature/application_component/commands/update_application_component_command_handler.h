// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/application_component_dto.h"
#include "application_component/commands/update_application_component_command.h"
#include "qleany_editor_application_application_component_export.h"

#include "repository/interface_application_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Commands;

namespace QleanyEditor::Application::Features::ApplicationComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_APPLICATION_COMPONENT_EXPORT UpdateApplicationComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateApplicationComponentCommandHandler(InterfaceApplicationComponentRepository *repository);
    Result<ApplicationComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateApplicationComponentCommand &request);
    Result<ApplicationComponentDTO> restore();

Q_SIGNALS:
    void applicationComponentUpdated(QleanyEditor::Contracts::DTO::ApplicationComponent::ApplicationComponentDTO applicationComponentDto);
    void applicationComponentDetailsUpdated(int id);

private:
    InterfaceApplicationComponentRepository *m_repository;
    Result<ApplicationComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateApplicationComponentCommand &request);
    Result<ApplicationComponentDTO> restoreImpl();
    Result<ApplicationComponentDTO> saveOldState();
    Result<ApplicationComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ApplicationComponent::Commands