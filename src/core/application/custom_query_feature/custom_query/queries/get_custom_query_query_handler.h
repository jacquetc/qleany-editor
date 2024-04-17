// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_query/custom_query_dto.h"
#include "custom_query/queries/get_custom_query_query.h"
#include "qleany_editor_application_custom_query_export.h"

#include "repository/interface_custom_query_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomQuery;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomQuery::Queries;

namespace QleanyEditor::Application::Features::CustomQuery::Queries
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_QUERY_EXPORT GetCustomQueryQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetCustomQueryQueryHandler(InterfaceCustomQueryRepository *repository);
    Result<CustomQueryDTO> handle(QPromise<Result<void>> &progressPromise, const GetCustomQueryQuery &query);

private:
    InterfaceCustomQueryRepository *m_repository;
    Result<CustomQueryDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomQueryQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomQuery::Queries