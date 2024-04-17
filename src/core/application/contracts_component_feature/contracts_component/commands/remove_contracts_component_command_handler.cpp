// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_contracts_component_command_handler.h"
#include "contracts_component/validators/remove_contracts_component_command_validator.h"
#include "repository/interface_contracts_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ContractsComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Commands;
using namespace QleanyEditor::Application::Features::ContractsComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Validators;

RemoveContractsComponentCommandHandler::RemoveContractsComponentCommandHandler(InterfaceContractsComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveContractsComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveContractsComponentCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveContractsComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveContractsComponentCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveContractsComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveContractsComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveContractsComponentCommand &request)
{
    int contractsComponentId = request.id;

    // Validate the command using the validator
    auto validator = RemoveContractsComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(contractsComponentId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::ContractsComponent> contractsComponentResult = m_repository->get(contractsComponentId);

    QLN_RETURN_IF_ERROR(int, contractsComponentResult)

    // save old entity
    m_oldState = contractsComponentResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << contractsComponentId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT contractsComponentRemoved(deleteResult.value());

    qDebug() << "ContractsComponent removed:" << contractsComponentId;

    return Result<int>(contractsComponentId);
}

Result<int> RemoveContractsComponentCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveContractsComponentCommandHandler::s_mappingRegistered = false;

void RemoveContractsComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ContractsComponent,
                                                           Contracts::DTO::ContractsComponent::ContractsComponentDTO>(true, true);
}