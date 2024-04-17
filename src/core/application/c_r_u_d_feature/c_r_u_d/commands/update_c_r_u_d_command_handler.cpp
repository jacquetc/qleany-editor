// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_c_r_u_d_command_handler.h"
#include "c_r_u_d/validators/update_c_r_u_d_command_validator.h"
#include "repository/interface_c_r_u_d_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CRUD;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CRUD::Commands;
using namespace QleanyEditor::Contracts::CQRS::CRUD::Validators;
using namespace QleanyEditor::Application::Features::CRUD::Commands;

UpdateCRUDCommandHandler::UpdateCRUDCommandHandler(InterfaceCRUDRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CRUDDTO> UpdateCRUDCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateCRUDCommand &request)
{
    Result<CRUDDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CRUDDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCRUDCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CRUDDTO> UpdateCRUDCommandHandler::restore()
{
    Result<CRUDDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CRUDDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCRUDCommand restore:" << ex.what();
    }
    return result;
}

Result<CRUDDTO> UpdateCRUDCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCRUDCommand &request)
{
    qDebug() << "UpdateCRUDCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateCRUDCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(CRUDDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::CRUD> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(CRUDDTO, currentResult)

        // map
        m_undoState = Result<CRUDDTO>(Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CRUD, CRUDDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<CRUDDTO, UpdateCRUDDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto cRUD = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateCRUDDTO, QleanyEditor::Entities::CRUD>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        cRUD.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto cRUDResult = m_repository->update(std::move(cRUD));

    if (cRUDResult.hasError()) {
        return Result<CRUDDTO>(cRUDResult.error());
    }

    // map
    auto cRUDDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CRUD, CRUDDTO>(cRUDResult.value());

    Q_EMIT cRUDUpdated(cRUDDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT cRUDDetailsUpdated(cRUDDto.id());
    }

    qDebug() << "UpdateCRUDCommandHandler::handleImpl done";

    return Result<CRUDDTO>(cRUDDto);
}

Result<CRUDDTO> UpdateCRUDCommandHandler::restoreImpl()
{
    qDebug() << "UpdateCRUDCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto cRUD = Qleany::Tools::AutoMapper::AutoMapper::map<CRUDDTO, QleanyEditor::Entities::CRUD>(m_undoState.value());

    // do
    auto cRUDResult = m_repository->update(std::move(cRUD));

    QLN_RETURN_IF_ERROR(CRUDDTO, cRUDResult)

    // map
    auto cRUDDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CRUD, CRUDDTO>(cRUDResult.value());

    Q_EMIT cRUDUpdated(cRUDDto);

    qDebug() << "UpdateCRUDCommandHandler::restoreImpl done";

    return Result<CRUDDTO>(cRUDDto);
}

bool UpdateCRUDCommandHandler::s_mappingRegistered = false;

void UpdateCRUDCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CRUD, Contracts::DTO::CRUD::CRUDDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CRUD::UpdateCRUDDTO, Contracts::DTO::CRUD::CRUDDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CRUD::UpdateCRUDDTO, QleanyEditor::Entities::CRUD>();
}