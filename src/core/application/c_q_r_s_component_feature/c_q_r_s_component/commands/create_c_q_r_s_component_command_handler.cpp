// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_c_q_r_s_component_command_handler.h"
#include "c_q_r_s_component/validators/create_c_q_r_s_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "project.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CQRSComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Validators;
using namespace QleanyEditor::Application::Features::CQRSComponent::Commands;

CreateCQRSComponentCommandHandler::CreateCQRSComponentCommandHandler(InterfaceCQRSComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CQRSComponentDTO> CreateCQRSComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateCQRSComponentCommand &request)
{
    Result<CQRSComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CQRSComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCQRSComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CQRSComponentDTO> CreateCQRSComponentCommandHandler::restore()
{
    Result<CQRSComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CQRSComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCQRSComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<CQRSComponentDTO> CreateCQRSComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateCQRSComponentCommand &request)
{
    qDebug() << "CreateCQRSComponentCommandHandler::handleImpl called";
    QleanyEditor::Entities::CQRSComponent cQRSComponent;
    CreateCQRSComponentDTO createDTO = request.req;

    QleanyEditor::Entities::CQRSComponent ownerEntityCqrsComponent;

    // Get the entities from owner
    int ownerId = createDTO.projectId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create CQRSComponent command using the validator
        auto validator = CreateCQRSComponentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(CQRSComponentDTO, validatorResult);

        // Map the create CQRSComponent command to a domain CQRSComponent object and
        // generate a UUID
        cQRSComponent = Qleany::Tools::AutoMapper::AutoMapper::map<CreateCQRSComponentDTO, QleanyEditor::Entities::CQRSComponent>(createDTO);

        // allow for forcing the uuid
        if (cQRSComponent.uuid().isNull()) {
            cQRSComponent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        cQRSComponent.setCreationDate(QDateTime::currentDateTime());
        cQRSComponent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        cQRSComponent = m_newEntity.value();
    }

    // Add the cQRSComponent to the repository

    m_repository->beginChanges();
    auto cQRSComponentResult = m_repository->add(std::move(cQRSComponent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(CQRSComponentDTO, cQRSComponentResult, m_repository->cancelChanges();)

    // Get the newly created CQRSComponent entity
    cQRSComponent = cQRSComponentResult.value();
    // Save the newly created entity
    m_newEntity = cQRSComponentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerCqrsComponentResult = m_repository->getEntityInRelationOf(Project::schema, ownerId, "cqrsComponent"_L1);
        if (Q_UNLIKELY(originalOwnerCqrsComponentResult.hasError())) {
            return Result<CQRSComponentDTO>(originalOwnerCqrsComponentResult.error());
        }
        auto originalOwnerCqrsComponent = originalOwnerCqrsComponentResult.value();

        // save
        m_oldOwnerCqrsComponent = originalOwnerCqrsComponent;
        originalOwnerCqrsComponent = cQRSComponent;

        m_ownerCqrsComponentNewState = originalOwnerCqrsComponent;
        ownerEntityCqrsComponent = originalOwnerCqrsComponent;
    } else {
        ownerEntityCqrsComponent = m_ownerCqrsComponentNewState;
        position = m_position;
    }

    // Add the cQRSComponent to the owner entity
    Result<QleanyEditor::Entities::CQRSComponent> updateResult =
        m_repository->updateEntityInRelationOf(Project::schema, ownerId, "cqrsComponent"_L1, ownerEntityCqrsComponent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(CQRSComponentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = cQRSComponentResult;

    auto cQRSComponentDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CQRSComponent, CQRSComponentDTO>(cQRSComponentResult.value());
    Q_EMIT cQRSComponentCreated(cQRSComponentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(cQRSComponent.id(), ownerId, position);

    qDebug() << "CQRSComponent added:" << cQRSComponentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created CQRSComponent as a Result object
    return Result<CQRSComponentDTO>(cQRSComponentDTO);
}

Result<CQRSComponentDTO> CreateCQRSComponentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(CQRSComponentDTO, deleteResult)

    Q_EMIT cQRSComponentRemoved(deleteResult.value());

    qDebug() << "CQRSComponent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<CQRSComponentDTO>(CQRSComponentDTO());
}

bool CreateCQRSComponentCommandHandler::s_mappingRegistered = false;

void CreateCQRSComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CQRSComponent, Contracts::DTO::CQRSComponent::CQRSComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CQRSComponent::CreateCQRSComponentDTO, QleanyEditor::Entities::CQRSComponent>();
}