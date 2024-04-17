// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field/custom_d_t_o_field_dto.h"
#include "custom_d_t_o_field/queries/get_custom_d_t_o_field_query.h"
#include "qleany_editor_application_custom_d_t_o_field_export.h"

#include "repository/interface_custom_d_t_o_field_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomDTOField;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTOField::Queries;

namespace QleanyEditor::Application::Features::CustomDTOField::Queries
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_D_T_O_FIELD_EXPORT GetCustomDTOFieldQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetCustomDTOFieldQueryHandler(InterfaceCustomDTOFieldRepository *repository);
    Result<CustomDTOFieldDTO> handle(QPromise<Result<void>> &progressPromise, const GetCustomDTOFieldQuery &query);

private:
    InterfaceCustomDTOFieldRepository *m_repository;
    Result<CustomDTOFieldDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomDTOFieldQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomDTOField::Queries