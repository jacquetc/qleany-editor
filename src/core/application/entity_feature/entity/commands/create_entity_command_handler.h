// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/commands/create_entity_command.h"
#include "entity/entity_dto.h"
#include "qleany_editor_application_entity_export.h"
#include "repository/interface_entity_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Entity::Commands;

namespace QleanyEditor::Application::Features::Entity::Commands
{
class QLEANY_EDITOR_APPLICATION_ENTITY_EXPORT CreateEntityCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateEntityCommandHandler(InterfaceEntityRepository *repository);

    Result<EntityDTO> handle(QPromise<Result<void>> &progressPromise, const CreateEntityCommand &request);
    Result<EntityDTO> restore();

Q_SIGNALS:
    void entityCreated(QleanyEditor::Contracts::DTO::Entity::EntityDTO entityDto);
    void entityRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceEntityRepository *m_repository;
    Result<EntityDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateEntityCommand &request);
    Result<EntityDTO> restoreImpl();
    Result<QleanyEditor::Entities::Entity> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::Entity> m_oldOwnerEntities;
    QList<QleanyEditor::Entities::Entity> m_ownerEntitiesNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::Entity::Commands