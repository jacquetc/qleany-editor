// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_field/commands/remove_entity_field_command.h"
#include "entity_field/entity_field_dto.h"
#include "qleany_editor_application_entity_field_export.h"

#include "repository/interface_entity_field_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityField::Commands;

namespace QleanyEditor::Application::Features::EntityField::Commands
{
class QLEANY_EDITOR_APPLICATION_ENTITY_FIELD_EXPORT RemoveEntityFieldCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveEntityFieldCommandHandler(InterfaceEntityFieldRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveEntityFieldCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void entityFieldRemoved(int id);

private:
    InterfaceEntityFieldRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveEntityFieldCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::EntityField m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::EntityField::Commands