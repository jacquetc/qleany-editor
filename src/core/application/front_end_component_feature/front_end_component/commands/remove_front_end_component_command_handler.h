// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "front_end_component/commands/remove_front_end_component_command.h"
#include "front_end_component/front_end_component_dto.h"
#include "qleany_editor_application_front_end_component_export.h"

#include "repository/interface_front_end_component_repository.h"
#include <QPromise>
#include <qleany/common/result.h>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::FrontEndComponent::Commands;

namespace QleanyEditor::Application::Features::FrontEndComponent::Commands
{
class QLEANY_EDITOR_APPLICATION_FRONT_END_COMPONENT_EXPORT RemoveFrontEndComponentCommandHandler : public QObject
{
    Q_OBJECT
public:
    RemoveFrontEndComponentCommandHandler(InterfaceFrontEndComponentRepository *repository);
    Result<int> handle(QPromise<Result<void>> &progressPromise, const RemoveFrontEndComponentCommand &request);
    Result<int> restore();

Q_SIGNALS:
    // repositories handle remove Q_SIGNALS
    // void frontEndComponentRemoved(int id);

private:
    InterfaceFrontEndComponentRepository *m_repository;
    Result<int> handleImpl(QPromise<Result<void>> &progressPromise, const RemoveFrontEndComponentCommand &request);
    Result<int> restoreImpl();
    QleanyEditor::Entities::FrontEndComponent m_oldState;
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::FrontEndComponent::Commands