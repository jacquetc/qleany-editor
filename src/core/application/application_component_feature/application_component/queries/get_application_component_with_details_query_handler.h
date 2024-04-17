// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_component/application_component_with_details_dto.h"
#include "application_component/queries/get_application_component_query.h"
#include "qleany_editor_application_application_component_export.h"

#include "repository/interface_application_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Queries;

namespace QleanyEditor::Application::Features::ApplicationComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_APPLICATION_COMPONENT_EXPORT GetApplicationComponentWithDetailsQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetApplicationComponentWithDetailsQueryHandler(InterfaceApplicationComponentRepository *repository);
    Result<ApplicationComponentWithDetailsDTO> handle(QPromise<Result<void>> &progressPromise, const GetApplicationComponentQuery &query);

private:
    InterfaceApplicationComponentRepository *m_repository;
    Result<ApplicationComponentWithDetailsDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetApplicationComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::ApplicationComponent::Queries