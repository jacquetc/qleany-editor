// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_q_r_s_component/c_q_r_s_component_dto.h"
#include "c_q_r_s_component/commands/remove_c_q_r_s_component_command.h"
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
class QLEANY_EDITOR_APPLICATION_C_Q_R_S_COMPONENT_EXPORT RemoveCQRSComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveCQRSComponentCommandHandler(InterfaceCQRSComponentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveCQRSComponentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void cQRSComponentRemoved(int id);

private:
    InterfaceCQRSComponentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCQRSComponentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::CQRSComponent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CQRSComponent::Commands