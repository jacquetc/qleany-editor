// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "contracts_component/commands/update_contracts_component_command.h"
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
class QLEANY_EDITOR_APPLICATION_CONTRACTS_COMPONENT_EXPORT UpdateContractsComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateContractsComponentCommandHandler(InterfaceContractsComponentRepository *repository);
    Result<ContractsComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateContractsComponentCommand &request);
    Result<ContractsComponentDTO> restore();

Q_SIGNALS:
    void contractsComponentUpdated(QleanyEditor::Contracts::DTO::ContractsComponent::ContractsComponentDTO contractsComponentDto);
    void contractsComponentDetailsUpdated(int id);

private:
    InterfaceContractsComponentRepository *m_repository;
    Result<ContractsComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateContractsComponentCommand &request);
    Result<ContractsComponentDTO> restoreImpl();
    Result<ContractsComponentDTO> saveOldState();
    Result<ContractsComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ContractsComponent::Commands