// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_presenter_component_command_handler.h"
#include "presenter_component/validators/remove_presenter_component_command_validator.h"
#include "repository/interface_presenter_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Commands;
using namespace QleanyEditor::Application::Features::PresenterComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Validators;

RemovePresenterComponentCommandHandler::RemovePresenterComponentCommandHandler(InterfacePresenterComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemovePresenterComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemovePresenterComponentCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemovePresenterComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemovePresenterComponentCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemovePresenterComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemovePresenterComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemovePresenterComponentCommand &request)
{
    int presenterComponentId = request.id;

    // Validate the command using the validator
    auto validator = RemovePresenterComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(presenterComponentId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::PresenterComponent> presenterComponentResult = m_repository->get(presenterComponentId);

    QLN_RETURN_IF_ERROR(int, presenterComponentResult)

    // save old entity
    m_oldState = presenterComponentResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << presenterComponentId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT presenterComponentRemoved(deleteResult.value());

    qDebug() << "PresenterComponent removed:" << presenterComponentId;

    return Result<int>(presenterComponentId);
}

Result<int> RemovePresenterComponentCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemovePresenterComponentCommandHandler::s_mappingRegistered = false;

void RemovePresenterComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::PresenterComponent,
                                                           Contracts::DTO::PresenterComponent::PresenterComponentDTO>(true, true);
}