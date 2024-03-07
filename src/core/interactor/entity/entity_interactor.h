// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/create_entity_dto.h"
#include "entity/entity_dto.h"
#include "entity/update_entity_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::Entity;

namespace QleanyEditor::Interactor::Entity
{

class QLEANY_EDITOR_INTERACTOR_EXPORT EntityInteractor : public QObject
{
    Q_OBJECT
public:
    explicit EntityInteractor(InterfaceRepositoryProvider *repositoryProvider,
                              ThreadedUndoRedoSystem *undo_redo_system,
                              QSharedPointer<EventDispatcher> eventDispatcher);

    static EntityInteractor *instance();

    Q_INVOKABLE QCoro::Task<EntityDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::Entity::CreateEntityDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::Entity::UpdateEntityDTO getUpdateDTO();

public slots:

    QCoro::Task<EntityDTO> create(const CreateEntityDTO &dto);

    QCoro::Task<EntityDTO> update(const UpdateEntityDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<EntityInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    EntityInteractor() = delete;
    EntityInteractor(const EntityInteractor &) = delete;
    EntityInteractor &operator=(const EntityInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::Entity