// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_list_model/commands/create_presenter_list_model_command.h"
#include "presenter_list_model/presenter_list_model_dto.h"
#include "qleany_editor_application_presenter_list_model_export.h"
#include "repository/interface_presenter_list_model_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::PresenterListModel;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterListModel::Commands;

namespace QleanyEditor::Application::Features::PresenterListModel::Commands
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_LIST_MODEL_EXPORT CreatePresenterListModelCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreatePresenterListModelCommandHandler(InterfacePresenterListModelRepository *repository);

    Result<PresenterListModelDTO> handle(QPromise<Result<void>> &progressPromise, const CreatePresenterListModelCommand &request);
    Result<PresenterListModelDTO> restore();

Q_SIGNALS:
    void presenterListModelCreated(QleanyEditor::Contracts::DTO::PresenterListModel::PresenterListModelDTO presenterListModelDto);
    void presenterListModelRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfacePresenterListModelRepository *m_repository;
    Result<PresenterListModelDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreatePresenterListModelCommand &request);
    Result<PresenterListModelDTO> restoreImpl();
    Result<QleanyEditor::Entities::PresenterListModel> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::PresenterListModel> m_oldOwnerListModels;
    QList<QleanyEditor::Entities::PresenterListModel> m_ownerListModelsNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::PresenterListModel::Commands