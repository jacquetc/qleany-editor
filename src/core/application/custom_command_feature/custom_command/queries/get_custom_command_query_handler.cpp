// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_custom_command_query_handler.h"
#include "repository/interface_custom_command_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CustomCommand::Queries;

GetCustomCommandQueryHandler::GetCustomCommandQueryHandler(InterfaceCustomCommandRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomCommandDTO> GetCustomCommandQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCustomCommandQuery &query)
{
    Result<CustomCommandDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CustomCommandDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCustomCommandQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomCommandDTO> GetCustomCommandQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomCommandQuery &query)
{
    qDebug() << "GetCustomCommandQueryHandler::handleImpl called with id" << query.id;

    // do
    auto customCommandResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(CustomCommandDTO, customCommandResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomCommand, CustomCommandDTO>(customCommandResult.value());

    qDebug() << "GetCustomCommandQueryHandler::handleImpl done";

    return Result<CustomCommandDTO>(dto);
}

bool GetCustomCommandQueryHandler::s_mappingRegistered = false;

void GetCustomCommandQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomCommand, Contracts::DTO::CustomCommand::CustomCommandDTO>(true, true);
}