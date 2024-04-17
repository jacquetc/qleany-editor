// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component/commands/update_presenter_component_command.h"
#include "presenter_component/presenter_component_dto.h"
#include "qleany_editor_application_presenter_component_export.h"

#include "repository/interface_presenter_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Commands;

namespace QleanyEditor::Application::Features::PresenterComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_COMPONENT_EXPORT UpdatePresenterComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdatePresenterComponentCommandHandler(InterfacePresenterComponentRepository *repository);
    Result<PresenterComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdatePresenterComponentCommand &request);
    Result<PresenterComponentDTO> restore();

Q_SIGNALS:
    void presenterComponentUpdated(QleanyEditor::Contracts::DTO::PresenterComponent::PresenterComponentDTO presenterComponentDto);
    void presenterComponentDetailsUpdated(int id);

private:
    InterfacePresenterComponentRepository *m_repository;
    Result<PresenterComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdatePresenterComponentCommand &request);
    Result<PresenterComponentDTO> restoreImpl();
    Result<PresenterComponentDTO> saveOldState();
    Result<PresenterComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterComponent::Commands