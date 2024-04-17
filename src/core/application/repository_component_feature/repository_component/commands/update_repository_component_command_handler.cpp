// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_repository_component_command_handler.h"
#include "repository/interface_repository_component_repository.h"
#include "repository_component/validators/update_repository_component_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Commands;
using namespace QleanyEditor::Contracts::CQRS::RepositoryComponent::Validators;
using namespace QleanyEditor::Application::Features::RepositoryComponent::Commands;

UpdateRepositoryComponentCommandHandler::UpdateRepositoryComponentCommandHandler(InterfaceRepositoryComponentRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RepositoryComponentDTO> UpdateRepositoryComponentCommandHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                               const UpdateRepositoryComponentCommand &request)
{
    Result<RepositoryComponentDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<RepositoryComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateRepositoryComponentCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RepositoryComponentDTO> UpdateRepositoryComponentCommandHandler::restore()
{
    Result<RepositoryComponentDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<RepositoryComponentDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateRepositoryComponentCommand restore:" << ex.what();
    }
    return result;
}

Result<RepositoryComponentDTO> UpdateRepositoryComponentCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                   const UpdateRepositoryComponentCommand &request)
{
    qDebug() << "UpdateRepositoryComponentCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateRepositoryComponentCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(RepositoryComponentDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::RepositoryComponent> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(RepositoryComponentDTO, currentResult)

        // map
        m_undoState = Result<RepositoryComponentDTO>(
            Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::RepositoryComponent, RepositoryComponentDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<RepositoryComponentDTO, UpdateRepositoryComponentDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto repositoryComponent = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateRepositoryComponentDTO, QleanyEditor::Entities::RepositoryComponent>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        repositoryComponent.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto repositoryComponentResult = m_repository->update(std::move(repositoryComponent));

    if (repositoryComponentResult.hasError()) {
        return Result<RepositoryComponentDTO>(repositoryComponentResult.error());
    }

    // map
    auto repositoryComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::RepositoryComponent, RepositoryComponentDTO>(repositoryComponentResult.value());

    Q_EMIT repositoryComponentUpdated(repositoryComponentDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT repositoryComponentDetailsUpdated(repositoryComponentDto.id());
    }

    qDebug() << "UpdateRepositoryComponentCommandHandler::handleImpl done";

    return Result<RepositoryComponentDTO>(repositoryComponentDto);
}

Result<RepositoryComponentDTO> UpdateRepositoryComponentCommandHandler::restoreImpl()
{
    qDebug() << "UpdateRepositoryComponentCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto repositoryComponent =
        Qleany::Tools::AutoMapper::AutoMapper::map<RepositoryComponentDTO, QleanyEditor::Entities::RepositoryComponent>(m_undoState.value());

    // do
    auto repositoryComponentResult = m_repository->update(std::move(repositoryComponent));

    QLN_RETURN_IF_ERROR(RepositoryComponentDTO, repositoryComponentResult)

    // map
    auto repositoryComponentDto =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::RepositoryComponent, RepositoryComponentDTO>(repositoryComponentResult.value());

    Q_EMIT repositoryComponentUpdated(repositoryComponentDto);

    qDebug() << "UpdateRepositoryComponentCommandHandler::restoreImpl done";

    return Result<RepositoryComponentDTO>(repositoryComponentDto);
}

bool UpdateRepositoryComponentCommandHandler::s_mappingRegistered = false;

void UpdateRepositoryComponentCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::RepositoryComponent,
                                                           Contracts::DTO::RepositoryComponent::RepositoryComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::RepositoryComponent::UpdateRepositoryComponentDTO,
                                                           Contracts::DTO::RepositoryComponent::RepositoryComponentDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::RepositoryComponent::UpdateRepositoryComponentDTO,
                                                           QleanyEditor::Entities::RepositoryComponent>();
}