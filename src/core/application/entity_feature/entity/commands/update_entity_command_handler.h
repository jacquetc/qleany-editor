// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/commands/update_entity_command.h"
#include "entity/entity_dto.h"
#include "qleany_editor_application_entity_export.h"

#include "repository/interface_entity_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Entity;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Entity::Commands;

namespace QleanyEditor::Application::Features::Entity::Commands
{
class QLEANY_EDITOR_APPLICATION_ENTITY_EXPORT UpdateEntityCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateEntityCommandHandler(InterfaceEntityRepository *repository);
    Result<EntityDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateEntityCommand &request);
    Result<EntityDTO> restore();

signals:
    void entityUpdated(QleanyEditor::Contracts::DTO::Entity::EntityDTO entityDto);
    void entityDetailsUpdated(int id);

private:
    InterfaceEntityRepository *m_repository;
    Result<EntityDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateEntityCommand &request);
    Result<EntityDTO> restoreImpl();
    Result<EntityDTO> saveOldState();
    Result<EntityDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Entity::Commands