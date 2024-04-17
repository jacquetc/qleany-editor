// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_q_r_s_component/c_q_r_s_component_dto.h"
#include "c_q_r_s_component/queries/get_c_q_r_s_component_query.h"
#include "qleany_editor_application_c_q_r_s_component_export.h"

#include "repository/interface_c_q_r_s_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CQRSComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Queries;

namespace QleanyEditor::Application::Features::CQRSComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_C_Q_R_S_COMPONENT_EXPORT GetCQRSComponentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetCQRSComponentQueryHandler(InterfaceCQRSComponentRepository *repository);
    Result<CQRSComponentDTO> handle(QPromise<Result<void>> &progressPromise, const GetCQRSComponentQuery &query);

private:
    InterfaceCQRSComponentRepository *m_repository;
    Result<CQRSComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetCQRSComponentQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CQRSComponent::Queries