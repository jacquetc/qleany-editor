// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field/commands/create_entity_field_command.h"
#include "entity_field/entity_field_dto.h"
#include "qleany_editor_application_entity_field_export.h"
#include "repository/interface_entity_field_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::EntityField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityField::Commands;

namespace QleanyEditor::Application::Features::EntityField::Commands
{
class QLEANY_EDITOR_APPLICATION_ENTITY_FIELD_EXPORT CreateEntityFieldCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateEntityFieldCommandHandler(InterfaceEntityFieldRepository *repository);

    Result<EntityFieldDTO> handle(QPromise<Result<void>> &progressPromise, const CreateEntityFieldCommand &request);
    Result<EntityFieldDTO> restore();

Q_SIGNALS:
    void entityFieldCreated(QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO entityFieldDto);
    void entityFieldRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceEntityFieldRepository *m_repository;
    Result<EntityFieldDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateEntityFieldCommand &request);
    Result<EntityFieldDTO> restoreImpl();
    Result<QleanyEditor::Entities::EntityField> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::EntityField> m_oldOwnerFields;
    QList<QleanyEditor::Entities::EntityField> m_ownerFieldsNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::EntityField::Commands