// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "contracts_component/commands/create_contracts_component_command.h"
#include "contracts_component/contracts_component_dto.h"
#include "qleany_editor_application_contracts_component_export.h"
#include "repository/interface_contracts_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::ContractsComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Commands;

namespace QleanyEditor::Application::Features::ContractsComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_CONTRACTS_COMPONENT_EXPORT CreateContractsComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateContractsComponentCommandHandler(InterfaceContractsComponentRepository *repository);

    Result<ContractsComponentDTO> handle(QPromise<Result<void>> &progressPromise, const CreateContractsComponentCommand &request);
    Result<ContractsComponentDTO> restore();

Q_SIGNALS:
    void contractsComponentCreated(QleanyEditor::Contracts::DTO::ContractsComponent::ContractsComponentDTO contractsComponentDto);
    void contractsComponentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceContractsComponentRepository *m_repository;
    Result<ContractsComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateContractsComponentCommand &request);
    Result<ContractsComponentDTO> restoreImpl();
    Result<QleanyEditor::Entities::ContractsComponent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::ContractsComponent m_oldOwnerContractsComponent;
    QleanyEditor::Entities::ContractsComponent m_ownerContractsComponentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::ContractsComponent::Commands