// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field/commands/remove_custom_d_t_o_field_command.h"
#include "custom_d_t_o_field/custom_d_t_o_field_dto.h"
#include "qleany_editor_application_custom_d_t_o_field_export.h"

#include "repository/interface_custom_d_t_o_field_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomDTOField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Commands;

namespace QleanyEditor::Application::Features::CustomDTOField::Commands
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_D_T_O_FIELD_EXPORT RemoveCustomDTOFieldCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveCustomDTOFieldCommandHandler(InterfaceCustomDTOFieldRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveCustomDTOFieldCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void customDTOFieldRemoved(int id);

private:
    InterfaceCustomDTOFieldRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCustomDTOFieldCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::CustomDTOField m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomDTOField::Commands