// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "d_t_o_component/d_t_o_component_dto.h"
#include "d_t_o_component/queries/get_d_t_o_component_query.h"
#include "qleany_editor_application_d_t_o_component_export.h"

#include "repository/interface_d_t_o_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::DTOComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::DTOComponent::Queries;

namespace QleanyEditor::Application::Features::DTOComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_D_T_O_COMPONENT_EXPORT GetDTOComponentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetDTOComponentQueryHandler(InterfaceDTOComponentRepository *repository);
    Result<DTOComponentDTO> handle(QPromise<Result<void>> &progressPromise, const GetDTOComponentQuery &query);

private:
    InterfaceDTOComponentRepository *m_repository;
    Result<DTOComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetDTOComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::DTOComponent::Queries