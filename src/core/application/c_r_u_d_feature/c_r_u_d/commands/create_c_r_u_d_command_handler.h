// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d/c_r_u_d_dto.h"
#include "c_r_u_d/commands/create_c_r_u_d_command.h"
#include "qleany_editor_application_c_r_u_d_export.h"
#include "repository/interface_c_r_u_d_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::CRUD;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CRUD::Commands;

namespace QleanyEditor::Application::Features::CRUD::Commands
{
class QLEANY_EDITOR_APPLICATION_C_R_U_D_EXPORT CreateCRUDCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateCRUDCommandHandler(InterfaceCRUDRepository *repository);

    Result<CRUDDTO> handle(QPromise<Result<void>> &progressPromise, const CreateCRUDCommand &request);
    Result<CRUDDTO> restore();

Q_SIGNALS:
    void cRUDCreated(QleanyEditor::Contracts::DTO::CRUD::CRUDDTO cRUDDto);
    void cRUDRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceCRUDRepository *m_repository;
    Result<CRUDDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateCRUDCommand &request);
    Result<CRUDDTO> restoreImpl();
    Result<QleanyEditor::Entities::CRUD> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::CRUD m_oldOwnerCrud;
    QleanyEditor::Entities::CRUD m_ownerCrudNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::CRUD::Commands