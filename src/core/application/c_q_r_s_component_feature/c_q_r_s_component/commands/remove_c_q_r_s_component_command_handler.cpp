// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "remove_c_q_r_s_component_command_handler.h"
#include "c_q_r_s_component/validators/remove_c_q_r_s_component_command_validator.h"
#include "repository/interface_c_q_r_s_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::CQRSComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Commands;
using namespace QleanyEditor::Application::Features::CQRSComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::CQRSComponent::Validators;

RemoveCQRSComponentCommandHandler::RemoveCQRSComponentCommandHandler(InterfaceCQRSComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<int> RemoveCQRSComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise, const RemoveCQRSComponentCommand &request)
{
    Result<int> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCQRSComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<int> RemoveCQRSComponentCommandHandler::restore()
{
    Result<int> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<int>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling RemoveCQRSComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<int> RemoveCQRSComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const RemoveCQRSComponentCommand &request)
{
    int cQRSComponentId = request.id;

    // Validate the command using the validator
    auto validator = RemoveCQRSComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(cQRSComponentId);

    QLN_RETURN_IF_ERROR(int, validatorResult);

    Result<QleanyEditor::Entities::CQRSComponent> cQRSComponentResult = m_repository->get(cQRSComponentId);

    QLN_RETURN_IF_ERROR(int, cQRSComponentResult)

    // save old entity
    m_oldState = cQRSComponentResult.value();

    auto deleteResult = m_repository->removeInCascade(QList<int>() << cQRSComponentId);

    QLN_RETURN_IF_ERROR(int, deleteResult)

    // repositories handle remove Q_SIGNALS
    // Q_EMIT cQRSComponentRemoved(deleteResult.value());

    qDebug() << "CQRSComponent removed:" << cQRSComponentId;

    return Result<int>(cQRSComponentId);
}

Result<int> RemoveCQRSComponentCommandHandler::restoreImpl()
{
    // no restore possible
    return Result<int>(0);
}

bool RemoveCQRSComponentCommandHandler::s_mappingRegistered = false;

void RemoveCQRSComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::CQRSComponent, Contracts::DTO::CQRSComponent::CQRSComponentDTO>(true, true);
}