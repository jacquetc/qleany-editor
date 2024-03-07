// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/commands/remove_entity_command.h"
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
class QLEANY_EDITOR_APPLICATION_ENTITY_EXPORT RemoveEntityCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveEntityCommandHandler(InterfaceEntityRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveEntityCommand &request);
    Result<int> restore();

signals:
    // repositories handle remove signals
    // void entityRemoved(int id);

private:
    InterfaceEntityRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveEntityCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::Entity m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Entity::Commands