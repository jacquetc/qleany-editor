// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_custom_command_with_details_query_handler.h"
#include "repository/interface_custom_command_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::CustomCommand::Queries;

GetCustomCommandWithDetailsQueryHandler::GetCustomCommandWithDetailsQueryHandler(InterfaceCustomCommandRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<CustomCommandWithDetailsDTO> GetCustomCommandWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetCustomCommandQuery &query)
{
    Result<CustomCommandWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<CustomCommandWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetCustomCommandQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<CustomCommandWithDetailsDTO> GetCustomCommandWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                        const GetCustomCommandQuery &query)
{
    qDebug() << "GetCustomCommandWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto customCommandResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(CustomCommandWithDetailsDTO, customCommandResult)

    QleanyEditor::Entities::CustomCommand customCommand = customCommandResult.value();

    // map
    auto customCommandWithDetailsDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::CustomCommand, CustomCommandWithDetailsDTO>(customCommand);

    qDebug() << "GetCustomCommandWithDetailsQueryHandler::handleImpl done";

    return Result<CustomCommandWithDetailsDTO>(customCommandWithDetailsDTO);
}

bool GetCustomCommandWithDetailsQueryHandler::s_mappingRegistered = false;

void GetCustomCommandWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CustomCommand, Contracts::DTO::CustomCommand::CustomCommandWithDetailsDTO>();
}