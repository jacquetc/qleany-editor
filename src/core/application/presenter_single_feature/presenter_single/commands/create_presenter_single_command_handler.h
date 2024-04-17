// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single/commands/create_presenter_single_command.h"
#include "presenter_single/presenter_single_dto.h"
#include "qleany_editor_application_presenter_single_export.h"
#include "repository/interface_presenter_single_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::PresenterSingle;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Commands;

namespace QleanyEditor::Application::Features::PresenterSingle::Commands
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_SINGLE_EXPORT CreatePresenterSingleCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreatePresenterSingleCommandHandler(InterfacePresenterSingleRepository *repository);

    Result<PresenterSingleDTO> handle(QPromise<Result<void>> &progressPromise, const CreatePresenterSingleCommand &request);
    Result<PresenterSingleDTO> restore();

Q_SIGNALS:
    void presenterSingleCreated(QleanyEditor::Contracts::DTO::PresenterSingle::PresenterSingleDTO presenterSingleDto);
    void presenterSingleRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfacePresenterSingleRepository *m_repository;
    Result<PresenterSingleDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreatePresenterSingleCommand &request);
    Result<PresenterSingleDTO> restoreImpl();
    Result<QleanyEditor::Entities::PresenterSingle> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::PresenterSingle> m_oldOwnerSingles;
    QList<QleanyEditor::Entities::PresenterSingle> m_ownerSinglesNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::PresenterSingle::Commands