// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/c_r_u_d_dto.h"
#include "c_r_u_d/commands/update_c_r_u_d_command.h"
#include "qleany_editor_application_c_r_u_d_export.h"

#include "repository/interface_c_r_u_d_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CRUD;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CRUD::Commands;

namespace QleanyEditor::Application::Features::CRUD::Commands
{
class QLEANY_EDITOR_APPLICATION_C_R_U_D_EXPORT UpdateCRUDCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdateCRUDCommandHandler(InterfaceCRUDRepository *repository);
    Result<CRUDDTO> handle(QPromise<Result<void>> &progressPromise, const UpdateCRUDCommand &request);
    Result<CRUDDTO> restore();

Q_SIGNALS:
    void cRUDUpdated(QleanyEditor::Contracts::DTO::CRUD::CRUDDTO cRUDDto);
    void cRUDDetailsUpdated(int id);

private:
    InterfaceCRUDRepository *m_repository;
    Result<CRUDDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdateCRUDCommand &request);
    Result<CRUDDTO> restoreImpl();
    Result<CRUDDTO> saveOldState();
    Result<CRUDDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CRUD::Commands