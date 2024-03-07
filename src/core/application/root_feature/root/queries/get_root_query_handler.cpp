// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_root_query_handler.h"
#include "repository/interface_root_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::Root::Queries;

GetRootQueryHandler::GetRootQueryHandler(InterfaceRootRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<RootDTO> GetRootQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetRootQuery &query)
{
    Result<RootDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<RootDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetRootQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<RootDTO> GetRootQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetRootQuery &query)
{
    qDebug() << "GetRootQueryHandler::handleImpl called with id" << query.id;

    // do
    auto rootResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(RootDTO, rootResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::Root, RootDTO>(rootResult.value());

    qDebug() << "GetRootQueryHandler::handleImpl done";

    return Result<RootDTO>(dto);
}

bool GetRootQueryHandler::s_mappingRegistered = false;

void GetRootQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::Root, Contracts::DTO::Root::RootDTO>(true, true);
}