// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "front_end_component/commands/update_front_end_component_command.h"
#include "front_end_component/front_end_component_dto.h"
#include "qleany_editor_application_front_end_component_export.h"

#include "repository/interface_front_end_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Commands;

namespace QleanyEditor::Application::Features::FrontEndComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_FRONT_END_COMPONENT_EXPORT UpdateFrontEndComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateFrontEndComponentCommandHandler(InterfaceFrontEndComponentRepository *repository);
    Result<FrontEndComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateFrontEndComponentCommand &request);
    Result<FrontEndComponentDTO> restore();

Q_SIGNALS:
    void frontEndComponentUpdated(QleanyEditor::Contracts::DTO::FrontEndComponent::FrontEndComponentDTO frontEndComponentDto);
    void frontEndComponentDetailsUpdated(int id);

private:
    InterfaceFrontEndComponentRepository *m_repository;
    Result<FrontEndComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateFrontEndComponentCommand &request);
    Result<FrontEndComponentDTO> restoreImpl();
    Result<FrontEndComponentDTO> saveOldState();
    Result<FrontEndComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::FrontEndComponent::Commands