// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity_parent/commands/remove_entity_parent_command.h"
#include "entity_parent/entity_parent_dto.h"
#include "qleany_editor_application_entity_parent_export.h"

#include "repository/interface_entity_parent_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::EntityParent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::EntityParent::Commands;

namespace QleanyEditor::Application::Features::EntityParent::Commands
{
class QLEANY_EDITOR_APPLICATION_ENTITY_PARENT_EXPORT RemoveEntityParentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveEntityParentCommandHandler(InterfaceEntityParentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveEntityParentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void entityParentRemoved(int id);

private:
    InterfaceEntityParentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveEntityParentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::EntityParent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::EntityParent::Commands