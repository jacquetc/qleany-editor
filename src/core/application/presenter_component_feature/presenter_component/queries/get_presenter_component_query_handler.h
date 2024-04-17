// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component/presenter_component_dto.h"
#include "presenter_component/queries/get_presenter_component_query.h"
#include "qleany_editor_application_presenter_component_export.h"

#include "repository/interface_presenter_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Queries;

namespace QleanyEditor::Application::Features::PresenterComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_COMPONENT_EXPORT GetPresenterComponentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetPresenterComponentQueryHandler(InterfacePresenterComponentRepository *repository);
    Result<PresenterComponentDTO> handle(QPromise<Result<void>> &progressPromise, const GetPresenterComponentQuery &query);

private:
    InterfacePresenterComponentRepository *m_repository;
    Result<PresenterComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetPresenterComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterComponent::Queries