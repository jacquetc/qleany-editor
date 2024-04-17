// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_application_component_command_handler.h"
#include "application_component/validators/update_application_component_command_validator.h"
#include "repository/interface_application_component_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::ApplicationComponent::Validators;
using namespace QleanyEditor::Application::Features::ApplicationComponent::Commands;

UpdateApplicationComponentCommandHandler::UpdateApplicationComponentCommandHandler(InterfaceApplicationComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ApplicationComponentDTO> UpdateApplicationComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                 const UpdateApplicationComponentCommand &request)
{
    Result<ApplicationComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<ApplicationComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateApplicationComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ApplicationComponentDTO> UpdateApplicationComponentCommandHandler::restore()
{
    Result<ApplicationComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<ApplicationComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateApplicationComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<ApplicationComponentDTO> UpdateApplicationComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                     const UpdateApplicationComponentCommand &request)
{
    qDebug() << "UpdateApplicationComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateApplicationComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(ApplicationComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::ApplicationComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(ApplicationComponentDTO, currentResult)

        // map
        m_undoState = Result<ApplicationComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationComponent, ApplicationComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<ApplicationComponentDTO, UpdateApplicationComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto applicationComponent =
        Qleany::Tools::AutoMapper::AutoMapper::map<UpdateApplicationComponentDTO, QleanyEditor::Entities::ApplicationComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        applicationComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto applicationComponentResult = m_repository->update(std::move(applicationComponent));

    if (applicationComponentResult.hasError()) {
        return Result<ApplicationComponentDTO>(applicationComponentResult.error());
    }

    // map
    auto applicationComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationComponent, ApplicationComponentDTO>(applicationComponentResult.value());

    Q_EMIT applicationComponentUpdated(applicationComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT applicationComponentDetailsUpdated(applicationComponentDto.id());
    }

    qDebug() << "UpdateApplicationComponentCommandHandler::handleImpl done";

    return Result<ApplicationComponentDTO>(applicationComponentDto);
}

Result<ApplicationComponentDTO> UpdateApplicationComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateApplicationComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto applicationComponent =
        Qleany::Tools::AutoMapper::AutoMapper::map<ApplicationComponentDTO, QleanyEditor::Entities::ApplicationComponent>(m_undoState.value());

    // do
    auto applicationComponentResult = m_repository->update(std::move(applicationComponent));

    QLN_RETURN_IF_ERROR(ApplicationComponentDTO, applicationComponentResult)

    // map
    auto applicationComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationComponent, ApplicationComponentDTO>(applicationComponentResult.value());

    Q_EMIT applicationComponentUpdated(applicationComponentDto);

    qDebug() << "UpdateApplicationComponentCommandHandler::restoreImpl done";

    return Result<ApplicationComponentDTO>(applicationComponentDto);
}

bool UpdateApplicationComponentCommandHandler::s_mappingRegistered = false;

void UpdateApplicationComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationComponent,
                                                           Contracts::DTO::ApplicationComponent::ApplicationComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ApplicationComponent::UpdateApplicationComponentDTO,
                                                           Contracts::DTO::ApplicationComponent::ApplicationComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::ApplicationComponent::UpdateApplicationComponentDTO,
                                                           QleanyEditor::Entities::ApplicationComponent>();
}