// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/commands/remove_custom_d_t_o_command.h"
#include "custom_d_t_o/custom_d_t_o_dto.h"
#include "qleany_editor_application_custom_d_t_o_export.h"

#include "repository/interface_custom_d_t_o_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomDTO;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTO::Commands;

namespace QleanyEditor::Application::Features::CustomDTO::Commands
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_D_T_O_EXPORT RemoveCustomDTOCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveCustomDTOCommandHandler(InterfaceCustomDTORepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveCustomDTOCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void customDTORemoved(int id);

private:
    InterfaceCustomDTORepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCustomDTOCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::CustomDTO m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomDTO::Commands