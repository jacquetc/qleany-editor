// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_presenter_list_model_command_handler.h"
#include "presenter_list_model/validators/update_presenter_list_model_command_validator.h"
#include "repository/interface_presenter_list_model_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterListModel;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Commands;
using namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Validators;
using namespace QleanyEditor::Application::Features::PresenterListModel::Commands;

UpdatePresenterListModelCommandHandler::UpdatePresenterListModelCommandHandler(InterfacePresenterListModelRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterListModelDTO> UpdatePresenterListModelCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                             const UpdatePresenterListModelCommand &request)
{
    Result<PresenterListModelDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<PresenterListModelDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdatePresenterListModelCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterListModelDTO> UpdatePresenterListModelCommandHandler::restore()
{
    Result<PresenterListModelDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<PresenterListModelDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdatePresenterListModelCommand restore:" << ex.what();
    }
    return result;
}

Result<PresenterListModelDTO> UpdatePresenterListModelCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                 const UpdatePresenterListModelCommand &request)
{
    qDebug() << "UpdatePresenterListModelCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdatePresenterListModelCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(PresenterListModelDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::PresenterListModel> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(PresenterListModelDTO, currentResult)

        // map
        m_undoState = Result<PresenterListModelDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterListModel, PresenterListModelDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<PresenterListModelDTO, UpdatePresenterListModelDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto presenterListModel = Qleany::Tools::AutoMapper::AutoMapper::map<UpdatePresenterListModelDTO, QleanyEditor::Entities::PresenterListModel>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        presenterListModel.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto presenterListModelResult = m_repository->update(std::move(presenterListModel));

    if (presenterListModelResult.hasError()) {
        return Result<PresenterListModelDTO>(presenterListModelResult.error());
    }

    // map
    auto presenterListModelDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterListModel, PresenterListModelDTO>(presenterListModelResult.value());

    Q_EMIT presenterListModelUpdated(presenterListModelDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT presenterListModelDetailsUpdated(presenterListModelDto.id());
    }

    qDebug() << "UpdatePresenterListModelCommandHandler::handleImpl done";

    return Result<PresenterListModelDTO>(presenterListModelDto);
}

Result<PresenterListModelDTO> UpdatePresenterListModelCommandHandler::restoreImpl()
{
    qDebug() << "UpdatePresenterListModelCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto presenterListModel =
        Qleany::Tools::AutoMapper::AutoMapper::map<PresenterListModelDTO, QleanyEditor::Entities::PresenterListModel>(m_undoState.value());

    // do
    auto presenterListModelResult = m_repository->update(std::move(presenterListModel));

    QLN_RETURN_IF_ERROR(PresenterListModelDTO, presenterListModelResult)

    // map
    auto presenterListModelDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterListModel, PresenterListModelDTO>(presenterListModelResult.value());

    Q_EMIT presenterListModelUpdated(presenterListModelDto);

    qDebug() << "UpdatePresenterListModelCommandHandler::restoreImpl done";

    return Result<PresenterListModelDTO>(presenterListModelDto);
}

bool UpdatePresenterListModelCommandHandler::s_mappingRegistered = false;

void UpdatePresenterListModelCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterListModel,
                                                           Contracts::DTO::PresenterListModel::PresenterListModelDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterListModel::UpdatePresenterListModelDTO,
                                                           Contracts::DTO::PresenterListModel::PresenterListModelDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterListModel::UpdatePresenterListModelDTO,
                                                           QleanyEditor::Entities::PresenterListModel>();
}