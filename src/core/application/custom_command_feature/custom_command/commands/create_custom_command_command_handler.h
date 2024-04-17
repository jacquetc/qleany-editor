// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/commands/create_custom_command_command.h"
#include "custom_command/custom_command_dto.h"
#include "qleany_editor_application_custom_command_export.h"
#include "repository/interface_custom_command_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CustomCommand;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomCommand::Commands;

namespace QleanyEditor::Application::Features::CustomCommand::Commands
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_COMMAND_EXPORT CreateCustomCommandCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateCustomCommandCommandHandler(InterfaceCustomCommandRepository *repository);

    Result<CustomCommandDTO> handle(QPromise<Result<void>> &progressPromise, const CreateCustomCommandCommand &request);
    Result<CustomCommandDTO> restore();

Q_SIGNALS:
    void customCommandCreated(QleanyEditor::Contracts::DTO::CustomCommand::CustomCommandDTO customCommandDto);
    void customCommandRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceCustomCommandRepository *m_repository;
    Result<CustomCommandDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateCustomCommandCommand &request);
    Result<CustomCommandDTO> restoreImpl();
    Result<QleanyEditor::Entities::CustomCommand> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::CustomCommand> m_oldOwnerCustomCommands;
    QList<QleanyEditor::Entities::CustomCommand> m_ownerCustomCommandsNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::CustomCommand::Commands