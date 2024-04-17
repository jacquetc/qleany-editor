// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_q_r_s_component/c_q_r_s_component_dto.h"
#include "c_q_r_s_component/commands/create_c_q_r_s_component_command.h"
#include "qleany_editor_application_c_q_r_s_component_export.h"
#include "repository/interface_c_q_r_s_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CQRSComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Commands;

namespace QleanyEditor::Application::Features::CQRSComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_C_Q_R_S_COMPONENT_EXPORT CreateCQRSComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateCQRSComponentCommandHandler(InterfaceCQRSComponentRepository *repository);

    Result<CQRSComponentDTO> handle(QPromise<Result<void>> &progressPromise, const CreateCQRSComponentCommand &request);
    Result<CQRSComponentDTO> restore();

Q_SIGNALS:
    void cQRSComponentCreated(QleanyEditor::Contracts::DTO::CQRSComponent::CQRSComponentDTO cQRSComponentDto);
    void cQRSComponentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceCQRSComponentRepository *m_repository;
    Result<CQRSComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateCQRSComponentCommand &request);
    Result<CQRSComponentDTO> restoreImpl();
    Result<QleanyEditor::Entities::CQRSComponent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::CQRSComponent m_oldOwnerCqrsComponent;
    QleanyEditor::Entities::CQRSComponent m_ownerCqrsComponentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::CQRSComponent::Commands