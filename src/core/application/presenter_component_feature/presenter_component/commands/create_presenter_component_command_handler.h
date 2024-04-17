// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_component/commands/create_presenter_component_command.h"
#include "presenter_component/presenter_component_dto.h"
#include "qleany_editor_application_presenter_component_export.h"
#include "repository/interface_presenter_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::PresenterComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::PresenterComponent::Commands;

namespace QleanyEditor::Application::Features::PresenterComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_PRESENTER_COMPONENT_EXPORT CreatePresenterComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreatePresenterComponentCommandHandler(InterfacePresenterComponentRepository *repository);

    Result<PresenterComponentDTO> handle(QPromise<Result<void>> &progressPromise, const CreatePresenterComponentCommand &request);
    Result<PresenterComponentDTO> restore();

Q_SIGNALS:
    void presenterComponentCreated(QleanyEditor::Contracts::DTO::PresenterComponent::PresenterComponentDTO presenterComponentDto);
    void presenterComponentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfacePresenterComponentRepository *m_repository;
    Result<PresenterComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreatePresenterComponentCommand &request);
    Result<PresenterComponentDTO> restoreImpl();
    Result<QleanyEditor::Entities::PresenterComponent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QleanyEditor::Entities::PresenterComponent m_oldOwnerPresenterComponent;
    QleanyEditor::Entities::PresenterComponent m_ownerPresenterComponentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::PresenterComponent::Commands