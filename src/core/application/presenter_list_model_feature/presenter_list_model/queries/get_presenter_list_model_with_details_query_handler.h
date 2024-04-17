// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model/presenter_list_model_with_details_dto.h"
#include "presenter_list_model/queries/get_presenter_list_model_query.h"
#include "qleany_editor_application_presenter_list_model_export.h"

#include "repository/interface_presenter_list_model_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterListModel;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Queries;

namespace QleanyEditor::Application::Features::PresenterListModel::Queries
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_LIST_MODEL_EXPORT GetPresenterListModelWithDetailsQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetPresenterListModelWithDetailsQueryHandler(InterfacePresenterListModelRepository *repository);
    Result<PresenterListModelWithDetailsDTO> handle(QPromise<Result<void>> &progressPromise, const GetPresenterListModelQuery &query);

private:
    InterfacePresenterListModelRepository *m_repository;
    Result<PresenterListModelWithDetailsDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetPresenterListModelQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterListModel::Queries