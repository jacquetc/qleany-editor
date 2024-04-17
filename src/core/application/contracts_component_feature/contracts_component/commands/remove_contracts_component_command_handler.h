// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "contracts_component/commands/remove_contracts_component_command.h"
#include "contracts_component/contracts_component_dto.h"
#include "qleany_editor_application_contracts_component_export.h"

#include "repository/interface_contracts_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ContractsComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Commands;

namespace QleanyEditor::Application::Features::ContractsComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_CONTRACTS_COMPONENT_EXPORT RemoveContractsComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveContractsComponentCommandHandler(InterfaceContractsComponentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveContractsComponentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void contractsComponentRemoved(int id);

private:
    InterfaceContractsComponentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveContractsComponentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::ContractsComponent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ContractsComponent::Commands