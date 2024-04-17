// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_presenter_single_command_handler.h"
#include "presenter_single/validators/create_presenter_single_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "presenter_component.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::PresenterSingle;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Validators;
using namespace QleanyEditor::Application::Features::PresenterSingle::Commands;

CreatePresenterSingleCommandHandler::CreatePresenterSingleCommandHandler(InterfacePresenterSingleRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterSingleDTO> CreatePresenterSingleCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreatePresenterSingleCommand &request)
{
    Result<PresenterSingleDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<PresenterSingleDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreatePresenterSingleCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterSingleDTO> CreatePresenterSingleCommandHandler::restore()
{
    Result<PresenterSingleDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<PresenterSingleDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreatePresenterSingleCommand restore:" << ex.what();
    }
    return result;
}

Result<PresenterSingleDTO> CreatePresenterSingleCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreatePresenterSingleCommand &request)
{
    qDebug() << "CreatePresenterSingleCommandHandler::handleImpl called";
    QleanyEditor::Entities::PresenterSingle presenterSingle;
    CreatePresenterSingleDTO createDTO = request.req;

    QList<QleanyEditor::Entities::PresenterSingle> ownerEntitySingles;

    // Get the entities from owner
    int ownerId = createDTO.presenterComponentId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create PresenterSingle command using the validator
        auto validator = CreatePresenterSingleCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(PresenterSingleDTO, validatorResult);

        // Map the create PresenterSingle command to a domain PresenterSingle object and
        // generate a UUID
        presenterSingle = Qleany::Tools::AutoMapper::AutoMapper::map<CreatePresenterSingleDTO, QleanyEditor::Entities::PresenterSingle>(createDTO);

        // allow for forcing the uuid
        if (presenterSingle.uuid().isNull()) {
            presenterSingle.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        presenterSingle.setCreationDate(QDateTime::currentDateTime());
        presenterSingle.setUpdateDate(QDateTime::currentDateTime());

    } else {
        presenterSingle = m_newEntity.value();
    }

    // Add the presenterSingle to the repository

    m_repository->beginChanges();
    auto presenterSingleResult = m_repository->add(std::move(presenterSingle));

    QLN_RETURN_IF_ERROR_WITH_ACTION(PresenterSingleDTO, presenterSingleResult, m_repository->cancelChanges();)

    // Get the newly created PresenterSingle entity
    presenterSingle = presenterSingleResult.value();
    // Save the newly created entity
    m_newEntity = presenterSingleResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerSinglesResult = m_repository->getEntitiesInRelationOf(PresenterComponent::schema, ownerId, "singles"_L1);
        if (Q_UNLIKELY(originalOwnerSinglesResult.hasError())) {
            return Result<PresenterSingleDTO>(originalOwnerSinglesResult.error());
        }
        auto originalOwnerSingles = originalOwnerSinglesResult.value();

        // save
        m_oldOwnerSingles = originalOwnerSingles;

        // Insert to the right position

        position = createDTO.position();
        if (position == -1) {
            position = originalOwnerSingles.count();
        }
        if (position > originalOwnerSingles.count()) {
            position = originalOwnerSingles.count();
        } else if (position < 0) {
            position = 0;
        }

        m_position = position;

        originalOwnerSingles.insert(position, presenterSingle);

        m_ownerSinglesNewState = originalOwnerSingles;
        ownerEntitySingles = originalOwnerSingles;
    } else {
        ownerEntitySingles = m_ownerSinglesNewState;
        position = m_position;
    }

    // Add the presenterSingle to the owner entity
    Result<QList<QleanyEditor::Entities::PresenterSingle>> updateResult =
        m_repository->updateEntitiesInRelationOf(PresenterComponent::schema, ownerId, "singles"_L1, ownerEntitySingles);

    QLN_RETURN_IF_ERROR_WITH_ACTION(PresenterSingleDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = presenterSingleResult;

    auto presenterSingleDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterSingle, PresenterSingleDTO>(presenterSingleResult.value());
    Q_EMIT presenterSingleCreated(presenterSingleDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(presenterSingle.id(), ownerId, position);

    qDebug() << "PresenterSingle added:" << presenterSingleDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created PresenterSingle as a Result object
    return Result<PresenterSingleDTO>(presenterSingleDTO);
}

Result<PresenterSingleDTO> CreatePresenterSingleCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(PresenterSingleDTO, deleteResult)

    Q_EMIT presenterSingleRemoved(deleteResult.value());

    qDebug() << "PresenterSingle removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<PresenterSingleDTO>(PresenterSingleDTO());
}

bool CreatePresenterSingleCommandHandler::s_mappingRegistered = false;

void CreatePresenterSingleCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterSingle, Contracts::DTO::PresenterSingle::PresenterSingleDTO>(true,
                                                                                                                                                         true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterSingle::CreatePresenterSingleDTO,
                                                           QleanyEditor::Entities::PresenterSingle>();
}