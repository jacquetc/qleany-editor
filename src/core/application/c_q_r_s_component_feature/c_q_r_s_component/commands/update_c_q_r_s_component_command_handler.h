// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_q_r_s_component/c_q_r_s_component_dto.h"
#include "c_q_r_s_component/commands/update_c_q_r_s_component_command.h"
#include "qleany_editor_application_c_q_r_s_component_export.h"

#include "repository/interface_c_q_r_s_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CQRSComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Commands;

namespace QleanyEditor::Application::Features::CQRSComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_C_Q_R_S_COMPONENT_EXPORT UpdateCQRSComponentCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateCQRSComponentCommandHandler(InterfaceCQRSComponentRepository *repository);
    Result<CQRSComponentDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateCQRSComponentCommand &request);
    Result<CQRSComponentDTO> restore();

Q_SIGNALS:
    void cQRSComponentUpdated(QleanyEditor::Contracts::DTO::CQRSComponent::CQRSComponentDTO cQRSComponentDto);
    void cQRSComponentDetailsUpdated(int id);

private:
    InterfaceCQRSComponentRepository *m_repository;
    Result<CQRSComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCQRSComponentCommand &request);
    Result<CQRSComponentDTO> restoreImpl();
    Result<CQRSComponentDTO> saveOldState();
    Result<CQRSComponentDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CQRSComponent::Commands