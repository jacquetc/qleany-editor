// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_all_repository_query_handler.h"
#include "repository/interface_repository_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::Repository::Queries;

GetAllRepositoryQueryHandler::GetAllRepositoryQueryHandler(InterfaceRepositoryRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<QList<RepositoryDTO>> GetAllRepositoryQueryHandler::handle(QPromise<Result<void>> &progressPromise)
{
    qDebug() << "GetAllRepositoryQueryHandler::handle called";

    Result<QList<RepositoryDTO>> result;

    try {
        result = handleImpl(progressPromise);
    } catch (const std::exception &ex) {
        result = Result<QList<RepositoryDTO>>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetAllRepositoryQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<QList<RepositoryDTO>> GetAllRepositoryQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise)
{
    qDebug() << "GetAllRepositoryQueryHandler::handleImpl called";

    // do
    auto repositoryResult = m_repository->getAll();

    QLN_RETURN_IF_ERROR(QList<RepositoryDTO>, repositoryResult)

    // map
    QList<RepositoryDTO> dtoList;

    for (const QleanyEditor::Entities::Repository &repository : repositoryResult.value()) {
        auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Repository, RepositoryDTO>(repository);
        dtoList.append(dto);
    }

    qDebug() << "GetAllRepositoryQueryHandler::handleImpl done";

    return Result<QList<RepositoryDTO>>(dtoList);
}

bool GetAllRepositoryQueryHandler::s_mappingRegistered = false;

void GetAllRepositoryQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Repository, Contracts::DTO::Repository::RepositoryDTO>(true, true);
}