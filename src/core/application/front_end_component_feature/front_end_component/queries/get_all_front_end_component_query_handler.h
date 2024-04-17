// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "front_end_component/front_end_component_dto.h"
#include "qleany_editor_application_front_end_component_export.h"

#include "repository/interface_front_end_component_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;
using namespace QleanyEditor::Contracts::Repository;

namespace QleanyEditor::Application::Features::FrontEndComponent::Queries
{
class QLEANY_EDITOR_APPLICATION_FRONT_END_COMPONENT_EXPORT GetAllFrontEndComponentQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetAllFrontEndComponentQueryHandler(InterfaceFrontEndComponentRepository *repository);
    Result<QList<FrontEndComponentDTO>> handle(QPromise<Result<void>> &progressPromise);

private:
    InterfaceFrontEndComponentRepository *m_repository;
    Result<QList<FrontEndComponentDTO>> handleImpl(QPromise<Result<void>> &progressPromise);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::FrontEndComponent::Queries