// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_presenter_single_command_handler.h"
#include "presenter_single/validators/update_presenter_single_command_validator.h"
#include "repository/interface_presenter_single_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterSingle;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Commands;
using namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Validators;
using namespace QleanyEditor::Application::Features::PresenterSingle::Commands;

UpdatePresenterSingleCommandHandler::UpdatePresenterSingleCommandHandler(InterfacePresenterSingleRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<PresenterSingleDTO> UpdatePresenterSingleCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdatePresenterSingleCommand &request)
{
    Result<PresenterSingleDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<PresenterSingleDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdatePresenterSingleCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<PresenterSingleDTO> UpdatePresenterSingleCommandHandler::restore()
{
    Result<PresenterSingleDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<PresenterSingleDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdatePresenterSingleCommand restore:" << ex.what();
    }
    return result;
}

Result<PresenterSingleDTO> UpdatePresenterSingleCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdatePresenterSingleCommand &request)
{
    qDebug() << "UpdatePresenterSingleCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdatePresenterSingleCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(PresenterSingleDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::PresenterSingle> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(PresenterSingleDTO, currentResult)

        // map
        m_undoState = Result<PresenterSingleDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterSingle, PresenterSingleDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<PresenterSingleDTO, UpdatePresenterSingleDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto presenterSingle = Qleany::Tools::AutoMapper::AutoMapper::map<UpdatePresenterSingleDTO, QleanyEditor::Entities::PresenterSingle>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        presenterSingle.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto presenterSingleResult = m_repository->update(std::move(presenterSingle));

    if (presenterSingleResult.hasError()) {
        return Result<PresenterSingleDTO>(presenterSingleResult.error());
    }

    // map
    auto presenterSingleDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterSingle, PresenterSingleDTO>(presenterSingleResult.value());

    Q_EMIT presenterSingleUpdated(presenterSingleDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT presenterSingleDetailsUpdated(presenterSingleDto.id());
    }

    qDebug() << "UpdatePresenterSingleCommandHandler::handleImpl done";

    return Result<PresenterSingleDTO>(presenterSingleDto);
}

Result<PresenterSingleDTO> UpdatePresenterSingleCommandHandler::restoreImpl()
{
    qDebug() << "UpdatePresenterSingleCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto presenterSingle = Qleany::Tools::AutoMapper::AutoMapper::map<PresenterSingleDTO, QleanyEditor::Entities::PresenterSingle>(m_undoState.value());

    // do
    auto presenterSingleResult = m_repository->update(std::move(presenterSingle));

    QLN_RETURN_IF_ERROR(PresenterSingleDTO, presenterSingleResult)

    // map
    auto presenterSingleDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::PresenterSingle, PresenterSingleDTO>(presenterSingleResult.value());

    Q_EMIT presenterSingleUpdated(presenterSingleDto);

    qDebug() << "UpdatePresenterSingleCommandHandler::restoreImpl done";

    return Result<PresenterSingleDTO>(presenterSingleDto);
}

bool UpdatePresenterSingleCommandHandler::s_mappingRegistered = false;

void UpdatePresenterSingleCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterSingle, Contracts::DTO::PresenterSingle::PresenterSingleDTO>(true,
                                                                                                                                                         true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterSingle::UpdatePresenterSingleDTO,
                                                           Contracts::DTO::PresenterSingle::PresenterSingleDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::PresenterSingle::UpdatePresenterSingleDTO,
                                                           QleanyEditor::Entities::PresenterSingle>();
}