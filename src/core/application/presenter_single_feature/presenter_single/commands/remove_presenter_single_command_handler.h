// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single/commands/remove_presenter_single_command.h"
#include "presenter_single/presenter_single_dto.h"
#include "qleany_editor_application_presenter_single_export.h"

#include "repository/interface_presenter_single_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::PresenterSingle;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterSingle::Commands;

namespace QleanyEditor::Application::Features::PresenterSingle::Commands
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_SINGLE_EXPORT RemovePresenterSingleCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemovePresenterSingleCommandHandler(InterfacePresenterSingleRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemovePresenterSingleCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void presenterSingleRemoved(int id);

private:
    InterfacePresenterSingleRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemovePresenterSingleCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::PresenterSingle m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterSingle::Commands