// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model/commands/update_presenter_list_model_command.h"
#include "presenter_list_model/presenter_list_model_dto.h"
#include "qleany_editor_application_presenter_list_model_export.h"

#include "repository/interface_presenter_list_model_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterListModel;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Commands;

namespace QleanyEditor::Application::Features::PresenterListModel::Commands
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_LIST_MODEL_EXPORT UpdatePresenterListModelCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdatePresenterListModelCommandHandler(InterfacePresenterListModelRepository *repository);
    Result<PresenterListModelDTO> handle(QPromise<Result<void>> &progressPromise, const UpdatePresenterListModelCommand &request);
    Result<PresenterListModelDTO> restore();

Q_SIGNALS:
    void presenterListModelUpdated(QleanyEditor::Contracts::DTO::PresenterListModel::PresenterListModelDTO presenterListModelDto);
    void presenterListModelDetailsUpdated(int id);

private:
    InterfacePresenterListModelRepository *m_repository;
    Result<PresenterListModelDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdatePresenterListModelCommand &request);
    Result<PresenterListModelDTO> restoreImpl();
    Result<PresenterListModelDTO> saveOldState();
    Result<PresenterListModelDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterListModel::Commands