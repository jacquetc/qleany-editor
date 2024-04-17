// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single/commands/update_presenter_single_command.h"
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
class QLEANY_EDITOR_APPLICATION_PRESENTER_SINGLE_EXPORT UpdatePresenterSingleCommandHandler : public QObject

{
    Q_OBJECT
public:
    UpdatePresenterSingleCommandHandler(InterfacePresenterSingleRepository *repository);
    Result<PresenterSingleDTO> handle(QPromise<Result<void>> &progressPromise, const UpdatePresenterSingleCommand &request);
    Result<PresenterSingleDTO> restore();

Q_SIGNALS:
    void presenterSingleUpdated(QleanyEditor::Contracts::DTO::PresenterSingle::PresenterSingleDTO presenterSingleDto);
    void presenterSingleDetailsUpdated(int id);

private:
    InterfacePresenterSingleRepository *m_repository;
    Result<PresenterSingleDTO> handleImpl(QPromise<Result<void>> &progressPromise, const UpdatePresenterSingleCommand &request);
    Result<PresenterSingleDTO> restoreImpl();
    Result<PresenterSingleDTO> saveOldState();
    Result<PresenterSingleDTO> m_undoState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::PresenterSingle::Commands