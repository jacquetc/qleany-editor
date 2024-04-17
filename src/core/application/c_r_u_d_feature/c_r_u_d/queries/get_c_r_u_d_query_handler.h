// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/c_r_u_d_dto.h"
#include "c_r_u_d/queries/get_c_r_u_d_query.h"
#include "qleany_editor_application_c_r_u_d_export.h"

#include "repository/interface_c_r_u_d_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CRUD;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CRUD::Queries;

namespace QleanyEditor::Application::Features::CRUD::Queries
{
class QLEANY_EDITOR_APPLICATION_C_R_U_D_EXPORT GetCRUDQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetCRUDQueryHandler(InterfaceCRUDRepository *repository);
    Result<CRUDDTO> handle(QPromise<Result<void>> &progressPromise, const GetCRUDQuery &query);

private:
    InterfaceCRUDRepository *m_repository;
    Result<CRUDDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetCRUDQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CRUD::Queries