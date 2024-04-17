// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "d_t_o_component/commands/remove_d_t_o_component_command.h"
#include "d_t_o_component/d_t_o_component_dto.h"
#include "qleany_editor_application_d_t_o_component_export.h"

#include "repository/interface_d_t_o_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::DTOComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::DTOComponent::Commands;

namespace QleanyEditor::Application::Features::DTOComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_D_T_O_COMPONENT_EXPORT RemoveDTOComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveDTOComponentCommandHandler(InterfaceDTOComponentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveDTOComponentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void dTOComponentRemoved(int id);

private:
    InterfaceDTOComponentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveDTOComponentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::DTOComponent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::DTOComponent::Commands