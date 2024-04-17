// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_repository_command_handler.h"
#include "repository/validators/create_repository_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "repository_component.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Repository::Validators;
using namespace QleanyEditor::Application::Features::Repository::Commands;

CreateRepositoryCommandHandler::CreateRepositoryCommandHandler(InterfaceRepositoryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RepositoryDTO> CreateRepositoryCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateRepositoryCommand &request)
{
    Result<RepositoryDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<RepositoryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateRepositoryCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RepositoryDTO> CreateRepositoryCommandHandler::restore()
{
    Result<RepositoryDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<RepositoryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateRepositoryCommand restore:" << ex.what();
    }
    return result;
}

Result<RepositoryDTO> CreateRepositoryCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateRepositoryCommand &request)
{
    qDebug() << "CreateRepositoryCommandHandler::handleImpl called";
    QleanyEditor::Entities::Repository repository;
    CreateRepositoryDTO createDTO = request.req;

    QList<QleanyEditor::Entities::Repository> ownerEntityRepositories;

    // Get the entities from owner
    int ownerId = createDTO.repositoryComponentId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create Repository command using the validator
        auto validator = CreateRepositoryCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(RepositoryDTO, validatorResult);

        // Map the create Repository command to a domain Repository object and
        // generate a UUID
        repository = Qleany::Tools::AutoMapper::AutoMapper::map<CreateRepositoryDTO, QleanyEditor::Entities::Repository>(createDTO);

        // allow for forcing the uuid
        if (repository.uuid().isNull()) {
            repository.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        repository.setCreationDate(QDateTime::currentDateTime());
        repository.setUpdateDate(QDateTime::currentDateTime());

    } else {
        repository = m_newEntity.value();
    }

    // Add the repository to the repository

    m_repository->beginChanges();
    auto repositoryResult = m_repository->add(std::move(repository));

    QLN_RETURN_IF_ERROR_WITH_ACTION(RepositoryDTO, repositoryResult, m_repository->cancelChanges();)

    // Get the newly created Repository entity
    repository = repositoryResult.value();
    // Save the newly created entity
    m_newEntity = repositoryResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerRepositoriesResult = m_repository->getEntitiesInRelationOf(RepositoryComponent::schema, ownerId, "repositories"_L1);
        if (Q_UNLIKELY(originalOwnerRepositoriesResult.hasError())) {
            return Result<RepositoryDTO>(originalOwnerRepositoriesResult.error());
        }
        auto originalOwnerRepositories = originalOwnerRepositoriesResult.value();

        // save
        m_oldOwnerRepositories = originalOwnerRepositories;

        // Insert to the right position

        position = createDTO.position();
        if (position == -1) {
            position = originalOwnerRepositories.count();
        }
        if (position > originalOwnerRepositories.count()) {
            position = originalOwnerRepositories.count();
        } else if (position < 0) {
            position = 0;
        }

        m_position = position;

        originalOwnerRepositories.insert(position, repository);

        m_ownerRepositoriesNewState = originalOwnerRepositories;
        ownerEntityRepositories = originalOwnerRepositories;
    } else {
        ownerEntityRepositories = m_ownerRepositoriesNewState;
        position = m_position;
    }

    // Add the repository to the owner entity
    Result<QList<QleanyEditor::Entities::Repository>> updateResult =
        m_repository->updateEntitiesInRelationOf(RepositoryComponent::schema, ownerId, "repositories"_L1, ownerEntityRepositories);

    QLN_RETURN_IF_ERROR_WITH_ACTION(RepositoryDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = repositoryResult;

    auto repositoryDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Repository, RepositoryDTO>(repositoryResult.value());
    Q_EMIT repositoryCreated(repositoryDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(repository.id(), ownerId, position);

    qDebug() << "Repository added:" << repositoryDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created Repository as a Result object
    return Result<RepositoryDTO>(repositoryDTO);
}

Result<RepositoryDTO> CreateRepositoryCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(RepositoryDTO, deleteResult)

    Q_EMIT repositoryRemoved(deleteResult.value());

    qDebug() << "Repository removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<RepositoryDTO>(RepositoryDTO());
}

bool CreateRepositoryCommandHandler::s_mappingRegistered = false;

void CreateRepositoryCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Repository, Contracts::DTO::Repository::RepositoryDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::Repository::CreateRepositoryDTO, QleanyEditor::Entities::Repository>();
}