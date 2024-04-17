// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_custom_query_command_handler.h"
#include "custom_query/validators/create_custom_query_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "application_feature.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CustomQuery;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomQuery::Validators;
using namespace QleanyEditor::Application::Features::CustomQuery::Commands;

CreateCustomQueryCommandHandler::CreateCustomQueryCommandHandler(InterfaceCustomQueryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomQueryDTO> CreateCustomQueryCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateCustomQueryCommand &request)
{
    Result<CustomQueryDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CustomQueryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCustomQueryCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomQueryDTO> CreateCustomQueryCommandHandler::restore()
{
    Result<CustomQueryDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CustomQueryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCustomQueryCommand restore:" << ex.what();
    }
    return result;
}

Result<CustomQueryDTO> CreateCustomQueryCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateCustomQueryCommand &request)
{
    qDebug() << "CreateCustomQueryCommandHandler::handleImpl called";
    QleanyEditor::Entities::CustomQuery customQuery;
    CreateCustomQueryDTO createDTO = request.req;

    QList<QleanyEditor::Entities::CustomQuery> ownerEntityCustomQueries;

    // Get the entities from owner
    int ownerId = createDTO.applicationFeatureId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create CustomQuery command using the validator
        auto validator = CreateCustomQueryCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(CustomQueryDTO, validatorResult);

        // Map the create CustomQuery command to a domain CustomQuery object and
        // generate a UUID
        customQuery = Qleany::Tools::AutoMapper::AutoMapper::map<CreateCustomQueryDTO, QleanyEditor::Entities::CustomQuery>(createDTO);

        // allow for forcing the uuid
        if (customQuery.uuid().isNull()) {
            customQuery.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        customQuery.setCreationDate(QDateTime::currentDateTime());
        customQuery.setUpdateDate(QDateTime::currentDateTime());

    } else {
        customQuery = m_newEntity.value();
    }

    // Add the customQuery to the repository

    m_repository->beginChanges();
    auto customQueryResult = m_repository->add(std::move(customQuery));

    QLN_RETURN_IF_ERROR_WITH_ACTION(CustomQueryDTO, customQueryResult, m_repository->cancelChanges();)

    // Get the newly created CustomQuery entity
    customQuery = customQueryResult.value();
    // Save the newly created entity
    m_newEntity = customQueryResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerCustomQueriesResult = m_repository->getEntitiesInRelationOf(ApplicationFeature::schema, ownerId, "customQueries"_L1);
        if (Q_UNLIKELY(originalOwnerCustomQueriesResult.hasError())) {
            return Result<CustomQueryDTO>(originalOwnerCustomQueriesResult.error());
        }
        auto originalOwnerCustomQueries = originalOwnerCustomQueriesResult.value();

        // save
        m_oldOwnerCustomQueries = originalOwnerCustomQueries;

        // Insert to the right position

        position = createDTO.position();
        if (position == -1) {
            position = originalOwnerCustomQueries.count();
        }
        if (position > originalOwnerCustomQueries.count()) {
            position = originalOwnerCustomQueries.count();
        } else if (position < 0) {
            position = 0;
        }

        m_position = position;

        originalOwnerCustomQueries.insert(position, customQuery);

        m_ownerCustomQueriesNewState = originalOwnerCustomQueries;
        ownerEntityCustomQueries = originalOwnerCustomQueries;
    } else {
        ownerEntityCustomQueries = m_ownerCustomQueriesNewState;
        position = m_position;
    }

    // Add the customQuery to the owner entity
    Result<QList<QleanyEditor::Entities::CustomQuery>> updateResult =
        m_repository->updateEntitiesInRelationOf(ApplicationFeature::schema, ownerId, "customQueries"_L1, ownerEntityCustomQueries);

    QLN_RETURN_IF_ERROR_WITH_ACTION(CustomQueryDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = customQueryResult;

    auto customQueryDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomQuery, CustomQueryDTO>(customQueryResult.value());
    Q_EMIT customQueryCreated(customQueryDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(customQuery.id(), ownerId, position);

    qDebug() << "CustomQuery added:" << customQueryDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created CustomQuery as a Result object
    return Result<CustomQueryDTO>(customQueryDTO);
}

Result<CustomQueryDTO> CreateCustomQueryCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(CustomQueryDTO, deleteResult)

    Q_EMIT customQueryRemoved(deleteResult.value());

    qDebug() << "CustomQuery removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<CustomQueryDTO>(CustomQueryDTO());
}

bool CreateCustomQueryCommandHandler::s_mappingRegistered = false;

void CreateCustomQueryCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomQuery, Contracts::DTO::CustomQuery::CustomQueryDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomQuery::CreateCustomQueryDTO, QleanyEditor::Entities::CustomQuery>();
}