// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_front_end_component_command_handler.h"
#include "front_end_component/validators/remove_front_end_component_command_validator.h"
#include "repository/interface_front_end_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Commands;
using namespace QleanyEditor::Application::Features::FrontEndComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Validators;

RemoveFrontEndComponentCommandHandler::RemoveFrontEndComponentCommandHandler(InterfaceFrontEndComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveFrontEndComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveFrontEndComponentCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveFrontEndComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveFrontEndComponentCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveFrontEndComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveFrontEndComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveFrontEndComponentCommand &request)
{
    int frontEndComponentId = request.id;

    // Validate the command using the validator
    auto validator = RemoveFrontEndComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(frontEndComponentId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::FrontEndComponent> frontEndComponentResult = m_repository->get(frontEndComponentId);

    QLN_RETURN_IF_ERROR(int, frontEndComponentResult)

    // save old entity
    m_oldState = frontEndComponentResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << frontEndComponentId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT frontEndComponentRemoved(deleteResult.value());

    qDebug() << "FrontEndComponent removed:" << frontEndComponentId;

    return Result<int>(frontEndComponentId);
}

Result<int> RemoveFrontEndComponentCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveFrontEndComponentCommandHandler::s_mappingRegistered = false;

void RemoveFrontEndComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::FrontEndComponent, Contracts::DTO::FrontEndComponent::FrontEndComponentDTO>(
        true,
        true);
}