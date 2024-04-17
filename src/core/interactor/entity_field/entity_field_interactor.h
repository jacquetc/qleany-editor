// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field/create_entity_field_dto.h"
#include "entity_field/entity_field_dto.h"
#include "entity_field/update_entity_field_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::EntityField;

namespace QleanyEditor::Interactor::EntityField
{

class QLEANY_EDITOR_INTERACTOR_EXPORT EntityFieldInteractor : public QObject
{
    Q_OBJECT
public:
    explicit EntityFieldInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                   ThreadedUndoRedoSystem *undo_redo_system,
                                   QSharedPointer<EventDispatcher> eventDispatcher);

    static EntityFieldInteractor *instance();

    Q_INVOKABLE QCoro::Task<EntityFieldDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::EntityField::CreateEntityFieldDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::EntityField::UpdateEntityFieldDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<EntityFieldDTO> create(const CreateEntityFieldDTO &dto);

    QCoro::Task<EntityFieldDTO> update(const UpdateEntityFieldDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<EntityFieldInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    EntityFieldInteractor() = delete;
    EntityFieldInteractor(const EntityFieldInteractor &) = delete;
    EntityFieldInteractor &operator=(const EntityFieldInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::EntityField