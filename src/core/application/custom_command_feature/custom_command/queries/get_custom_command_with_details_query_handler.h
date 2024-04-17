// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command/custom_command_with_details_dto.h"
#include "custom_command/queries/get_custom_command_query.h"
#include "qleany_editor_application_custom_command_export.h"

#include "repository/interface_custom_command_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomCommand;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomCommand::Queries;

namespace QleanyEditor::Application::Features::CustomCommand::Queries
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_COMMAND_EXPORT GetCustomCommandWithDetailsQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetCustomCommandWithDetailsQueryHandler(InterfaceCustomCommandRepository *repository);
    Result<CustomCommandWithDetailsDTO> handle(QPromise<Result<void>> &progressPromise, const GetCustomCommandQuery &query);

private:
    InterfaceCustomCommandRepository *m_repository;
    Result<CustomCommandWithDetailsDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomCommandQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomCommand::Queries