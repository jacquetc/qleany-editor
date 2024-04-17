// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field/commands/create_custom_d_t_o_field_command.h"
#include "custom_d_t_o_field/custom_d_t_o_field_dto.h"
#include "qleany_editor_application_custom_d_t_o_field_export.h"
#include "repository/interface_custom_d_t_o_field_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CustomDTOField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Commands;

namespace QleanyEditor::Application::Features::CustomDTOField::Commands
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_D_T_O_FIELD_EXPORT CreateCustomDTOFieldCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateCustomDTOFieldCommandHandler(InterfaceCustomDTOFieldRepository *repository);

    Result<CustomDTOFieldDTO> handle(QPromise<Result<void>> &progressPromise, const CreateCustomDTOFieldCommand &request);
    Result<CustomDTOFieldDTO> restore();

Q_SIGNALS:
    void customDTOFieldCreated(QleanyEditor::Contracts::DTO::CustomDTOField::CustomDTOFieldDTO customDTOFieldDto);
    void customDTOFieldRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceCustomDTOFieldRepository *m_repository;
    Result<CustomDTOFieldDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateCustomDTOFieldCommand &request);
    Result<CustomDTOFieldDTO> restoreImpl();
    Result<QleanyEditor::Entities::CustomDTOField> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::CustomDTOField> m_oldOwnerFields;
    QList<QleanyEditor::Entities::CustomDTOField> m_ownerFieldsNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::CustomDTOField::Commands