// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "global_component/global_component_dto.h"
#include "global_component/queries/get_global_component_query.h"
#include "qleany_editor_application_global_component_export.h"

#include "repository/interface_global_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::GlobalComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::GlobalComponent::Queries;

namespace QleanyEditor::Application::Features::GlobalComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_GLOBAL_COMPONENT_EXPORT GetGlobalComponentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetGlobalComponentQueryHandler(InterfaceGlobalComponentRepository *repository);
    Result<GlobalComponentDTO> handle(QPromise<Result<void>> &progressPromise, const GetGlobalComponentQuery &query);

private:
    InterfaceGlobalComponentRepository *m_repository;
    Result<GlobalComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetGlobalComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::GlobalComponent::Queries