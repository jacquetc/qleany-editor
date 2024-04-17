// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "d_t_o_component/commands/create_d_t_o_component_command.h"
#include "d_t_o_component/d_t_o_component_dto.h"
#include "qleany_editor_application_d_t_o_component_export.h"
#include "repository/interface_d_t_o_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::DTOComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::DTOComponent::Commands;

namespace QleanyEditor::Application::Features::DTOComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_D_T_O_COMPONENT_EXPORT CreateDTOComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateDTOComponentCommandHandler(InterfaceDTOComponentRepository *repository);

    Result<DTOComponentDTO> handle(QPromise<Result<void>> &progressPromise, const CreateDTOComponentCommand &request);
    Result<DTOComponentDTO> restore();

Q_SIGNALS:
    void dTOComponentCreated(QleanyEditor::Contracts::DTO::DTOComponent::DTOComponentDTO dTOComponentDto);
    void dTOComponentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceDTOComponentRepository *m_repository;
    Result<DTOComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateDTOComponentCommand &request);
    Result<DTOComponentDTO> restoreImpl();
    Result<QleanyEditor::Entities::DTOComponent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::DTOComponent m_oldOwnerDtoComponent;
    QleanyEditor::Entities::DTOComponent m_ownerDtoComponentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::DTOComponent::Commands