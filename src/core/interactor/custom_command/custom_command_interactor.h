// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/create_custom_command_dto.h"
#include "custom_command/custom_command_dto.h"
#include "custom_command/custom_command_with_details_dto.h"
#include "custom_command/update_custom_command_dto.h"
#include "event_dispatcher.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::CustomCommand;

namespace QleanyEditor::Interactor::CustomCommand
{

class QLEANY_EDITOR_INTERACTOR_EXPORT CustomCommandInteractor : public QObject
{
    Q_OBJECT
public:
    explicit CustomCommandInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                     ThreadedUndoRedoSystem *undo_redo_system,
                                     QSharedPointer<EventDispatcher> eventDispatcher);

    static CustomCommandInteractor *instance();

    Q_INVOKABLE QCoro::Task<CustomCommandDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<CustomCommandWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::CustomCommand::CreateCustomCommandDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::CustomCommand::UpdateCustomCommandDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<CustomCommandDTO> create(const CreateCustomCommandDTO &dto);

    QCoro::Task<CustomCommandDTO> update(const UpdateCustomCommandDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<CustomCommandInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    CustomCommandInteractor() = delete;
    CustomCommandInteractor(const CustomCommandInteractor &) = delete;
    CustomCommandInteractor &operator=(const CustomCommandInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::CustomCommand