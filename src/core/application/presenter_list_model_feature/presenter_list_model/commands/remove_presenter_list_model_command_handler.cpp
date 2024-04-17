// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_presenter_list_model_command_handler.h"
#include "presenter_list_model/validators/remove_presenter_list_model_command_validator.h"
#include "repository/interface_presenter_list_model_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterListModel;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Commands;
using namespace QleanyEditor::Application::Features::PresenterListModel::Commands;
using namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Validators;

RemovePresenterListModelCommandHandler::RemovePresenterListModelCommandHandler(InterfacePresenterListModelRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemovePresenterListModelCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemovePresenterListModelCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemovePresenterListModelCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemovePresenterListModelCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemovePresenterListModelCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemovePresenterListModelCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemovePresenterListModelCommand &request)
{
    int presenterListModelId = request.id;

    // Validate the command using the validator
    auto validator = RemovePresenterListModelCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(presenterListModelId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::PresenterListModel> presenterListModelResult = m_repository->get(presenterListModelId);

    QLN_RETURN_IF_ERROR(int, presenterListModelResult)

    // save old entity
    m_oldState = presenterListModelResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << presenterListModelId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT presenterListModelRemoved(deleteResult.value());

    qDebug() << "PresenterListModel removed:" << presenterListModelId;

    return Result<int>(presenterListModelId);
}

Result<int> RemovePresenterListModelCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemovePresenterListModelCommandHandler::s_mappingRegistered = false;

void RemovePresenterListModelCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterListModel,
                                                           Contracts::DTO::PresenterListModel::PresenterListModelDTO>(true, true);
}