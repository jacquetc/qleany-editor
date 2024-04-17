// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_application_feature_query_handler.h"
#include "repository/interface_application_feature_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::ApplicationFeature::Queries;

GetApplicationFeatureQueryHandler::GetApplicationFeatureQueryHandler(InterfaceApplicationFeatureRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ApplicationFeatureDTO> GetApplicationFeatureQueryHandler::handle(QPromise<Result<void>> &progressPromise, const GetApplicationFeatureQuery &query)
{
    Result<ApplicationFeatureDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<ApplicationFeatureDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetApplicationFeatureQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ApplicationFeatureDTO> GetApplicationFeatureQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise, const GetApplicationFeatureQuery &query)
{
    qDebug() << "GetApplicationFeatureQueryHandler::handleImpl called with id" << query.id;

    // do
    auto applicationFeatureResult = m_repository->get(query.id);

    QLN_RETURN_IF_ERROR(ApplicationFeatureDTO, applicationFeatureResult)

    // map
    auto dto = Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationFeature, ApplicationFeatureDTO>(applicationFeatureResult.value());

    qDebug() << "GetApplicationFeatureQueryHandler::handleImpl done";

    return Result<ApplicationFeatureDTO>(dto);
}

bool GetApplicationFeatureQueryHandler::s_mappingRegistered = false;

void GetApplicationFeatureQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationFeature,
                                                           Contracts::DTO::ApplicationFeature::ApplicationFeatureDTO>(true, true);
}