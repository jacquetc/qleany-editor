// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "create_presenter_list_model_command_handler.h"
#include "presenter_list_model/validators/create_presenter_list_model_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

#include "presenter_component.h"

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::PresenterListModel;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Validators;
using namespace QleanyEditor::Application::Features::PresenterListModel::Commands;

CreatePresenterListModelCommandHandler::CreatePresenterListModelCommandHandler(InterfacePresenterListModelRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterListModelDTO> CreatePresenterListModelCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                             const CreatePresenterListModelCommand &request)
{
    Result<PresenterListModelDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<PresenterListModelDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreatePresenterListModelCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterListModelDTO> CreatePresenterListModelCommandHandler::restore()
{
    Result<PresenterListModelDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<PresenterListModelDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling CreatePresenterListModelCommand restore:" << ex.what();
    }
    return result;
}

Result<PresenterListModelDTO> CreatePresenterListModelCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                 const CreatePresenterListModelCommand &request)
{
    qDebug() << "CreatePresenterListModelCommandHandler::handleImpl called";
    QleanyEditor::Entities::PresenterListModel presenterListModel;
    CreatePresenterListModelDTO createDTO = request.req;

    QList<QleanyEditor::Entities::PresenterListModel> ownerEntityListModels;

    // Get the entities from owner
    int ownerId = createDTO.presenterComponentId();
    m_ownerId = ownerId;

    if (m_firstPass) {
        // Validate the create PresenterListModel command using the validator
        auto validator = CreatePresenterListModelCommandValidator(m_repository);
        Result<void> validatorResult = validator.validate(createDTO);

        QLN_RETURN_IF_ERROR(PresenterListModelDTO, validatorResult);

        // Map the create PresenterListModel command to a domain PresenterListModel object and
        // generate a UUID
        presenterListModel = Qleany::Tools::AutoMapper::AutoMapper::map<CreatePresenterListModelDTO, QleanyEditor::Entities::PresenterListModel>(createDTO);

        // allow for forcing the uuid
        if (presenterListModel.uuid().isNull()) {
            presenterListModel.setUuid(QUuid::createUuid());
        }

        // Set the creation and update timestamps to the current date and time
        presenterListModel.setCreationDate(QDateTime::currentDateTime());
        presenterListModel.setUpdateDate(QDateTime::currentDateTime());

    } else {
        presenterListModel = m_newEntity.value();
    }

    // Add the presenterListModel to the repository

    m_repository->beginChanges();
    auto presenterListModelResult = m_repository->add(std::move(presenterListModel));

    QLN_RETURN_IF_ERROR_WITH_ACTION(PresenterListModelDTO, presenterListModelResult, m_repository->cancelChanges();)

    // Get the newly created PresenterListModel entity
    presenterListModel = presenterListModelResult.value();
    // Save the newly created entity
    m_newEntity = presenterListModelResult;

    //  Manage relation to owner

    int position = -1;

    if (m_firstPass) {
        auto originalOwnerListModelsResult = m_repository->getEntitiesInRelationOf(PresenterComponent::schema, ownerId, "listModels"_L1);
        if (Q_UNLIKELY(originalOwnerListModelsResult.hasError())) {
            return Result<PresenterListModelDTO>(originalOwnerListModelsResult.error());
        }
        auto originalOwnerListModels = originalOwnerListModelsResult.value();

        // save
        m_oldOwnerListModels = originalOwnerListModels;

        // Insert to the right position

        position = createDTO.position();
        if (position == -1) {
            position = originalOwnerListModels.count();
        }
        if (position > originalOwnerListModels.count()) {
            position = originalOwnerListModels.count();
        } else if (position < 0) {
            position = 0;
        }

        m_position = position;

        originalOwnerListModels.insert(position, presenterListModel);

        m_ownerListModelsNewState = originalOwnerListModels;
        ownerEntityListModels = originalOwnerListModels;
    } else {
        ownerEntityListModels = m_ownerListModelsNewState;
        position = m_position;
    }

    // Add the presenterListModel to the owner entity
    Result<QList<QleanyEditor::Entities::PresenterListModel>> updateResult =
        m_repository->updateEntitiesInRelationOf(PresenterComponent::schema, ownerId, "listModels"_L1, ownerEntityListModels);

    QLN_RETURN_IF_ERROR_WITH_ACTION(PresenterListModelDTO, updateResult, m_repository->cancelChanges();)

    m_repository->saveChanges();

    m_newEntity = presenterListModelResult;

    auto presenterListModelDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterListModel, PresenterListModelDTO>(presenterListModelResult.value());
    Q_EMIT presenterListModelCreated(presenterListModelDTO);

    // send an insertion signal
    Q_EMIT relationWithOwnerInserted(presenterListModel.id(), ownerId, position);

    qDebug() << "PresenterListModel added:" << presenterListModelDTO.id();

    m_firstPass = false;

    // Return the DTO of the newly created PresenterListModel as a Result object
    return Result<PresenterListModelDTO>(presenterListModelDTO);
}

Result<PresenterListModelDTO> CreatePresenterListModelCommandHandler::restoreImpl()
{
    int entityId = m_newEntity.value().id();
    auto deleteResult = m_repository->remove(entityId);

    QLN_RETURN_IF_ERROR(PresenterListModelDTO, deleteResult)

    Q_EMIT presenterListModelRemoved(deleteResult.value());

    qDebug() << "PresenterListModel removed:" << deleteResult.value();

    Q_EMIT relationWithOwnerRemoved(entityId, m_ownerId);

    return Result<PresenterListModelDTO>(PresenterListModelDTO());
}

bool CreatePresenterListModelCommandHandler::s_mappingRegistered = false;

void CreatePresenterListModelCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterListModel,
                                                           Contracts::DTO::PresenterListModel::PresenterListModelDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterListModel::CreatePresenterListModelDTO,
                                                           QleanyEditor::Entities::PresenterListModel>();
}