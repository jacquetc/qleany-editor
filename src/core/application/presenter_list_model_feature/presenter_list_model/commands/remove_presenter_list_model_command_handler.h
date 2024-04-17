// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model/commands/remove_presenter_list_model_command.h"
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
class QLEANY_EDITOR_APPLICATION_PRESENTER_LIST_MODEL_EXPORT RemovePresenterListModelCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemovePresenterListModelCommandHandler(InterfacePresenterListModelRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemovePresenterListModelCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void presenterListModelRemoved(int id);

private:
    InterfacePresenterListModelRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemovePresenterListModelCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::PresenterListModel m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterListModel::Commands