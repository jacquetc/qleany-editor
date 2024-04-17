// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_parent/create_entity_parent_dto.h"
#include "entity_parent/entity_parent_dto.h"
#include "entity_parent/update_entity_parent_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::EntityParent;

namespace QleanyEditor::Interactor::EntityParent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT EntityParentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit EntityParentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                    ThreadedUndoRedoSystem *undo_redo_system,
                                    QSharedPointer<EventDispatcher> eventDispatcher);

    static EntityParentInteractor *instance();

    Q_INVOKABLE QCoro::Task<EntityParentDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::EntityParent::CreateEntityParentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::EntityParent::UpdateEntityParentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<EntityParentDTO> create(const CreateEntityParentDTO &dto);

    QCoro::Task<EntityParentDTO> update(const UpdateEntityParentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<EntityParentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    EntityParentInteractor() = delete;
    EntityParentInteractor(const EntityParentInteractor &) = delete;
    EntityParentInteractor &operator=(const EntityParentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::EntityParent