// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_component/entity_component_dto.h"
#include "entity_component/entity_component_with_details_dto.h"
#include "entity_component/update_entity_component_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::EntityComponent;

namespace QleanyEditor::Interactor::EntityComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT EntityComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit EntityComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                       ThreadedUndoRedoSystem *undo_redo_system,
                                       QSharedPointer<EventDispatcher> eventDispatcher);

    static EntityComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<EntityComponentDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<EntityComponentWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::EntityComponent::UpdateEntityComponentDTO getUpdateDTO();

public slots:

    QCoro::Task<EntityComponentDTO> update(const UpdateEntityComponentDTO &dto);

private:
    static QPointer<EntityComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    EntityComponentInteractor() = delete;
    EntityComponentInteractor(const EntityComponentInteractor &) = delete;
    EntityComponentInteractor &operator=(const EntityComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::EntityComponent