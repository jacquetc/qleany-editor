// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/commands/create_custom_d_t_o_command.h"
#include "custom_d_t_o/custom_d_t_o_dto.h"
#include "qleany_editor_application_custom_d_t_o_export.h"
#include "repository/interface_custom_d_t_o_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CustomDTO;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTO::Commands;

namespace QleanyEditor::Application::Features::CustomDTO::Commands
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_D_T_O_EXPORT CreateCustomDTOCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateCustomDTOCommandHandler(InterfaceCustomDTORepository *repository);

    Result<CustomDTODTO> handle(QPromise<Result<void>> &progressPromise, const CreateCustomDTOCommand &request);
    Result<CustomDTODTO> restore();

Q_SIGNALS:
    void customDTOCreated(QleanyEditor::Contracts::DTO::CustomDTO::CustomDTODTO customDTODto);
    void customDTORemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceCustomDTORepository *m_repository;
    Result<CustomDTODTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateCustomDTOCommand &request);
    Result<CustomDTODTO> restoreImpl();
    Result<QleanyEditor::Entities::CustomDTO> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::CustomDTO m_oldOwnerDtoIn;
    QleanyEditor::Entities::CustomDTO m_ownerDtoInNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::CustomDTO::Commands