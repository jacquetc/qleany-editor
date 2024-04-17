// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "front_end_component/commands/create_front_end_component_command.h"
#include "front_end_component/front_end_component_dto.h"
#include "qleany_editor_application_front_end_component_export.h"
#include "repository/interface_front_end_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Entities;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Commands;

namespace QleanyEditor::Application::Features::FrontEndComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_FRONT_END_COMPONENT_EXPORT CreateFrontEndComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    CreateFrontEndComponentCommandHandler(InterfaceFrontEndComponentRepository *repository);

    Result<FrontEndComponentDTO> handle(QPromise<Result<void>> &progressPromise, const CreateFrontEndComponentCommand &request);
    Result<FrontEndComponentDTO> restore();

Q_SIGNALS:
    void frontEndComponentCreated(QleanyEditor::Contracts::DTO::FrontEndComponent::FrontEndComponentDTO frontEndComponentDto);
    void frontEndComponentRemoved(int id);

    void relationWithOwnerInserted(int id, int ownerId, int position);
    void relationWithOwnerRemoved(int id, int ownerId);

private:
    InterfaceFrontEndComponentRepository *m_repository;
    Result<FrontEndComponentDTO> handleImpl(QPromise<Result<void>> &progressPromise, const CreateFrontEndComponentCommand &request);
    Result<FrontEndComponentDTO> restoreImpl();
    Result<QleanyEditor::Entities::FrontEndComponent> m_newEntity;

    int m_ownerId = -1;
    int m_position = -1;

    QList<QleanyEditor::Entities::FrontEndComponent> m_oldOwnerFrontEndComponent;
    QList<QleanyEditor::Entities::FrontEndComponent> m_ownerFrontEndComponentNewState;

    static bool s_mappingRegistered;
    void registerMappings();
    bool m_firstPass = true;
};

} // namespace QleanyEditor::Application::Features::FrontEndComponent::Commands