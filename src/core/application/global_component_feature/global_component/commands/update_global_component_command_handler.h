// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "global_component/commands/update_global_component_command.h"
#include "global_component/global_component_dto.h"
#include "qleany_editor_application_global_component_export.h"

#include "repository/interface_global_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::GlobalComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::GlobalComponent::Commands;

namespace QleanyEditor::Application::Features::GlobalComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_GLOBAL_COMPONENT_EXPORT UpdateGlobalComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateGlobalComponentCommandHandler(InterfaceGlobalComponentRepository *repository);
    Result<GlobalComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateGlobalComponentCommand &request);
    Result<GlobalComponentDTO> restore();

signals:
    void globalComponentUpdated(QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO globalComponentDto);
    void globalComponentDetailsUpdated(int id);

private:
    InterfaceGlobalComponentRepository *m_repository;
    Result<GlobalComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateGlobalComponentCommand &request);
    Result<GlobalComponentDTO> restoreImpl();
    Result<GlobalComponentDTO> saveOldState();
    Result<GlobalComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::GlobalComponent::Commands