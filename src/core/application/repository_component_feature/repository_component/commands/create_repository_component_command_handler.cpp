// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_repository_component_command_handler.h"
#include "repository_component/validators/create_repository_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "project.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Validators;
using namespace QleanyEditor::Application::Features::RepositoryComponent::Commands;

CreateRepositoryComponentCommandHandler::CreateRepositoryComponentCommandHandler(InterfaceRepositoryComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RepositoryComponentDTO> CreateRepositoryComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                               const CreateRepositoryComponentCommand &request)
{
    Result<RepositoryComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<RepositoryComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateRepositoryComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RepositoryComponentDTO> CreateRepositoryComponentCommandHandler::restore()
{
    Result<RepositoryComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<RepositoryComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateRepositoryComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<RepositoryComponentDTO> CreateRepositoryComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                   const CreateRepositoryComponentCommand &request)
{
    qDebug() << "CreateRepositoryComponentCommandHandler::handleImpl called";
    QleanyEditor::Entities::RepositoryComponent repositoryComponent;
    CreateRepositoryComponentDTO createDTO = request.req;

    QleanyEditor::Entities::RepositoryComponent ownerEntityRepositoryComponent;

    // Get the entities from owner
    int ownerId = createDTO.projectId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create RepositoryComponent command using the validator
        auto validator = CreateRepositoryComponentCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(RepositoryComponentDTO, validatorResult);

        // Map the create RepositoryComponent command to a domain RepositoryComponent object and
        // generate a UUID
        repositoryComponent = Qleany::Tools::AutoMapper::AutoMapper::map<CreateRepositoryComponentDTO, QleanyEditor::Entities::RepositoryComponent>(createDTO);

        // allow for forcing the uuid
        if (repositoryComponent.uuid().isNull()) {
            repositoryComponent.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        repositoryComponent.setCreationDate(QDateTime::currentDateTime());
        repositoryComponent.setUpdateDate(QDateTime::currentDateTime());

    } else {
        repositoryComponent = m_newEntity.value();
    }

    // Add the repositoryComponent to the repository

    m_repository->beginChanges();
    auto repositoryComponentResult = m_repository->add(std::move(repositoryComponent));

    QLN_RETURN_IF_ERROR_WITH_ACTION(RepositoryComponentDTO, repositoryComponentResult, m_repository->cancelChanges();)

    // Get the newly created RepositoryComponent entity
    repositoryComponent = repositoryComponentResult.value();
    // Save the newly created entity
    m_newEntity = repositoryComponentResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerRepositoryComponentResult = m_repository->getEntityInRelationOf(Project::schema, ownerId, "repositoryComponent"_L1);
        if (Q_UNLIKELY(originalOwnerRepositoryComponentResult.hasError())) {
            return Result<RepositoryComponentDTO>(originalOwnerRepositoryComponentResult.error());
        }
        auto originalOwnerRepositoryComponent = originalOwnerRepositoryComponentResult.value();

        // save
        m_oldOwnerRepositoryComponent = originalOwnerRepositoryComponent;
        originalOwnerRepositoryComponent = repositoryComponent;

        m_ownerRepositoryComponentNewState = originalOwnerRepositoryComponent;
        ownerEntityRepositoryComponent = originalOwnerRepositoryComponent;
    } else {
        ownerEntityRepositoryComponent = m_ownerRepositoryComponentNewState;
        position = m_position;
    }

    // Add the repositoryComponent to the owner entity
    Result<QleanyEditor::Entities::RepositoryComponent> updateResult =
        m_repository->updateEntityInRelationOf(Project::schema, ownerId, "repositoryComponent"_L1, ownerEntityRepositoryComponent);

    QLN_RETURN_IF_ERROR_WITH_ACTION(RepositoryComponentDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = repositoryComponentResult;

    auto repositoryComponentDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::RepositoryComponent, RepositoryComponentDTO>(repositoryComponentResult.value());
    Q_EMIT repositoryComponentCreated(repositoryComponentDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(repositoryComponent.id(), ownerId, position);

    qDebug() << "RepositoryComponent added:" << repositoryComponentDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created RepositoryComponent as a Result object
    return Result<RepositoryComponentDTO>(repositoryComponentDTO);
}

Result<RepositoryComponentDTO> CreateRepositoryComponentCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(RepositoryComponentDTO, deleteResult)

    Q_EMIT repositoryComponentRemoved(deleteResult.value());

    qDebug() << "RepositoryComponent removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<RepositoryComponentDTO>(RepositoryComponentDTO());
}

bool CreateRepositoryComponentCommandHandler::s_mappingRegistered = false;

void CreateRepositoryComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::RepositoryComponent,
                                                           Contracts::DTO::RepositoryComponent::RepositoryComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::RepositoryComponent::CreateRepositoryComponentDTO,
                                                           QleanyEditor::Entities::RepositoryComponent>();
}