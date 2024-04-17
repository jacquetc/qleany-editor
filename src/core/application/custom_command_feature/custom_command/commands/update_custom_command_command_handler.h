// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/commands/update_custom_command_command.h"
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
class QLEANY_EDITOR_APPLICATION_CUSTOM_COMMAND_EXPORT UpdateCustomCommandCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateCustomCommandCommandHandler(InterfaceCustomCommandRepository *repository);
    Result<CustomCommandDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateCustomCommandCommand &request);
    Result<CustomCommandDTO> restore();

Q_SIGNALS:
    void customCommandUpdated(QleanyEditor::Contracts::DTO::CustomCommand::CustomCommandDTO customCommandDto);
    void customCommandDetailsUpdated(int id);

private:
    InterfaceCustomCommandRepository *m_repository;
    Result<CustomCommandDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCustomCommandCommand &request);
    Result<CustomCommandDTO> restoreImpl();
    Result<CustomCommandDTO> saveOldState();
    Result<CustomCommandDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomCommand::Commands