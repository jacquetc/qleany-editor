// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_contracts_component_command_handler.h"
#include "contracts_component/validators/create_contracts_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "project.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::ContractsComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ContractsComponent::Validators;
using namespace QleanyEditor::Application::Features::ContractsComponent::Commands;

CreateContractsComponentCommandHandler::CreateContractsComponentCommandHandler(InterfaceContractsComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ContractsComponentDTO> CreateContractsComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                             const CreateContractsComponentCommand &request)
{
    Result<ContractsComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<ContractsComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateContractsComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ContractsComponentDTO> CreateContractsComponentCommandHandler::restore()
{
    Result<ContractsComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<ContractsComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateContractsComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<ContractsComponentDTO> CreateContractsComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                 const CreateContractsComponentCommand &request)
{
    qDebug() << "CreateContractsComponentCommandHandler::handleImpl called";
    QleanyEditor::Entities::ContractsComponent contractsComponent;
    CreateContractsComponentDTO createDTO = request.req;

    QleanyEditor::Entities::ContractsComponent ownerEntityContractsComponent;

    // Get the entities from owner
    int ownerId = createDTO.projectId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create ContractsComponent command using the validator
        auto validator = CreateContractsComponentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(ContractsComponentDTO, validatorResult);

        // Map the create ContractsComponent command to a domain ContractsComponent object and
        // generate a UUID
        contractsComponent = Qleany::Tools::AutoMapper::AutoMapper::map<CreateContractsComponentDTO, QleanyEditor::Entities::ContractsComponent>(createDTO);

        // allow for forcing the uuid
        if (contractsComponent.uuid().isNull()) {
            contractsComponent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        contractsComponent.setCreationDate(QDateTime::currentDateTime());
        contractsComponent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        contractsComponent = m_newEntity.value();
    }

    // Add the contractsComponent to the repository

    m_repository->beginChanges();
    auto contractsComponentResult = m_repository->add(std::move(contractsComponent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(ContractsComponentDTO, contractsComponentResult, m_repository->cancelChanges();)

    // Get the newly created ContractsComponent entity
    contractsComponent = contractsComponentResult.value();
    // Save the newly created entity
    m_newEntity = contractsComponentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerContractsComponentResult = m_repository->getEntityInRelationOf(Project::schema, ownerId, "contractsComponent"_L1);
        if (Q_UNLIKELY(originalOwnerContractsComponentResult.hasError())) {
            return Result<ContractsComponentDTO>(originalOwnerContractsComponentResult.error());
        }
        auto originalOwnerContractsComponent = originalOwnerContractsComponentResult.value();

        // save
        m_oldOwnerContractsComponent = originalOwnerContractsComponent;
        originalOwnerContractsComponent = contractsComponent;

        m_ownerContractsComponentNewState = originalOwnerContractsComponent;
        ownerEntityContractsComponent = originalOwnerContractsComponent;
    } else {
        ownerEntityContractsComponent = m_ownerContractsComponentNewState;
        position = m_position;
    }

    // Add the contractsComponent to the owner entity
    Result<QleanyEditor::Entities::ContractsComponent> updateResult =
        m_repository->updateEntityInRelationOf(Project::schema, ownerId, "contractsComponent"_L1, ownerEntityContractsComponent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(ContractsComponentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = contractsComponentResult;

    auto contractsComponentDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ContractsComponent, ContractsComponentDTO>(contractsComponentResult.value());
    Q_EMIT contractsComponentCreated(contractsComponentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(contractsComponent.id(), ownerId, position);

    qDebug() << "ContractsComponent added:" << contractsComponentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created ContractsComponent as a Result object
    return Result<ContractsComponentDTO>(contractsComponentDTO);
}

Result<ContractsComponentDTO> CreateContractsComponentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(ContractsComponentDTO, deleteResult)

    Q_EMIT contractsComponentRemoved(deleteResult.value());

    qDebug() << "ContractsComponent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<ContractsComponentDTO>(ContractsComponentDTO());
}

bool CreateContractsComponentCommandHandler::s_mappingRegistered = false;

void CreateContractsComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ContractsComponent,
                                                           Contracts::DTO::ContractsComponent::ContractsComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ContractsComponent::CreateContractsComponentDTO,
                                                           QleanyEditor::Entities::ContractsComponent>();
}