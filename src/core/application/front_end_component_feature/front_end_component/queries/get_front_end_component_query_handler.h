// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "front_end_component/front_end_component_dto.h"
#include "front_end_component/queries/get_front_end_component_query.h"
#include "qleany_editor_application_front_end_component_export.h"

#include "repository/interface_front_end_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Queries;

namespace QleanyEditor::Application::Features::FrontEndComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_FRONT_END_COMPONENT_EXPORT GetFrontEndComponentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetFrontEndComponentQueryHandler(InterfaceFrontEndComponentRepository *repository);
    Result<FrontEndComponentDTO> handle(QPromise<Result<void>> &progressPromise, const GetFrontEndComponentQuery &query);

private:
    InterfaceFrontEndComponentRepository *m_repository;
    Result<FrontEndComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetFrontEndComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::FrontEndComponent::Queries