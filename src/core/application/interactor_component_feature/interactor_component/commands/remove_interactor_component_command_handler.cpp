// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_interactor_component_command_handler.h"
#include "interactor_component/validators/remove_interactor_component_command_validator.h"
#include "repository/interface_interactor_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::InteractorComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Commands;
using namespace QleanyEditor::Application::Features::InteractorComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::InteractorComponent::Validators;

RemoveInteractorComponentCommandHandler::RemoveInteractorComponentCommandHandler(InterfaceInteractorComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveInteractorComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveInteractorComponentCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveInteractorComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveInteractorComponentCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveInteractorComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveInteractorComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveInteractorComponentCommand &request)
{
    int interactorComponentId = request.id;

    // Validate the command using the validator
    auto validator = RemoveInteractorComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(interactorComponentId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::InteractorComponent> interactorComponentResult = m_repository->get(interactorComponentId);

    QLN_RETURN_IF_ERROR(int, interactorComponentResult)

    // save old entity
    m_oldState = interactorComponentResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << interactorComponentId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT interactorComponentRemoved(deleteResult.value());

    qDebug() << "InteractorComponent removed:" << interactorComponentId;

    return Result<int>(interactorComponentId);
}

Result<int> RemoveInteractorComponentCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveInteractorComponentCommandHandler::s_mappingRegistered = false;

void RemoveInteractorComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::InteractorComponent,
                                                           Contracts::DTO::InteractorComponent::InteractorComponentDTO>(true, true);
}