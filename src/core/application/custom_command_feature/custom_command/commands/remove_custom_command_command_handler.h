// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/commands/remove_custom_command_command.h"
#include "custom_command/custom_command_dto.h"
#include "qleany_editor_application_custom_command_export.h"

#include "repository/interface_custom_command_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomCommand;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomCommand::Commands;

namespace QleanyEditor::Application::Features::CustomCommand::Commands
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_COMMAND_EXPORT RemoveCustomCommandCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveCustomCommandCommandHandler(InterfaceCustomCommandRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveCustomCommandCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void customCommandRemoved(int id);

private:
    InterfaceCustomCommandRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCustomCommandCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::CustomCommand m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomCommand::Commands