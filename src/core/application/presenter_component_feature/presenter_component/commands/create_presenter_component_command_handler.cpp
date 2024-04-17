// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_presenter_component_command_handler.h"
#include "presenter_component/validators/create_presenter_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "project.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::PresenterComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Validators;
using namespace QleanyEditor::Application::Features::PresenterComponent::Commands;

CreatePresenterComponentCommandHandler::CreatePresenterComponentCommandHandler(InterfacePresenterComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterComponentDTO> CreatePresenterComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                             const CreatePresenterComponentCommand &request)
{
    Result<PresenterComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<PresenterComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreatePresenterComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterComponentDTO> CreatePresenterComponentCommandHandler::restore()
{
    Result<PresenterComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<PresenterComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreatePresenterComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<PresenterComponentDTO> CreatePresenterComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                 const CreatePresenterComponentCommand &request)
{
    qDebug() << "CreatePresenterComponentCommandHandler::handleImpl called";
    QleanyEditor::Entities::PresenterComponent presenterComponent;
    CreatePresenterComponentDTO createDTO = request.req;

    QleanyEditor::Entities::PresenterComponent ownerEntityPresenterComponent;

    // Get the entities from owner
    int ownerId = createDTO.projectId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create PresenterComponent command using the validator
        auto validator = CreatePresenterComponentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(PresenterComponentDTO, validatorResult);

        // Map the create PresenterComponent command to a domain PresenterComponent object and
        // generate a UUID
        presenterComponent = Qleany::Tools::AutoMapper::AutoMapper::map<CreatePresenterComponentDTO, QleanyEditor::Entities::PresenterComponent>(createDTO);

        // allow for forcing the uuid
        if (presenterComponent.uuid().isNull()) {
            presenterComponent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        presenterComponent.setCreationDate(QDateTime::currentDateTime());
        presenterComponent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        presenterComponent = m_newEntity.value();
    }

    // Add the presenterComponent to the repository

    m_repository->beginChanges();
    auto presenterComponentResult = m_repository->add(std::move(presenterComponent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(PresenterComponentDTO, presenterComponentResult, m_repository->cancelChanges();)

    // Get the newly created PresenterComponent entity
    presenterComponent = presenterComponentResult.value();
    // Save the newly created entity
    m_newEntity = presenterComponentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerPresenterComponentResult = m_repository->getEntityInRelationOf(Project::schema, ownerId, "presenterComponent"_L1);
        if (Q_UNLIKELY(originalOwnerPresenterComponentResult.hasError())) {
            return Result<PresenterComponentDTO>(originalOwnerPresenterComponentResult.error());
        }
        auto originalOwnerPresenterComponent = originalOwnerPresenterComponentResult.value();

        // save
        m_oldOwnerPresenterComponent = originalOwnerPresenterComponent;
        originalOwnerPresenterComponent = presenterComponent;

        m_ownerPresenterComponentNewState = originalOwnerPresenterComponent;
        ownerEntityPresenterComponent = originalOwnerPresenterComponent;
    } else {
        ownerEntityPresenterComponent = m_ownerPresenterComponentNewState;
        position = m_position;
    }

    // Add the presenterComponent to the owner entity
    Result<QleanyEditor::Entities::PresenterComponent> updateResult =
        m_repository->updateEntityInRelationOf(Project::schema, ownerId, "presenterComponent"_L1, ownerEntityPresenterComponent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(PresenterComponentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = presenterComponentResult;

    auto presenterComponentDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterComponent, PresenterComponentDTO>(presenterComponentResult.value());
    Q_EMIT presenterComponentCreated(presenterComponentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(presenterComponent.id(), ownerId, position);

    qDebug() << "PresenterComponent added:" << presenterComponentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created PresenterComponent as a Result object
    return Result<PresenterComponentDTO>(presenterComponentDTO);
}

Result<PresenterComponentDTO> CreatePresenterComponentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(PresenterComponentDTO, deleteResult)

    Q_EMIT presenterComponentRemoved(deleteResult.value());

    qDebug() << "PresenterComponent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<PresenterComponentDTO>(PresenterComponentDTO());
}

bool CreatePresenterComponentCommandHandler::s_mappingRegistered = false;

void CreatePresenterComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterComponent,
                                                           Contracts::DTO::PresenterComponent::PresenterComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterComponent::CreatePresenterComponentDTO,
                                                           QleanyEditor::Entities::PresenterComponent>();
}