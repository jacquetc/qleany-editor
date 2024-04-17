// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/application_component_dto.h"
#include "application_component/commands/remove_application_component_command.h"
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
class QLEANY_EDITOR_APPLICATION_APPLICATION_COMPONENT_EXPORT RemoveApplicationComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveApplicationComponentCommandHandler(InterfaceApplicationComponentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveApplicationComponentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void applicationComponentRemoved(int id);

private:
    InterfaceApplicationComponentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveApplicationComponentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::ApplicationComponent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ApplicationComponent::Commands