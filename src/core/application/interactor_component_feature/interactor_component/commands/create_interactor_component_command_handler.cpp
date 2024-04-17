// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_interactor_component_command_handler.h"
#include "interactor_component/validators/create_interactor_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "project.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::InteractorComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Validators;
using namespace QleanyEditor::Application::Features::InteractorComponent::Commands;

CreateInteractorComponentCommandHandler::CreateInteractorComponentCommandHandler(InterfaceInteractorComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<InteractorComponentDTO> CreateInteractorComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                               const CreateInteractorComponentCommand &request)
{
    Result<InteractorComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<InteractorComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateInteractorComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<InteractorComponentDTO> CreateInteractorComponentCommandHandler::restore()
{
    Result<InteractorComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<InteractorComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateInteractorComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<InteractorComponentDTO> CreateInteractorComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                   const CreateInteractorComponentCommand &request)
{
    qDebug() << "CreateInteractorComponentCommandHandler::handleImpl called";
    QleanyEditor::Entities::InteractorComponent interactorComponent;
    CreateInteractorComponentDTO createDTO = request.req;

    QleanyEditor::Entities::InteractorComponent ownerEntityInteractorComponent;

    // Get the entities from owner
    int ownerId = createDTO.projectId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create InteractorComponent command using the validator
        auto validator = CreateInteractorComponentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(InteractorComponentDTO, validatorResult);

        // Map the create InteractorComponent command to a domain InteractorComponent object and
        // generate a UUID
        interactorComponent = Qleany::Tools::AutoMapper::AutoMapper::map<CreateInteractorComponentDTO, QleanyEditor::Entities::InteractorComponent>(createDTO);

        // allow for forcing the uuid
        if (interactorComponent.uuid().isNull()) {
            interactorComponent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        interactorComponent.setCreationDate(QDateTime::currentDateTime());
        interactorComponent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        interactorComponent = m_newEntity.value();
    }

    // Add the interactorComponent to the repository

    m_repository->beginChanges();
    auto interactorComponentResult = m_repository->add(std::move(interactorComponent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(InteractorComponentDTO, interactorComponentResult, m_repository->cancelChanges();)

    // Get the newly created InteractorComponent entity
    interactorComponent = interactorComponentResult.value();
    // Save the newly created entity
    m_newEntity = interactorComponentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerInteractorComponentResult = m_repository->getEntityInRelationOf(Project::schema, ownerId, "interactorComponent"_L1);
        if (Q_UNLIKELY(originalOwnerInteractorComponentResult.hasError())) {
            return Result<InteractorComponentDTO>(originalOwnerInteractorComponentResult.error());
        }
        auto originalOwnerInteractorComponent = originalOwnerInteractorComponentResult.value();

        // save
        m_oldOwnerInteractorComponent = originalOwnerInteractorComponent;
        originalOwnerInteractorComponent = interactorComponent;

        m_ownerInteractorComponentNewState = originalOwnerInteractorComponent;
        ownerEntityInteractorComponent = originalOwnerInteractorComponent;
    } else {
        ownerEntityInteractorComponent = m_ownerInteractorComponentNewState;
        position = m_position;
    }

    // Add the interactorComponent to the owner entity
    Result<QleanyEditor::Entities::InteractorComponent> updateResult =
        m_repository->updateEntityInRelationOf(Project::schema, ownerId, "interactorComponent"_L1, ownerEntityInteractorComponent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(InteractorComponentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = interactorComponentResult;

    auto interactorComponentDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::InteractorComponent, InteractorComponentDTO>(interactorComponentResult.value());
    Q_EMIT interactorComponentCreated(interactorComponentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(interactorComponent.id(), ownerId, position);

    qDebug() << "InteractorComponent added:" << interactorComponentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created InteractorComponent as a Result object
    return Result<InteractorComponentDTO>(interactorComponentDTO);
}

Result<InteractorComponentDTO> CreateInteractorComponentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(InteractorComponentDTO, deleteResult)

    Q_EMIT interactorComponentRemoved(deleteResult.value());

    qDebug() << "InteractorComponent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<InteractorComponentDTO>(InteractorComponentDTO());
}

bool CreateInteractorComponentCommandHandler::s_mappingRegistered = false;

void CreateInteractorComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::InteractorComponent,
                                                           Contracts::DTO::InteractorComponent::InteractorComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::InteractorComponent::CreateInteractorComponentDTO,
                                                           QleanyEditor::Entities::InteractorComponent>();
}