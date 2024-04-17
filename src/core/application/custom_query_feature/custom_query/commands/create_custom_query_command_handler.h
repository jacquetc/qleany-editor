// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_query/commands/create_custom_query_command.h"
#include "custom_query/custom_query_dto.h"
#include "qleany_editor_application_custom_query_export.h"
#include "repository/interface_custom_query_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CustomQuery;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomQuery::Commands;

namespace QleanyEditor::Application::Features::CustomQuery::Commands
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_QUERY_EXPORT CreateCustomQueryCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateCustomQueryCommandHandler(InterfaceCustomQueryRepository *repository);

    Result<CustomQueryDTO> handle(QPromise<Result<void>> &progressPromise, const CreateCustomQueryCommand &request);
    Result<CustomQueryDTO> restore();

Q_SIGNALS:
    void customQueryCreated(QleanyEditor::Contracts::DTO::CustomQuery::CustomQueryDTO customQueryDto);
    void customQueryRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceCustomQueryRepository *m_repository;
    Result<CustomQueryDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateCustomQueryCommand &request);
    Result<CustomQueryDTO> restoreImpl();
    Result<QleanyEditor::Entities::CustomQuery> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::CustomQuery> m_oldOwnerCustomQueries;
    QList<QleanyEditor::Entities::CustomQuery> m_ownerCustomQueriesNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::CustomQuery::Commands