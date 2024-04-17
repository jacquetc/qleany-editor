// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/custom_d_t_o_dto.h"
#include "custom_d_t_o/queries/get_custom_d_t_o_query.h"
#include "qleany_editor_application_custom_d_t_o_export.h"

#include "repository/interface_custom_d_t_o_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CustomDTO;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CustomDTO::Queries;

namespace QleanyEditor::Application::Features::CustomDTO::Queries
{
class QLEANY_EDITOR_APPLICATION_CUSTOM_D_T_O_EXPORT GetCustomDTOQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetCustomDTOQueryHandler(InterfaceCustomDTORepository *repository);
    Result<CustomDTODTO> handle(QPromise<Result<void>> &progressPromise, const GetCustomDTOQuery &query);

private:
    InterfaceCustomDTORepository *m_repository;
    Result<CustomDTODTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetCustomDTOQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CustomDTO::Queries