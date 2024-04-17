// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "get_application_feature_with_details_query_handler.h"
#include "repository/interface_application_feature_repository.h"
#include <qleany/tools/automapper/automapper.h>

using namespace Qleany;
using namespace QleanyEditor::Application::Features::ApplicationFeature::Queries;

GetApplicationFeatureWithDetailsQueryHandler::GetApplicationFeatureWithDetailsQueryHandler(InterfaceApplicationFeatureRepository *repository)
    : m_repository(repository)
{
    if (!s_mappingRegistered) {
        registerMappings();
        s_mappingRegistered = true;
    }
}

Result<ApplicationFeatureWithDetailsDTO> GetApplicationFeatureWithDetailsQueryHandler::handle(QPromise<Result<void>> &progressPromise,
                                                                                              const GetApplicationFeatureQuery &query)
{
    Result<ApplicationFeatureWithDetailsDTO> result;

    try {
        result = handleImpl(progressPromise, query);
    } catch (const std::exception &ex) {
        result = Result<ApplicationFeatureWithDetailsDTO>(QLN_ERROR_2(Q_FUNC_INFO, Error::Critical, "Unknown error", ex.what()));
        qDebug() << "Error handling GetApplicationFeatureQuery:" << ex.what();
    }
    progressPromise.addResult(Result<void>(result.error()));
    return result;
}

Result<ApplicationFeatureWithDetailsDTO> GetApplicationFeatureWithDetailsQueryHandler::handleImpl(QPromise<Result<void>> &progressPromise,
                                                                                                  const GetApplicationFeatureQuery &query)
{
    qDebug() << "GetApplicationFeatureWithDetailsQueryHandler::handleImpl called with id" << query.id;

    // do
    auto applicationFeatureResult = m_repository->getWithDetails(query.id);

    QLN_RETURN_IF_ERROR(ApplicationFeatureWithDetailsDTO, applicationFeatureResult)

    QleanyEditor::Entities::ApplicationFeature applicationFeature = applicationFeatureResult.value();

    // map
    auto applicationFeatureWithDetailsDTO =
        Qleany::Tools::AutoMapper::AutoMapper::map<QleanyEditor::Entities::ApplicationFeature, ApplicationFeatureWithDetailsDTO>(applicationFeature);

    qDebug() << "GetApplicationFeatureWithDetailsQueryHandler::handleImpl done";

    return Result<ApplicationFeatureWithDetailsDTO>(applicationFeatureWithDetailsDTO);
}

bool GetApplicationFeatureWithDetailsQueryHandler::s_mappingRegistered = false;

void GetApplicationFeatureWithDetailsQueryHandler::registerMappings()
{
    Qleany::Tools::AutoMapper::AutoMapper::registerMapping<QleanyEditor::Entities::ApplicationFeature,
                                                           Contracts::DTO::ApplicationFeature::ApplicationFeatureWithDetailsDTO>();
}