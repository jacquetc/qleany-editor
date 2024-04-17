// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_contracts_component_command_handler.h"
#include "contracts_component/validators/update_contracts_component_command_validator.h"
#include "repository/interface_contracts_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ContractsComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Validators;
using namespace QleanyEditor::Application::Features::ContractsComponent::Commands;

UpdateContractsComponentCommandHandler::UpdateContractsComponentCommandHandler(InterfaceContractsComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ContractsComponentDTO> UpdateContractsComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                             const UpdateContractsComponentCommand &request)
{
    Result<ContractsComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<ContractsComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateContractsComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ContractsComponentDTO> UpdateContractsComponentCommandHandler::restore()
{
    Result<ContractsComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<ContractsComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateContractsComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<ContractsComponentDTO> UpdateContractsComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                 const UpdateContractsComponentCommand &request)
{
    qDebug() << "UpdateContractsComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateContractsComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(ContractsComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::ContractsComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(ContractsComponentDTO, currentResult)

        // map
        m_undoState = Result<ContractsComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ContractsComponent, ContractsComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<ContractsComponentDTO, UpdateContractsComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto contractsComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateContractsComponentDTO, QleanyEditor::Entities::ContractsComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        contractsComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto contractsComponentResult = m_repository->update(std::move(contractsComponent));

    if (contractsComponentResult.hasError()) {
        return Result<ContractsComponentDTO>(contractsComponentResult.error());
    }

    // map
    auto contractsComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ContractsComponent, ContractsComponentDTO>(contractsComponentResult.value());

    Q_EMIT contractsComponentUpdated(contractsComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT contractsComponentDetailsUpdated(contractsComponentDto.id());
    }

    qDebug() << "UpdateContractsComponentCommandHandler::handleImpl done";

    return Result<ContractsComponentDTO>(contractsComponentDto);
}

Result<ContractsComponentDTO> UpdateContractsComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateContractsComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto contractsComponent =
        Qleany::Tools::AutoMapper::AutoMapper::map<ContractsComponentDTO, QleanyEditor::Entities::ContractsComponent>(m_undoState.value());

    // do
    auto contractsComponentResult = m_repository->update(std::move(contractsComponent));

    QLN_RETURN_IF_ERROR(ContractsComponentDTO, contractsComponentResult)

    // map
    auto contractsComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ContractsComponent, ContractsComponentDTO>(contractsComponentResult.value());

    Q_EMIT contractsComponentUpdated(contractsComponentDto);

    qDebug() << "UpdateContractsComponentCommandHandler::restoreImpl done";

    return Result<ContractsComponentDTO>(contractsComponentDto);
}

bool UpdateContractsComponentCommandHandler::s_mappingRegistered = false;

void UpdateContractsComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ContractsComponent,
                                                           Contracts::DTO::ContractsComponent::ContractsComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ContractsComponent::UpdateContractsComponentDTO,
                                                           Contracts::DTO::ContractsComponent::ContractsComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ContractsComponent::UpdateContractsComponentDTO,
                                                           QleanyEditor::Entities::ContractsComponent>();
}