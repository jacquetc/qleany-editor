// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_parent/commands/create_entity_parent_command.h"
#include "entity_parent/entity_parent_dto.h"
#include "qleany_editor_application_entity_parent_export.h"
#include "repository/interface_entity_parent_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::EntityParent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityParent::Commands;

namespace QleanyEditor::Application::Features::EntityParent::Commands
{
class QLEANY_EDITOR_APPLICATION_ENTITY_PARENT_EXPORT CreateEntityParentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateEntityParentCommandHandler(InterfaceEntityParentRepository *repository);

    Result<EntityParentDTO> handle(QPromise<Result<void>> &progressPromise, const CreateEntityParentCommand &request);
    Result<EntityParentDTO> restore();

Q_SIGNALS:
    void entityParentCreated(QleanyEditor::Contracts::DTO::EntityParent::EntityParentDTO entityParentDto);
    void entityParentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceEntityParentRepository *m_repository;
    Result<EntityParentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateEntityParentCommand &request);
    Result<EntityParentDTO> restoreImpl();
    Result<QleanyEditor::Entities::EntityParent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::EntityParent m_oldOwnerParent;
    QleanyEditor::Entities::EntityParent m_ownerParentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::EntityParent::Commands