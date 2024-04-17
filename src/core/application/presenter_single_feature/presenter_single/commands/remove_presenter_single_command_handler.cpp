// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_presenter_single_command_handler.h"
#include "presenter_single/validators/remove_presenter_single_command_validator.h"
#include "repository/interface_presenter_single_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterSingle;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Commands;
using namespace QleanyEditor::Application::Features::PresenterSingle::Commands;
using namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Validators;

RemovePresenterSingleCommandHandler::RemovePresenterSingleCommandHandler(InterfacePresenterSingleRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemovePresenterSingleCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemovePresenterSingleCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemovePresenterSingleCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemovePresenterSingleCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemovePresenterSingleCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemovePresenterSingleCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemovePresenterSingleCommand &request)
{
    int presenterSingleId = request.id;

    // Validate the command using the validator
    auto validator = RemovePresenterSingleCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(presenterSingleId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::PresenterSingle> presenterSingleResult = m_repository->get(presenterSingleId);

    QLN_RETURN_IF_ERROR(int, presenterSingleResult)

    // save old entity
    m_oldState = presenterSingleResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << presenterSingleId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT presenterSingleRemoved(deleteResult.value());

    qDebug() << "PresenterSingle removed:" << presenterSingleId;

    return Result<int>(presenterSingleId);
}

Result<int> RemovePresenterSingleCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemovePresenterSingleCommandHandler::s_mappingRegistered = false;

void RemovePresenterSingleCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterSingle, Contracts::DTO::PresenterSingle::PresenterSingleDTO>(true,
                                                                                                                                                         true);
}