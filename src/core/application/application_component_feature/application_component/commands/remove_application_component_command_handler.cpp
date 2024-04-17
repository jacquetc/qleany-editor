// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_application_component_command_handler.h"
#include "application_component/validators/remove_application_component_command_validator.h"
#include "repository/interface_application_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Commands;
using namespace QleanyEditor::Application::Features::ApplicationComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Validators;

RemoveApplicationComponentCommandHandler::RemoveApplicationComponentCommandHandler(InterfaceApplicationComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveApplicationComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveApplicationComponentCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveApplicationComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveApplicationComponentCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveApplicationComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveApplicationComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveApplicationComponentCommand &request)
{
    int applicationComponentId = request.id;

    // Validate the command using the validator
    auto validator = RemoveApplicationComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(applicationComponentId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::ApplicationComponent> applicationComponentResult = m_repository->get(applicationComponentId);

    QLN_RETURN_IF_ERROR(int, applicationComponentResult)

    // save old entity
    m_oldState = applicationComponentResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << applicationComponentId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT applicationComponentRemoved(deleteResult.value());

    qDebug() << "ApplicationComponent removed:" << applicationComponentId;

    return Result<int>(applicationComponentId);
}

Result<int> RemoveApplicationComponentCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveApplicationComponentCommandHandler::s_mappingRegistered = false;

void RemoveApplicationComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationComponent,
                                                           Contracts::DTO::ApplicationComponent::ApplicationComponentDTO>(true, true);
}