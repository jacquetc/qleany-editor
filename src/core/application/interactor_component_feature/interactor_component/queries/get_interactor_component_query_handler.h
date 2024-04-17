// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "interactor_component/interactor_component_dto.h"
#include "interactor_component/queries/get_interactor_component_query.h"
#include "qleany_editor_application_interactor_component_export.h"

#include "repository/interface_interactor_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::InteractorComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Queries;

namespace QleanyEditor::Application::Features::InteractorComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_INTERACTOR_COMPONENT_EXPORT GetInteractorComponentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetInteractorComponentQueryHandler(InterfaceInteractorComponentRepository *repository);
    Result<InteractorComponentDTO> handle(QPromise<Result<void>> &progressPromise, const GetInteractorComponentQuery &query);

private:
    InterfaceInteractorComponentRepository *m_repository;
    Result<InteractorComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetInteractorComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::InteractorComponent::Queries