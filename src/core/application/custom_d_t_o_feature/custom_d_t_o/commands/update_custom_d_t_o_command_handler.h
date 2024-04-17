// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/commands/update_custom_d_t_o_command.h"
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
class QLEANY_EDITOR_APPLICATION_CUSTOM_D_T_O_EXPORT UpdateCustomDTOCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateCustomDTOCommandHandler(InterfaceCustomDTORepository *repository);
    Result<CustomDTODTO> handle(QPromise<Result<void>> &progressPromise, const UpdateCustomDTOCommand &request);
    Result<CustomDTODTO> restore();

Q_SIGNALS:
    void customDTOUpdated(QleanyEditor::Contracts::DTO::CustomDTO::CustomDTODTO customDTODto);
    void customDTODetailsUpdated(int id);

private:
    InterfaceCustomDTORepository *m_repository;
    Result<CustomDTODTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCustomDTOCommand &request);
    Result<CustomDTODTO> restoreImpl();
    Result<CustomDTODTO> saveOldState();
    Result<CustomDTODTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomDTO::Commands