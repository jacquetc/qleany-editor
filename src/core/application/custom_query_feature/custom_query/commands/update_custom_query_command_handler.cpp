// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_custom_query_command_handler.h"
#include "custom_query/validators/update_custom_query_command_validator.h"
#include "repository/interface_custom_query_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomQuery;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomQuery::Commands;
using namespace QleanyEditor::Contracts::CQRS::CustomQuery::Validators;
using namespace QleanyEditor::Application::Features::CustomQuery::Commands;

UpdateCustomQueryCommandHandler::UpdateCustomQueryCommandHandler(InterfaceCustomQueryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomQueryDTO> UpdateCustomQueryCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateCustomQueryCommand &request)
{
    Result<CustomQueryDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<CustomQueryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCustomQueryCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomQueryDTO> UpdateCustomQueryCommandHandler::restore()
{
    Result<CustomQueryDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<CustomQueryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateCustomQueryCommand restore:" << ex.what();
    }
    return result;
}

Result<CustomQueryDTO> UpdateCustomQueryCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCustomQueryCommand &request)
{
    qDebug() << "UpdateCustomQueryCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateCustomQueryCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(CustomQueryDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::CustomQuery> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(CustomQueryDTO, currentResult)

        // map
        m_undoState =
            Result<CustomQueryDTO>(Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomQuery, CustomQueryDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<CustomQueryDTO, UpdateCustomQueryDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto customQuery = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateCustomQueryDTO, QleanyEditor::Entities::CustomQuery>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        customQuery.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto customQueryResult = m_repository->update(std::move(customQuery));

    if (customQueryResult.hasError()) {
        return Result<CustomQueryDTO>(customQueryResult.error());
    }

    // map
    auto customQueryDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomQuery, CustomQueryDTO>(customQueryResult.value());

    Q_EMIT customQueryUpdated(customQueryDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT customQueryDetailsUpdated(customQueryDto.id());
    }

    qDebug() << "UpdateCustomQueryCommandHandler::handleImpl done";

    return Result<CustomQueryDTO>(customQueryDto);
}

Result<CustomQueryDTO> UpdateCustomQueryCommandHandler::restoreImpl()
{
    qDebug() << "UpdateCustomQueryCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto customQuery = Qleany::Tools::AutoMapper::AutoMapper::map<CustomQueryDTO, QleanyEditor::Entities::CustomQuery>(m_undoState.value());

    // do
    auto customQueryResult = m_repository->update(std::move(customQuery));

    QLN_RETURN_IF_ERROR(CustomQueryDTO, customQueryResult)

    // map
    auto customQueryDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomQuery, CustomQueryDTO>(customQueryResult.value());

    Q_EMIT customQueryUpdated(customQueryDto);

    qDebug() << "UpdateCustomQueryCommandHandler::restoreImpl done";

    return Result<CustomQueryDTO>(customQueryDto);
}

bool UpdateCustomQueryCommandHandler::s_mappingRegistered = false;

void UpdateCustomQueryCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomQuery, Contracts::DTO::CustomQuery::CustomQueryDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomQuery::UpdateCustomQueryDTO, Contracts::DTO::CustomQuery::CustomQueryDTO>(
        true,
        true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::CustomQuery::UpdateCustomQueryDTO, QleanyEditor::Entities::CustomQuery>();
}