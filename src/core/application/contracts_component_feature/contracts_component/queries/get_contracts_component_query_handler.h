// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "contracts_component/contracts_component_dto.h"
#include "contracts_component/queries/get_contracts_component_query.h"
#include "qleany_editor_application_contracts_component_export.h"

#include "repository/interface_contracts_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ContractsComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Queries;

namespace QleanyEditor::Application::Features::ContractsComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_CONTRACTS_COMPONENT_EXPORT GetContractsComponentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetContractsComponentQueryHandler(InterfaceContractsComponentRepository *repository);
    Result<ContractsComponentDTO> handle(QPromise<Result<void>> &progressPromise, const GetContractsComponentQuery &query);

private:
    InterfaceContractsComponentRepository *m_repository;
    Result<ContractsComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetContractsComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ContractsComponent::Queries