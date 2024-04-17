// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/c_r_u_d_dto.h"
#include "c_r_u_d/commands/remove_c_r_u_d_command.h"
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
class QLEANY_EDITOR_APPLICATION_C_R_U_D_EXPORT RemoveCRUDCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveCRUDCommandHandler(InterfaceCRUDRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveCRUDCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void cRUDRemoved(int id);

private:
    InterfaceCRUDRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCRUDCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::CRUD m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::CRUD::Commands