// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_custom_query_command_handler.h"
#include "custom_query/validators/remove_custom_query_command_validator.h"
#include "repository/interface_custom_query_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomQuery;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomQuery::Commands;
using namespace QleanyEditor::Application::Features::CustomQuery::Commands;
using namespace QleanyEditor::Contracts::CQRS::CustomQuery::Validators;

RemoveCustomQueryCommandHandler::RemoveCustomQueryCommandHandler(InterfaceCustomQueryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveCustomQueryCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveCustomQueryCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCustomQueryCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveCustomQueryCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCustomQueryCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveCustomQueryCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCustomQueryCommand &request)
{
    int customQueryId = request.id;

    // Validate the command using the validator
    auto validator = RemoveCustomQueryCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(customQueryId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::CustomQuery> customQueryResult = m_repository->get(customQueryId);

    QLN_RETURN_IF_ERROR(int, customQueryResult)

    // save old entity
    m_oldState = customQueryResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << customQueryId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT customQueryRemoved(deleteResult.value());

    qDebug() << "CustomQuery removed:" << customQueryId;

    return Result<int>(customQueryId);
}

Result<int> RemoveCustomQueryCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveCustomQueryCommandHandler::s_mappingRegistered = false;

void RemoveCustomQueryCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomQuery, Contracts::DTO::CustomQuery::CustomQueryDTO>(true, true);
}