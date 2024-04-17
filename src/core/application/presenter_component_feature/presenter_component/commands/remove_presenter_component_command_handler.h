// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component/commands/remove_presenter_component_command.h"
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
class QLEANY_EDITOR_APPLICATION_PRESENTER_COMPONENT_EXPORT RemovePresenterComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemovePresenterComponentCommandHandler(InterfacePresenterComponentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemovePresenterComponentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void presenterComponentRemoved(int id);

private:
    InterfacePresenterComponentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemovePresenterComponentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::PresenterComponent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterComponent::Commands