// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single/presenter_single_dto.h"
#include "presenter_single/queries/get_presenter_single_query.h"
#include "qleany_editor_application_presenter_single_export.h"

#include "repository/interface_presenter_single_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterSingle;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Queries;

namespace QleanyEditor::Application::Features::PresenterSingle::Queries
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_SINGLE_EXPORT GetPresenterSingleQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetPresenterSingleQueryHandler(InterfacePresenterSingleRepository *repository);
    Result<PresenterSingleDTO> handle(QPromise<Result<void>> &progressPromise, const GetPresenterSingleQuery &query);

private:
    InterfacePresenterSingleRepository *m_repository;
    Result<PresenterSingleDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetPresenterSingleQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterSingle::Queries