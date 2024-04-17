// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_query/commands/update_custom_query_command.h"
#include "custom_query/custom_query_dto.h"
#include "qleany_editor_application_custom_query_export.h"

#include "repository/interface_custom_query_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomQuery;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomQuery::Commands;

namespace QleanyEditor::Application::Features::CustomQuery::Commands
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_QUERY_EXPORT UpdateCustomQueryCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateCustomQueryCommandHandler(InterfaceCustomQueryRepository *repository);
    Result<CustomQueryDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateCustomQueryCommand &request);
    Result<CustomQueryDTO> restore();

Q_SIGNALS:
    void customQueryUpdated(QleanyEditor::Contracts::DTO::CustomQuery::CustomQueryDTO customQueryDto);
    void customQueryDetailsUpdated(int id);

private:
    InterfaceCustomQueryRepository *m_repository;
    Result<CustomQueryDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCustomQueryCommand &request);
    Result<CustomQueryDTO> restoreImpl();
    Result<CustomQueryDTO> saveOldState();
    Result<CustomQueryDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomQuery::Commands