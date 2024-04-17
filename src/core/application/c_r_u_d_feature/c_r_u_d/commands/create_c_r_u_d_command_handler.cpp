// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_c_r_u_d_command_handler.h"
#include "c_r_u_d/validators/create_c_r_u_d_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "application_feature.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CRUD;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CRUD::Validators;
using namespace QleanyEditor::Application::Features::CRUD::Commands;

CreateCRUDCommandHandler::CreateCRUDCommandHandler(InterfaceCRUDRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CRUDDTO> CreateCRUDCommandHandler::handle(QPromise<Result<void>> &progressPromise, const CreateCRUDCommand &request)
{
    Result<CRUDDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CRUDDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCRUDCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CRUDDTO> CreateCRUDCommandHandler::restore()
{
    Result<CRUDDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CRUDDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreateCRUDCommand restore:" << ex.what();
    }
    return result;
}

Result<CRUDDTO> CreateCRUDCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const CreateCRUDCommand &request)
{
    qDebug() << "CreateCRUDCommandHandler::handleImpl called";
    QleanyEditor::Entities::CRUD cRUD;
    CreateCRUDDTO createDTO = request.req;

    QleanyEditor::Entities::CRUD ownerEntityCrud;

    // Get the entities from owner
    int ownerId = createDTO.applicationFeatureId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create CRUD command using the validator
        auto validator = CreateCRUDCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(CRUDDTO, validatorResult);

        // Map the create CRUD command to a domain CRUD object and
        // generate a UUID
        cRUD = Qleany::Tools::AutoMapper::AutoMapper::map<CreateCRUDDTO, QleanyEditor::Entities::CRUD>(createDTO);

        // allow for forcing the uuid
        if (cRUD.uuid().isNull()) {
            cRUD.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        cRUD.setCreationDate(QDateTime::currentDateTime());
        cRUD.setUpdateDate(QDateTime::currentDateTime());

    } else {
        cRUD = m_newEntity.value();
    }

    // Add the cRUD to the repository

    m_repository->beginChanges();
    auto cRUDResult = m_repository->add(std::move(cRUD));

    QLN_RETURN_IF_ERROR_WITH_ACTION(CRUDDTO, cRUDResult, m_repository->cancelChanges();)

    // Get the newly created CRUD entity
    cRUD = cRUDResult.value();
    // Save the newly created entity
    m_newEntity = cRUDResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerCrudResult = m_repository->getEntityInRelationOf(ApplicationFeature::schema, ownerId, "crud"_L1);
        if (Q_UNLIKELY(originalOwnerCrudResult.hasError())) {
            return Result<CRUDDTO>(originalOwnerCrudResult.error());
        }
        auto originalOwnerCrud = originalOwnerCrudResult.value();

        // save
        m_oldOwnerCrud = originalOwnerCrud;
        originalOwnerCrud = cRUD;

        m_ownerCrudNewState = originalOwnerCrud;
        ownerEntityCrud = originalOwnerCrud;
    } else {
        ownerEntityCrud = m_ownerCrudNewState;
        position = m_position;
    }

    // Add the cRUD to the owner entity
    Result<QleanyEditor::Entities::CRUD> updateResult = m_repository->updateEntityInRelationOf(ApplicationFeature::schema, ownerId, "crud"_L1, ownerEntityCrud);

    QLN_RETURN_IF_ERROR_WITH_ACTION(CRUDDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = cRUDResult;

    auto cRUDDTO = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CRUD, CRUDDTO>(cRUDResult.value());
    Q_EMIT cRUDCreated(cRUDDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(cRUD.id(), ownerId, position);

    qDebug() << "CRUD added:" << cRUDDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created CRUD as a Result object
    return Result<CRUDDTO>(cRUDDTO);
}

Result<CRUDDTO> CreateCRUDCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(CRUDDTO, deleteResult)

    Q_EMIT cRUDRemoved(deleteResult.value());

    qDebug() << "CRUD removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<CRUDDTO>(CRUDDTO());
}

bool CreateCRUDCommandHandler::s_mappingRegistered = false;

void CreateCRUDCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CRUD, Contracts::DTO::CRUD::CRUDDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CRUD::CreateCRUDDTO, QleanyEditor::Entities::CRUD>();
}