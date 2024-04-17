// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "update_repository_command_handler.h"
#include "repository/interface_repository_repository.h"
#include "repository/validators/update_repository_command_validator.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Repository::Commands;
using namespace QleanyEditor::Contracts::CQRS::Repository::Validators;
using namespace QleanyEditor::Application::Features::Repository::Commands;

UpdateRepositoryCommandHandler::UpdateRepositoryCommandHandler(InterfaceRepositoryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RepositoryDTO> UpdateRepositoryCommandHandler::handle(QPromise<Result<void>> &progressPromise, const UpdateRepositoryCommand &request)
{
    Result<RepositoryDTO> result;

    try {
        result = handleImpl(progressPromise, request);
    } catch (const std::exception &ex) {
        result = Result<RepositoryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateRepositoryCommand:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RepositoryDTO> UpdateRepositoryCommandHandler::restore()
{
    Result<RepositoryDTO> result;

    try {
        result = restoreImpl();
    } catch (const std::exception &ex) {
        result = Result<RepositoryDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling UpdateRepositoryCommand restore:" << ex.what();
    }
    return result;
}

Result<RepositoryDTO> UpdateRepositoryCommandHandler::handleImpl(QPromise<Result<void>> &progressPromise, const UpdateRepositoryCommand &request)
{
    qDebug() << "UpdateRepositoryCommandHandler::handleImpl called with id" << request.req.id();

    // validate:
    auto validator = UpdateRepositoryCommandValidator(m_repository);
    Result<void> validatorResult = validator.validate(request.req);

    QLN_RETURN_IF_ERROR(RepositoryDTO, validatorResult)

    // save old state
    if (m_undoState.isEmpty()) {
        Result<QleanyEditor::Entities::Repository> currentResult = m_repository->get(request.req.id());

        QLN_RETURN_IF_ERROR(RepositoryDTO, currentResult)

        // map
        m_undoState =
            Result<RepositoryDTO>(Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Repository, RepositoryDTO>(currentResult.value()));
    }
    auto updateDto = Qleany::Tools::AutoMapper::AutoMapper::map<RepositoryDTO, UpdateRepositoryDTO>(m_undoState.value());
    updateDto << request.req;

    // map
    auto repository = Qleany::Tools::AutoMapper::AutoMapper::map<UpdateRepositoryDTO, QleanyEditor::Entities::Repository>(updateDto);

    // set update timestamp only on first pass
    if (m_undoState.isEmpty()) {
        repository.setUpdateDate(QDateTime::currentDateTime());
    }

    // do
    auto repositoryResult = m_repository->update(std::move(repository));

    if (repositoryResult.hasError()) {
        return Result<RepositoryDTO>(repositoryResult.error());
    }

    // map
    auto repositoryDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Repository, RepositoryDTO>(repositoryResult.value());

    Q_EMIT repositoryUpdated(repositoryDto);

    if (request.req.metaData().areDetailsSet()) {
        Q_EMIT repositoryDetailsUpdated(repositoryDto.id());
    }

    qDebug() << "UpdateRepositoryCommandHandler::handleImpl done";

    return Result<RepositoryDTO>(repositoryDto);
}

Result<RepositoryDTO> UpdateRepositoryCommandHandler::restoreImpl()
{
    qDebug() << "UpdateRepositoryCommandHandler::restoreImpl called with id" << m_undoState.value().uuid();

    // map
    auto repository = Qleany::Tools::AutoMapper::AutoMapper::map<RepositoryDTO, QleanyEditor::Entities::Repository>(m_undoState.value());

    // do
    auto repositoryResult = m_repository->update(std::move(repository));

    QLN_RETURN_IF_ERROR(RepositoryDTO, repositoryResult)

    // map
    auto repositoryDto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Repository, RepositoryDTO>(repositoryResult.value());

    Q_EMIT repositoryUpdated(repositoryDto);

    qDebug() << "UpdateRepositoryCommandHandler::restoreImpl done";

    return Result<RepositoryDTO>(repositoryDto);
}

bool UpdateRepositoryCommandHandler::s_mappingRegistered = false;

void UpdateRepositoryCommandHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Repository, Contracts::DTO::Repository::RepositoryDTO>(true, true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::Repository::UpdateRepositoryDTO, Contracts::DTO::Repository::RepositoryDTO>(true,
                                                                                                                                                       true);
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<Contracts::DTO::Repository::UpdateRepositoryDTO, QleanyEditor::Entities::Repository>();
}