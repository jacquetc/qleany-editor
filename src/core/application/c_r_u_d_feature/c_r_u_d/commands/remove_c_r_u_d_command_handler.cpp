// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_c_r_u_d_command_handler.h"
#include "c_r_u_d/validators/remove_c_r_u_d_command_validator.h"
#include "repository/interface_c_r_u_d_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CRUD;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CRUD::Commands;
using namespace QleanyEditor::Application::Features::CRUD::Commands;
using namespace QleanyEditor::Contracts::CQRS::CRUD::Validators;

RemoveCRUDCommandHandler::RemoveCRUDCommandHandler(InterfaceCRUDRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveCRUDCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveCRUDCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCRUDCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveCRUDCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCRUDCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveCRUDCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCRUDCommand &request)
{
    int cRUDId = request.id;

    // Validate the command using the validator
    auto validator = RemoveCRUDCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(cRUDId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::CRUD> cRUDResult = m_repository->get(cRUDId);

    QLN_RETURN_IF_ERROR(int, cRUDResult)

    // save old entity
    m_oldState = cRUDResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << cRUDId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT cRUDRemoved(deleteResult.value());

    qDebug() << "CRUD removed:" << cRUDId;

    return Result<int>(cRUDId);
}

Result<int> RemoveCRUDCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveCRUDCommandHandler::s_mappingRegistered = false;

void RemoveCRUDCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CRUD, Contracts::DTO::CRUD::CRUDDTO>(true, true);
}